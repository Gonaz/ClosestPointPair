#define STATISTICS 0

#if STATISTICS
#include <iostream>
#endif //STATISTICS
#include <deque>
#include <cfloat>
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
    std::sort(points->begin(), points->end(), [](Point<dimensions> p1, Point<dimensions> p2){return p1.getCoordinate(0) < p2.getCoordinate(0);});

    deque<Point<dimensions> > pointsSorted;
    for(size_t i=0; i<nbOfPoints; ++i){
        pointsSorted.push_back(points->operator [](i));
    }

    std::pair<Point<dimensions> , Point<dimensions> > closestPointPair(pointsSorted.at(0), pointsSorted.at(1));

    double d = pointsSorted.at(0).calculateSquareDistanceTo(pointsSorted.at(1));
    double sqrtD = sqrt(d);
    long unsigned l = 2;

#if STATISTICS
    long unsigned aantal = 0; //nodige voor de gemiddelde k-waarde/c-waarde te berekenen
    long unsigned k = 0; //nodige voor de gemiddelde k-waarde te berekenen
    long unsigned c = 0;  //nodige voor de gemiddelde c-waarde te berekenen
    long unsigned maxK = 0; //nodige voor de maximale k-waarde te berekenen
    long unsigned tellerK = 0; //nodige voor de maximale k-waarde te berekenen
    long unsigned maxC = 0;
    long unsigned tellerC = 0;
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
            if(pointsSorted.at(l).getCoordinate(0)-pointsSorted.at(j).getCoordinate(0) >= sqrtD){
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
                    candidate = pointsSorted.at(l).getCoordinate(i)-pointsSorted.at(j).getCoordinate(i++) < sqrtD;
                }
                
                if(candidate){
#if STATISTICS
                    ++c;  //nodige voor de gemiddelde c-waarde te berekenen
                    ++tellerC;
#endif //STATISTICS
                    double distance = pointsSorted.at(j).calculateSquareDistanceTo(pointsSorted.at(l));
                    if(distance < d){
                        d = distance;
                        sqrtD = sqrt(d);
                        closestPointPair.first = pointsSorted.at(j);
                        closestPointPair.second = pointsSorted.at(l);
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
