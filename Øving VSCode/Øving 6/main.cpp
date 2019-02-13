#include "funksjoner.h"

using namespace::std;

int main()
{
    // Emne fagplan{"TMA4245", "Statistikk"};
    // fagplan.addCourse("TFY4215", "Inføring i kvantemekanikk");
    // fagplan.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
    // fagplan.saveData("fagplan.txt");

    string filePath = "fagplan.txt"; 
    Emne fagplan;
    fagplan.importData(filePath);

    cout << fagplan;

    return 0;
}