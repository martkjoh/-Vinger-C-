#include "funksjoner.h"

using namespace::std;

int main()
{
    // Emne fagplan{"TMA4245", "Statistikk"};
    // fagplan.addCourse("TFY4215", "Inføring i kvantemekanikk");
    // fagplan.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
    // fagplan.saveData("fagplan.txt");

    string filePath = "temps.txt"; 
    ifstream file{filePath};
    vector<Temps> temps;

    while(file)
    {
        temps.push_back(Temps{file});
    }

    for (Temps temp: temps)
    {
        cout << temp.max << ", " << temp.min << endl;
    }
    
    return 0;
}