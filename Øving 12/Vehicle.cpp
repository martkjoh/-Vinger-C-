#include "Vehicle.h"

// Vehicle
//
// Implementasjon av klassen Vehicle

Vehicle::Vehicle(double vX, double vY) : 
    Fl_Widget(0, 0, 200, 200, "test"), state{300, 500, vX, vY, 0, 0} {}

void Vehicle::draw()
{
    fl_color(FL_BLACK);
    fl_circle(state.x, state.y, 5);
    fl_circle(x0, y0, 10);
    fl_line(x0, y0, state.x, state.y);
}

void Vehicle::updateState()
{   
    state.time++;
    state.x += state.velX + state.aksX;
    state.y += state.velY + state.aksY; 
    double x = state.x - x0;
    double y = state.y - y0;
    double G = 1500;
    state.velX += state.aksX;
    state.velY += state.aksY;
    double rSquared = (x*x + y*y);
    double theta = atan2(-y, x);
    state.aksX = -G / rSquared * cos(theta);
    state.aksY =  G / rSquared * sin(theta);
    // std::cout  << x << ", " << y << ", " << std::endl;
}
