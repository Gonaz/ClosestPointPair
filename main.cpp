#include <iostream>
#include <exception>
#include <chrono>

#include "Point.cpp"
#include "NDimensional.cpp"

size_t getDimension(){
    std::cout << "Dimension: ";

    size_t dimension;
    std::cin >> dimension;

    return dimension;
}

size_t getNumberOfPoints(){
    std::cout << "Number of points: ";

    size_t nbOfPoints;
    std::cin >> nbOfPoints;

    return nbOfPoints;
}

template <size_t dimension>
void print(std::pair<Point<dimension>, Point<dimension> > closestPointPair){
    printf("Point 1: (");
    for(size_t i=0; i<dimension; ++i){
        printf("%lf,", closestPointPair.first.getCoordinate(i));
    }
    printf(")\n");

    printf("Point 2: (");
    for(size_t i=0; i<dimension; ++i){
        printf("%lf, ", closestPointPair.second.getCoordinate(i));
    }
    printf(")\n");
    
    printf("Distance: %lf\n", closestPointPair.first.calculateDistanceTo(closestPointPair.second));
}

template<size_t dimensions>
void go(){
    unsigned long *sizes;
    size_t nbOfPoints = 0;

    sizes = new unsigned long[dimensions];
    nbOfPoints = getNumberOfPoints();

    NDimensional<dimensions> d(nbOfPoints);
    std::pair<Point<dimensions>, Point<dimensions> > closestPointPair;

    auto t1 = std::chrono::high_resolution_clock::now();
    closestPointPair = d.sweep();
    auto t2 = std::chrono::high_resolution_clock::now();
    printf("\nPlane Sweep\n");
    print(closestPointPair);
    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " milliseconds\n";

    delete[] sizes;
}

int main() {
    go<2>();
    return 0;
}
