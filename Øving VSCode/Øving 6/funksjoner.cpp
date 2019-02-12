#include <fstream>
#include <iostream>
#include <string>
#include <stdexcept>
#include "../std_lib_facilities.h"

using namespace::std;

void textToFile(string filePath)
{
    string filePath = "test.txt";
    ofstream file{filePath};

    cout << "Write words to input to file. 'quit' to quit." << endl;
    string temp;

    while (true)
    {
        cin >> temp;
        if (temp == "quit") break;
        file << temp + '\n';
    };
}

void copyFile(string filePath)
{
    string filePath = "test.txt";
    ifstream file{filePath};
    if (!file) throw runtime_error("File path " + filePath + " invalid");

    ofstream fileCopy{"copyOf_" + filePath};
    string temp;

    while (file >> temp) fileCopy << temp + '\n';
}