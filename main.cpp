#include <cstdlib>
#include <iostream>
#include <sys/time.h>
#include <exception>
#include <cstdio>

#include "TwoDimensional.h"
#include "ThreeDimensional.h"
#include "NDimensional.h"

#define TRUE 1
#define FALSE 0

int sec;
int uSec;

void startTimer(){
    struct timeval tv;
    struct timezone tz;

    gettimeofday(&tv,&tz);

    sec = tv.tv_sec;
    uSec = tv.tv_usec;
}

void stopTimer(){
    struct timeval tv;
    struct timezone tz;

    gettimeofday(&tv,&tz);

    int beginSec = sec;
    int beginUSec = uSec;
    int endUSec;
    int endSec;
    endSec = tv.tv_sec;
    endUSec = tv.tv_usec;
    sec = endSec-beginSec;
    uSec = endUSec-beginUSec;

    if(uSec <= 0){
        --sec;
        uSec = 1000000+(endUSec-beginUSec);
    }
}

void getDimension(size_t *dimension){
    printf("Dimension: ");
    unsigned int result = scanf("%d", dimension);
    if(result == 0){
        fprintf(stderr, "Bad input");
    }
}

void getInput(unsigned long *sizes, size_t dimension, size_t *nbOfPoints){
    unsigned int result;

    for(size_t i=0; i<dimension; ++i){
        printf("Maximum size for dimension %d: ", i+1);
        result = scanf("%d", &sizes[i]);
        if(result == 0){
            fprintf(stderr, "Bad input");
        }
    }

    printf("Number of points: ", nbOfPoints);
    result = scanf("%d", nbOfPoints);
    if(result == 0){
        fprintf(stderr, "Bad input");
    }
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
    printf("Time calculation: %d s %.6d µs\n", sec, uSec);
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

    startTimer();
    closestPointPair = d.sweep();
    stopTimer();
    printf("\nPlane Sweep\n");
    print(closestPointPair);
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

    startTimer();
    closestPointPair = d.sweep();
    stopTimer();
    printf("\nPlane Sweep\n");
    print(closestPointPair);
    d.drawPoints(closestPointPair, 0.0, 0.0, 1.0);

    d.printPlane(0.025);

    delete[] closestPointPair;
    delete sizes;
}

void nDimensional(){
    unsigned long *sizes;
    size_t nbOfPoints = 0;
    size_t dimension = 0;
    unsigned int result = 0;

    getDimension(&dimension);

//    printf("Number of points: ", nbOfPoints);
//    result = scanf("%d", &nbOfPoints);
//    if(result == 0){
//        fprintf(stderr, "Bad input");
//    }

    for(; dimension<=3; ++dimension){
        printf("Dimension: %d \n", dimension);
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
                printf("%d\t", nbOfPoints);
                NDimensional *d = new NDimensional(sizes, dimension, nbOfPoints);
                Point *closestPointPair;

    //                startTimer();
    //                closestPointPair = d->bruteForce();
    //                stopTimer();
    //                printf("%d,%d\t", sec, uSec);

                startTimer();
                closestPointPair = d->sweep();
                stopTimer();
                printf("%d,%d\n", sec, uSec);

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

    startTimer();
    closestPointPair = d->bruteForce();
    stopTimer();
    printf("\nBrute Force\n");
    print(closestPointPair);

    startTimer();
    closestPointPair = d->sweep();
    stopTimer();
    printf("\nPlane Sweep\n");
    print(closestPointPair);
    printf("%d,%d\n", sec, uSec);

    delete[] closestPointPair;
    delete d;
    delete[] sizes;
}

int main(int argc, char** argv) {
    twoDimensional();
    //threeDimensional();
    //nDimensional();
    return (EXIT_SUCCESS);
}
