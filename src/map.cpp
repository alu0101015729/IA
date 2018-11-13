#include "../include/map.hpp"




map::map(int m,int n):M_(m),N_(n){}

map::~map(){}


int map::get_pos(std::pair<int, int> pos_xy)
{
  int i = pos_xy.first;
  int j = pos_xy.second;

  return i*M_+j;
}

void map::handmade_obst(){
    int obstaculos=0;
    do{
        cout<<"Cuantos obstaculos quieres:";
        cin>>obstaculos;
        if(obstaculos >= M_*N_-2){
            cout << "Nº de obstaculos iadecuado. Tenga en cuenta pos. inicio y final. Máximo: " <<  M_*N_-2 << std::endl;
        }

    }while(obstaculos >= M_*N_-2);
    for(int i=1;i<=obstaculos;i++){
        pair<int,int> obs;
        cout << "Coordenada y:";
        cin>> obs.first;
        cout << "Coordenada x:";
        cin>> obs.second;
        obstacles.push_back(obs);
    }
}

void map::random_obst(){
    int obstaculos=0;
    do{
        cout<<"Cuantos obstaculos quieres:";
        cin>>obstaculos;
        if(obstaculos >= M_*N_-2){
            cout << "Nº de obstaculos iadecuado. Tenga en cuenta pos. inicio y final. Máximo: " <<  M_*N_-2 << std::endl;
        }

    }while(obstaculos >= M_*N_-2);
    for(int i=1;i<=obstaculos;i++){
        pair<int,int> obs;
        obs.first=rand()%M_;
        obs.second=rand()%N_;
        obstacles.push_back(obs);
    }
}



void map::pos_M(int m){
    M_=m;
}

void map::pos_N(int n){
    N_=n;
}

int map::get_M(){
    return M_;
}

int map::get_N(){
    return N_;
}

vector<pair<int,int>> map::get_obstacles(){
    return obstacles;
}

