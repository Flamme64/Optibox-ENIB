#include "carton.h"

// Constructeur
Carton::Carton(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name, const bool fragile, const float masse)
:   Pave(x,y,z,dimX,dimY,dimZ,name), _fragile(fragile), _masse(masse)
{
  //  Attributs qui seront instancies ulterieurement
  _poidRang=0; //Le poid de l'objet dans le tableau sera calcule quand on aura trouve la methode pour le faire
  _cont=NULL;  //Le contenant sera attribue pendant la phase de rangement
  
  // Rangement des dimensions par ordre decroissant
  arrangeDim();
  
}

// Fonction qui range les dimensions par ordre croissant
void Carton::arrangeDim(void){
  // 1- On copie les dimensions dans des variables temporaires
  int dimX, dimY, dimZ;
  dimX=getDimX();
  dimY=getDimY();
  dimZ=getDimZ();
  
  // 2- On les range par ordre croissant
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
  
  // 3- On les recopie dans les attributs
  setDimX(dimX);
  setDimY(dimY);
  setDimZ(dimZ);
  
}



/* IDEES/REMARQUES :

1 - Jacques
  Est ce que maxDim a toujours un sens si on range les dimensions par ordre croissant ?


*/
