#include"nodo.hpp"

nodo::nodo(nodo* nodopadre, nodo* nodofinal,int x,int y, float costo){
    NodoPadre = nodopadre;
    NodoFinal = nodofinal;
    i=x;
    j=y;
    costeG = costo;
    if (NodoFinal != nullptr){
        costeTotal = costeG + Calcularcosto();
    }
}

float nodo::Calcularcosto(){
 return (i - NodoFinal->i)*(i - NodoFinal->i) + (j - NodoFinal->j)*(j - NodoFinal->j);
}



nodo nodo::igualar(nodo Nodo,nodo Nodo1){
    Nodo1=Nodo;
    return Nodo1;
}

nodo nodo::getnodopadre(){
    return *NodoPadre;
}




