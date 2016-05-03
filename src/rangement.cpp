#include "rangement.h"

/* Fonctions a coder
	void recupererCartons(std::string fichier);
	int trouverCarton(EspaceLibre* espaceLibre);
	bool attributionPossible(Carton * carton, EspaceLibre *);
	void attributionCoordonnees(void);
	void rangerLesCartons(void);
*/
	

  
  // Mutateurs
	// Ajoute un carton au vecteur de cartons
	void Rangement::addCarton(Carton* carton){
		if(carton) _cartRang.push_back(carton);
}
		
	// Permet de creer le carton dans la fonction puis de l'ajouter au vecteur de cartons
	void Rangement::addCarton(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name, const bool fragile, const float masse){
		Carton * cartTmp = new Carton(x,y,z,dimX,dimY,dimZ,name,fragile,masse);
		addCarton(cartTmp);
}	

	// Ajoute un contenant au vecteur de contenants
	void Rangement::addContenant(Contenant* contenant){
		if(contenant) _contRang.push_back(contenant);
}

	// Permet de creer le contenant dans la fonction puis de l'ajouter au vecteur de contenants
	void Rangement::addContenant(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name, float masseMax){
		Contenant * contTmp = new Contenant(x,y,z,dimX,dimY,dimZ,name,masseMax);
		addContenant(contTmp);
}

	// Ajoute un espace libre dans le vecteur d'espaces libres
	void Rangement::addEL(EspaceLibre* espLibre){
		if (espLibre) _espLib.push_back(espLibre);
}

	// Permet de creer l'espace libre dans la fonction puis de l'ajouter au vecteur de contenants
	void Rangement::addEL(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name){
		EspaceLibre * espLibTmp = new EspaceLibre(x,y,z,dimX,dimY,dimZ,name);
		addEL(espLibTmp);
}
	
  // Methodes specialisees :
    // Recuperation des cartons a ranger
	  // A adapter car depend de comment on nous envoie les cartons
	void Rangement::recupererCartons(std::string fichier){} //TODO
	
    // Tri des cartons fonction de leurs dimensions
	void Rangement::triDesCartons(void){
	  int modif;
	  while (modif) {
	    modif=0;
	    for (unsigned int i=0;i<_cartRang.size()-1;i++){
	      
		// Si la dimX du suivant est plus grande que la dimX de l'actuel, on inverse les deux
	      if(_cartRang[i]->getDimX()<_cartRang[i+1]->getDimX()){
		Carton * tmp=_cartRang[i+1];
		_cartRang.erase(_cartRang.begin()+i+1);
		_cartRang.insert(_cartRang.begin()+i,tmp);
		modif=modif+1;
	      }
	      
		// Si la dimX des deux est égale, on regarde les dimY
	      else if(_cartRang[i]->getDimX()==_cartRang[i+1]->getDimX()){
		  // Si la dimY du suivant est plus grande que la dimY de l'actuel, on inverse les deux
		if(_cartRang[i]->getDimY()<_cartRang[i+1]->getDimY()){
		  Carton * tmp=_cartRang[i+1];
		  _cartRang.erase(_cartRang.begin()+i+1);
		  _cartRang.insert(_cartRang.begin()+i, tmp);
		  modif=modif+1;
		}
		  // Si la dimY des deux est égale, on regarde les dimZ
		else if(_cartRang[i]->getDimY()==_cartRang[i+1]->getDimY()){
		    // SI la dimZ du suivant est plus grande que la dimZ de l'actuel on inverse
		  if(_cartRang[i]->getZ()<_cartRang[i+1]->getZ()){
		    Carton * tmp=_cartRang[i+1];
		    _cartRang.erase(_cartRang.begin()+i+1);
		    _cartRang.insert(_cartRang.begin()+i, tmp);
		    modif=modif+1;
		  }
		    // Si i.dimZ > i+1.dimZ
		  else continue;
		}
		  // Si i.dimY > i+1.dimY
		else continue;
	      }
		// Si i.dimX > i+1.dimX
	      else continue;
	    }
	  }
}

    // Verification de la possibilite de placement du carton
		// Fonctions utilisees avec une instance de test d'un carton
	bool Rangement::verifMasseLegale(Carton * cartonTest){
		float nouveauPoid = cartonTest->getMasse()+_contRang[_qContenant]->getMasseActuelle();
		if(nouveauPoid <= _contRang[_qContenant]->getMasseMax()) return true;
		else return false;
}

	bool Rangement::verifContactContainer(Carton * carton,int x,int y,int z){
	  carton->setX(x); carton->setY(y); carton->setZ(z); // On fixe les coordonnees du carton a l'endroit du test
	    // Si le carton touche le fond ou la porte du container
	  if((carton->getX()==1) | ((carton->getX()+carton->getDimX())==(_contRang[_qContenant]->getDimX()-1))) return true;
	    // Si le carton touche la gauche ou la droite du container
	  else if((carton->getY()==1) | ((carton->getY()+carton->getDimY())==(_contRang[_qContenant]->getDimY()-1))) return true;
	    // Si le carton touche le bas ou le haut du container
	  else if((carton->getZ()==1) | ((carton->getZ()+carton->getDimZ())==(_contRang[_qContenant]->getDimZ()-1))) return true;
	    // Sinon on renvoie faux
	  else return false;
}
		
		//On prend en compte qu'on rajoute toujours un carton soit a droite soit devant soit au dessus d'un carton deja positionne 
	bool Rangement::verifContactCarton(Carton * carton,int x,int y,int z){
	  carton->setX(x); carton->setY(y); carton->setZ(z); // On fixe les coordonnees du carton a l'endroit du test
	  for (unsigned int i=0;i<_cartRang.size();i++){
	      // Si le carton touche un autre carton selon un plan definit par les axes y,z
	    if(carton->getX()==(_cartRang[i]->getX()+_cartRang[i]->getDimX()+1)) return true;
	      // Si le carton touche un autre carton selon un plan definit par les axes x,z
	    else if(carton->getY()==(_cartRang[i]->getY()+_cartRang[i]->getDimY()+1)) return true;
	      // Si le carton touche un autre carton selon un plan definit par les axes x,y
	    else if(carton->getZ()==(_cartRang[i]->getZ()+_cartRang[i]->getDimZ()+1)) return true;
	  }
	    // Sinon on renvoie faux
	  return false;
}	    
		
    // Trouver le carton le plus adapte
	  // Renveira l'indice du carton le plus adapte
	int Rangement::trouverCarton(EspaceLibre* espaceLibre){ return 0;} //TODO
	bool Rangement::attributionPossible(Carton * carton, EspaceLibre * espLib){ return false;} //TODO
	
    // Attribution des coordonnees de la position du carton
	void Rangement::attributionCoordonnees(int x,int y,int z){} //TODO
	
    // Ranger les cartons
	void Rangement::rangerLesCartons(void){} //TODO