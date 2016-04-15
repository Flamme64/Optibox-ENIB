#ifndef CONTENANT_H
#define CONTENANT_H

#include <vector>

#include "boite.h"
Class Carton; //Il faudra mettre un include dans le fichier final

class Contenant : public Boite{
  public :
    // Attributs :
    float _chargeMax; 
    std::vector<Carton*> _cartons;
    
    // Méthodes génériques
    // Contructeur
    Contenant(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name, float chargeMax);
    // Destructeur
    ~Contenant(void) {}
    
    // Gestion des cartons :
    
  

};


#endif

/* REMARQUES :
1 - Jacques
  Je ne me souviens pas de ce que l'attribut chargeMax représente


*/
