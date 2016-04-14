#ifndef POINT_H
#define POINT_H

class Point{
  private :
    //Attributs
      int _x,_y,_z;
      
  public :
    //Méthodes génériques :
      //Constructeur
      Point(int x, int y, int z) : _x(x), _y(y), _z(z) {}
      //Destructeur
      ~Point(void){}
      
      //Accesseurs
      int getX(void) {return _x;}
      int getY(void) {return _y;}
      int getZ(void) {return _z;}
      
      //Mutateurs
      void setX(int x) {_x=x;}
      void setY(int y) {_y=y;}
      void setZ(int z) {_z=z;}
    
    //Méthodes spéciales :
      //Implémenter un move ? Est ce que ça sera utile ?
};


#endif
