//
// scheduling.cpp
//

#include "Aircrew.h"
#include <iostream>
using namespace std;

int main()
{
  char ch;
  string s;
  cin >> ch >> s;
  while (cin)
  {
    Aircrew *p = Aircrew::makeAircrew(ch,s);
    if (p != nullptr )
    {
      int f;
      double h;
      cin >> f >> h;
      p->setFlights(f);
      p->setHours(h);

      cin >> f >> h;
      p->print();
      p->scheduleFlight(f, h);

      cin >> ch >> s;
    }
    else
    {
      cout << "unknown aircrew type" << endl;
      return 1;
    }
    delete p;
  }
}
