//Arnav Sharma
//SID - 921870432

#include "Airline.h"
#include <stdexcept>
#include <iostream>

Airline::Airline(int nA321, int nB777, int nB787) : nAirplanes(nA321 + nB777 + nB787) {
    airplaneList = new Airplane*[nAirplanes];
    int index = 0;
    for (int i = 0; i < nA321; ++i, ++index) {
        airplaneList[index] = new Airplane(10);
        std::cout << "Airplane " << index+1 << " maximum load " << "10" << std::endl;
    }
    for (int i = 0; i < nB777; ++i, ++index) {
        airplaneList[index] = new Airplane(32);
        std::cout << "Airplane " << index+1 << " maximum load " << "32" << std::endl;
    }
    for (int i = 0; i < nB787; ++i, ++index) {
        airplaneList[index] = new Airplane(40);
        std::cout << "Airplane " << index+1 << " maximum load " << "40" << std::endl;
    }
}
Airline::~Airline() {
    for (int i = 0; i < nAirplanes; ++i) {
        std::cout << "deallocating airplane " << i+1 << std::endl;
        delete airplaneList[i];
    }
    delete[] airplaneList;
}
void Airline::addShipment(int size) {
    if (size <= 0) {
        throw std::invalid_argument("must be positive");
    }
    for (int i = 0; i < nAirplanes; ++i) {
        if (airplaneList[i]->addContainers(size)) {
            std::cout << size << " containers added to airplane " << i+1<< std::endl;
            return;
        }
    }
    std::cout << " could not fit " << size << " containers" << std::endl;
}

void Airline::printSummary(void) const {
    std::cout<<"Summary:"<< std::endl;
    for (int i = 0; i < nAirplanes; ++i) {
        if (airplaneList[i]->currentLoad() > 0) {
            std::cout << "airplane "<< i +1 << " " << airplaneList[i]->currentLoad()
                      << "/" << airplaneList[i]->maxLoad() << std::endl;
        }
    }
}