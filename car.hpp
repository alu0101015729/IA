#ifndef CAR_HPP
#define CAR_HPP
#include<ostream>

class car{
private:
    int x;
    int y;
public:
  car():x(0),y(0){}
  ~car(){}
  int mov_este(int i);
  int mov_norte(int i);
  int mov_oeste(int i);
  int mov_sur(int i);
  int pos_x();
  int pos_y();
 // void write(ostream& os);
};

#endif // CAR_HPP
