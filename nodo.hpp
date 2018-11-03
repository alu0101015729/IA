#ifndef NODO_HPP
#define NODO_HPP
#include<math.h>
#include<iostream>

class nodo{
private:
    nodo* NodoPadre;
    nodo* NodoFinal;
    int i;
    int j;

    float costeG;
public:
    nodo(nodo* nodopadre, nodo* nodofinal,int x,int y, float costo);
    float Calcularcosto();
    bool esIgual(nodo Nodo);

    float costeTotal;

};











#endif // NODO_HPP
