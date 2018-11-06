#include "map.hpp"




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
        std::cout<<"Cuantos obstaculos quieres:";
        std::cin>>obstaculos;
        if(obstaculos >= M_*N_-2){
            std::cout << "Nº de obstaculos iadecuado. Tenga en cuenta pos. inicio y final. Máximo: " <<  map_.size()-2 << std::endl;
        }

    }while(obstaculos >= M_*N_-2);
    for(int i=1;i<=obstaculos;i++){
        std::pair<int,int> obs;
        std::cout << "Coordenada x:";
        std::cin>> obs.first;
        std::cout << "Coordenada y:";
        std::cin>> obs.second;
        obstacles.push_back(obs);
    }
}

void map::random_obst(){
    int obstaculos=0,m=0,n=0;
    std::pair<int,int> coordenadas;
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0, N_*M_-2);
    std::uniform_int_distribution<int> horizonte(0, N_);
    std::uniform_int_distribution<int> vertical(0, M_);
    obstaculos=distribution(generator);
    for(int i=0;i<=obstaculos;i++){
        m=vertical(generator);
        n=horizonte(generator);
        coordenadas.first=m;
        coordenadas.second=n;
        obstacles.push_back(coordenadas);
    }
}
//Construcción de rejilla. Necesito N y M = vector posiciones
// Necesito lista obstaculos = vector obstaculos
//Problemas: Revisar obstaculos cada vez q se vaya a imprimir casilla
//
void map::write(std::ostream& os) const{
  //std::vector<std::pair<int,int>>::iterator it;
  for(auto it=obstacles.begin();it != obstacles.end();it++){
      for(int i=0;i<=M_;i++){
          for(int j=0;j<=N_;j++){
              std::pair<int,int> coor=std::make_pair(i,j);
              if(*it==coor){
                  //os << "\E[0;31m" << "X" << "\E[00m" << " ";
                  os << "X ";
              }
              else{
                  os << "O ";
              }
          }
      }
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

std::vector<std::pair<int,int>> map::get_obstacles(){
    return obstacles;
}

