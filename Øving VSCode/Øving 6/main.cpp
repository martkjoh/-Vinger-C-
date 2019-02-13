#include "funksjoner.h"

using namespace::std;

int main()
{
    Emne fagplan{"TMA4245", "Statistikk"};
    fagplan.addCourse("TFY4215", "Inføring i kvantemekanikk");
    fagplan.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
    fagplan.saveData("fagplan.txt");

    return 0;
}
