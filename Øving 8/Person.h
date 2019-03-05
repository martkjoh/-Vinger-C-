#pragma once

#include <string>
#include <ostream>
#include <iostream>
#include <set>
#include <vector>
#include <iomanip>
#include <cstdlib>


using namespace::std;

class Car
{
    private:
        int freeSeats;

    public:
        Car(int numFreeSeats);

        bool hasFreeSeats() const;
        void reserveFreeSeat();
}; 


// A person has a name an an email adress, and may have a car

class Person
{
    private:
        string name;
        string email;
        Car* car;

    public:
        Person(string n, string e, Car* c = nullptr);

        string getName() const;
        string getEmail() const;
        void setEmail(string e);
        bool hasFreeSeats() const;

        // Hvorfor fungerer dette bare med friend?
        friend ostream& operator<<(ostream& os, const Person& p);
};
