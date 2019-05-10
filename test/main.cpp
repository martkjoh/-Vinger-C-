#include "Graph.h"
#include "Graph_lib.h"
#include "Simple_window.h"

using namespace::Graph_lib;

int main()
{
    Circle * c = new Circle{Point{100, 100}, 5};

    Simple_window win{Point{100, 100}, 600, 600, "test"};
    win.attach(*c);
    win.wait_for_button();

    return 0;

}