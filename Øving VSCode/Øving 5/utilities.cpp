#include "utilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes) 
{
    for (int i = 0; i < numTimes; i++) 
    {
        startValue += increment;
    }
    return startValue;
}

void incrementByCalueNumTimesRef(int& startValue, int increment, int numTimes)
{
    for (int i = 0; i < numTimes; i++)
    {
        startValue += increment;
    }
}

void swapNumbers(int& a, int& b)
{
    // Ja, fordi det blir mer kompakt, og man slipper å ærklere flere variabler
    int c = a;
    a = b;
    b = c;
}

void seedRandom()
{
    srand(static_cast<unsigned int>(time(nullptr)));
}

double randomWithLimits(int limit)
{
    return rand() % (limit + 1);
}

void randomizeVector(vector<int>& vec, int n)
{
    for (int i = 0; i < n; i++)
    {
        vec.push_back(randomWithLimits(100));
    }
}


void printVector(vector<int> vec)
{
    int n = vec.size();
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << ", ";
    }
    cout << endl;
}

void sortVector(vector<int>& vec)
{   
    int i = 1;
    int lengthOfVec = vec.size();
    while (i < lengthOfVec)
    {
        int j = i;
        while (j > 0 && vec[j - 1] > vec[j])
        {
            swapNumbers(vec[j], vec[j - 1]);
            j--;
        }
    i++;
    }
}


double medianOfVector(vector<int> vec)
{
    sortVector(vec);
    int lengthOfVector = vec.size();
    if (lengthOfVector % 2 == 0)
    {
        return static_cast<double>(vec[lengthOfVector / 2 - 1] + vec[lengthOfVector / 2]) / 2;
    }
    else
    {
        return static_cast<double>(vec[(lengthOfVector - 1) / 2]);
    }
}


string randomizeString(int n, char lowerLimit, char upperLimit)
{   
    string str;
    for (int i = 0; i < n; i++)
    {   
        str.push_back(lowerLimit + randomWithLimits(upperLimit - lowerLimit));
    }
    return str;
}


string readInputToString(int n, char lowerLimit, char upperLimit)
{
    string str;
    char temp;
    if (isalpha(lowerLimit)) toupper(lowerLimit);
    if (isalnum(upperLimit)) toupper(upperLimit);
    cout 
    << "Gjett på " << n << " karakterer mellom " << lowerLimit 
    << " og " << upperLimit << ", og trykk: ";
    while (str.size() < n)
    {
        cin >> temp;
        if (isalpha(temp))
        {
            temp = toupper(temp);
            if ((temp - lowerLimit >= 0) && (temp - upperLimit <= 0)) 
            {
                str.push_back(temp);
            }
            else 
            {
                cout << "Karakteren må være mellom " << lowerLimit << " og " << upperLimit << endl;
                cout << "Godkjente karakterer: " << str << ", skriv inn resten: ";
            }        
        }
        else
        {
            cout << "Ugyldig karakter. Prøv igjen." << endl;
        }
    }
    return str;
}


int countChar(string str, char karakter)
{   
    int count = 0;
    karakter = toupper(karakter);
    for(char a: str)
    {
        if (isalpha(a)) 
        {
            a = toupper(a);
            if (a == karakter) count++;
        }
    }
    return count;
}


int checkPosition(string code, string guess)
{
    int correct = 0;
    int length = code.size();
    for (int i = 0; i < length; i++)
    {
        correct += (toupper(code[i]) == toupper(guess[i]));
    }
    return correct;
}


int checkCharacters(string code, string guess)
{
    for (int i = 0; i < guess.size(); i++)
    {
        for (int j = 0; j < code.size(); j++)
        {
            if (toupper(guess[i]) == toupper(code[j]))
            {
                code = code.substr(0, j)  + code.substr(j + 1);
                break;
            }  
        }
    }
    return guess.size() - code.size();
}
