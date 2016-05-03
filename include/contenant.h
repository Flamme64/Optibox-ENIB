#ifndef CONTENANT_H
#define CONTENANT_H

#include <vector>

#include "pave.h"
#include <iostream>

class Carton;

class Contenant : public Pave{
  public :
    // Attributs :
      float _masseMax; // La masse maximum qu'un contenant peut supporter
      float _masseActuelle; // La masse actualisee du chargement du contenant
	  std::vector<Carton*> _cartons;
    
    // Methodes generiques
    // Contructeur
      Contenant(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name, float masseMax) : Pave(x,y,z,dimX,dimY,dimZ, name), _masseMax(masseMax), _masseActuelle(0) {}
    // Destructeur
      ~Contenant(void) {}
    
    // Accesseurs et Mutateurs de securite :
	  float getMasseMax(void){ return _masseMax;}
	  float getMasseActuelle(void){ return _masseActuelle;}
	  
      void setX(int x){ std::cout << "ERROR : Modification de la position d'un contenant (selon x)" << std::endl;}
      void setY(int y){ std::cout << "ERROR : Modification de la position d'un contenant (selon y)" << std::endl;}
      void setZ(int z){ std::cout << "ERROR : Modification de la position d'un contenant (selon z)" << std::endl;}
      void setDimX(int dimX) { std::cout << "ERROR : Modification de la dimX d'un contenant" << std::endl;}
      void setDimY(int dimY) { std::cout << "ERROR : Modification de la dimY d'un contenant" << std::endl;}
      void setDimZ(int dimZ) { std::cout << "ERROR : Modification de la dimZ d'un contenant" << std::endl;}
    
    // Gestion des cartons :
    
  

};


#endif

/* REMARQUES :



*/
