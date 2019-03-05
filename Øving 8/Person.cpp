#include "Person.h"


// Class Car
// 
// Implementasjonen av klassen Car

Car::Car(int numFreeSeats): freeSeats{numFreeSeats} {}

bool Car::hasFreeSeats() const {return freeSeats;}

void Car::reserveFreeSeat() {freeSeats--;}

// Class Person
// 
// Implementasjonen av kalssen Person

// Hvorfor burkes det bare referanser her?
ostream& operator << (ostream& os, const Person& p)
{
    os << p.getName() << ": " <<  p.getEmail() << endl;
    if (p.hasFreeSeats()) os << "Has available seats" << endl;
    else os << "Does not have available seats" << endl;
    
    return os;
}
