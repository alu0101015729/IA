#include"busqueda.hpp"

busqueda::busqueda(){
    costoIrDerecho = 1;
    cout << "tamaño filas:";
    cin >> M;
    cout << "tamaño columnas:";
    cin >> N;
    map mapa(M,N);
    mapa.handmade_obst();
}



void busqueda::encontrarCamino(int x,int y){
    pair<int,int> posTileInicial;
    posTileInicial.first=0;
    posTileInicial.second=0;
    pair<int,int> posTileFinal;
    posTileFinal.first=x;
    posTileFinal.second=y;

    nodo nodoFinal(nullptr, nullptr, posTileFinal.first,posTileFinal.second, 0);
    nodo nodoInicial(nullptr, &nodoFinal, posTileInicial.first,posTileInicial.second, 0);

    // se adiciona el nodo inicial
    listaAbierta.push_back(nodoInicial);
    nodo nodoActual = nodoInicial;
    float coste=999999;
    while(!esIgual(nodoActual,nodoFinal)){
        listaCerrada.push_back(nodoActual);
        encontrarNodosAdyacentes(nodoActual,nodoFinal);
        for(vector<nodo>::iterator it1 = listaAbierta.begin();it1 != listaAbierta.end();it1++){
             if(esIgual(*it1,nodoActual)){
                listaAbierta.erase(it1);
                }
             else{
                it1->Calcularcosto();
                if(it1->costeTotal< coste){
                    coste=nodoActual.costeTotal;
                    nodoActual=*it1;
                }
            }
        }
    }
    while(esIgual(nodoActual,nodoInicial)==false){
        unsigned int i=0;
        nodo var=nodoActual.getnodopadre();
        camino[i].first=var.i;
        camino[i].second=var.j;
        nodoActual=var;

    }
}

ostream& busqueda::write(ostream& os){
    vector<pair<int,int> > map=mapa.get_obstacles();
    vector<pair<int,int> >::iterator it;
    bool imprime;
    int k=0;
    for(int i=0;i<=mapa.get_N();i++){
        for(int j=0;j<=mapa.get_M();j++){
            imprime=false;
            for(it=map.begin();it!=map.end();it++){
                if((it[k].first==i)&&(it[k].second==j)){
                    os << "X ";
                    imprime=true;
                }
                k++;
            }
            k=0;
            for(it=camino.begin();it!=camino.end();it++){
                if((it[k].first==i)&&(it[k].second==j)){
                    os << "S ";
                    imprime=true;
                }
            }
            if(imprime==false){
                os << "0 ";
            }
        }
        os << endl;
    }
    return os;
}


void busqueda::encontrarNodosAdyacentes(nodo nodoActual, nodo nodoFinal){

bool Izquierda = true;
bool Derecha = true;
bool Abajo = true;
bool Arriba = true;

//Izquierda
if(nodoActual.i > 0){
    for(vector<pair<int,int> >::iterator it1= obstaculos.begin();it1!=obstaculos.end();it1++){
        pair<int,int> it=*it1;
        if((it.first==nodoActual.i-1)&&(it.second==nodoActual.j)){
            Izquierda=false;
        }
    }
}
else{
    Izquierda=false;
    }
if(Izquierda==true){
         nodo var(&nodoActual,&nodoFinal,nodoActual.i-1,nodoActual.j,nodoActual.costeTotal);
         listaAbierta.push_back(var);
    }


//Derecha
if(nodoActual.i < mapa.get_M()){
    vector<pair<int,int> >::iterator it1= mapa.get_obstacles().begin() ;
    while(it1!=mapa.get_obstacles().end() ){
        pair<int,int> it=*it1;
        if((it.first==nodoActual.i+1)&&(it.second==nodoActual.j)){
            Derecha=false;
        }
        it1++;
    }
}
else{
    Derecha=false;
}
if(Derecha==true){
    nodo var(&nodoActual,&nodoFinal,nodoActual.i+1,nodoActual.j,nodoActual.costeTotal);
    listaAbierta.push_back(var);
    }
//Arriba
if(nodoActual.j > 0){
    vector<pair<int,int> >::iterator it1= mapa.get_obstacles().begin() ;
    while(it1!=mapa.get_obstacles().end() ){
        pair<int,int> it=*it1;
        if((it.second==nodoActual.j-1)&&(it.first==nodoActual.i)){
            Arriba=false;
        }
        it1++;
    }
}
else{
    Arriba=false;
}
if(Arriba==true){
    nodo var(&nodoActual,&nodoFinal,nodoActual.i,nodoActual.j-1,nodoActual.costeTotal);
    listaAbierta.push_back(var);
}
// Abajo
if(nodoActual.j < mapa.get_N()){
    vector<pair<int,int> >::iterator it1= mapa.get_obstacles().begin() ;
    while(it1!=mapa.get_obstacles().end() ){
        pair<int,int> it=*it1;
        if((it.second==nodoActual.j+1)&&(it.first==nodoActual.i)){
            Abajo=false;
        }
        it1++;
    }
}
else{
    Abajo=false;
}
if(Abajo==true){
    nodo var(&nodoActual,&nodoFinal,nodoActual.i,nodoActual.j+1,nodoActual.costeTotal);
    listaAbierta.push_back(var);
    }
}

bool busqueda::esIgual(nodo A,nodo B){
    if((A.i==B.i)&&(A.j==B.j)){
        return true;
    }
    else{
        return false;
    }
}

