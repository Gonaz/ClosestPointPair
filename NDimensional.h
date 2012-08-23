#ifndef _NDIMENSIONAL_H
#define	_NDIMENSIONAL_H

#include "Point.h"
#include <algorithm>

template <size_t dimensions, size_t nbOfPoints>
struct NDimensional {
    NDimensional();
    ~NDimensional(){delete points;}
    std::pair<Point<dimensions>, Point<dimensions> > sweep();
    std::pair<Point<dimensions>, Point<dimensions> > bruteForce();
    void fillPlane();
    void fillPlaneWorstCase();

    std::array<Point<dimensions>, nbOfPoints> *points;

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<> dis;
};

#endif	/* _NDIMENSIONAL_H */
