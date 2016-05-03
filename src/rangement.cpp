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
		return 1;
	}
}
