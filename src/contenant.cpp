#include "contenant.h"


// Affichage :
void Contenant::printContenant(void) {
	printPave();
	std::cout << "Massemax :" << getMasseMax();
	// On ne peut afficher les cartons que dans la classe rangement
}


/*
1 - Jacques (RESOLU)
  Il faudrait faire un traitement des coordonnées du contenant. 
  J'ai peur qu'on confonde deux contenants si leurs coordonnées sont toutes à 0.
  
  On les traite séparément donc pas de confusion.

*/
