#include <iostream>
#include "car.hpp"
//#include "map.hpp"
#include "busqueda.hpp"

using namespace std;

int main()
{
  busqueda bus;
  bus.encontrarCamino(10,15);
  bus.write(cout);


}
