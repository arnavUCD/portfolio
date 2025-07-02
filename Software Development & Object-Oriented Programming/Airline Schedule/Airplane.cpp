//Arnav Sharma
//SID - 921870432

#include "Airplane.h"

Airplane::Airplane(int n) : maxContainers(n), numContainers(0) {}

int Airplane::maxLoad(void) const {
    return maxContainers;
}

int Airplane::currentLoad(void) const {
    return numContainers;
}

bool Airplane::addContainers(int n) {
    if (n + numContainers > maxContainers) {
        return false;
    }
    numContainers += n;
    return true;
}