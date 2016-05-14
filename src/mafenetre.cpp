//MaFenetre.cpp

#include "mafenetre.h"
//#include "fenetreRecap.h"

#include <QApplication>
#include <QtWidgets>
#include <QDoubleSpinBox>
#include <QDebug>
#include <sstream>

                                            // // // // // //  //
                                            // Constructeurs  //
                                            // // // // // // //
MaFenetre::MaFenetre(int largeur, int hauteur) : QWidget()
{
    this->setWindowTitle("Fenetre principale");
    // test
    QString s = "début constructeur Mafenetre";
    qDebug() << s;
    _largeur = largeur;
    _hauteur = hauteur;
    setFixedSize(_largeur, _hauteur);

    // Construction du bouton
    btn_suivant = new QPushButton("ok", this);

    btn_suivant->setFont(QFont("Verdana", 10));

    QWidget::connect(btn_suivant, SIGNAL(pressed()), this, SLOT(fenetreInit()));


    //        //bouton de dialogue

    m_boutonDialogue = new QPushButton("Cartons", this);
    m_boutonDialogue->move(0,0);

    m_boutonDialogue = new QPushButton("Conteneurs", this);
    m_boutonDialogue->move(0,50);

    // test
    QString s2 = "suite constructeur";
    qDebug() << s2;
    // 1 : Créer le QTabWidget
    QTabWidget *onglets = new QTabWidget(this);
    onglets->setGeometry(0, 0, _largeur, _hauteur);

    // 2 : Créer les pages, en utilisant un widget parent pour contenir chacune des pages
    QWidget *page1 = new QWidget;
    QWidget *page2 = new QWidget;
    QLabel *page3 = new QLabel; // Comme un QLabel est aussi un QWidget (il en hérite), on peut aussi s'en servir de page

    // 3 : Créer le contenu des pages de widgets

    // Page 1
    //une liste de conteneurs "de base"
    this->listeConteneurs = new QComboBox(this);
    this->listeConteneurs ->addItem("conteneurs 1");
    this->listeConteneurs ->addItem("conteneurs 2");
    this->listeConteneurs ->addItem("conteneurs 3");
    this->listeConteneurs ->addItem("conteneurs 4");


    QLabel *label1 = new QLabel("Nombre de conteneurs", this);
    QLabel *label2 = new QLabel("Dimensions des conteneurs",this);
    QLabel *label3= new QLabel("poids max",this);

    this->conteneurs= new QSpinBox ;
    this->dimensionX= new QSpinBox ;
    this->dimensionY= new QSpinBox ;
    this->dimensionZ= new QSpinBox ;
    this->poidsMax =  new QSpinBox;
    btn_suivant = new QPushButton("Suivant", this);
    QVBoxLayout *vbox1 = new QVBoxLayout;

    vbox1->addWidget(this->listeConteneurs);
    vbox1->addWidget((label1));
    vbox1->addWidget(this->conteneurs);
    vbox1->addWidget(label2);
    vbox1->addWidget(this->dimensionX);
    vbox1->addWidget(this->dimensionY);
    vbox1->addWidget(this->dimensionZ);
    vbox1->addWidget(label3);
    vbox1->addWidget(this->poidsMax);
    vbox1->addWidget(btn_suivant);

    page1->setLayout(vbox1);



    // Page 2
    //une liste de Cartons "de base"
    this->listeCartons= new QComboBox(this);
    this->listeCartons->addItem("carton 1");
    this->listeCartons->addItem("carton 2");
    this->listeCartons->addItem("carton 3");
    this->listeCartons->addItem("carton 4");

    QLabel *label10 = new QLabel("Nombre de cartons", this);
    this->cartons = new QSpinBox ;
    QLabel *label11 = new QLabel("Dimensions des cartons",this);
    this->DimensionX = new QSpinBox ;
    this->DimensionY= new QSpinBox ;
    this->DimensionZ= new QSpinBox ;
    this->fragil= new QRadioButton("Fragile");
    this->resistant= new QRadioButton("Résistant");
    this->btn_suivant2 = new QPushButton("Suivant", this);
    QVBoxLayout *vbox2 = new QVBoxLayout;

    vbox2->addWidget(listeCartons);
    vbox2->addWidget((label10));
    vbox2->addWidget(this->cartons);
    vbox2->addWidget(label11);
    vbox2->addWidget(this->DimensionX);
    vbox2->addWidget(this->DimensionY);
    vbox2->addWidget(this->DimensionZ);
    vbox2->addWidget(this->fragil);
    vbox2->addWidget(this->resistant);


    vbox2->addWidget(btn_suivant2);


    page2->setLayout(vbox2);

    // Page 3
    QPushButton *bouton1 = new QPushButton("ouvrir la vidéo?");
    QVBoxLayout *vbox3 = new QVBoxLayout;
    vbox3->addWidget(bouton1);

    page3->setLayout(vbox3);



    // 4 : ajouter les onglets au QTabWidget, en indiquant la page qu'ils contiennent
    onglets->addTab(page1, "Conteneurs");
    onglets->addTab(page2, "Cartons");
    onglets->addTab(page3, "Vidéo");

    this->fenetreInit();
}

