#include "contenant.h"

Contenant::Contenant(int x=0, int y=0, int z=0, const int dimX, const  int dimY, const int dimZ, const std::string name, float chargeMax){
  Boite(x,y,z,dimX,dimY,dimZ, name);
  _chargeMax=chargeMax;
  _cartons=NULL;
}
