#include <iostream>
#include <string>
#include "personnage.h"

using namespace std;

Personnage::Personnage() : m_vie(100), m_mana(100)
{

}

Personnage::Personnage(string nomArme, int degatsArme) : m_vie(100), m_mana(100), m_arme(nomArme, degatsArme)
{

}

void Personnage::recevoirDegats(int nbDegats)
{
    m_vie-=nbDegats;
    if(m_vie < 0)
    m_vie=0;
}

void Personnage::attaquer(Personnage &cible)
{
    cible.recevoirDegats(m_arme.getDegats());
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_vie+=quantitePotion;
    if(m_vie>100)
    m_vie=100;
}

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
    m_arme.changer(nomNouvelleArme, degatsNouvelleArme);
}

bool Personnage::estVivant() const
{
    if(m_vie>0)
    return true;
    else
    return false;
}

void Personnage::afficherEtat() const
{
    cout << "Vie : " << m_vie << endl;
    cout << "Mana : " << m_mana << endl;
    m_arme.afficher();
}
