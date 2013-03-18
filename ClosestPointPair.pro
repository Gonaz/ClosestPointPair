TEMPLATE = app
CONFIG += console
CONFIG -= qt

HEADERS += NDimensional.h \
		Point.h

SOURCES += main.cpp \
		NDimensional.cpp \
		Point.cpp

QMAKE_CXX = g++-4.7

#QMAKE_LFLAGS += -O3 -std=c++11 -Wall -Wextra -m64 -fprofile-generate
#QMAKE_CXXFLAGS += -O3 -std=c++11 -Wall -Wextra -m64 -fprofile-generate

#QMAKE_LFLAGS += -O3 -std=c++11 -Wall -Wextra -m64 -fprofile-use
#QMAKE_CXXFLAGS += -O3 -std=c++11 -Wall -Wextra -m64 -fprofile-use

QMAKE_CXXFLAGS += -O3 -m64 -std=c++11 -Wall -Wextra -Wconversion -Wdouble-promotion -Wfloat-equal
