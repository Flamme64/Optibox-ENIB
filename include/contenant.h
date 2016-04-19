#ifndef CONTENANT_H
#define CONTENANT_H

#include <vector>

#include "pave.h"
class Carton;

class Contenant : public Pave{
  public :
    // Attributs :
    float _masseMax; // La masse maximum qu'un contenant peut supporter
    std::vector<Carton*> _cartons;
    
    // Méthodes génériques
    // Contructeur
    Contenant(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name, float masseMax) : Pave(x,y,z,dimX,dimY,dimZ, name), _masseMax(masseMax) {}
    // Destructeur
    ~Contenant(void) {}
    
    // Mutateurs de sécurité :
      void setDimX(int dimX) {print("ERROR : Modification de la dimX d'un contenant");}
      void setDimY(int dimY) {print("ERROR : Modification de la dimY d'un contenant"):}
      void setDimZ(int dimZ) {print("ERROR : Modification de la dimZ d'un contenant");}
    
    // Gestion des cartons :
    
  

};


#endif

/* REMARQUES :



*/
