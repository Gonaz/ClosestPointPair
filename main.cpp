#include <cstdlib>
#include <iostream>
#include <exception>
#include <cstdio>
#include <chrono>

#include "TwoDimensional.h"
#include "ThreeDimensional.h"
#include "NDimensional.h"

size_t getDimension(){
    std::cout << "Dimension: ";

    size_t dimension;
    std::cin >> dimension;

    return dimension;
}

void getInput(unsigned long *sizes, size_t dimension, size_t &nbOfPoints){
    for(size_t i=0; i<dimension; ++i){
        std::cout << "Maximum size for dimension " << (i+1) << ": ";
        std::cin >> sizes[i]; //result = scanf("%d", &sizes[i]);
    }

    std::cout << "Number of points: ";
    std::cin >> nbOfPoints;
}

void print(std::pair<Point, Point> closestPointPair){
    printf("Point 1: (");
    for(size_t i=0; i<closestPointPair.first.dimension; ++i){
        printf("%lf,", closestPointPair.first.getCoordinate(i));
    }
    printf(")\n");

    printf("Point 2: (");
    for(size_t i=0; i<closestPointPair.second.dimension; ++i){
        printf("%lf, ", closestPointPair.second.getCoordinate(i));
    }
    printf(")\n");
    
    printf("Distance: %lf\n", closestPointPair.first.calculateDistanceTo(closestPointPair.second));
}

void go(size_t dimension){
    unsigned long *sizes;
    size_t nbOfPoints = 0;

    sizes = new unsigned long[dimension];

    getInput(sizes, dimension, nbOfPoints);

    NDimensional d(dimension, nbOfPoints);
    std::pair<Point, Point> closestPointPair;

    auto t1 = std::chrono::high_resolution_clock::now();
    closestPointPair = d.sweep();
    auto t2 = std::chrono::high_resolution_clock::now();
    printf("\nPlane Sweep\n");
    print(closestPointPair);
    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " milliseconds\n";

    delete[] sizes;
}

int main() {
    go(2);
    return (EXIT_SUCCESS);
}
