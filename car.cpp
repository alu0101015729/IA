#include "car.hpp"

int car::mov_norte(int i){
    return x=i+1;
}
int car::mov_este(int i){
    return y=i-1;
}
int car::mov_oeste(int i){
    return y=i-1;
}
int car::mov_sur(int i){
    return x=i+1;
}
int car::pos_x(){
    return x;
}
int car::pos_y(){
    return y;
}

