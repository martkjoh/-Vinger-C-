#include <fstream>      // File stream
#include <iostream>     // standrad I/O, cout etc
#include <stdexcept>    // raise exceptions
#include <string>       // type string
#include <sstream>      // type string strema
#include <vector>       // type vector
#include <map>          // type map

using namespace::std;


class Emne
{
    private:
        map<string, string> emner;

    public:
        Emne();
        Emne(string key, string mapped);

        void addCourse(string key, string mapped);
        void removeCourse(string key);
        string getCours(string key);
        void saveData(string filePath);
        void importData(string filePath);

    friend ostream& operator<<(ostream& os, const Emne& emne);
};


void textToFile(string filePath);

void copyFile(string filePath);

void countLetters(string filePath);