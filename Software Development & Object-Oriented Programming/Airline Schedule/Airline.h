//
// Airline.h
//
// Do not modify this file
#ifndef AIRLINE_H 
#define AIRLINE_H
#include "Airplane.h"
class Airline 
{
  public:
  Airline(int nA321, int nB777, int nB787);
  ~Airline(void);
  void addShipment(int size);
  void printSummary(void) const;

  private:
  const int nAirplanes;
  Airplane** airplaneList;
};
#endif
