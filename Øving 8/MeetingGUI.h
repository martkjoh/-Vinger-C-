#include "Graph.h"
#include "Window.h"
#include "GUI.h"
#include "Person.h"

using namespace Graph_lib;

class MeetingWindow : public Graph_lib::Window
{   
    public:
        MeetingWindow(Point xy, int w, int h, const string& title);

        void addPerson();
        void printPersons();

    private:
        static constexpr int pad = 30;
        static constexpr int buttonW = 80;
        static constexpr int buttonH = 30;
        static constexpr int buttonPad = 10;
        static constexpr int fieldW = 340;
        static constexpr int fieldH = 50;
        static constexpr int fieldPad = 80;

        In_box nameField;
        In_box emailField;
        Button* quit;
        Button* submit;

        vector<Person*> people;

        static void cbQuit(Address, Address window);
        static void cbNewPerson(Address, Address window);    
};
