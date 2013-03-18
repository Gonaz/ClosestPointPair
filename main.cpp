// Copyright (c) 2010-2012, Jonas Vanthornhout
// All rights reserved.
 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
 
// 1. Redistributions of source code must retain the above copyright notice, this
// list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
// ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include <iostream>
#include <chrono>

#include "Point.cpp"
#include "NDimensional.cpp"

template <typename T, size_t dimension>
void print(std::pair<Point<T, dimension>, Point<T, dimension> > closestPointPair){
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

template<typename T, size_t dimensions, size_t nbOfPoints>
void go(){
    NDimensional<T, dimensions, nbOfPoints> d;
    std::pair<Point<T, dimensions>, Point<T, dimensions> > closestPointPair;

    auto t1 = std::chrono::high_resolution_clock::now();
    closestPointPair = d.sweep();
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << "Plane sweep" << std::endl;
    print(closestPointPair);
    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " milliseconds\n";
}

int main() {
    go<double, 2, 10000000>();
}
