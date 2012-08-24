#include <iostream>
#include <chrono>

#include "Point.cpp"
#include "NDimensional.cpp"

template <size_t dimension>
void print(std::pair<Point<dimension>, Point<dimension> > closestPointPair){
    std::cout << "Point 1: (" << std::fixed;
    for(size_t i=0; i<(dimension-1); ++i){
        std::cout << closestPointPair.first.coordinates[i] << ", ";
    }
    std::cout << closestPointPair.first.coordinates[dimension-1];

    std::cout << ")" << std::endl;

    std::cout << "Point 2: (";
    for(size_t i=0; i<dimension-1; ++i){
       std::cout << closestPointPair.second.coordinates[i] << ", ";
    }
    std::cout << closestPointPair.second.coordinates[dimension-1];
    std::cout << ")" << std::endl;
    
    std::cout << "Distance: " << closestPointPair.first.calculateDistanceTo(closestPointPair.second) << std::endl;
}

template<size_t dimensions, size_t nbOfPoints>
void go(){
    NDimensional<dimensions, nbOfPoints> d;
    std::pair<Point<dimensions>, Point<dimensions> > closestPointPair;

    auto t1 = std::chrono::high_resolution_clock::now();
    closestPointPair = d.sweep();
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Plane sweep" << std::endl;
    print(closestPointPair);
    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " milliseconds\n";
}

int main() {
    go<2, 10000000>();
    return 0;
}
