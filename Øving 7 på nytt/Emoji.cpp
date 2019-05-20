#include "Emoji.h"

Face::Face(Point center, int radius) : center{center}, radius{radius}, 
    face{new Circle(center, radius)} 
    {
        face->set_fill_color(Color::yellow);
    }

void Face::attach_to(Graph_lib::Window &win)
{
    win.attach(*face);
}

EmptyFace::EmptyFace(Point center, int radius) 
    : Face(center, radius), 
    lEye{new Circle(Point{center.x - radius/2, center.y - radius / 3}, radius / 6)},
    rEye{new Circle(Point{center.x + radius/2, center.y - radius / 3}, radius / 6)}
    {
        lEye->set_fill_color(Color::black);
        rEye->set_fill_color(Color::black);
    }

void EmptyFace::attach_to(Graph_lib::Window &win)
{
    Face::attach_to(win);
    win.attach(*lEye);
    win.attach(*rEye);
}

PlainFace::PlainFace(Point center, int radius)
    : EmptyFace(center, radius) {}

void PlainFace::attach_to(Graph_lib::Window &win)
{
    EmptyFace::attach_to(win);
    win.attach(*mouth);
}
