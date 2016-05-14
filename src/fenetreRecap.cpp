//FenetreRecap.cpp

#include "fenetreRecap.h"
//#include "mafenetre.h"

#include <QApplication>
#include <QtWidgets>
#include <QDoubleSpinBox>
#include <QDebug>
#include <QFormLayout>

#define chargeMax = 64295169;


                                                                // // // // // //  //
                                                                // Constructeurs  //
                                                                // // // // // // //


FenetreRecap::FenetreRecap():_largeur(250),_hauteur(300){}

FenetreRecap::FenetreRecap(int largeur, int hauteur) : QWidget()
{
    this->setWindowTitle("Récap des cartons/conteneurs");

    //this->maFenetre = MaFenetre(10,10);
    _largeur = largeur;
    _hauteur = hauteur;
    setFixedSize(_largeur, _hauteur);
    // Construction du bouton
    m_bouton = new QPushButton("Quitter", this);

    m_bouton->setFont(QFont("Verdana", 10));


    // 1 : Créer le QTabWidget
    QTabWidget *onglets = new QTabWidget(this);
    onglets->setGeometry(0, 0, _largeur, _hauteur);

    // 2 : Créer les pages, en utilisant un widget parent pour contenir chacune des pages
    QWidget *page1 = new QWidget;
    QWidget *page2 = new QWidget;

    // 3 : Créer le contenu des pages de widgets

    // Page 1
    this->label1 = new QLabel("Nombre", this);
    QLabel *label2 = new QLabel("dimX", this);
    QLabel *label3 = new QLabel("dimY", this);
    QLabel *label4 = new QLabel("dimZ", this);
    this->vbox1 = new QVBoxLayout;

    vbox1->addWidget(label1);
    vbox1->addWidget(label2);
    vbox1->addWidget(label3);
    vbox1->addWidget(label4);


    page1->setLayout(vbox1);

    // Page 2
    QLabel *label10 = new QLabel("Nombre", this);
    QLabel *label11 = new QLabel("dimX", this);
    QLabel *label12 = new QLabel("dimY", this);
    QLabel *label13 = new QLabel("dimZ", this);
    QVBoxLayout *vbox2 = new QVBoxLayout;

/*    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget((label10));
    layout->addWidget((label11));
    layout->addWidget((label12));
    layout->addWidget((label13))*/;

    vbox2->addWidget(label10);
    vbox2->addWidget(label11);
    vbox2->addWidget(label12);
    vbox2->addWidget(label13);


    page2->setLayout(vbox2);


    // 4 : ajouter les onglets au QTabWidget, en indiquant la page qu'ils contiennent
    onglets->addTab(page1, "Conteneurs");
    onglets->addTab(page2, "Cartons");


}


FenetreRecap::FenetreRecap(FenetreRecap &f)
{
    _largeur            = f.getLargeur();
    _hauteur            = f.getHauteur();
}



//FenetreRecap::FenetreRecap(int &largeur, int &hauteur, int &bidon)        //constructeur test
//{
//    &_largeur            =&largeur;
//    &_hauteur            = &hauteur;
//    bidon = 1;
//}


                                                            // // // // // //  //
                                                            //      Méthodes   //
                                                            // // // // // // //


void FenetreRecap::ouvrirDialogue()
{
    QString pseudo = QInputDialog::getText(this, "Pseudo", "Quel est votre pseudo ?");
}


// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

void FenetreRecap::fenetreInit()
{
    //bidon
    //QObject::connect(this, SIGNAL(ajoutChamp()), this, SLOT(ajoutChamp()));
    QString message = "FenetreRecapInit";
    qDebug()<<message;
}

void FenetreRecap::ajoutChamp(MaFenetre &f)
{

    QString message = "implémentation du tableau dans FenetreRecap";
    qDebug()<<message;
}
