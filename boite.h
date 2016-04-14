#ifndef BOITE_H
#define BOITE_H

#include "point.h"

class Boite{
  private :
    //Attributs :
      const int _dimX, _dimY, _dimZ;
    
  public :
    //Attributs importés :
      Point _point;
    
    //Méthodes génériques :
      //Constructeur :
      Boite(x,y,z,dimX,dimY,dimZ) : _dimX(dimX), _dimY(dimY), _dimZ(dimZ) {_point = Point(x,y,z);}
      //Destructeur
      ~Boite(void) {delete _point;}
      
      //Accesseurs :
      const int getDimX(void) {return _dimX;}
      const int getDimY(void) {return _dimY;}
      const int getDimZ(void) {return _dimZ;}
  
};

#endif
