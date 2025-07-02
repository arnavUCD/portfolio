// Name- Arnav Sharma
// Student Id - 921870432
#include "Fraction.h"
#include <stdexcept>
#include <numeric> // For std::gcd in C++17 and later

Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("zero denominator");
    }
    reduce();
}

void Fraction::reduce() {
    int gcd = std::gcd(numerator, denominator); // C++17 and later
    numerator /= gcd;
    denominator /= gcd;
}

Fraction Fraction::operator+(const Fraction& other) const {
    return Fraction(numerator * other.denominator + other.numerator * denominator,
                    denominator * other.denominator);
}

Fraction Fraction::operator-(const Fraction& other) const {
    return Fraction(numerator * other.denominator - other.numerator * denominator,
                    denominator * other.denominator);
}

Fraction Fraction::operator*(const Fraction& other) const {
    return Fraction(numerator * other.numerator, denominator * other.denominator);
}

Fraction Fraction::operator/(const Fraction& other) const {
    return Fraction(numerator * other.denominator, denominator * other.numerator);
}

Fraction Fraction::operator-() const {
    return Fraction(-numerator, denominator);
}

Fraction& Fraction::operator=(const Fraction& other) {
    numerator = other.numerator;
    denominator = other.denominator;
    return *this;
}

int Fraction::getNum() const {
    return numerator;
}

int Fraction::getDen() const {
    return denominator;
}

// Overloaded operators for integer and Fraction
Fraction operator+(int lhs, const Fraction& rhs) {
    return Fraction(lhs) + rhs;
}

Fraction operator-(int lhs, const Fraction& rhs) {
    return Fraction(lhs) - rhs;
}

Fraction operator*(int lhs, const Fraction& rhs) {
    return Fraction(lhs) * rhs;
}

Fraction operator/(int lhs, const Fraction& rhs) {
    if (rhs.getNum() == 0) {
        throw std::invalid_argument("Division by zero.");
    }
    return Fraction(lhs) / rhs;
}

//To represent the fraction as whole number when the denominator is 1.
std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
    if (fraction.getDen() == 1) {
        os << fraction.getNum();
    } else {
        os << fraction.getNum() << '/' << fraction.getDen();
    }
    return os;
}