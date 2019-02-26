#include "Simple_window.h"
#include "Emoji.h"


int main()
{
	using namespace Graph_lib;

	const Point tl{R, R};
	const string win_label{"Emoji factory"};
	Simple_window win{tl, xmax, ymax, win_label};

	EmptyFace* face;
	
	for (int i = 0; i < 5; i++)
	{
		face = new EmptyFace{ Point{R + (i % 3 * 2 * R), (R + R * (i / 3)) * 2}, R };

		face->setMood(Mood(i));
		face->attachTo(win);
	}

	face = new EmptyFace{ Point{R + (2 * 2 * R), 4*R}, R };

	face->setMood(Mood::happy);
	face->setWhink(true);
	face->attachTo(win);


	win.wait_for_button();
}
