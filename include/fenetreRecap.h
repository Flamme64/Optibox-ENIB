//FenetreRecap.h

#ifndef DEF_FENETRERECAP_H
#define DEF_FENETRERECAP_H


#include <QtWidgets/QApplication>
#include <QtWidgets>
#include <QDebug>
#include <QFormLayout>


//#include "mafenetre.h"
#include "carton.h"
#include "contenant.h"

class MaFenetre;


class FenetreRecap : public QWidget // On hérite de QWidget (IMPORTANT)
{
    Q_OBJECT

public:
    FenetreRecap(int largeur, int hauteur);
    FenetreRecap(int largeur, int hauteur, int bidon);
    FenetreRecap(FenetreRecap &f);
    FenetreRecap();

//    MaFenetre maFenetre;
    QPushButton *m_bouton;
    QPushButton * m_boutonDialogue;
    int _largeur;
    int _hauteur;
    QLabel *label1;
    QVBoxLayout *vbox1;
    QVBoxLayout *vbox2;



public slots:
    void fenetreInit();
    void ouvrirDialogue();
    void ajoutChamp(MaFenetre &f);
    int getLargeur() const { return _largeur;}
    int getHauteur() const { return _hauteur;}


private:
};

#endif
