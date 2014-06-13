#ifndef ARME_H_INCLUDED
#define ARME_H_INCLUDED


#include <iostream>
#include <string>

class Arme
{
    public:

    Arme();
    Arme(std::string nom, int degats);
    void changer(std::string nom, int degats);
    void afficher() const;
    int getDegats() const;


    private:
    std::string m_nom; // Pas de using namespace std, donc il faut mettre std:: devant string.
    int m_degats;
};

#endif // ARME_H_INCLUDED
