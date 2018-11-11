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

using namespace std;

class map{
private:
    int M_, N_;
     std::vector <std::pair<int, int> > obstacles;
public:
    map(){}
    map(int m, int n);
    ~map();
    int get_pos(pair<int, int> pos_xy);
    void handmade_obst();
    //void random_obst();
    void pos_N(int n);
    void pos_M(int m);
    int get_N();
    int get_M();
    vector<pair<int,int> > get_obstacles();
};

#endif // MAP_HPP
