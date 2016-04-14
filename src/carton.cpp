#include "carton.h"

Carton::Carton(int x, int y, int z, const int dimX, const int dimY, const int dimZ, const bool fragile, const float masse){
  
  // Rangement des dimensions par ordre décroissant
  int cache;
  for(int i=0; i<3; i++){
    if(dimX < dimY){ //Si dimY est plus grande que dimX on met dimY dans dimX
      cache = dimX;
      dimX = dimY;
      dimY = cache;
    }
    if(dimY < dimZ){ //Si dimZ est plus grande que dimY on met dimZ dans dimY
      cache = dimY;
      dimY = dimZ;
      dimZ = cache;
    }
  }
  
  // Création de l'objet
  Boite(x,y,z,dimX,dimY,dimZ);
  _poidRang=NULL;
  _fragile=fragile;
  _masse=masse;
  _maxDim=dimX; 
  
}

/* IDEES/REMARQUES :

1 - Jacques
  Est ce que maxDim a toujours un sens si on range les dimensions par ordre croissant ?


*/
