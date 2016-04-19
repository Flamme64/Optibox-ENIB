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
        
      // Mutateurs de sécurité :
      void setDimX(int dimX) {print("ERROR : Modification de la dimX d'un espace libre");}
      void setDimY(int dimY) {print("ERROR : Modification de la dimY d'un espace libre"):}
      void setDimZ(int dimZ) {print("ERROR : Modification de la dimZ d'un espace libre");}
        
}


#endif
