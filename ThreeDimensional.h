#ifndef _THREEDIMENSIONAL_H
#define	_THREEDIMENSIONAL_H

#include "Point.h"
#include "NDimensional.h"

class ThreeDimensional : public NDimensional{
public:
    ThreeDimensional(unsigned long *sizes, size_t nbOfPoints);
    void drawPoints(Point *points, double r, double g, double b);
    void printPlane();
    void printPlane(double angle);
};

#endif	/* _THREEDIMENSIONAL_H */

