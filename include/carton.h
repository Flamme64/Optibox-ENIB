#ifndef CARTON_H
#define CARTON_H

#include "pave.h"
class Contenant;

class Carton : public Pave{
  
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
      Carton(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name, const bool fragile, const float masse);
      //Destructeur
      ~Carton(void) {}
      
      // Accesseurs
      float getPoidRang(void) {return _poidRang;}
      bool getFragile(void) {return _fragile;}
      int getMaxDim(void) {return _maxDim;}
      float getMasse(void) {return _masse;}
      Contenant* getCont(void) {return _cont;}
      
      // Mutateurs :
      void setCont(Contenant* cont) {_cont=cont;}
      void setDimX(int dimX) {_dimX=dimX;}
      void setDimY(int dimY) {_dimY=dimY;}
      void setDimZ(int dimZ) {_dimZ=dimZ;}
    
    //Méthodes spéciales :
    void arrangeDim(void); //Gère le rangement par ordre décroissant des dimensions
    
    
};

/*REMARQUES :
1 - Jacques
  Il faudrait prende en compte le cas où l'utilisateur ne connait pas le poid du carton,
  il y a quand même peut de chance pour qu'il connaisse exactement le poid ou qu'il prenne le temps de tous les peser.

*/
#endif


