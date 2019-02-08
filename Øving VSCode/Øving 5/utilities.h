#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace::std;

int incrementByValueNumTimes(int startValue, int increment, int numTimes);

void incrementByCalueNumTimesRef(int& startValue, int increment, int numTimes);

void swapNumbers(int& a, int& b);

void seedRandom();

double randomWithLimits(int limit);

void randomizeVector(vector<int>& vec, int n);

void printVector(vector<int> vec);

void sortVector(vector<int>& vec);

double medianOfVector(vector<int> vec);

// Generer tilfeldig string, lengde n, med uppercase mellom char lowerLimit og upperLimit 
string randomizeString(int n, char lowerLimit, char upperLimit);

// Henter string fra brukeren, karakter for karakter, lengde n, 
// med char mellom lowerLimit og upperLimit. Case insensitive.
string readInputToString(int n, char lowerLimit, char upperLimit);

// sjekker hvor mange tilfeller av karakter i str, gitt isalpha(karakter)
// case insensitive
int countChar(string str, char karakter);

// Returnerer antallet karrakterer i guess som er på like (case insesnsitive),
// og på samme posisjon
int checkPosition(string code, string guess);

int checkCharacters(string code, string guess);