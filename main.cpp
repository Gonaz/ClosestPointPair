#include <cstdlib>
#include <iostream>
#include <exception>
#include <cstdio>
#include <chrono>

#include "TwoDimensional.h"
#include "ThreeDimensional.h"
#include "NDimensional.h"

void getDimension(size_t *dimension){
    std::cout << "Dimension: ";
    std::cin >> *(dimension);
}

void getInput(unsigned long *sizes, size_t dimension, size_t *nbOfPoints){
    for(size_t i=0; i<dimension; ++i){
        std::cout << "Maximum size for dimension " << (i+1) << ": ";
        std::cin >> sizes[i]; //result = scanf("%d", &sizes[i]);
    }

    std::cout << "Number of points: ";
    std::cin >> *(nbOfPoints);
}

void print(Point *closestPointPair){
    printf("Point 1: (");
    for(size_t i=0; i<closestPointPair[0].dimension; ++i){
        printf("%lf,", closestPointPair[0].getCoordinate(i));
    }
    printf(")\n");

    printf("Point 2: (");
    for(size_t i=0; i<closestPointPair[1].dimension; ++i){
        printf("%lf, ", closestPointPair[1].getCoordinate(i));
    }
    printf(")\n");
    
    printf("Distance: %lf\n", closestPointPair[0].calculateDistanceTo(closestPointPair[1]));
}

void go(size_t dimension){
    unsigned long *sizes;
    size_t nbOfPoints = 0;

    sizes = new unsigned long[dimension];

    getInput(sizes, dimension, &nbOfPoints);

    NDimensional d(sizes, dimension, nbOfPoints);
    Point *closestPointPair;

    auto t1 = std::chrono::high_resolution_clock::now();
    closestPointPair = d.sweep();
    auto t2 = std::chrono::high_resolution_clock::now();
    printf("\nPlane Sweep\n");
    print(closestPointPair);
    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " milliseconds\n";

    delete[] closestPointPair;
    delete[] sizes;
}

int main() {
    go(2);
    return (EXIT_SUCCESS);
}
