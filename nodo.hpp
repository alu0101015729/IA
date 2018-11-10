#ifndef NODO_HPP
#define NODO_HPP
#include<math.h>
#include<iostream>

class nodo{
private:
    nodo* NodoPadre;
    nodo* NodoFinal;
    float costeG;
public:
    int i;
    int j;
    nodo(){}
    nodo(nodo* nodopadre, nodo* nodofinal,int x,int y, float costo);
    float Calcularcosto();
    bool esIgual(nodo Nodo);
    nodo getnodopadre();
    nodo igualar(nodo Nodo,nodo Nodo1);

    float costeTotal;
};

/*bool operator==(nodo A,nodo B){
    return A==B;
}*/












#endif // NODO_HPP
