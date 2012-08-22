TEMPLATE = app
CONFIG += console
CONFIG -= qt

HEADERS += NDimensional.h \
		Point.h

SOURCES += main.cpp \
		NDimensional.cpp \
		Point.cpp

QMAKE_CXXFLAGS += -O3 -std=c++11 -Wall -Wextra -m64
