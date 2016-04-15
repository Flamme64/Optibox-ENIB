#ifndef BOITE_H
#define BOITE_H

#include "point.h"

class Boite{
  private :
    //Attributs :
      const int _dimX, _dimY, _dimZ;
      const std::string _name;
    
  public :
    //Attributs importés :
      Point _point;
    
    //Méthodes génériques :
      //Constructeur :
      Boite(int x, int y, int z, const int dimX, const int dimY, const int dimZ, const std::string name) : _dimX(dimX), _dimY(dimY), _dimZ(dimZ), _name(name) {_point = Point(x,y,z);}
      //Destructeur
      ~Boite(void) {delete _point;}
      
      //Accesseurs :
      const int getDimX(void) {return _dimX;}
      const int getDimY(void) {return _dimY;}
      const int getDimZ(void) {return _dimZ;}
      const std::string getName(void) {return _name;}
  
};

#endif
