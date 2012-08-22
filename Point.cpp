#include "Point.h"
#include <cmath>

Point::Point(){}

Point::Point(size_t dimension) : dimension(dimension){
    coordinates = new double[dimension];
}

void Point::setCoordinates(double *coordinates){
    for(size_t i=0; i<dimension; ++i){
        this->coordinates[i] = coordinates[i];
    }
}

void Point::setDimension(size_t dimension){
    this->dimension = dimension;
    coordinates = new double[dimension];
}

/*
 * Pre: punten moeten van dezelfde dimensie zijn
 */
double Point::calculateDistanceTo(Point p){
    double *diff = new double[dimension];

    for(size_t i=0; i<dimension; ++i){
        diff[i] = getCoordinate(i)-p.getCoordinate(i);
    }

    double sum = 0.0;
    for(size_t i=0; i<dimension; ++i){
        sum += (diff[i]*diff[i]);
    }

    delete[] diff;
    return sqrt(sum);
}

/*
 *  Pre: punten moeten van dezelfde dimensie zijn
 */
double Point::calculateSquareDistanceTo(Point p){
    double *diff = new double[dimension];

    for(size_t i=0; i<dimension; ++i){
        diff[i] = getCoordinate(i)-p.getCoordinate(i);
    }

    double sum = 0.0;
    for(size_t i=0; i<dimension; ++i){
        sum += (diff[i]*diff[i]);
    }

    delete[] diff;
    return sum;
}
