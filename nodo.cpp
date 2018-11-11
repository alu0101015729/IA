#include"nodo.hpp"

nodo::nodo(int padrex,int padrey, nodo* nodofinal,int x,int y, float costo){
    pair<int,int> fle=make_pair(padrex,padrey);
    NodoPadre=fle;
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

pair<int,int> nodo::getnodopadre(){
    return NodoPadre;
}






