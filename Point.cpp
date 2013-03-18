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

#include "Point.h"
#include <cmath>

template <typename T, size_t dimensions>
void Point<T, dimensions>::setCoordinates(std::array<T, dimensions> &coordinates){
    //TODO: zou dit niet opgelost kunnen worden met move semantics (niet kritisch)
    for(size_t i=0; i<dimensions; ++i){
        this->coordinates[i] = coordinates[i];
    }
}

template <typename T, size_t dimensions>
T Point<T, dimensions>::calculateDistanceTo(const Point &p) const{
    return std::sqrt(calculateSquareDistanceTo(p));
}

template <typename T, size_t dimensions>
T Point<T, dimensions>::calculateSquareDistanceTo(const Point &p) const{
    std::array<T, dimensions> diff;

    for(size_t i=0; i<dimensions; ++i){
        diff[i] = coordinates[i]-p.coordinates[i];
    }

    T sum = 0.0;
    for(size_t i=0; i<dimensions; ++i){
        sum += (diff[i]*diff[i]);
    }

    return sum;
}
