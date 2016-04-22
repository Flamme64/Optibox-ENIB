#ifndef RANGEMENT_H
#define RANGEMENT_H

#include <vector>

#include "contenant.h"
#include "carton.h"
#include "espaceLibre.h"

class Rangement{
  public :
  // Attributs :
    int _qContenant;
    std::vector<Carton*> _cartRang;
    std::vector<Contenant*> _contRang;
    std::vector<EspaceLibre*> _espLib;
  
  // Méthodes génériques :
  // Constructeur
	Rangement(void) : _qContenant(0) {}
  // Destructeur
  ~Rangement(void) {}
  
  // Vérification de la possibilité de placement des cartons
	bool verifMasseLegale(Carton * carton);
	bool verifPlaceDispo(Carton * carton, int x, int y, int z);
};

#endif
