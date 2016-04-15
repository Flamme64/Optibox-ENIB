#ifndef BOITE_H
#define BOITE_H

#include <string>
#include "point.h"

class Boite{
  private :
    //Attributs :
      int _dimX, _dimY, _dimZ;
      const std::string _name;
    
  public :
    //Attributs importés :
      Point _point;
    
    //Méthodes génériques :
      //Constructeur :
      Boite(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name) : _dimX(dimX), _dimY(dimY), _dimZ(dimZ), _name(name), _point(x,y,z) {}
      //Destructeur
      ~Boite(void) {}
      
      //Accesseurs :
      int getDimX(void) {return _dimX;}
      int getDimY(void) {return _dimY;}
      int getDimZ(void) {return _dimZ;}
      std::string getName(void) {return _name;}
  
};

#endif
