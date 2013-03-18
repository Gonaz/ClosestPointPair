ClosestPointPair
===========================
Find the two points that are closest to each other in a pointcloud.


Compiling
--------------------------
Execute the following commands

    mkdir build
    cd build
    qmake ../ClosestPointPair.pro
	make

Settings
---------------------------
The number of points, the amount of dimensions and the type of the points can be set in main.cpp in the function main(). The first parameter is the type of the points (double means that each coordinate has type double), the second parameter is the dimension of the points (2 means we are working in a plane) and the third parameter is the number of points that are in the pointcloud.

In the file NDimensional.cpp there is also macro defined, when the value is not 0 then some statistics are calculated.

Running
--------------------------
Execute the following command in the build directory.

    ./ClosestPointPair
