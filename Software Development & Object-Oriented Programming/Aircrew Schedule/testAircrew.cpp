//
// testAircrew.cpp
//

#include "Aircrew.h"
#include <iostream>
using namespace std;

int main()
{
  Aircrew *p1 = Aircrew::makeAircrew('P', "Paul");
  p1->setFlights(4);
  p1->setHours(40);
  p1->print();
  p1->scheduleFlight(0,10); //can work
  delete p1;

  Aircrew *p2 = Aircrew::makeAircrew('A', "Allen");
  p2->setFlights(6);
  p2->setHours(20);
  p2->print();
  p2->scheduleFlight(2,15.2); //cannot work
  delete p2;

  Aircrew *p3 = Aircrew::makeAircrew('T', "Tony");
  p3->setFlights(2);
  p3->setHours(50);
  p3->print();
  p3->scheduleFlight(0,16); // can work
  delete p3;
}
