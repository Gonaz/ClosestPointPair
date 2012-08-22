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
    for(size_t i=0; i<closestPointPair[0].getDimension(); ++i){
        printf("%lf,", closestPointPair[0].getCoordinate(i));
    }
    printf(")\n");

    printf("Point 2: (");
    for(size_t i=0; i<closestPointPair[1].getDimension(); ++i){
        printf("%lf, ", closestPointPair[1].getCoordinate(i));
    }
    printf(")\n");
    
    printf("Distance: %lf\n", closestPointPair[0].calculateDistanceTo(closestPointPair[1]));
}

void twoDimensional(){
    unsigned long *sizes;
    size_t nbOfPoints = 0;
    size_t dimension = 2;

    sizes = new unsigned long[dimension];

    getInput(sizes, dimension, &nbOfPoints);

    TwoDimensional d(sizes, nbOfPoints);
    Point *closestPointPair;
    d.printPlane();

//    startTimer();
//    closestPointPair = d.bruteForce();
//    stopTimer();
//    printf("\nBrute Force\n");
//    print(closestPointPair);
//    d.drawPoints(closestPointPair, 0.0, 1.0, 0.0);

    auto t1 = std::chrono::high_resolution_clock::now();
    closestPointPair = d.sweep();
    auto t2 = std::chrono::high_resolution_clock::now();
    printf("\nPlane Sweep\n");
    print(closestPointPair);
    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " milliseconds\n";
    d.drawPoints(closestPointPair, 0.0, 0.0, 1.0);

    delete[] closestPointPair;
    delete[] sizes;
}

void threeDimensional(){
    unsigned long *sizes;
    size_t nbOfPoints = 0;
    size_t dimension = 3;

    sizes = new unsigned long[dimension];

    getInput(sizes, dimension, &nbOfPoints);

    ThreeDimensional d(sizes, nbOfPoints);
    Point *closestPointPair;
    d.printPlane();

//    startTimer();
//    closestPointPair = d.bruteForce();
//    stopTimer();
//    printf("\nBrute Force\n");
//    print(closestPointPair);
//    d.drawPoints(closestPointPair, 0.0, 1.0, 0.0);

    auto t1 = std::chrono::high_resolution_clock::now();
    closestPointPair = d.sweep();
    auto t2 = std::chrono::high_resolution_clock::now();
    printf("\nPlane Sweep\n");
    print(closestPointPair);
    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " milliseconds\n";
    d.drawPoints(closestPointPair, 0.0, 0.0, 1.0);

    d.printPlane(0.025);

    delete[] closestPointPair;
    delete sizes;
}

void nDimensional(){
    unsigned long *sizes;
    size_t nbOfPoints = 0;
    size_t dimension = 0;

    getDimension(&dimension);

//    printf("Number of points: ", nbOfPoints);
//    result = scanf("%d", &nbOfPoints);
//    if(result == 0){
//        fprintf(stderr, "Bad input");
//    }

    for(; dimension<=3; ++dimension){
        std::cout << "Dimension: " << dimension << std::endl;
        sizes = new unsigned long[dimension];
        for(size_t i=0; i<dimension; ++i){
            sizes[i] = 1;
        }

        for(int it=0; it<=0; ++it){
            if(it == 0){
                nbOfPoints = 1000;
            } else if(it == 1){
                nbOfPoints = 3000000;
            } else if(it == 2){
                nbOfPoints = 4000000;
            } else if(it == 3){
                nbOfPoints = 5000000;
            } else if(it == 4){
                nbOfPoints = 100000;
            } else if(it == 5){
                nbOfPoints = 500000;
            } else if(it == 6){
                nbOfPoints = 1000000;
            }

            for(int i=0; i<10; ++i){
                std::cout << nbOfPoints << "\t";
                NDimensional *d = new NDimensional(sizes, dimension, nbOfPoints);
                Point *closestPointPair;

    //                startTimer();
    //                closestPointPair = d->bruteForce();
    //                stopTimer();
    //                printf("%d,%d\t", sec, uSec);

                auto t1 = std::chrono::high_resolution_clock::now();
                closestPointPair = d->sweep();
                auto t2 = std::chrono::high_resolution_clock::now();
                std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " milliseconds\n";

                delete[] closestPointPair;
                delete d;
                system("sleep 1");
            }
            printf("\n");

        }
        
        printf("\n");
        delete[] sizes;
    }
}

void nDimensional2(){
    unsigned long *sizes;
    size_t nbOfPoints = 0;
    size_t dimension = 0;

    getDimension(&dimension);
    sizes = new unsigned long[dimension];

    getInput(sizes, dimension, &nbOfPoints);
    NDimensional *d = new NDimensional(sizes, dimension, nbOfPoints);
    Point *closestPointPair;

    auto t1 = std::chrono::high_resolution_clock::now();
    closestPointPair = d->bruteForce();
    auto t2 = std::chrono::high_resolution_clock::now();
    printf("\nBrute Force\n");
    print(closestPointPair);
    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " milliseconds\n";

    t1 = std::chrono::high_resolution_clock::now();
    closestPointPair = d->sweep();
    t2 = std::chrono::high_resolution_clock::now();
    printf("\nPlane Sweep\n");
    print(closestPointPair);
    std::cout << "Duration: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count() << " milliseconds\n";

    delete[] closestPointPair;
    delete d;
    delete[] sizes;
}

int main() {
    twoDimensional();
    //threeDimensional();
    //nDimensional();
    return (EXIT_SUCCESS);
}
