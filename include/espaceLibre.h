#ifndef ESPACELIBRE_H
#define ESPACELIBRE_H

#include "pave.h"

class EspaceLibre : public Pave{
  private :
    // Attributs :
      float _surface; // Je ne sais pas si ça sera utile mais dans le doute ...
  
  public :
    // Méthodes génériques :
      // Constructeur
      EspaceLibre(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name) : Pave(x,y,z,dimX,dimY,dimZ,name) {_surface=dimX*dimY}
      // Destructeur
      ~EspaceLibre(void) {}
      
      // Accesseur
        float getSurface(void) {return _surface;}
        
}


#endif
