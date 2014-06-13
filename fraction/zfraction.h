#ifndef ZFRACTION_H_INCLUDED
#define ZFRACTION_H_INCLUDED

class ZFraction
{
    public:

    ZFraction();
    ZFraction(int numerateur, int denominateur);
    ZFraction(int numerateur);
    ZFraction& operator+=(const ZFraction &duree);
    ZFraction& operator*=(const ZFraction &duree);

    private:

    int m_numerateur;
    int m_denominateur;

};
ZFraction operator+(ZFraction const& a, ZFraction const& b);
ZFraction operator*(ZFraction const& a, ZFraction const& b);

#endif // ZFRACTION_H_INCLUDED
