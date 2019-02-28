#include "Carpool.h"

// Class Car
// 
// Implementasjonen av klassen Car

Car::Car(int numFreeSeats): freeSeats{numFreeSeats} {}

bool Car::hasFreeSeats() const {return freeSeats;}

void Car::reserveFreeSeat() {freeSeats--;}


// Class Person
// 
// Implementasjonen av kalssen Person

Person::Person(string n, string e, Car* c): name{n}, email{e}, car{c} {}

// Hvorfor burkes det bare referanser her?
ostream& operator<<(ostream& os, const Person& p)
{
    os << p.getName() << ": " <<  p.getEmail() << endl;
    if (p.hasFreeSeats()) os << "Has available seats" << endl;
    else os << "Does not have available seats" << endl;
    
    return os;
}

string Person::getName() const {return name;}

string Person::getEmail() const {return email;}

void Person::setEmail(string e) {email = e;}

bool Person::hasFreeSeats() const {return car && car->hasFreeSeats();}