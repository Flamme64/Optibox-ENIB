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
  Rangement(void) {_cartRang=NULL; _contRang=NULL;}
  // Destructeur
  ~Rangement(void) {}
  
};

#endif
