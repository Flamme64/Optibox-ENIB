#ifndef PAVEDROIT_H
#define PAVEDROIT_H

#include <string>
#include "point.h"

class Pave{
  private :
    //Attributs :
      int _dimX, _dimY, _dimZ;
      const std::string _name;
      
    //Mutateurs :
    void setDimX(int dimX) {_dimX=dimX;}
    void setDimY(int dimY) {_dimY=dimY;}
    void setDimZ(int dimZ) {_dimZ=dimZ;}
    // Les mutateurs des dimensions sont en private parce qu'on veut qu'ils ne soient accessibles qu'à partir de la classe amie Carton mais pas dans Contenant et EspaceLibre
    
    
  public :
    //Attributs importés :
      Point _point;
    
    //Méthodes génériques :
      //Constructeur :
      Pave(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name) : _dimX(dimX), _dimY(dimY), _dimZ(dimZ), _name(name), _point(x,y,z) {}
      // Destructeur
      ~Pave(void) {}
      
      // Accesseurs
      int getDimX(void) {return _dimX;}
      int getDimY(void) {return _dimY;}
      int getDimZ(void) {return _dimZ;}
      std::string getName(void) {return _name;}
      
    
  
};

#endif
