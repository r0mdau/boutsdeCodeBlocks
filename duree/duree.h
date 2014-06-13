#ifndef DUREE_H_INCLUDED
#define DUREE_H_INCLUDED

class Duree
{
    public:
    Duree(int heures = 0, int minutes = 0, int secondes = 0);
    Duree& operator-=(Duree const& duree);
    Duree& operator+=(Duree const& duree);
    void afficher() const;


    private:
    int m_heures;
    int m_minutes;
    int m_secondes;

};
Duree operator+(Duree const& a, Duree const& b);
Duree operator-(Duree const& a, Duree const& b);
#endif // DUREE_H_INCLUDED
