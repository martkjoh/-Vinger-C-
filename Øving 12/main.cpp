#include "Vehicle.h"
#include <chrono>

using namespace::std;

int getTime()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>
        (std::chrono::system_clock::now().time_since_epoch()).count();
}

double** getInitCond(int argc, char **argv)
{
    double* args [argc];
    
    if (argc == 1) 
    {
        *args[1] = 1; 
        *args[2] = 1;
    }
    
    else
    {
        for (int i = 0; i < argc; i++) 
            {
                *args[i] = atof(argv[i]);
                cout << args[i] << ", " << argv[i] << endl;   
            }
    }

    return args;
}


int main(int argc, char **argv)                             
{
    double* vs;
    vs = *getInitCond(argc, argv);

    Fl_Window *window = new Fl_Window(1500, 1000);
    
    Vehicle* v = new Vehicle(vs[1], vs[2]);
    window->end();
    window->show();

    while (window->shown())
    {
        using namespace::std::chrono;
        int t = getTime();
        int refreshTime = 10;
        v->updateState();
        Fl::check();
        Fl::redraw();
        while (getTime() - t < refreshTime);
    }

    return 0;
}

