#ifndef _TWODIMENSIONAL_H
#define	_TWODIMENSIONAL_H

#include "Point.h"
#include "NDimensional.h"

class TwoDimensional : public NDimensional{
public:
    TwoDimensional(unsigned long *sizes, size_t nbOfPoints);
    void drawPoints(Point *points, double r, double g, double b);
    void printPlane();
};

#endif /*_TWODIMENSIONAL_H */
