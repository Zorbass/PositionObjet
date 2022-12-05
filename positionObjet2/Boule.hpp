//Ce fichier contient la d�claration des m�thodes et attributs de la classe boule.
//La classe boule nous est utile pour modifier les attributs des boules, notammentsa vitesse.
//Dans cette classe sont aussi d�finis les m�thodes relatives au moteur physique, notamment les m�thodes de d�placement, collision boule-table, collision boule-boule.

#ifndef BOULE_HPP_INCLUDED
#define BOULE_HPP_INCLUDED

#include <iostream>
#include <string>
#include "Vecteur.hpp"

using namespace std;

class Boule
{
    public:

    Boule();
    Boule(std::string numero, std::string type, double x, double y);

    void shoot();

    void afficher();

    double positionX();

    double positionY();

    double intensiteeV();

    double intensiteeA();

    double angle();

    string typeBoule();

    bool boulband();

    bool empochee();

    bool bouledejaempochee();

    bool boulesempochees();

    bool collisionBoule();

    void verificationbouledejaempochee();

    void replacementblanche();

    void changerVitesse(double x, double y);

    void deplacemelent(double f);

    void empochage();

    void collBoule(Boule &cible);

    void collTable();


    private:

    std::string m_numero;
    std::string m_type;
    double m_x; //Position de la boule sur l'axe x.
    double m_y; //Position de la boule sur l'axe y.
    double m_t; //Temps de d�placement de la boule.
    Vecteur acceleration; //Vecteur d'acc�l�ration subit par une boule.
    double m_r = 0.0286; //Rayon d'une boule.
    double m_d; //D�placement de la r�sultante.
    Vecteur vitesse; //Vecteur de la vitesse d'une boule:
    bool m_empochee = false; //D�finit si la boule est empoch�e.
    bool m_dejaempochee =false; //D�finit si la boule la boule est deja empoch�e.
    bool boulebande = false; //D�finit si la boule la boule a touch� une bande lors du tour.
    bool collboule =false; //D�finit si la boule la boule a touch� une autre boule.


};

#endif
