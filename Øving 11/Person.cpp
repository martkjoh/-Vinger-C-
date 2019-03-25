#include "Person.h"


// Implementation of the calss Person

Person::Person(string fn, string en): fornavn{fn}, etternavn{en} {}

void Person::printPersonCasual() const {cout << fornavn << " " << etternavn << endl;}

void Person::printPersonOfficial() const {cout << etternavn << ", " << fornavn << endl;}

string Person::getLastName() const {return etternavn;}

string Person::getFirstName() const {return fornavn;}


// Functions

void insertPerson(list<Person> &l, const Person& p)
{
    for (list<Person>::iterator itr = l.begin(); itr != l.end(); itr++)
    {
        if (itr->getLastName() < p.getLastName()) {continue;}
        if (itr->getLastName() == p.getLastName() && itr->getFirstName() < p.getFirstName())
        {
            continue;
        }
        if (itr->getLastName() == p.getLastName() && itr->getFirstName() == p.getFirstName())
        {
            cout << "Person alredy in list." << endl;
            return;
        }

        l.insert(itr, p);
        return;
    }

    l.insert(l.end(), p);
}


void printPeopleList(list<Person> l)
{
    for(list<Person>::iterator itr = l.begin(); itr != l.end(); itr++)
    {
        itr->printPersonOfficial();
    }    
}