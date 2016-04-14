#include "carton.h"

Carton::Carton(int x, int y, int z, int dimX, int dimY, int dimZ, const bool fragile, const float masse){
  
  //Ordonnancement des dimensions dimX, dimY, dimZ pour les ranger dans un ordre décroissant
  //A FAIRE
  
  //Création de l'objet
  Boite(x,y,z,dimX,dimY,dimZ);
  _poidRang=NULL;
  _fragile=fragile;
   _masse=masse;
   
  
  
  }
  
}
