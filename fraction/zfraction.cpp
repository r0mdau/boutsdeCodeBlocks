#include <iostream>
#include "zfraction.h"

ZFraction::ZFraction(): m_numerateur(0), m_denominateur(0)
{

}

ZFraction::Zfraction(int numerateur, int denominateur): m_numerateur(numerateur), m_denominateur(denominateur)
{

}
ZFraction::Zfraction(int numerateur): m_numerateur(numerateur), m_denominateur(1)
{
}

ZFraction operator+(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a);
    copie += b;
    return copie;
}

ZFraction& ZFraction::operator+=(const ZFraction &duree2)
{
    if(m_denominateur==duree2.m_denominateur)
    {
        m_numerateur+=duree2.m_numerateur;
    }
    else
    {
        m_denominateur*=duree2.m_denominateur;
        m_numerateur*=duree2.m_denominateur;
        m_numerateur+=duree2.m_numerateur;
    }

    return *this;
}

ZFraction operator*(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a);
    copie *= b;
    return copie;
}


ZFraction& ZFraction::operator*=(const ZFraction &duree2)
{
    m_denominateur*=duree2.m_denominateur;
    m_numerateur*=duree2.m_numerateur;
}
