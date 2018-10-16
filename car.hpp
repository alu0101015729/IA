#ifndef CAR_HPP
#define CAR_HPP

class car{
private:
  int i;
  int j;
public:
  car(){
      i=0;
      j=0;
  }
  car(int x,int y){
      i=x;
      j=y;
  }
  ~car(){}
};

#endif // CAR_HPP
