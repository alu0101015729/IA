#ifndef BUSQUEDA_HPP
#define BUSQUEDA_HPP
#include"nodo.hpp"
#include"car.hpp"
#include"map.hpp"


class busqueda{
    private:
        int costoIrDerecho = 1;
        std::vector<nodo> *listaAbierta = new std::vector<nodo>();
        std::vector<nodo> *listaCerrada = new std::vector<nodo>();
    public:
        busqueda();
        void adicionarNodoAListaAbierta(nodo nodo);
        std::vector<nodo> encontrarCamino(int x,int y);
    private:
        std::vector<nodo> encontrarNodosAdyacentes(nodo nodoActual, nodo nodoFinal);
};

#endif // BUSQUEDA_HPP
