#ifndef NODO_HPP
#define NODO_HPP
#include<math.h>
#include<iostream>

using namespace std;

class nodo{
private:
    pair<int,int> NodoPadre;
    nodo* NodoFinal;
    float costeG;
public:
    int i;
    int j;
    nodo(){}
    nodo(int,int, nodo* nodofinal,int x,int y, float costo);
    float Calcularcosto();
    pair<int,int> getnodopadre();
    nodo igualar(nodo Nodo,nodo Nodo1);
    nodo* getnodofinal(){return NodoFinal;}

    float costeTotal;
};













#endif // NODO_HPP
