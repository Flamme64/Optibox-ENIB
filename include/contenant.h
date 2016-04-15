#ifndef CONTENANT_H
#define CONTENANT_H

#include <vector>

#include "pave.h"
class Carton; //Il faudra mettre un include dans le fichier final

class Contenant : public Pave{
  public :
    // Attributs :
    float _masseMax; 
    std::vector<Carton*> _cartons;
    
    // Méthodes génériques
    // Contructeur
    Contenant(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name, float masseMax) : Pave(x,y,z,dimX,dimY,dimZ, name), _masseMax(masseMax) {}
    // Destructeur
    ~Contenant(void) {}
    
    // Gestion des cartons :
    
  

};


#endif

/* REMARQUES :
1 - Jacques
  Je ne me souviens pas de ce que l'attribut chargeMax représente


*/
