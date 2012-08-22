TEMPLATE = app
CONFIG += console
CONFIG -= qt

HEADERS += NDimensional.h \
		TwoDimensional.h \
		ThreeDimensional.h \
		Point.h

SOURCES += main.cpp \
		NDimensional.cpp \
		TwoDimensional.cpp \
		ThreeDimensional.cpp \
		Point.cpp

QMAKE_CXXFLAGS += -O3 -std=c++11 -Wall -Wextra -m64
