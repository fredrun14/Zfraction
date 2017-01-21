#include <iostream>
#include "Zfraction.h"

using namespace std;

int main()
{

  Zfraction a(4,5); //Declare a fraction equal to 4/5
  Zfraction b(2); //Declare a fraction equal to 2/1 (is 2)
  Zfraction c,d; //Declare two fraction equal to 0

  a.display(cout);
  b.display(cout);

  c = a+b; //Calculated 4/5 + 2/1 = 14/5
  c.display(cout);
  d = a*b; //Calculated 4/5 * 2/1 = 8/5
  d.display(cout);
  cout << a << " + " << b << " = " << c << endl;
  cout << a << " * " << b << " = " << d << endl;
   if(a > b)
    cout << "a Is greater than b." << endl;
  else if(a==b)
    cout << "a is equal to b." << endl;
  else
    cout << "a is smaller than b." << endl;

   return 0;
} 
