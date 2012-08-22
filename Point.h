#ifndef _POINT_H
#define	_POINT_H

#include <cstddef>

struct Point {
    Point();
    Point(size_t dimension);
    void setCoordinates(double *coordinates);
    double getCoordinate(size_t dimension){return coordinates[dimension];}
    void setCoordinate(size_t dimension, double coordinate){coordinates[dimension] = coordinate;}
    void setDimension(size_t dimension);
    double calculateDistanceTo(Point p);
    double calculateSquareDistanceTo(Point p);

    size_t dimension;
    double *coordinates;
};

#endif	/* _POINT_H */

