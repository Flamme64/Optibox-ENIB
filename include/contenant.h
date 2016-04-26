#ifndef CONTENANT_H
#define CONTENANT_H

#include <vector>

#include "pave.h"
#include <iostream>

class Carton;

class Contenant : public Pave{
	
private :
	float _masseMax; // La masse maximum qu'un contenant peut supporter


public :
	// Attributs :
	std::vector<Carton*> _cartons;
   
	// Méthodes génériques
		// Contructeur
		Contenant(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name, float masseMax) : Pave(x,y,z,dimX,dimY,dimZ, name), _masseMax(masseMax) {}
		// Destructeur
		~Contenant(void) {}
		
		//Accesseurs :
		float getMasseMax(void) { return _masseMax; }

		// Accesseurs de sécurité :
		void setDimX(int dimX) { std::cout << "ERROR : Modification de la dimX d'un contenant" << std::endl;}
		void setDimY(int dimY) { std::cout << "ERROR : Modification de la dimY d'un contenant" << std::endl;}
		void setDimZ(int dimZ) { std::cout << "ERROR : Modification de la dimZ d'un contenant" << std::endl;}
    

	// Méthodes spéciales :
		// Affichage :
		void printContenant(void);
		  
		// Gestion des cartons :
    
  

};


#endif

/* REMARQUES :



*/
