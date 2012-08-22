#include "Point.h"
#include <cmath>

template <size_t dimensions>
Point<dimensions>::Point(){}

template <size_t dimensions>
void Point<dimensions>::setCoordinates(std::array<double, dimensions> &coordinates){
    for(size_t i=0; i<dimensions; ++i){
        this->coordinates[i] = coordinates[i];
    }
}

template <size_t dimensions>
double Point<dimensions>::calculateDistanceTo(Point p){
    double *diff = new double[dimensions];

    for(size_t i=0; i<dimensions; ++i){
        diff[i] = getCoordinate(i)-p.getCoordinate(i);
    }

    double sum = 0.0;
    for(size_t i=0; i<dimensions; ++i){
        sum += (diff[i]*diff[i]);
    }

    delete[] diff;
    return sqrt(sum);
}

template <size_t dimensions>
double Point<dimensions>::calculateSquareDistanceTo(Point p){
    double *diff = new double[dimensions];

    for(size_t i=0; i<dimensions; ++i){
        diff[i] = getCoordinate(i)-p.getCoordinate(i);
    }

    double sum = 0.0;
    for(size_t i=0; i<dimensions; ++i){
        sum += (diff[i]*diff[i]);
    }

    delete[] diff;
    return sum;
}
