#ifndef _POINT_H
#define	_POINT_H

#include <cstdlib>

class Point {
public:
    Point();
    Point(size_t dimension);
    double* getCoordinates(){return coordinates;};
    void setCoordinates(double *coordinates);
    double getCoordinate(size_t dimension){return coordinates[dimension];};
    void setCoordinate(size_t dimension, double coordinate){coordinates[dimension] = coordinate;};
    size_t getDimension(){return dimension;};
    void setDimension(size_t dimension);
    double calculateDistanceTo(Point p);
    double calculateSquareDistanceTo(Point p);
private:
    size_t dimension;
    double *coordinates;
};

#endif	/* _POINT_H */

