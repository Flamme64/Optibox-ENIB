#ifndef Pave_H
#define Pave_H

#include <string>
#include "point.h"
#include <iostream>

class Pave{
  private :
    //Attributs :
      int _dimX, _dimY, _dimZ;
      const std::string _name;

  public :
    //Attributs importes :
      Point _point;

    //Methodes generiques :
      //Constructeur :
    Pave(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name) : _dimX(dimX), _dimY(dimY), _dimZ(dimZ), _name(name), _point(x,y,z) {}
    Pave(int dimx, int dimy, int dimz, Point p ) : _dimX(dimx), _dimY(dimy), _dimZ(dimz), _point(p){}
    Pave(const int dimX, const int dimY, const int dimZ) : _dimX(dimX), _dimY(dimY), _dimZ(dimZ) {_point = Point(0,0,0);}

    // Destructeur
    ~Pave(void) {}

      // Accesseurs
    int getX(void){return _point.getX();}
    int getY(void){return _point.getY();}
    int getZ(void){return _point.getZ();}
    int getDimX(void) {return _dimX;}
    int getDimY(void) {return _dimY;}
    int getDimZ(void) {return _dimZ;}
    std::string getName(void) {return _name;}

      // Mutateurs
    // Position
    virtual void setX(int x){ _point.setX(x);}
    virtual void setY(int y){ _point.setY(y);}
    virtual void setZ(int z){ _point.setZ(z);}
    // Dimension
    virtual void setDimX(int dimX) {_dimX=dimX;}
    virtual void setDimY(int dimY) {_dimY=dimY;}
    virtual void setDimZ(int dimZ) {_dimZ=dimZ;}

    // Affichage
    void printPave(void);

};

#endif

// Mon code //
