#include "Emoji.h"


// Face
Face::Face(Point& c, int r) : base{ c, r }, centre{ c }
{
	base.set_color(Color::black);
	base.set_fill_color(Color::yellow);
}

void Face::attachTo(Graph_lib::Window& win)
{
	win.attach(base);
}


// EmptyFace

EmptyFace::EmptyFace(Point c, int r, bool whink): 
	Face{ c, r },
	rEye{ Point{centre.x - 20, centre.y - 20 }, 10 },
	lEyeOpen{ Point{centre.x + 20, centre.y - 20 }, 10 },
	lEyeClosed{ Point{centre.x + 20, centre.y - 20 }, 10, 10, 0, 180},
	whink{whink}
{

	rEye.set_color(Color::black);
	rEye.set_fill_color(Color::white);
	lEyeOpen.set_color(Color::black);
	lEyeOpen.set_fill_color(Color::white);
}

void EmptyFace::attachTo(Graph_lib::Window& win)
{
	Face::attachTo(win);
	win.attach(rEye);
	if (whink) win.attach(lEyeClosed);
	else win.attach(lEyeOpen);

};


