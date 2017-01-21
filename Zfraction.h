/*
 * =====================================================================================
 *
 *       Filename:  Zfraction.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  15/01/2017 00:20:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  fredRun14 (fR14), 
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef DEF_ZFRACTION
#define DEF_ZFRACTION

#include <iostream>

  /*
   * =====================================================================================
   *        Class:  Zfraction
   *  Description:  fractions
   * =====================================================================================
   */
  class Zfraction
  {
    public:
      /* ====================  LIFECYCLE     ======================================= */
      Zfraction ();                             /* constructor */
      Zfraction(int numerator);
      Zfraction(int numerator,int denominator);

      /* ====================  ACCESSORS     ======================================= */
      int getNumerator() const;
      int getDenominator() const;
      void setNumerator(int numerator);
      void setDenominator(int denominator);
      /* ====================  MUTATORS      ======================================= */

      void display(std::ostream &flux) const;
    private:
      /* ====================  DATA MEMBERS  ======================================= */
      int m_numerator; 
      int m_denominator; 

  }; /* -----  end of class Zfraction  ----- */

      /* ====================  OPERATORS     ======================================= */
      Zfraction operator+ (Zfraction const& a, Zfraction const& b);
      Zfraction operator* (Zfraction const& a, Zfraction const& b);
      std::ostream& operator<< (std::ostream& flux, Zfraction const& z);
      bool operator==(Zfraction const& a, Zfraction const& b);
      bool operator!=(Zfraction const& a, Zfraction const& b);
      bool operator> (Zfraction const& a, Zfraction const& b);

      /*  ====================  FUNCTIONS     ======================================= */
      int pgcdEuclide (int a, int b); 
      int pgcd(int a, int b);

#endif
