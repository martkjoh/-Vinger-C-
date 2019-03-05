#include "MeetingGUI.h"

// Meeting Window

MeetingWindow::MeetingWindow(Point xy, int w, int h, const string& title): 
    Window{xy, w, h, title}, 
    nameField{Point{fieldPad, pad}, fieldW, fieldH, "Name"}, 
    emailField{Point{fieldPad, pad * 2 + fieldH}, fieldW, fieldH, "e-mail"}
{
    submit = new Button{
        Point{fieldPad, 2 * pad + 2 * fieldH + buttonPad},
        buttonW, buttonH, "Submit", cbNewPerson};

    quit = new Button{
        Point{fieldPad + buttonW + buttonPad, 2 * pad + 2 * fieldH + buttonPad},
        buttonW, buttonH, "Quit", cbQuit};
    
    attach(nameField);
    attach(emailField);
    attach(*submit);
    attach(*quit);
}

void MeetingWindow::addPerson()
{
    people.push_back(new Person{nameField.get_string(), emailField.get_string()});
}

void MeetingWindow::printPersons()
{
    for (const Person* p: people) {cout << *p << endl;}
}

// Funksjoner

void MeetingWindow::cbQuit(Address, Address window) 
{
    reference_to<MeetingWindow>(window).hide();
}

void MeetingWindow::cbNewPerson(Address, Address window) 
{
    MeetingWindow* win = &reference_to<MeetingWindow>(window);
    win->addPerson();
    win->nameField.hide();
    win->emailField.hide();
    win->attach(win->nameField);
    win->attach(win->emailField);
}