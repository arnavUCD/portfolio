//
// Airplane.h
//
// Do not modify this file
#ifndef AIRPLANE_H
#define AIRPLANE_H
class Airplane
{
  public:
    Airplane(int n);
    int maxLoad(void) const;
    int currentLoad(void) const;
    bool addContainers(int n);
  private:
    const int maxContainers;
    int numContainers;
};
#endif
