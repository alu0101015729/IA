#ifndef BUSQUEDA_HPP
#define BUSQUEDA_HPP
#include"nodo.hpp"
#include"car.hpp"
#include"map.hpp"

using namespace std;


class busqueda{
    private:
        int costoIrDerecho;
        int N,M;
        vector<nodo> listaAbierta;
        vector<nodo> listaCerrada;
        vector<pair<int,int> > obstaculos;
        map mapa;

    public:
        busqueda();
        void encontrarCamino(int x,int y);
        ostream& write(ostream& os);
        void encontrarNodosAdyacentes(nodo nodoActual, nodo nodoFinal);
        vector<pair<int,int> > camino;
        bool esIgual(nodo,nodo);
    private:


};

#endif // BUSQUEDA_HPP
