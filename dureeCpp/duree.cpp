#include <iostream>
#include "duree.h"


Duree::Duree(int heures, int minutes, int secondes) : m_heures(heures), m_minutes(minutes), m_secondes(secondes)
{

}

Duree Duree::operator+(const Duree &duree)
{
    int heures = m_heures;
    int minutes = m_minutes;
    int secondes = m_secondes;

    // 1 : ajout des secondes
    secondes += duree.m_secondes; // Exceptionnellement autorisé car même classe
    // Si le nombre de secondes dépasse 60, on rajoute des minutes et on met un nombre de secondes inférieur à 60
    minutes += secondes / 60;
    secondes %= 60;

    // 2 : ajout des minutes
    minutes += duree.m_minutes;
    // Si le nombre de minutes dépasse 60, on rajoute des heures et on met un nombre de minutes inférieur à 60
    heures += minutes / 60;
    minutes %= 60;

    // 3 : ajout des heures
    heures += duree.m_heures;

    // Création de l'objet resultat et retour
    Duree resultat(heures, minutes, secondes);
    return resultat;
}
