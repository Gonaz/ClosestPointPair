#include "NDimensional.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <deque>
#include <cfloat>
#include <cmath>

#define RESOLUTION 0.0000000001

NDimensional::NDimensional(unsigned long *sizes, size_t dimension, size_t nbOfPoints){
    this->dimension = dimension;
    this->nbOfPoints = nbOfPoints;
    this->sizes = sizes;
    fillPlane();
    //fillPlaneWorstCase();
}

void NDimensional::fillPlane(){
    srand(time(NULL));
    try{
        points = new Point[nbOfPoints];
    }catch(bad_alloc&){
        fprintf(stderr, "Bad memory allocation. Maybe the number of points is too large or negative.\n");
    }

    double *locations = new double[dimension];

    for(size_t i=0; i<nbOfPoints; ++i){
        points[i].setDimension(dimension);
        for(size_t j=0; j<dimension; ++j){
            locations[j] = (rand()%(long)(sizes[j]/RESOLUTION))*RESOLUTION;
        }
        points[i].setCoordinates(locations);
    }

    delete[] locations;
}

void NDimensional::fillPlaneWorstCase(){
    srand(time(NULL));
    try{
        points = new Point[nbOfPoints];
    }catch(bad_alloc&){
        fprintf(stderr, "Bad memory allocation. Maybe the number of points is too large or negative.\n");
    }
    
    double *locations = new double[dimension];
    locations[0] = (rand()%(long)(sizes[0]/RESOLUTION))*RESOLUTION;
//    for(size_t j=1; j<dimension; ++j){
//        locations[j] = 0.5;
//    }

    for(size_t i=0; i<nbOfPoints; ++i){
        points[i].setDimension(dimension);
        for(size_t j=1; j<dimension; ++j){
            //locations[j] += RESOLUTION;
            locations[j] = (rand()%(long)(sizes[j]/RESOLUTION))*RESOLUTION;
        }
        points[i].setCoordinates(locations);
    }

    delete[] locations;
}

Point* NDimensional::sweep(){
    sortPoints(&points[0], nbOfPoints);

    deque<Point> pointsSorted;
    for(size_t i=0; i<nbOfPoints; ++i){
        pointsSorted.push_back(points[i]);
    }

    Point *closestPointPair;
    try{
        closestPointPair = new Point[2];
    } catch(bad_alloc&){
        fprintf(stderr, "Bad memory allocation");
    }

    closestPointPair[0] = pointsSorted.at(0);
    closestPointPair[1] = pointsSorted.at(1);

    double d = pointsSorted.at(0).calculateSquareDistanceTo(pointsSorted.at(1));
    double sqrtD = sqrt(d);
    long unsigned l = 2;

    long unsigned aantal = 0; //nodige voor de gemiddelde k-waarde/c-waarde te berekenen
    long unsigned k = 0; //nodige voor de gemiddelde k-waarde te berekenen
    long unsigned c = 0;  //nodige voor de gemiddelde c-waarde te berekenen
    long unsigned maxK = 0; //nodige voor de maximale k-waarde te berekenen
    long unsigned tellerK = 0; //nodige voor de maximale k-waarde te berekenen
    long unsigned maxC = 0;
    long unsigned tellerC = 0;

    while(l<pointsSorted.size()){
        ++aantal; //nodige voor de gemiddelde k-waarde te berekenen
        if(tellerK>maxK){ //nodige voor de maximale k-waarde te berekenen
            maxK = tellerK;
        }
        if(tellerC>maxC){ //nodige voor de maximale c-waarde te berekenen
            maxC = tellerC;
        }
        tellerK = 0; //nodige voor de maximale k-waarde te berekenen
        tellerC = 0; //nodige voor de maximale c-waarde te berekenen

        for(unsigned long j=0; j<l;){
            if(pointsSorted.at(l).getCoordinate(0)-pointsSorted.at(j).getCoordinate(0) >= sqrtD){
                pointsSorted.pop_front();
                --l;
            } else{
                ++k; //nodige voor de gemiddelde k-waarde te berekenen
                ++tellerK; //nodige voor de maximale k-waarde te berekenen
                bool candidate = true;
                size_t i=1;
                while(candidate && i<dimension){
                    candidate = pointsSorted.at(l).getCoordinate(i)-pointsSorted.at(j).getCoordinate(i++) < sqrtD;
                }
                
                if(candidate){
                    ++c;  //nodige voor de gemiddelde c-waarde te berekenen
                    ++tellerC;
                    double distance = pointsSorted.at(j).calculateSquareDistanceTo(pointsSorted.at(l));
                    if(distance < d){
                        d = distance;
                        sqrtD = sqrt(d);
                        closestPointPair[0] = pointsSorted.at(j);
                        closestPointPair[1] = pointsSorted.at(l);
                    }
                }
                ++j;
            }
        }
        ++l;
    }

    double kGem = (double)k/aantal; //nodige voor de gemiddelde k-waarde te berekenen
    double cGem = (double)c/aantal;  //nodige voor de gemiddelde c-waarde te berekenen
    printf("%lf\t", kGem); //nodige voor de gemiddelde k-waarde te berekenen
    printf("%lf\t", cGem); //nodige voor de gemiddelde c-waarde te berekenen
    printf("%lu\t", maxK);
    printf("%lu\t", maxC);

    return closestPointPair;
}

Point* NDimensional::bruteForce(){
    double min = DBL_MAX;
    size_t index1, index2;
    double distance;

    for(size_t i=0; i<nbOfPoints; ++i){
        for(size_t j=0; j<i; ++j){
            distance = points[i].calculateDistanceTo(points[j]);
            if(distance < min){
                min = distance;
                index1 = i;
                index2 = j;
            }
        }
    }

    Point *closestPointPair;
    try{
        closestPointPair = new Point[2];
    } catch(bad_alloc&){
        fprintf(stderr, "Bad memory allocation.");
    }
    closestPointPair[0] = points[index1];
    closestPointPair[1] = points[index2];

    return closestPointPair;
}
