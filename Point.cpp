#include "Point.h"
#include <cmath>

template <typename T, size_t dimensions>
void Point<T, dimensions>::setCoordinates(std::array<T, dimensions> &coordinates){
    //TODO: zou dit niet opgelost kunnen worden met move semantics (niet kritisch)
    for(size_t i=0; i<dimensions; ++i){
        this->coordinates[i] = coordinates[i];
    }
}

template <typename T, size_t dimensions>
T Point<T, dimensions>::calculateDistanceTo(const Point &p) const{
    return std::sqrt(calculateSquareDistanceTo(p));
}

template <typename T, size_t dimensions>
T Point<T, dimensions>::calculateSquareDistanceTo(const Point &p) const{
    std::array<T, dimensions> diff;

    for(size_t i=0; i<dimensions; ++i){
        diff[i] = coordinates[i]-p.coordinates[i];
    }

    T sum = 0.0;
    for(size_t i=0; i<dimensions; ++i){
        sum += (diff[i]*diff[i]);
    }

    return sum;
}