//MaFenetre::MaFenetre(const MaFenetre &f)                //constructeur par recopie
//{
//    _largeur            = f.getLargeur();
//    _hauteur            = f.getHauteur();
//}


MaFenetre::MaFenetre():_largeur(250),_hauteur(300){}


// On met ici le code d'ouverture des boîtes de dialogue
//    void MaFenetre::ouvrirDialogue()
//    {
//            QMessageBox::information(this, "renseignements", "Veuillez renseigner votre cas particulier");
//     }


                                                            // // // // // //  //
                                                            //      Méthodes   //
                                                            // // // // // // //


void MaFenetre::ouvrirDialogue()
{
    QString pseudo = QInputDialog::getText(this, "Pseudo", "Quel est votre pseudo ?");
}

// // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // // //

void MaFenetre::fenetreInit()
{
    QString message = "on est dans la fonction fenetreInit de MaFenetre";
    qDebug()<<message;

    emit ajoutChamp();   // on envoie un signal pour ajouter les caractérisitques rentré
    QWidget::connect(btn_suivant, SIGNAL(pressed()), this, SLOT(recupCaracContenant())); // on connect le bouton "suivant" des contenant à la fonction recupCaracContenant
    QWidget::connect(btn_suivant2, SIGNAL(pressed()), this, SLOT(recupCaracCarton())); // on connect le bouton "suivant" des contenant à la fonction recupCaracContenant

    QWidget::connect(btn_suivant, SIGNAL(pressed()), this, SLOT(resetConteneurs())); // on connect le bouton "suivant" des contenant à la fonction ResetContenants
    QWidget::connect(btn_suivant2, SIGNAL(pressed()), this, SLOT(resetCartons())); // on connect le bouton "suivant" des cartons à la fonction ResetCartons
}


void MaFenetre::recupCaracContenant()
{
    QString message = "on est dans la fonction recupCaracContenant";
    qDebug()<<message;
    while (this->conteneurs->value() >0)
    {
        int i = this->conteneurs->value() ;
        i = i-1;
        this->conteneurs->setValue(i);
        VecteurContenants.push_back(Contenant(this->poidsMax->value(), this->dimensionX->value(), this->dimensionY->value(),this->DimensionZ->value()));
        qDebug()<<VecteurContenants[0].getDimX();

    }
    QString message2 = "on implémente le TABLEAU";
    qDebug()<<message2;

    QLabel *label64 = new QLabel();
//    int multiplicite= this->conteneurs->value();
//    label1->setNum(multiplicite);

//    fenetreRecap.vbox1->addWidget(label64);

}

void MaFenetre::recupCaracCarton()
{
    QString message = "on est dans la fonction recupCaracCarton";
    qDebug()<<message;
    while (this->cartons->value() >0)
    {
        int i = this->cartons->value() ;
        i = i-1;
        this->cartons->setValue(i);
        VecteurCartons.push_back(Carton(this->dimensionX->value(), this->dimensionY->value(),this->DimensionZ->value()));
    }
}

void MaFenetre::resetConteneurs()
{
    QString message = "on reset les contenants";
    qDebug()<<message;
    qDebug()<<this->dimensionX->value();
    this->dimensionX->setValue(0);
    this->dimensionY->setValue(0);
    this->dimensionZ->setValue(0);
    this->poidsMax->setValue(0);
    this->conteneurs->setValue(0);

}


void MaFenetre::resetCartons()
{
    QString message = "on reset les cartons";
    qDebug()<<message;
    this->cartons->setValue(0);
    this->DimensionX->setValue(0);
    this->DimensionY->setValue(0);
    this->DimensionZ->setValue(0);
//    this->poids->setValue(0);
//    this->masse->setValue(0);

}

