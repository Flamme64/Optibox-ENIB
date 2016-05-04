#include "contenant.h"


// Affichage :
void Contenant::printContenant(void) {
	printPave();
	std::cout << "Massemax :" << getMasseMax();
	// On ne peut afficher les cartons que dans la classe rangement
}

/*
1 - Jacques (RESOLU)
  Il faudrait faire un traitement des coordonnees du contenant. 
  J'ai peur qu'on confonde deux contenants si leurs coordonnees sont toutes a 0.
  
  On les traite separement donc pas de confusion.

*/
