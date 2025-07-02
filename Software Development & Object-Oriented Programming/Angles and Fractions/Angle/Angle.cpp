// Name- Arnav Sharma
// Student Id - 921870432

#include "Angle.h"
#include <stdexcept>
#include <iostream>

// Constructor to initialize the angle to the default value
Angle::Angle() : theta(30) { // Assuming 30 is the default start angle
}

// Public method to change the angle
void Angle::change(int dt) {
    set(theta + dt); // 'theta' should be the member variable
}

// Private method to set the angle, ensuring it is within the valid range
// Private method to set the angle, ensuring it is within the valid range
void Angle::set(int t) {
    if (t < -60) {
        theta = -60;
    } else if (t > 120) {
        theta = 120;
    } else {
        theta = t;
    }
}


// Public method to get the current angle value
int Angle::get(void) {
    return theta; // Return the value of 'theta'
}

// Public method to print the current angle value
void Angle::print(void) {
    std::cout << "angle: " << theta << std::endl; // Match the expected output format
}
