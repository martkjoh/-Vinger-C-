// Bug i linje 28 hvis de inkluderes in motsatt rekkefølge (?!???!)
#include "MeetingGUI.h"
#include "Meeting.h"


int main()
{

    MeetingWindow m{Point{100, 100}, 500, 250, "Meeting"};
    gui_main();
    m.printPersons();

    Car lynet{1};
    Car Tesla{4};
    Car CBR125{1};
    Car boble{3};
   
    Person Ola{"Ola Normann", "xxXXolaXXxx@hotmail.com"};
    Person Frank{"Frank Nilsen", "franknilsen@gmail.com", &lynet};
    Person Martin{"Martin Johnsrud", "martkjoh@stud.ntnu.no", &Tesla};
    Person Lise{"Lise Nilsen", "lise@gmail.com", &CBR125};
    Person Hans{"Hans Giil", "hansgii@gmail.com", &boble};
    
    CBR125.reserveFreeSeat();

    Meeting campus{1, 12, 14, Meeting::Campus::Gløshaugen, "Campusutvikling", &Ola};
    campus.addParticipants(&Frank);
    
    Meeting BN{1, 11, 14, Meeting::Campus::Gløshaugen, "Møte i BN", &Martin};
    BN.addParticipants(&Lise);
    BN.addParticipants(&Hans);

    cout << campus << endl;

    vector<const Person*> coDriving = campus.findPotentialCoDriving();
    for (const Person* p : coDriving)
    {
        cout << *p;
    }
    return 0;
}