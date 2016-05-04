#include "rangement.h"

//										----------------
//										|  ACCESSEURS  |
//										----------------

// Par nom
// Par dimension : si une des dimensions du pavé correspond

// Accesseurs pour carton
std::vector<unsigned int> Rangement::getCartonByName(std::string name) {
	std::vector<unsigned int> solution;
	for(unsigned int i=0; i < _cartRang.size();i++){
		if (_cartRang[i]->getName() == name) {
			solution.push_back(i);
		}
	}
	return solution;
}
std::vector<unsigned int> Rangement::getCartonByDim(int dim) {
	std::vector<unsigned int> solution;
	for (unsigned int i = 0; i < _cartRang.size(); i++) {
		if ((_cartRang[i]->getDimX()==dim) | (_cartRang[i]->getDimY()==dim) | (_cartRang[i]->getDimZ()==dim)) { // Si une des dimensions du carton est égale à dim
			solution.push_back(i);
		}
	}
	return solution;
}

// Accesseurs pour contenant
std::vector<unsigned int> Rangement::getContenantByName(std::string name) {
	std::vector<unsigned int> solution;
	for (unsigned int i = 0; i < _contRang.size(); i++) {
		if (_contRang[i]->getName() == name) {
			solution.push_back(i);
		}
	}
	return solution;
}
std::vector<unsigned int> Rangement::getContenantByDim(int dim) {
	std::vector<unsigned int> solution;
	for (unsigned int i = 0; i < _contRang.size(); i++) {
		if ((_contRang[i]->getDimX() == dim) | (_contRang[i]->getDimY() == dim) | (_contRang[i]->getDimZ() == dim)) { // Si une des dimensions du carton est égale à dim
			solution.push_back(i);
		}
	}
	return solution;
}

// Accesseurs pour espace libre
std::vector<unsigned int> Rangement::getELByName(std::string name) {
	std::vector<unsigned int> solution;
	for (unsigned int i = 0; i < _espLib.size(); i++) {
		if (_espLib[i]->getName() == name) {
			solution.push_back(i);
		}
	}
	return solution;
}
std::vector<unsigned int> Rangement::getELByDim(int dim) {
	std::vector<unsigned int> solution;
	for (unsigned int i = 0; i < _espLib.size(); i++) {
		if ((_espLib[i]->getDimX() == dim) | (_espLib[i]->getDimY() == dim) | (_espLib[i]->getDimZ() == dim)) { // Si une des dimensions du carton est égale à dim
			solution.push_back(i);
		}
	}
	return solution;
}

// Mutateurs de Norbert à Ordonner

// Mutateurs
// Ajoute un carton au vecteur de cartons
void Rangement::addCarton(Carton* carton) {
	if (carton) _cartRang.push_back(carton);
}

// Permet de creer le carton dans la fonction puis de l'ajouter au vecteur de cartons
void Rangement::addCarton(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name, const bool fragile, const float masse) {
	Carton * cartTmp = new Carton(x, y, z, dimX, dimY, dimZ, name, fragile, masse);
	addCarton(cartTmp);
}

// Ajoute un contenant au vecteur de contenants
void Rangement::addContenant(Contenant* contenant) {
	if (contenant) _contRang.push_back(contenant);
}

// Permet de creer le contenant dans la fonction puis de l'ajouter au vecteur de contenants
void Rangement::addContenant(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name, float masseMax) {
	Contenant * contTmp = new Contenant(x, y, z, dimX, dimY, dimZ, name, masseMax);
	addContenant(contTmp);
}

// Ajoute un espace libre dans le vecteur d'espaces libres
void Rangement::addEL(EspaceLibre* espLibre) {
	if (espLibre) _espLib.push_back(espLibre);
}

// Permet de creer l'espace libre dans la fonction puis de l'ajouter au vecteur de contenants
void Rangement::addEL(int x, int y, int z, int dimX, int dimY, int dimZ, const std::string name) {
	EspaceLibre * espLibTmp = new EspaceLibre(x, y, z, dimX, dimY, dimZ, name);
	addEL(espLibTmp);
}

// Méthodes spécialisées de Norbert à ordonner

// Methodes specialisees :
// Recuperation des cartons a ranger
// A adapter car depend de comment on nous envoie les cartons
void Rangement::recupererCartons(std::string fichier) {} //TODO

														 // Tri des cartons fonction de leurs dimensions
void Rangement::triDesCartons(void) {
	int modif=1;
	while (modif) {
		modif = 0;
		for (unsigned int i = 0; i<_cartRang.size() - 1; i++) {

			// Si la dimX du suivant est plus grande que la dimX de l'actuel, on inverse les deux
			if (_cartRang[i]->getDimX()<_cartRang[i + 1]->getDimX()) {
				Carton * tmp = _cartRang[i + 1];
				_cartRang.erase(_cartRang.begin() + i + 1);
				_cartRang.insert(_cartRang.begin() + i, tmp);
				modif = modif + 1;
			}

			// Si la dimX des deux est égale, on regarde les dimY
			else if (_cartRang[i]->getDimX() == _cartRang[i + 1]->getDimX()) {
				// Si la dimY du suivant est plus grande que la dimY de l'actuel, on inverse les deux
				if (_cartRang[i]->getDimY()<_cartRang[i + 1]->getDimY()) {
					Carton * tmp = _cartRang[i + 1];
					_cartRang.erase(_cartRang.begin() + i + 1);
					_cartRang.insert(_cartRang.begin() + i, tmp);
					modif = modif + 1;
				}
				// Si la dimY des deux est égale, on regarde les dimZ
				else if (_cartRang[i]->getDimY() == _cartRang[i + 1]->getDimY()) {
					// SI la dimZ du suivant est plus grande que la dimZ de l'actuel on inverse
					if (_cartRang[i]->getZ()<_cartRang[i + 1]->getZ()) {
						Carton * tmp = _cartRang[i + 1];
						_cartRang.erase(_cartRang.begin() + i + 1);
						_cartRang.insert(_cartRang.begin() + i, tmp);
						modif = modif + 1;
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
bool Rangement::verifMasseLegale(Carton * cartonTest) {
	float nouveauPoid = cartonTest->getMasse() + _contRang[_qContenant]->getMasseActuelle();
	if (nouveauPoid <= _contRang[_qContenant]->getMasseMax()) return true;
	else return false;
}

//										---------------
//										|  AFFICHAGE  |
//										---------------

// Affichage d'un carton et de son contenant respectif
bool Rangement::printCarton(unsigned int i) {
	// Test d'entrée sur i
	if (i > _cartRang.size()) {
		return 0;
	}
	else {
		_cartRang[i]->printCarton();
		std::cout << "Contenant : " << _cartRang[i]->getCont()->getName() << std::endl;
		return 1;
	}
}
// Affichage de tous les cartons et de leur contenant respectif
void Rangement::printCartons(void) {
	unsigned int i = 0;
	while (printCarton(i)) {
		i++;
	}
}

// Affichage d'un contenant et des cartons qui le composent
bool Rangement::printContenant(unsigned int i) {
	// Test d'entrée sur i
	if (i > _contRang.size()) {
		return 0;
	}
	else {
		_contRang[i]->printContenant();
		for (unsigned int u = 0; u < _contRang[i]->_cartons.size(); u++) {
			_contRang[i]->_cartons[u]->printCarton();
			std::cout << std::endl;
			
		}
	}
	return 1;
}

//Méthodes spécialisées de Norbert à Ordonner

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