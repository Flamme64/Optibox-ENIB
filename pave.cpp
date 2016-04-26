#include "pave.h"

// Affichage du nom, des coordonées du point et des dimensions
void Pave::printPave(void) {
	std::cout << _name << " (" << _point.getX() << ", " << _point.getY() << ", " << _point.getZ() << " ) (" << getDimX() << ", " << getDimY() << ", " << getDimZ() << " )";
}