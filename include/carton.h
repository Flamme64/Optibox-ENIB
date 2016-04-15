#ifndef CARTON_H
#define CARTON_H

#include "boite.h"
Class Contenant; //Il faudra mettre un include dans le fichier final

class Carton : public Boite{
  
  private :
    // Attributs :
      float _poidRang;  // Poid du carton pour le classer dans le tableau de rangement
      const bool _fragile;    // Pour savoir si le carton doit être placé au dessus
      int _maxDim;      // La dimension maximale parmis dimX, dimY et dimZ
      const float _masse;     // Le poids réel du carton, sa masse quoi 
      Contenant * _cont;
      
  public :
    // Méthodes génériques :
    // Constructeur
    Carton(int x, int y, int z, const int dimX, const  int dimY, const int dimZ, const bool fragile, const float masse);
    //Destructeur
    ~Carton(void) {}
    
    // Accesseurs
    float getPoidRang(void) {return _poidRang;}
    const bool getFragile(void) {return _fragile;}
    int getMaxDim(void) {return _maxDim;}
    const float getMasse(void) {return _masse;}
    Contenant getCont(void) {return _cont;}
    
    // Mutateurs :
    void setCont(Contenant cont) {_cont=cont;}
    
};

#endif CARTON_H

/*REMARQUES :
1 - Jacques
  Il faudrait prende en compte le cas où l'utilisateur ne connait pas le poid du carton,
  il y a quand même peut de chance pour qu'il connaisse exactement le poid ou qu'il prenne le temps de tous les peser.




*/
