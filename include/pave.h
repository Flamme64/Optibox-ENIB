#ifndef PAVEDROIT_H
#define PAVEDROIT_H

#include "point.h"

#include <string>
#include <iostream>

class Pave{
  private :
    //Attributs :
      int _dimX, _dimY, _dimZ;
      const std::string _name;
    
  public :
    //Attributs importés :
      Point _point;
    
    // Méthodes génériques :
      //Constructeur :
	Pave(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name) : _dimX(dimX), _dimY(dimY), _dimZ(dimZ), _name(name), _point(x,y,z) {}
      // Destructeur
	~Pave(void) {}
      
      // Accesseurs
	int getDimX(void) {return _dimX;}
	int getDimY(void) {return _dimY;}
	int getDimZ(void) {return _dimZ;}
	std::string getName(void) {return _name;}
      
      // Mutateurs
	virtual void setDimX(int dimX) {_dimX=dimX;}
	virtual void setDimY(int dimY) {_dimY=dimY;}
	virtual void setDimZ(int dimZ) {_dimZ=dimZ;}
      
	// Affichage
	void printPave(void);
    
  
};

#endif
