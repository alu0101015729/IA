#ifndef BUSQUEDA_HPP
#define BUSQUEDA_HPP
#include"nodo.hpp"
#include"car.hpp"
#include"map.hpp"


class busqueda{
    private:
        int costoIrDerecho = 1;
        int N,M;
        std::vector<nodo> *listaAbierta = new std::vector<nodo>();
        std::vector<nodo> *listaCerrada = new std::vector<nodo>();
        map mapa;

    public:
        busqueda();
        void adicionarNodoAListaAbierta(nodo nodo);
        std::vector<nodo> encontrarCamino(int x,int y);
        std::ostream write(std::ostream& os);
        std::vector<nodo> encontrarNodosAdyacentes(nodo nodoActual, nodo *nodoFinal);
        std::vector<std::pair<int,int>> camino;
    private:


};

#endif // BUSQUEDA_HPP
