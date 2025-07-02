// Name- Arnav Sharma
// Student Id - 921870432

#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
public:
    Fraction(int numerator = 0, int denominator = 1); // Default values provided

    // Overloaded binary operators for Fraction operations
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    // Overloaded unary minus operator
    Fraction operator-() const;

    // Overloaded binary operators for Fraction with int operations
    friend Fraction operator+(int lhs, const Fraction& rhs);
    friend Fraction operator-(int lhs, const Fraction& rhs);
    friend Fraction operator*(int lhs, const Fraction& rhs);
    friend Fraction operator/(int lhs, const Fraction& rhs);

    // Overloaded assignment operator
    Fraction& operator=(const Fraction& other);

    // Getter methods
    int getNum() const;
    int getDen() const;

    // Friend function for stream output
    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction);

private:
    int numerator;
    int denominator;

    void reduce(); // Helper function to reduce the fraction
};

#endif // FRACTION_H
