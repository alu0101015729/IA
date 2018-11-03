#include <iostream>
#include "car.hpp"
#include "map.hpp"
#include "busqueda.hpp"

using namespace std;

int main()
{
  car coche_;
  map mapa(20,20);
  mapa.handmade_obst();
  mapa.write(cout);


}
