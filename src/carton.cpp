#include "carton.h"

Carton::Carton(int x, int y, int z, int dimX, int dimY, int dimZ, const bool fragile, const float masse){
  
  //Ordonnancement des coordonnées x,y,z pour les ranger dans un ordre décroissant
  if(x>=y)
  
  //Création de l'objet
  Boite(x,y,z,dimX,dimY,dimZ);
  _poidRang=NULL;
  _fragile=fragile;
   _masse=masse;
   
  
  
  }
  
}
