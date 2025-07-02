//Arnav Sharma
//SID - 921870432
#include <iostream>
#include "Aircrew.h"

// Define the constructor for the Aircrew class
Aircrew::Aircrew(std::string name_str) : nm(name_str), flightsTaken(0), hoursWorked(0) {}

// Define the maxHours function for the Aircrew class
const double Aircrew::maxHours(void) const {
    return 60.0; // Assuming all aircrew members have a max of 60 hours per week
}

// Define the name function for the Aircrew class
const std::string Aircrew::name(void) const {
    return nm;
}

// Define the setFlights function for the Aircrew class
void Aircrew::setFlights(int i) {
    flightsTaken = i;
}

// Define the setHours function for the Aircrew class
void Aircrew::setHours(double h) {
    hoursWorked = h;
}

// Define the print function for the Aircrew class
void Aircrew::print(void) const {
    // Output the aircrew's details
    std::cout << type() << ": " << nm << " has operated " << flightsTaken
              << " flights for a total of " << hoursWorked << " hours this week" << std::endl;
    int availableFlights = maxFlights() - flightsTaken;
    std::cout<<"Available flights: "<<availableFlights<<"\n";
    double availableHours = maxHours() - hoursWorked;
    std::cout<<"Available hours: "<<availableHours<<"\n";
}

// Define the destructor for the Aircrew class
Aircrew::~Aircrew() {}

// Define the factory function for creating Aircrew objects
Aircrew* Aircrew::makeAircrew(char ch, std::string name_str) {
    switch(ch) {
        case 'P':
            return new Pilot(name_str);
        case 'A':
            return new Attendant(name_str);
        case 'T':
            return new TaggedAttendant(name_str);
        default:
            return nullptr;
    }
}



    Pilot::Pilot(std::string name_str) : Aircrew(name_str) {}
    const std::string Pilot::type(void) const { return "Pilot"; }
    const int Pilot::maxFlights(void) const { return 5; }




    Attendant::Attendant(std::string name_str) : Aircrew(name_str) {}
    const std::string Attendant::type(void) const  { return "Attendant"; }
    const int Attendant::maxFlights(void) const { return 8; }



    TaggedAttendant::TaggedAttendant(std::string name_str) : Aircrew(name_str) {}
    const std::string TaggedAttendant::type(void) const { return "TaggedAttendant"; }
    const int TaggedAttendant::maxFlights(void) const { return 8; }


void TaggedAttendant::scheduleFlight(int stops, double hours) const {
    double adjustedHours = hours / 2;
    int scheduledFlights = flightsTaken + stops + 1;
    double totalHours = hoursWorked + adjustedHours;

    std::cout << "Attempting to schedule for " << stops << " stop(s) " << hours << " hours flight...\n";

    if (scheduledFlights <= maxFlights() && totalHours <= maxHours()) {
        std::cout << "This crew member can be scheduled\n";
    } else {
        std::cout << "This crew member should be replaced\n";
    }
    std::cout << "Done scheduling " << nm << std::endl;
}

void Aircrew::scheduleFlight(int f, double h) const {
    int scheduledFlights = flightsTaken + f + 1;
    double totalHours = hoursWorked + h;

    std::cout << "Attempting to schedule for " << f << " stop(s) " << h << " hours flight...\n";

    if (scheduledFlights <= maxFlights() && totalHours <= maxHours()) {
        std::cout << "This crew member can be scheduled\n";
    } else {
        std::cout << "This crew member should be replaced\n";
    }
    std::cout << "Done scheduling " << nm << std::endl;
}