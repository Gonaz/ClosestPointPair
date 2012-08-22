#ifndef _NDIMENSIONAL_H
#define	_NDIMENSIONAL_H

#include "Point.h"
#include <algorithm>

struct NDimensional {
    NDimensional(size_t dimension, size_t nbOfPoints);
    std::pair<Point, Point> sweep();
    Point* bruteForce();
    size_t getNbOfPoints(){return nbOfPoints;}
    void fillPlane();
    void fillPlaneWorstCase();

    std::vector<Point> points;
    size_t nbOfPoints;
    size_t dimension;

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<> dis;

    bool static cmp(Point p1, Point p2){return p1.getCoordinate(0) < p2.getCoordinate(0);}
    void static sortPoints(Point *p, size_t nbOfPoints){std::sort(p, p+nbOfPoints, cmp);}
};

#endif	/* _NDIMENSIONAL_H */

