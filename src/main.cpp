#include <iostream>
#include "../include/map.hpp"
#include "../include/busqueda.hpp"
#include<ctime>

using namespace std;

int main()
{
    unsigned t0,t1;
    int x=0,y=0;
    busqueda bus;
    cout << "coordenada x del final:";
    cin >> x;
    cout << "coordenada y del final:";
    cin >> y;
    t0=clock();
    bus.encontrarCamino(x,y);
    t1=clock();
    bus.write(cout);
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    cout << "Execution Time: " << time << endl;
    cout << "Coste Total del camino:" << bus.retornar_coste() << endl;
    cout << "Numero de nodos generados:" << bus.retornar_listaAbierta().size() << endl;
    cout << "Numero de nodos explorados:" << bus.retornar_listaCerrada().size() << endl;
    cout << "Numero de nodos:" << bus.retornar_camino().size() << endl;
    return 0;
}
