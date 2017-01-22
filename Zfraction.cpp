/*
 * =====================================================================================
 *
 *       Filename:  Zfraction.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/01/2017 00:34:09
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  fredRun14 (fR14), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include "Zfraction.h"

using namespace std;


/* ############################### the constructors  ############################### */
Zfraction::Zfraction() : m_numerator(0), m_denominator(1)
{
}

Zfraction::Zfraction( int numerator) : m_numerator(numerator), m_denominator(1)
{
}

Zfraction::Zfraction( int numerator, int denominator) : m_numerator(numerator), m_denominator(denominator)
{
}


/* ############################### the accessors     ############################### */
int Zfraction::getNumerator() const
{
  return m_numerator;
}

int Zfraction::getDenominator() const
{
  return m_denominator;
}

void Zfraction::setNumerator( int numerator)
{
  m_numerator = numerator;
}

void Zfraction::setDenominator(int denominator)
{
  if (denominator == 0)
    m_denominator = 1;
  else
    m_denominator = denominator;
}

/* ############################### the methods       ############################### */
void Zfraction::display (ostream &flux) const
{
  if (m_denominator == 1 )
    flux << m_numerator << endl;
  else
    flux << m_numerator << "/" << m_denominator << endl;
}

/* simplification à l'aide du pgcd */
void Zfraction::simplify()
{
  int i_pgcd = pgcd (m_numerator,m_denominator);
  m_numerator = m_numerator / i_pgcd;
  m_denominator = m_denominator / i_pgcd; 
}
/* ############################### the operators     ############################### */
ostream &operator<< (ostream &flux, Zfraction const& z)
{
  if (z.getDenominator() == 1)
    flux << z.getNumerator();
  else
    flux << z.getNumerator() << "/" << z.getDenominator();
  return flux; 
}

bool operator== (Zfraction const& a, Zfraction const& b)
{
  if (a.getNumerator() == b.getNumerator() && a.getDenominator() == b.getDenominator())
    return true;
  else
    return false;
}

bool operator!= (Zfraction const& a, Zfraction const& b)
{
 return !(a==b);
}

bool operator> (Zfraction const& a, Zfraction const& b)
{
 return ((a.getNumerator()/a.getDenominator())>(b.getNumerator()/b.getDenominator()));
}
/*
 *--------------------------------------------------------------------------------------
 * Description:  Arithmetic operator  +
 * A/B + C/D = (A*D)+(C*B)/(B*D) with A/B a Zfraction and C/D a Zfraction
 *--------------------------------------------------------------------------------------
 */
Zfraction operator+ (Zfraction const& a, Zfraction const& b)
{
  Zfraction resultat;
  resultat.setNumerator ((a.getNumerator()* b.getDenominator()) + (b.getNumerator()*a.getDenominator()));
  resultat.setDenominator((a.getDenominator()*b.getDenominator()));
  return resultat;
}

/*
 *--------------------------------------------------------------------------------------
 * Description:  Arithmetic operator  *
 * A/B * C/D = (A*C)/(B*D) 
 *--------------------------------------------------------------------------------------
 */
Zfraction operator* (Zfraction const& a, Zfraction const& b)
{
  Zfraction resultat;
  resultat.setNumerator((a.getNumerator() * b.getNumerator()));
  resultat.setDenominator((a.getDenominator()*b.getDenominator()));
  return resultat;
}


/*
 *--------------------------------------------------------------------------------------
 * Description:  PGCD and Algorithm of successive subtractions
 *--------------------------------------------------------------------------------------
 */
int pgcd (int a,int b)
{
  while (a!=b)
  {
    if (a>b)
      a-=b;
    else
      b-=a; 
  }
  return a;
}


/*
 *--------------------------------------------------------------------------------------
 * Description:  PGCD and Algorithm of euclide   
 *--------------------------------------------------------------------------------------
 */
int pgcdEuclide (int a, int b)
{
  if (b==0)
    return a;
  else
    return pgcdEuclide (b, a%b);
}


/*
 *--------------------------------------------------------------------------------------
 * Description:  PPCM starting from pgcd
 *--------------------------------------------------------------------------------------
 */
int ppcm (int a,int b)
{
  return (a*b) / pgcd(a,b);
}
