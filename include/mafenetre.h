//MaFenetre.h

#ifndef DEF_MAFENETRE_H
#define DEF_MAFENETRE_H

#include <QApplication>
#include <QtWidgets>
#include <QPushButton>
#include <QMessageBox>
#include <QInputDialog>
#include <QString>
#include <QIcon>
#include <QSpinBox>
#include <QApplication>
#include <vector>



#include "point.h"
#include "Pave.h"
#include "carton.h"
#include "contenant.h"
#include "fenetreRecap.h"

using namespace std;
//class FenetreRecap;

class MaFenetre : public QWidget // On hérite de QWidget (IMPORTANT)
{
    Q_OBJECT

public:
    MaFenetre(int largeur, int hauteur);
//    MaFenetre( const MaFenetre &f);
    MaFenetre();


    QPushButton *btn_suivant;
    QPushButton *btn_suivant2;
    QLCDNumber *m_lcd;
    QSlider *m_slider;
    QPushButton * m_boutonDialogue;
    int _largeur;
    int _hauteur;
    QSpinBox* conteneurs;
    QSpinBox*dimensionX ;
    QSpinBox*dimensionY;
    QSpinBox*dimensionZ ;
    QSpinBox* cartons;
    QSpinBox*DimensionX ;
    QSpinBox*DimensionY;
    QSpinBox*DimensionZ;
    QSpinBox*poidsMax;
    QRadioButton*fragil;
    QRadioButton*resistant;
    QSpinBox*masse;
    QSpinBox*poids;
    QComboBox *listeConteneurs ;
    QComboBox *listeCartons ;
    vector<Carton> VecteurCartons;
    vector<Contenant> VecteurContenants;
    FenetreRecap fenetreRecap;



public slots:
    void ouvrirDialogue();
    void fenetreInit();
    void recupCaracContenant();
    void recupCaracCarton();
    void resetConteneurs();
    void resetCartons();
//    void reset(FenetreRecap &f);


    //Acesseurs & Mutateurs s'il faut
    int getLargeur() const { return _largeur;}
    int getHauteur() const { return _hauteur;}
    int getCartons() const { return this->cartons->value();}

signals:
    void ajoutChamp();

private:


};

#endif
