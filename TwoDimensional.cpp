#include "TwoDimensional.h"
#include <iostream>

TwoDimensional::TwoDimensional(unsigned long *sizes, size_t nbOfPoints):NDimensional(sizes, 2, nbOfPoints){}

void TwoDimensional::printPlane(){
	std::cout << "2D Print plane" << std::endl;
}

void TwoDimensional::drawPoints(Point *points, double r, double g, double b){
	std::cout << "2D Draw points" << std::endl;
}
