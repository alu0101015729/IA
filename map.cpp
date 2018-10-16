#include "map.hpp"



map::map(int m,int n):M_(m),N_(n){}

map::~map(){}

map::handmade_obst(){
    int obstaculos=0;
    do{
        std::cout<<"Cuantos obstaculos quieres:";
        std::cin>>obstaculos;
        if(obstaculos >= map_.size()-2){
            std::cout << "Por favor introduzca un nº de obstaculos adecuados(tenga en cuenta pos. inicio y final). Maximo: " <<  map_.size() << std::endl;
        }

    }while(obstaculos >= map.size()-2);
    for(int i=0;i<=obstaculos;i++){
        std::pair<int,int> obs;
        std::cout << "Coordenada x:";
        std::cin>> obs.first;
        std::cout << "Coordenada y:";
        std::cin>> obs.second;
        obstacles.push_back(obs);
    }
}

map::random_obst(){
    int obstaculos=0;
    do{
        std::cout<<"Cuantos obstaculos quieres:";
        std::cin>>obstaculos;
        if(obstaculos >= map_.size()-2){
            std::cout << "Por favor introduzca un nº de obstaculos adecuados(tenga en cuenta pos. inicio y final). Maximo: " <<  map_.size() << std::endl;
        }

    }while(obstaculos >= map.size()-2);
    for(int i=0;i<=obstaculos;i++){
        std::pair<int,int> obs;
        std::cout << "Coordenada x:";
        std::cin>> obs.first;
        std::cout << "Coordenada y:";
        std::cin>> obs.second;
        obstacles.push_back(obs);
    }
}
