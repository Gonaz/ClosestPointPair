#ifndef _POINT_H
#define	_POINT_H

#include <cstddef>
#include <array>

template<size_t dimensions>
struct Point {
    Point();
    void setCoordinates(std::array<double, dimensions> &coordinates);
    double getCoordinate(size_t dimension){return coordinates[dimension];}
    void setCoordinate(size_t dimension, double coordinate){coordinates[dimension] = coordinate;}
    double calculateDistanceTo(Point p);
    double calculateSquareDistanceTo(Point p);

    std::array<double, dimensions> coordinates;
};

#endif	/* _POINT_H */

