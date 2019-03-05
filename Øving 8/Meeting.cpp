#include "Meeting.h"


Person::Person(string n, string e, Car* c): name{n}, email{e}, car{c} {}

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
    os << left << setw(10) << "Subject: " << m.getSubject() << endl;
    os << left << setw(10) << "Leader: " << m.getLeader() << endl;
    os << left << setw(10) << "Location: " << m.getLocation() << endl;
    os << "From " << m.getStartTime() << " to " << m.getEndTime() << endl; 
    return os;
}

Meeting::Meeting(int dayIn, int startTimeIn, int endTimeIn, 
    Campus locationIn, string subjectIn, Person* leaderIn):
    day{dayIn}, startTime{startTimeIn}, endTime{endTimeIn}, location{locationIn}, 
    subject{subjectIn}, leader{leaderIn}, participants{leaderIn}
    {
        meetings.insert(this);
    }

int Meeting::getDay() const {return day;}

int Meeting::getStartTime() const {return startTime;}

int Meeting::getEndTime() const {return endTime;}

string Meeting::getLocation() const 
{
    switch(location) 
    {
        case(Meeting::Campus::Gløshaugen): {return "Gløshaugen";}
        case(Meeting::Campus::Gjøvik): {return "Gjøvik";}
        case(Meeting::Campus::Dragvoll): {return "Dragvoll";}
        case(Meeting::Campus::Kalvskinnet): {return "Kalvskinnet";}
        case(Meeting::Campus::Ålesund): {return "Ålesund";}
    }
}

string Meeting::getLeader() const {return leader->getName();}

string Meeting::getSubject() const {return subject;}

void Meeting::addParticipants(Person* p) {participants.insert(p);}

vector<string> Meeting::getParticipants() const
{
    vector<string> names;
    for(auto p : participants) {names.push_back(p->getName());}
    return names;
}

vector<const Person*> Meeting::findPotentialCoDriving() const
{
    vector<const Person*> persons;
    for (const Meeting* m : meetings)
    {
        bool sameDay = (day == m->getDay());
        bool samePlace = (this->getLocation() == m->getLocation());
        bool sameTime = abs(m->getStartTime() - startTime) <= 1 && 
            abs(m->getEndTime() - endTime) <= 1;
        if (!(sameDay && sameTime && samePlace)) {break;}

        for (const Person* p : m->participants)
        {
            if (p->hasFreeSeats()) {persons.push_back(p);}
        }
    }
    return persons;
}