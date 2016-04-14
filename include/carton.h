#ifndef CARTON_H
#define CARTON_H

#include "boite.h"

class Carton : public Boite{
  
  private :
    //Attributs :
      float _poidRang;  // Poid du carton pour le classer dans le tableau de rangement
      bool _fragile;    // Pour savoir si le carton doit être placé au dessus
      int _maxDim;      // La dimension maximale parmis dimX, dimY et dimZ
      float _masse;     // Le poids réel du carton, sa masse quoi 
      
  public :
    //Méthodes génériques :
    //Constructeur
    Carton(int x, int y, int z, int dimX, int dimY, int dimZ, float poidRang, bool fragile, float masse);
    //Destructeur
    ~Carton(void) {}
    
};

#endif CARTON_H

/*IDEES :
1 - Jacques
  Il faudrait prende en compte le cas où l'utilisateur ne connait pas le poid du carton,
  il y a quand même peut de chance pour qu'il connaisse exactement le poid ou qu'il prenne le temps de tous les peser.




*/
