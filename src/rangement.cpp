#include "rangement.h"

//										----------------
//										|  ACCESSEURS  |
//										----------------

// Par nom
// Par dimension : si une des dimensions du pavé correspond

//	----------------------------
//	-  Accesseurs des cartons  -
//	----------------------------

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


//	-----------------------------
//	- Accesseurs des contenants -
//	-----------------------------

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


//	-----------------------------------
//	-  Accesseurs des espaces libres  -
//	-----------------------------------

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