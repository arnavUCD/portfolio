//
// Aircrew.h
//
#ifndef AIRCREW_H
#define AIRCREW_H
#include <string>

class Aircrew
{
  public:
    Aircrew(std::string name_str);
    virtual const std::string type(void) const = 0;
    virtual const int maxFlights(void) const = 0;
    const double maxHours(void) const;
    const std::string name(void) const;
    void setFlights(int i);
    void setHours(double h);
    void print(void) const;
    virtual void scheduleFlight(int f, double h) const;
    static Aircrew* makeAircrew(char ch, std::string name_str);
    virtual ~Aircrew(void);
  protected:
    const std::string nm;
    int flightsTaken;
    double hoursWorked;
};

class Pilot: public Aircrew
{
  public:
    Pilot(std::string name_str);
    virtual const std::string type(void) const;
    virtual const int maxFlights(void) const;
};

class Attendant: public Aircrew
{
  public:
    Attendant(std::string name_str);
    virtual const std::string type(void) const;
    virtual const int maxFlights(void) const;
};

class TaggedAttendant: public Aircrew
{
  public:
    TaggedAttendant(std::string name_str);
    virtual const std::string type(void) const;
    virtual const int maxFlights(void) const;
    virtual void scheduleFlight(int f, double h) const;
};
#endif
