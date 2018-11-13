TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    src/busqueda.cpp \
    src/car.cpp \
    src/main.cpp \
    src/map.cpp \
    src/nodo.cpp

HEADERS += \
    include/busqueda.hpp \
    include/car.hpp \
    include/map.hpp \
    include/nodo.hpp

DISTFILES += \
    build/Makefile
