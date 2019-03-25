#include "LinkedList.h"


int main()
{
    LinkedList l;
    l.insert(l.begin(), "Dette");
    l.insert(l.end(), "er");
    l.insert(l.end(), "en");
    l.insert(l.end(), "test");
    cout << l << endl;
    l.insert(l.begin(), "inb4");
    l.remove("test");
    l.remove("er");
    l.remove("inb4");
    cout << l << endl;

    return 0;
}
