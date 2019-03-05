#pragma once

#include "Person.h"


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
        string getLocation() const;
        string getLeader() const;
        string getSubject() const;
        vector<string> getParticipants() const;
        vector<const Person*> findPotentialCoDriving() const;
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

        // Må lage destruktør
};


// Operatorer

ostream& operator << (ostream& os, const Meeting& m);