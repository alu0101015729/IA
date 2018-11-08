#include"busqueda.hpp"

busqueda::busqueda(){
    std::cout << "tamaño filas:";
    std::cin >> M;
    std::cout << "tamaño columnas:";
    std::cin >> N;
    map mapa(M,N);
    mapa.random_obst();
}



std::vector<nodo> busqueda::encontrarCamino(int x,int y){
    std::pair<int,int> posTileInicial;
    posTileInicial.first=0;
    posTileInicial.second=0;
    std::pair<int,int> posTileFinal;
    posTileFinal.first=x;
    posTileFinal.second=y;

    listaAbierta->clear();
    listaCerrada->clear();

    nodo *nodoFinal = new nodo(NULL, NULL, posTileFinal.first,posTileFinal.second, 0);
    nodo *nodoInicial = new nodo(NULL, nodoFinal, posTileInicial.first,posTileInicial.second, 0);

    // se adiciona el nodo inicial
    listaAbierta->push_back(*nodoInicial);
    nodo nodoActual = listaAbierta->front();
    float coste=999999;
    nodo var;
    nodo var1;
    while(nodoFinal->esIgual(nodoActual)==false){
        std::cout << "hola\n";
        listaCerrada->push_back(nodoActual);
        for(std::vector<nodo>::iterator it1 = listaAbierta->begin();it1 != listaAbierta->end();it1++){
            var1=*it1;
            if(var1.esIgual(nodoActual)){
                listaAbierta->erase(it1);
                break;}
        }
        encontrarNodosAdyacentes(nodoActual,nodoFinal);
        for(std::vector<nodo>::iterator it = listaAbierta->begin() ; it != listaAbierta->end(); ++it){
            var=*it;
            var.Calcularcosto();
            if(var.costeTotal< coste){
                coste=nodoActual.costeTotal;
                nodoActual=var;
            }

        }

    }
    while(nodoInicial->esIgual(nodoActual)==false){
        int i=0;
        var=nodoActual.getnodopadre();
        camino[i].first=var.i;
        camino[i].second=var.j;
        nodoActual=var;

    }
}

std::ostream busqueda::write(std::ostream& os){
    std::vector<std::pair<int,int>> map=mapa.get_obstacles();
    std::vector<std::pair<int,int>>::iterator it;
    bool imprime;
    int k=0;
    for(int i=0;i<=mapa.get_M();i++){
        for(int j=0;j<=mapa.get_N();j++){
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
        os << std::endl;
    }
}


std::vector<nodo> busqueda::encontrarNodosAdyacentes(nodo nodoActual, nodo* nodoFinal){

bool Izquierda = true;
bool Derecha = true;
bool Abajo = true;
bool Arriba = true;

//Izquierda
if(nodoActual.i > 0){
    std::vector<std::pair<int,int>>::iterator it1= mapa.get_obstacles().begin() ;
    while(it1!=mapa.get_obstacles().end() ){
        std::pair<int,int> it=*it1;
        if((it.first==nodoActual.i-1)&&(it.second==nodoActual.j)){
            Izquierda=false;
        }
    }
}
else{
    Izquierda=false;
    }
if(Izquierda==true){
         nodo var(&nodoActual,nodoFinal,nodoActual.i-1,nodoActual.j,nodoActual.costeTotal);
         listaAbierta->push_back(var);
    }


//Derecha
if(nodoActual.i < mapa.get_M()){
    std::vector<std::pair<int,int>>::iterator it1= mapa.get_obstacles().begin() ;
    while(it1!=mapa.get_obstacles().end() ){
        std::pair<int,int> it=*it1;
        if((it.first==nodoActual.i+1)&&(it.second==nodoActual.j)){
            Derecha=false;
        }
    }
}
else{
    Derecha=false;
}
if(Derecha==true){
    nodo var(&nodoActual,nodoFinal,nodoActual.i+1,nodoActual.j,nodoActual.costeTotal);
    listaAbierta->push_back(var);
    }
//Arriba
if(nodoActual.j > 0){
    std::vector<std::pair<int,int>>::iterator it1= mapa.get_obstacles().begin() ;
    while(it1!=mapa.get_obstacles().end() ){
        std::pair<int,int> it=*it1;
        if((it.second==nodoActual.j-1)&&(it.first==nodoActual.i)){
            Arriba=false;
        }
    }
}
else{
    Arriba=false;
}
if(Arriba==true){
    nodo var(&nodoActual,nodoFinal,nodoActual.i,nodoActual.j-1,nodoActual.costeTotal);
    listaAbierta->push_back(var);
}
// Abajo
if(nodoActual.j > mapa.get_N()){
    std::vector<std::pair<int,int>>::iterator it1= mapa.get_obstacles().begin() ;
    while(it1!=mapa.get_obstacles().end() ){
        std::pair<int,int> it=*it1;
        if((it.second==nodoActual.j+1)&&(it.first==nodoActual.i)){
            Abajo=false;
        }
    }
}
else{
    Abajo=false;
}
if(Abajo==true){
    nodo var(&nodoActual,nodoFinal,nodoActual.i,nodoActual.j+1,nodoActual.costeTotal);
    listaAbierta->push_back(var);
    }
}

