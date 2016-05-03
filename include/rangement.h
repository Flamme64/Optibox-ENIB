#ifndef RANGEMENT_H
#define RANGEMENT_H

#include <vector>
#include <string>
#include <iterator>

#include "contenant.h"
#include "carton.h"
#include "espaceLibre.h"

/*
	void recupererCartons(std::string fichier);
	void triDesCartons(void);
	bool validationAttributionCoordonnees(void); // Fonction de test globale
	bool verifMasseLegale(Carton * carton);
	bool verifContactContainer(Carton * carton);
	bool verifContactCarton(Carton * carton, int x, int y, int z);
	int trouverCarton(EspaceLibre* espaceLibre);
	bool attributionPossible(Carton * carton, EspaceLibre *);
	void attributionCoordonnees(void);
	void rangerLesCartons(void);
*/

class Rangement{
  public :
  // Attributs :
    int _qContenant;
    std::vector<Carton*> _cartRang;
    std::vector<Contenant*> _contRang;
    std::vector<EspaceLibre*> _espLib;
  
  // Methodes generiques :
    // Constructeur
	Rangement(void) : _qContenant(0) {}
    // Destructeur
	~Rangement(void) {}
    // Accesseur et mutateurs
	int getContActuel(void){return _qContenant;}
	Carton* getCarton(int i){return _cartRang[i];}
	Contenant* getContenant(int i){return _contRang[i];}
	EspaceLibre* getEL(int i){return _espLib[i];}
	
	void setContActuel(int i){_qContenant=i;}
	void addCarton(Carton* carton);
	void addCarton(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name, const bool fragile, const float masse); // Permet de creer le carton dans la fonction
	void addContenant(Contenant* contenant);
	void addContenant(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name, float masseMax); // Permet de creer le contenant dans la fonction
	void addEL(EspaceLibre* espLibre);
	void addEL(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name); // Permet de creer l'espace libre dans la fonction
	
  // Methodes specialisees :
    // Recuperation des cartons a ranger
	void recupererCartons(std::string fichier); // A adapter car depend de l'interface
	
    // Tri des cartons fonction de leurs dimensions
	void triDesCartons(void);
  
    // Verification de la possibilite de placement des cartons
	// Fonction utilisées avec un carton tampon
	bool verifMasseLegale(Carton * carttmp);
	bool verifContactContainer(Carton * carttmp, int x, int y, int z);
	bool verifContactCarton(Carton * carttmp, int x, int y, int z);
		
    // Trouver le carton le plus adapte
	int trouverCarton(EspaceLibre* espaceLibre); //Renveira l'indice du carton le plus adapte
	bool attributionPossible(Carton * carton, EspaceLibre * espLib);
	
    // Attribution des coordonnees de la position du carton
	void attributionCoordonnees(int x,int y,int z);
	
    // Ranger les cartons
	void rangerLesCartons(void);
};

#endif

/* Remarques

1  Nono 
	Realiser un pattern de classement des cartons dans le vecteur une fois ranges pour faciliter 
	la modelisation graphique (Nono)
   
*/
