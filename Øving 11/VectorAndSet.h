#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace::std;


void replaceElementVec(vector<string> &vec, string old, string replacement)
{
    for (vector<string>::iterator itr = vec.begin(); itr < vec.end(); itr++)
    {
        if (*itr != old) {continue;}
        vec.erase(itr);
        vec.insert(itr, replacement);
    }
}

void printVec(vector<string> vec)
{
    for (vector<string>::iterator itr = vec.begin(); itr < vec.end(); itr++)
    {
        cout << *itr << endl;
    }
}

void printSet(set<string> words)
{
    for (set<string>::iterator itr = words.begin(); not(itr == words.end()); itr++)
    {
        cout << *itr << endl;
    }
}

void replaceElementSet(set<string> &words, string old, string replacement)
{
    for (set<string>::iterator itr = words.begin(); itr != words.end(); itr++)
    {
        if (*itr != old) {continue;}
        words.erase(itr);
        words.insert(itr, replacement);
        break;
    }
}

void testVectorAndSet()
{
    vector<string> vec{"Dette", "er", "en", "test"};
    set<string> sett{"Dette", "er", "også", "en", "test"};
    replaceElementVec(vec, "en", "to");
    printVec(vec);   
    replaceElementSet(sett, "Dette", "Det der");
    printSet(sett); 
}