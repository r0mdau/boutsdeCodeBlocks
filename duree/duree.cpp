#include <iostream>
#include "duree.h"

using namespace std;

Duree::Duree(int heures, int minutes, int secondes) : m_heures(heures), m_minutes(minutes), m_secondes(secondes)
{

}

Duree operator+(Duree const& a, Duree const& b)
{
    Duree copie(a);
    copie += b;
    return copie;
}
Duree operator-(Duree const& a, Duree const& b)
{
    Duree copie(a);
    copie -= b;
    return copie;
}

Duree& Duree::operator+=(const Duree &duree2)
{
    // 1 : ajout des secondes
    m_secondes += duree2.m_secondes; // Exceptionnellement autoris� car m�me classe
    // Si le nombre de secondes d�passe 60, on rajoute des minutes et on met un nombre de secondes inf�rieur � 60
    m_minutes += m_secondes / 60;
    m_secondes %= 60;

    // 2 : ajout des minutes
    m_minutes += duree2.m_minutes;
    // Si le nombre de minutes d�passe 60, on rajoute des heures et on met un nombre de minutes inf�rieur � 60
    m_heures += m_minutes / 60;
    m_minutes %= 60;

    // 3 : ajout des heures
    m_heures += duree2.m_heures;

    return *this;
}

Duree& Duree::operator-=(const Duree &duree2)
{
    // 1 : ajout des secondes
    m_secondes -= duree2.m_secondes; // Exceptionnellement autoris� car m�me classe
    // Si le nombre de secondes d�passe 60, on rajoute des minutes et on met un nombre de secondes inf�rieur � 60
    m_minutes -= m_secondes / 60;
    m_secondes %= 60;

    // 2 : ajout des minutes
    m_minutes -= duree2.m_minutes;
    // Si le nombre de minutes d�passe 60, on rajoute des heures et on met un nombre de minutes inf�rieur � 60
    m_heures -= m_minutes / 60;
    m_minutes %= 60;

    // 3 : ajout des heures
    m_heures -= duree2.m_heures;

    return *this;
}

void Duree::afficher() const
{
    cout<<"H : " << m_heures<<endl<<"Minutes : "<<m_minutes<<endl<<"Secondes : "<<m_secondes<<endl;
}
