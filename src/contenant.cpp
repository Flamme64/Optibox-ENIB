#include "contenant.h"

Contenant::Contenant(int x, int y, int z, int dimX,  int dimY, int dimZ, const std::string name, float chargeMax)
: Boite(x,y,z,dimX,dimY,dimZ, name), _chargeMax(chargeMax)
{
  //Attribut qui sera intancié plus tard
  _cartons=NULL;
}

/*
1 - Jacques
  Il faudrait faire un traitement des coordonnées du contenant. 
  J'ai peur qu'on confonde deux contenants si leurs coordonnées sont toutes à 0.

*/
