#ifndef ESPACELIBRE_H
#define ESPACELIBRE_H


#include "pave.h"
#include <iostream>
class Contenant;

class EspaceLibre : public Pave{
  private :
    // Attributs :
      int _surface; // Je ne sais pas si ça sera utile mais dans le doute ...
      Contenant * _contenant; // Contenant dans lequel se situe l'espace libre
  
  public :
    // Methodes generiques :
      // Constructeur
	  EspaceLibre(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name) : Pave(x, y, z, dimX, dimY, dimZ, name) { _surface = dimX*dimY; }
      // Destructeur
          ~EspaceLibre(void) {}
      
      // Accesseur
          int getSurface(void) {return _surface;}
        
      // Mutateurs de securite :
	  void setDimX(int dimX) { std::cout << "ERROR : Modification de la dimX d'un espace libre" << std::endl; }
	  void setDimY(int dimY) { std::cout << "ERROR : Modification de la dimY d'un espace libre" << std::endl; }
	  void setDimZ(int dimZ) { std::cout << "ERROR : Modification de la dimZ d'un espace libre" << std::endl; }
        
};

#endif
