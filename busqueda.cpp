#include"busqueda.hpp"

busqueda::busqueda(){
    costoIrDerecho = 1;
    cout << "tamaño filas:";
    cin >> M;
    cout << "tamaño columnas:";
    cin >> N;
    map mapa(M,N);
    mapa.handmade_obst();
    obstaculos=mapa.get_obstacles();
}

bool busqueda::estaCerrada(nodo A){
    for(vector<nodo>::iterator it=listaCerrada.begin();it!=listaCerrada.end();it++){
        if(esIgual(*it,A)){
            return true;
        }
    }
    return false;
}
bool busqueda::estaAbierta(pair<int,int> A){
    for(vector<nodo>::iterator it=listaAbierta.begin();it!=listaAbierta.end();it++){
        if((A.first==it->i)&&(A.second==it->j)){
            return true;
        }
    }
    return false;
}

nodo busqueda::estaCerrada(pair<int,int> A){
    for(vector<nodo>::iterator it=listaCerrada.begin();it!=listaCerrada.end();it++){
        if((A.first==it->i)&&(A.second==it->j)){
            return *it;
        }
    }
}

void busqueda::encontrarCamino(int x,int y){
    pair<int,int> posTileInicial;
    posTileInicial.first=0;
    posTileInicial.second=0;
    pair<int,int> posTileFinal;
    posTileFinal.first=x;
    posTileFinal.second=y;
    nodo nodoFinal(NULL,NULL,nullptr, posTileFinal.first,posTileFinal.second, 0);
    nodo nodoInicial(NULL,NULL,&nodoFinal, posTileInicial.first,posTileInicial.second, 0);
    // se adiciona el nodo inicial
    listaAbierta.push_back(nodoInicial);
    nodo nodoActual = nodoInicial;
    while(!esIgual(nodoActual,nodoFinal)){
        float coste=999999;
        listaCerrada.push_back(nodoActual);
        encontrarNodosAdyacentes(nodoActual,nodoFinal);
        for(vector<pair<int,int>>::iterator it=obstaculos.begin();it!=obstaculos.end();it++){
            for(vector<nodo>::iterator it1=listaAbierta.begin();it1!=listaAbierta.end();it1++){
                if(it->first == it1->i){
                        if(it->second == it1->j){
                            listaAbierta.erase(it1);
                            it1=listaAbierta.begin();
                        }
                }
            }
        }
        for(vector<nodo>::iterator it2 = listaAbierta.begin();it2 != listaAbierta.end();it2++){
                it2->Calcularcosto();
                if((it2->costeTotal< coste)&&(estaCerrada(*it2)==false)&&(esIgual(*it2,nodoActual)==false)){
                    coste=nodoActual.costeTotal;
                    nodoActual=*it2;
                }
            }
        }
    listaCerrada.push_back(nodoActual);
    pair<int,int> foo1 = make_pair(nodoActual.i,nodoActual.j);
    camino.push_back(foo1);
    while(esIgual(nodoActual,nodoInicial)==false){
        pair<int,int> foo = make_pair(nodoActual.getnodopadre().first,nodoActual.getnodopadre().second);
        camino.push_back(foo);
        nodo var=estaCerrada(foo);
        nodoActual=var;
    }

}

ostream& busqueda::write(ostream& os){

        vector<pair<int,int> >::iterator it;
        bool imprime;
        int k=0;
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                imprime=false;
                for(it=obstaculos.begin();it!=obstaculos.end();it++){
                    if((it[k].first==i)&&(it[k].second==j)){
                        os << "X ";
                        imprime=true;
                    }
                    k++;
                }
                k=0;
                if(imprime != true){
                    for(it=camino.begin();it!=camino.end();it++){
                        if((it[k].first==i)&&(it[k].second==j)){
                            os << "S ";
                            imprime=true;
                        }
                    }
                }
                if(imprime!=true){
                    os << "0 ";
                }
            }
            os << endl;
        }
    return os;
}


void busqueda::encontrarNodosAdyacentes(nodo nodoActual, nodo nodoFinal){

    //Izquierda
    if(nodoActual.i > 0){
        pair<int,int> foo=make_pair(nodoActual.i-1,nodoActual.j);
        if(estaAbierta(foo)==false){
             nodo var(nodoActual.i,nodoActual.j,&nodoFinal,nodoActual.i-1,nodoActual.j,nodoActual.costeTotal);
             listaAbierta.push_back(var);
        }
    }
    //Derecha
    if(nodoActual.i < M){
        pair<int,int> foo=make_pair(nodoActual.i+1,nodoActual.j);
        if(estaAbierta(foo)==false){
            nodo var(nodoActual.i,nodoActual.j,&nodoFinal,nodoActual.i+1,nodoActual.j,nodoActual.costeTotal);
            listaAbierta.push_back(var);
        }
    }
    //Arriba
    if(nodoActual.j > 0){
        pair<int,int> foo=make_pair(nodoActual.i,nodoActual.j-1);
        if(estaAbierta(foo)==false){
            nodo var(nodoActual.i,nodoActual.j,&nodoFinal,nodoActual.i,nodoActual.j-1,nodoActual.costeTotal);
            listaAbierta.push_back(var);
        }
    }
    // Abajo

    if(nodoActual.j <N){
        nodo var(nodoActual.i,nodoActual.j,&nodoFinal,nodoActual.i,nodoActual.j+1,nodoActual.costeTotal);
        pair<int,int> foo=make_pair(nodoActual.i-1,nodoActual.j+1);
        if(estaAbierta(foo)==false){
            listaAbierta.push_back(var);
        }
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

