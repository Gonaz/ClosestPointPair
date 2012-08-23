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
double Point<dimensions>::calculateDistanceTo(Point &p) const{
    return sqrt(calculateSquareDistanceTo(p));
}

template <size_t dimensions>
double Point<dimensions>::calculateSquareDistanceTo(Point &p) const{
    //TODO: misschien eens herschrijven met std::accumulate
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
