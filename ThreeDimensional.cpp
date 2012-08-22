#include "ThreeDimensional.h"
#include <iostream>

ThreeDimensional::ThreeDimensional(unsigned long *sizes, size_t nbOfPoints):NDimensional(sizes, 3, nbOfPoints){}

void ThreeDimensional::printPlane(double angle){
	std::cout << "3D Print plane " << angle << std::endl;
}

void ThreeDimensional::printPlane(){
	std::cout << "3D Print plane" << std::endl;
}

void ThreeDimensional::drawPoints(Point *points, double r, double g, double b){
	std::cout << "3D Draw points" << std::endl;
}
