#ifndef BUSQUEDA_HPP
#define BUSQUEDA_HPP
#include"nodo.hpp"
#include"car.hpp"
#include"map.hpp"

using namespace std;


class busqueda{
    private:
        int costoIrDerecho;
        float costeT;
        int N,M;
        vector<nodo> listaAbierta;
        vector<nodo> listaCerrada;
        vector<pair<int,int> > obstaculos;
        vector<pair<int,int> > camino;
        map mapa;

    public:
        busqueda();
        void encontrarCamino(int x,int y);
        ostream& write(ostream& os);
        void encontrarNodosAdyacentes(nodo nodoActual, nodo nodoFinal);
        bool esIgual(nodo,nodo);
        bool estaCerrada(nodo A);
        bool estaAbierta(pair<int,int> A);
        nodo estaCerrada(pair<int,int> A);
        vector<nodo> retornar_listaAbierta(){ return listaAbierta;}
        float retornar_coste(){return costeT;}
    private:


};

#endif // BUSQUEDA_HPP
