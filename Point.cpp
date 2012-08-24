#include "Point.h"
#include <cmath>

template <size_t dimensions>
void Point<dimensions>::setCoordinates(std::array<double, dimensions> &coordinates){
    //TODO: zou dit niet opgelost kunnen worden met move semantics (niet kritisch)
    for(size_t i=0; i<dimensions; ++i){
        this->coordinates[i] = coordinates[i];
    }
}

template <size_t dimensions>
double Point<dimensions>::calculateDistanceTo(const Point &p) const{
    return std::sqrt(calculateSquareDistanceTo(p));
}

template <size_t dimensions>
double Point<dimensions>::calculateSquareDistanceTo(const Point &p) const{
    std::array<double, dimensions> diff;

    for(size_t i=0; i<dimensions; ++i){
        diff[i] = coordinates[i]-p.coordinates[i];
    }

    double sum = 0.0;
    for(size_t i=0; i<dimensions; ++i){
        sum += (diff[i]*diff[i]);
    }

    return sum;
}
