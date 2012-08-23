#define STATISTICS 0

#if STATISTICS
#include <iostream>
#endif //STATISTICS
#include <deque>
#include <cfloat>
#include <algorithm>
#include "NDimensional.h"

using namespace std;

template <size_t dimensions, size_t nbOfPoints>
NDimensional<dimensions, nbOfPoints>::NDimensional() : gen(rd()), dis(std::uniform_real_distribution<>(0, 1000000)){
    points = new std::array<Point<dimensions>, nbOfPoints>();
    fillPlane();
    //fillPlaneWorstCase();
}

template <size_t dimensions, size_t nbOfPoints>
void NDimensional<dimensions, nbOfPoints>::fillPlane(){
    std::array<double, dimensions> locations;

    for(size_t i=0; i<nbOfPoints; ++i){
        for(size_t j=0; j<dimensions; ++j){
            locations[j] = dis(gen);
        }
        points->operator [](i).setCoordinates(locations);
    }
}

template <size_t dimensions, size_t nbOfPoints>
void NDimensional<dimensions, nbOfPoints>::fillPlaneWorstCase(){
    points = std::vector<Point<dimensions> >(nbOfPoints);
    std::vector<double> locations(dimensions);

    locations[0] = dis(gen);
    for(size_t i=0; i<nbOfPoints; ++i){
        points[i].setDimension(dimensions);
        for(size_t j=1; j<dimensions; ++j){
            locations[j] = dis(gen);
        }
        points->operator [](i).setCoordinates(locations);
    }
}

template <size_t dimensions, size_t nbOfPoints>
std::pair<Point<dimensions> , Point<dimensions> > NDimensional<dimensions, nbOfPoints>::sweep(){
    std::sort(points->begin(), points->end(), [](Point<dimensions> p1, Point<dimensions> p2){return p1.coordinates[0] < p2.coordinates[0];});

    deque<Point<dimensions> > pointsSorted;
    for(size_t i=0; i<nbOfPoints; ++i){
        pointsSorted.push_back(points->operator [](i));
    }

    std::pair<Point<dimensions> , Point<dimensions> > closestPointPair(pointsSorted[0], pointsSorted[1]);

    double d = pointsSorted[0].calculateSquareDistanceTo(pointsSorted[1]);
    double sqrtD = sqrt(d);
    unsigned long l = 2;

#if STATISTICS
    unsigned long aantal = 0; //nodige voor de gemiddelde k-waarde/c-waarde te berekenen
    unsigned long k = 0; //nodige voor de gemiddelde k-waarde te berekenen
    unsigned long c = 0;  //nodige voor de gemiddelde c-waarde te berekenen
    unsigned long maxK = 0; //nodige voor de maximale k-waarde te berekenen
    unsigned long tellerK = 0; //nodige voor de maximale k-waarde te berekenen
    unsigned long maxC = 0;
    unsigned long tellerC = 0;
#endif //STATISTICS

    while(l<pointsSorted.size()){
#if STATISTICS
        ++aantal; //nodige voor de gemiddelde k-waarde te berekenen
        if(tellerK>maxK){ //nodige voor de maximale k-waarde te berekenen
            maxK = tellerK;
        }
        if(tellerC>maxC){ //nodige voor de maximale c-waarde te berekenen
            maxC = tellerC;
        }
        tellerK = 0; //nodige voor de maximale k-waarde te berekenen
        tellerC = 0; //nodige voor de maximale c-waarde te berekenen
#endif //STATISTICS

        for(unsigned long j=0; j<l;){
            if(pointsSorted[l].coordinates[0]-pointsSorted[j].coordinates[0] >= sqrtD){
                pointsSorted.pop_front();
                --l;
            } else{
#if STATISTICS
                ++k; //nodige voor de gemiddelde k-waarde te berekenen
                ++tellerK; //nodige voor de maximale k-waarde te berekenen
#endif //STATISTICS
                bool candidate = true;
                size_t i=1;
                while(candidate && i<dimensions){
                    candidate = pointsSorted[l].coordinates[i]-pointsSorted[j].coordinates[i] < sqrtD;
                    ++i;
                }
                
                if(candidate){
#if STATISTICS
                    ++c;  //nodige voor de gemiddelde c-waarde te berekenen
                    ++tellerC;
#endif //STATISTICS
                    const double distance = pointsSorted[j].calculateSquareDistanceTo(pointsSorted[l]);
                    if(distance < d){
                        d = distance;
                        sqrtD = sqrt(d);
                        closestPointPair.first = pointsSorted[j];
                        closestPointPair.second = pointsSorted[l];
                    }
                }
                ++j;
            }
        }
        ++l;
    }

#if STATISTICS
    double kGem = (double)k/aantal; //nodige voor de gemiddelde k-waarde te berekenen
    double cGem = (double)c/aantal;  //nodige voor de gemiddelde c-waarde te berekenen
    std::cout << kGem << "\t" << cGem << "\t" << "\t" << maxK << "\t" << maxC << std::endl;
#endif //STATISTICS

    return closestPointPair;
}

template <size_t dimensions, size_t nbOfPoints>
std::pair<Point<dimensions> , Point<dimensions> > NDimensional<dimensions, nbOfPoints>::bruteForce(){
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

    return std::make_pair(points[index1], points[index2]);
}
