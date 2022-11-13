//Ce fichier contient la déclaration des méthodes et attributs de la classe boule.
//La classe boule nous est utile pour modifier les attributs des boules, notammentsa vitesse.
//Dans cette classe sont aussi définis les méthodes relatives au moteur physique, notamment les méthodes de déplacement, collision boule-table, collision boule-boule.

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
    double m_t; //Temps de déplacement de la boule.
    Vecteur acceleration; //Vecteur d'accélération subit par une boule.
    double m_r = 0.0286; //Rayon d'une boule.
    double m_d; //Déplacement de la résultante.
    Vecteur vitesse; //Vecteur de la vitesse d'une boule:
    bool m_empochee = false; //Définit si la boule est empochée.
    bool m_dejaempochee =false; //Définit si la boule la boule est deja empochée.
    bool boulebande = false; //Définit si la boule la boule a touché une bande lors du tour.
    bool collboule =false; //Définit si la boule la boule a touché une autre boule.


};

#endif
