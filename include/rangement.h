#ifndef RANGEMENT_H
#define RANGEMENT

#include <vector>

#include "contenant.h"
#include "carton.h"

class Rangement{
  public :
  // Attributs :
    std::vector<Carton*> _cartRang;
    std::vector<Contenant*> _contRang;
  
  // Méthodes génériques :
  // Constructeur
  Rangement(void) {}
  // Destructeur
  ~Rangement(void) {}
  
};

#endif
