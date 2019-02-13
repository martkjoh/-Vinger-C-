#include "funksjoner.h"


//emne


ostream& operator<<(ostream& os, const Emne& emne)
{
    for(auto i: emne.emner)
    {
        os << i.first << "\t" <<  i.second << endl;
    }

    return os;
}

Emne::Emne(string key, string mapped)
{
    emner[key] = mapped;
}

Emne::Emne(){}


void Emne::addCourse(string key, string mapped)
{
    emner[key] = mapped;
}

void Emne::removeCourse(string key)
{
    emner.erase(key);
}

string Emne::getCours(string key)
{
    return emner[key];
}

void Emne::saveData(string filePath)
{
    ofstream file{filePath};
    file << *this;

}

void importData(string filePath)
{
    ifstream file{filePath};
    if (!file) throw runtime_error("File path " + filePath + " invalid");

}


// funksjoner

void textToFile(string filePath)
{
    ofstream file{filePath};

    cout << "Write words to input to file. Two enters for newline, 'quit' to quit" << endl;
    string temp;

    while (true)
    {
        getline(cin, temp);
        if (temp == "quit") break;
        file << temp + '\n';
    };
}

void copyFile(string filePath)
{
    ifstream file{filePath};
    if (!file) throw runtime_error("File path " + filePath + " invalid");

    ofstream fileCopy{"copyOf_" + filePath};
    string temp;
    int row  = 0;

    while (getline(file, temp)) 
    {
        fileCopy << to_string(row) + '\t' +  temp + '\n';
        row++;
    }
}


void countLetters(string filePath)
{
    vector<int> letters(26);

    ifstream file{filePath};
    if (!file) throw runtime_error("File path " + filePath + " invalid");

    string line;
    while(getline(file, line))
    {
        for (char character: line)
        {
            character = tolower(character);
            if (character >= 'a' && character <= 'z') letters[character - 'a']++;
        }
    }
    
    int tableLength = 9;
    int rows = letters.size() / tableLength;
    string temp;

    for (int i = 0; i < letters.size(); i++)
    {
        cout << static_cast<char>('a' + i) << ": " << to_string(letters[i]) << '\t';
        if (i % 3 == 2) cout << endl;
    }  
}