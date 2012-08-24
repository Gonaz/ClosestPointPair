#ifndef _POINT_H
#define	_POINT_H

#include <array>

template<typename T, size_t dimensions>
struct Point {
    Point(){}

    void setCoordinates(std::array<T, dimensions> &coordinates);

    T calculateDistanceTo(const Point &p) const;
    T calculateSquareDistanceTo(const Point &p) const;

    std::array<T, dimensions> coordinates;
};

#endif	/* _POINT_H */

