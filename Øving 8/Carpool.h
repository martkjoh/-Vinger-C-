#include <string>
#include <ostream>
#include <iostream>
#include <set>
#include <vector>
#include <iomanip>


using namespace::std;

// A Car is an object with an amount of free seats, which can bee reserved

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

// A Meeting is a class containing the location

class Meeting
{    
    public:
        enum class Campus{Gløshaugen, Dragvoll, Kalvskinnet, Gjøvik, Ålesund};

        Meeting(int dayIn, int startTimeIn, int endTimeIn, Campus locationIn,
            string subjectIn, Person* leaderIn);

        int getDay() const;
        int getStartTime() const;
        int getEndTime() const;
        Campus getLocation() const;
        string getLeader() const;
        string getSubject() const;
        vector<string> getParticipants() const;
        void addParticipants(Person* p);

    private:
        int day;
        int startTime;
        int endTime;
        Campus location;
        string subject;
        const Person* leader;
        set<const Person*> participants;
        static set<const Meeting*> meetings;
}