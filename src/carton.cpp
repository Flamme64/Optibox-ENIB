#include "carton.h"

Carton::Carton(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name, const bool fragile, const float masse)
:   Boite(x,y,z,dimX,dimY,dimZ,name), _fragile(fragile), _masse(masse)
{
  
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
  // On stocke les valeurs dans cet ordre
  _maxDim=dimX;
  this.setDimX(dimX);
  this.setDimY(dimY);
  this.setDimZ(dimZ);
    
  //  Attributs qui seront instanciés ultérieurement
  _poidRang=NULL; //Le poid de l'objet dans le tableau sera calculé quand on aura trouvé la méthode pour le faire
  _cont=NULL; //Le contenant sera attribué pendant la phase de rangement
  
}

/* IDEES/REMARQUES :

1 - Jacques
  Est ce que maxDim a toujours un sens si on range les dimensions par ordre croissant ?


*/
