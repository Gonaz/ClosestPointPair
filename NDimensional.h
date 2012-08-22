#ifndef _NDIMENSIONAL_H
#define	_NDIMENSIONAL_H

#include "Point.h"
#include <algorithm>

template <size_t dimensions>
struct NDimensional {
    NDimensional(size_t nbOfPoints);
    std::pair<Point<dimensions>, Point<dimensions> > sweep();
    std::pair<Point<dimensions>, Point<dimensions> > bruteForce();
    size_t getNbOfPoints(){return nbOfPoints;}
    void fillPlane();
    void fillPlaneWorstCase();

    std::vector<Point<dimensions> > points;
    size_t nbOfPoints;

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<> dis;
};

#endif	/* _NDIMENSIONAL_H */

