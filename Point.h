#ifndef _POINT_H
#define	_POINT_H

#include <array>

template<size_t dimensions>
struct Point {
    Point(){}

    void setCoordinates(std::array<double, dimensions> &coordinates);

    double calculateDistanceTo(const Point &p) const;
    double calculateSquareDistanceTo(const Point &p) const;

    std::array<double, dimensions> coordinates;
};

#endif	/* _POINT_H */

