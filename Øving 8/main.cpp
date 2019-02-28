#include "Carpool.h"

int main()
{
    cout << endl;

    Person Ola{"Ola Normann", "xxXXolaXXxx@hotmail.com"};
    Car lynet{1};
    Person Frank{"Frank Nilsen", "franknilsen@gmail.com", &lynet};
    cout << Ola;
    cout << Frank;
    
    Ola.setEmail("memelord@yahoo.com");
    lynet.reserveFreeSeat();
    cout << Ola;
    cout << Frank;
    return 0;
}