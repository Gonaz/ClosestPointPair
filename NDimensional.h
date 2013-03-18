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

#ifndef _NDIMENSIONAL_H
#define	_NDIMENSIONAL_H

#include "Point.h"
#include <random>

template <typename T, size_t dimensions, size_t nbOfPoints>
struct NDimensional {
    NDimensional();
    ~NDimensional(){delete points;}

    std::pair<Point<T, dimensions>, Point<T, dimensions> > sweep();
    std::pair<Point<T, dimensions>, Point<T, dimensions> > bruteForce();

    void fillPlane();
    void fillPlaneWorstCase();

    std::array<Point<T, dimensions>, nbOfPoints> *points;

    std::random_device rd;
    std::mt19937 gen;
    std::uniform_real_distribution<> dis;
};

#endif	/* _NDIMENSIONAL_H */
