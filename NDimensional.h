#ifndef _NDIMENSIONAL_H
#define	_NDIMENSIONAL_H

#include "Point.h"
#include <random>

template <typename T, size_t dimensions, size_t nbOfPoints>
struct NDimensional {
    NDimensional();
    ~NDimensional(){delete points;}

    std::pair<Point<T, dimensions>, Point<T, dimensions> > sweep();
    std::pair<Point<T, dimensions>, Point<T, dimensions> > bruteForce();

    void fillPlane();
    void fillPlaneWorstCase();

    std::array<Point<T, dimensions>, nbOfPoints> *points;

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<> dis;
};

#endif	/* _NDIMENSIONAL_H */
