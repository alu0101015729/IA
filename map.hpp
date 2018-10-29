#ifndef MAP_HPP
#define MAP_HPP

#include "car.hpp"
#include <vector>
#include <iterator>
#include<fstream>
#include<iostream>
#include <cstdio>
#include <random>
#include <ostream>
#include<utility>



#endif // MAP_HPP


class map {

private:

    // Vector que simula matriz.
    std::vector <std::pair<int, int>> map_;
    int N_, M_;
    std::vector <std::pair<int, int>> obstacles;

public:

    map(int m, int n);
    ~map();

    // Devuelve posicion real. i*M+j = posicion en el vector del par 'i,j' de la matriz)
    int get_pos(std::pair<int, int> pos_xy);
    void handmade_obst();
    void random_obst();

    void write(std::ostream& os) const;


};
