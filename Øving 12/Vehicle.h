#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/fl_draw.H>
#include <math.h>
#include <iostream>


struct PhysicalState
{
    double x, y, velX, velY, aksX, aksY, grip, time;

    PhysicalState(double a, double b, double c, double d, double e, double f, double g = 1):
        x{a}, y{b}, velX{c}, velY{d}, aksX{e}, aksY{f}, grip{g}, time{0} {};
};

class Vehicle : public Fl_Widget
{
    private:
        PhysicalState state;
        double x0 = 750;
        double y0 = 500;

    public:
        Vehicle(double vX, double vY);
        ~Vehicle() = default;
        
        void draw();
        void updateState();
};
