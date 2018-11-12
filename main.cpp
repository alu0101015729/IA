#include <iostream>
#include "car.hpp"
#include "map.hpp"
#include "busqueda.hpp"

using namespace std;

int main()
{
  int x=0,y=0;
  busqueda bus;
  cout << "coordenada x del final:";
  cin >> x;
  cout << "coordenada y del final:";
  cin >> y;
  bus.encontrarCamino(x,y);
  bus.write(cout);
  return 0;
}
