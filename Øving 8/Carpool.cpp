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


// Class Meeting
//
// Implementasjon av Meeting

set<const Meeting*> Meeting::meetings;

ostream& operator << (ostream& os, const Meeting& m)
{
    os << setw(10) << "Subject: " << m.getSubject() << endl;
    os << setw(10) << "Leader: " << m.getLeader() << endl;
    os << setw(10) << "Location: " << m.getLeader() << endl;
    os << "From " << m.getStartTime() << " to " << m.getEndTime() << endl; 
    return os;
}

Meeting::Meeting(int dayIn, int startTimeIn, int endTimeIn, 
    Campus locationIn, string subjectsIn, Person* leaderIn):
    day{dayIn}, startTime{startTimeIn}, endTime{endTimeIn}, location{locationIn}, 
    leader{leaderIn}, participants{leaderIn}
    {
        meetings.insert(this);
    }

int Meeting::getDay() const {return day;}

int Meeting::getStartTime() const {return startTime;}

int Meeting::getEndTime() const {return endTime;}

Meeting::Campus Meeting::getLocation() const {return location;};

string Meeting::getLeader() const {return leader->getName();};

string Meeting::getSubject() const {return subject;}

void Meeting::addParticipants(Person* p) {participants.insert(p);}

vector<string> Meeting::getParticipants() const
{
    vector<string> names;
    for(auto p : participants) {names.push_back(p->getName());}
    return names;
}
