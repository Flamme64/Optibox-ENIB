#ifndef ESPACELIBRE_H
#define ESPACELIBRE_H

#include "pave.h"
#include <iostream>
class EspaceLibre : public Pave{
  private :
    // Attributs :
      float _surface; // Je ne sais pas si ça sera utile mais dans le doute ...
  
  public :
    // Méthodes génériques :
      // Constructeur
	  EspaceLibre(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name) : Pave(x, y, z, dimX, dimY, dimZ, name) { _surface = dimX*dimY; }
      // Destructeur
      ~EspaceLibre(void) {}
      
      // Accesseur
      float getSurface(void) {return _surface;}
        
      // Mutateurs de sécurité :
	  void setDimX(int dimX) { std::cout << "ERROR : Modification de la dimX d'un espace libre" << std::endl; }
	  void setDimY(int dimY) { std::cout << "ERROR : Modification de la dimY d'un espace libre" << std::endl; }
	  void setDimZ(int dimZ) { std::cout << "ERROR : Modification de la dimZ d'un espace libre" << std::endl; }
        
};


#endif
