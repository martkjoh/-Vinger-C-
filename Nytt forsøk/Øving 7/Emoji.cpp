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

EmptyFace::EmptyFace(Point c, int r): 
	Face{ c, r }, whink{ false }, mood{ Mood::neutral },
	rEye{ Point{centre.x - (R  * 2)/5, centre.y - (R * 2)/5 }, R/5 },
	lEyeOpen{ Point{centre.x + (R * 2) / 5, centre.y - (R * 2) / 5}, R/5 },
	lEyeClosed{ Point{centre.x + (R * 2) / 5, centre.y - (R * 2) / 5 }, 
		(R * 2) / 5, (R * 2) / 5, 0, 180},
	mouth(new Line{ Point{centre.x - (R * 3) / 20, centre.y + (R * 3) / 10},
	Point{ centre.x + (R * 3) / 20, centre.y - (R * 3) / 10 } })
{
	rEye.set_color(Color::black);
	rEye.set_fill_color(Color::white);
	lEyeOpen.set_color(Color::black);
	lEyeOpen.set_fill_color(Color::white);
	lEyeClosed.set_color(Color::black);
	mouth->set_color(Color::black);
}


void EmptyFace::attachTo(Graph_lib::Window& win)
{
	Face::attachTo(win);
	win.attach(rEye);
	if (whink) win.attach(lEyeClosed);
	else win.attach(lEyeOpen);

	int mouthWidth = (R * 3) / 5;
	int mouthCentre = (R * 2) / 5;

	switch (mood)
	{
		case Mood::neutral:
		{
			mouth = new Line{ Point{centre.x - mouthWidth, centre.y + mouthCentre},
				Point{ centre.x + mouthWidth , centre.y + mouthCentre } };
			mouth->set_color(Color::black);
			break;
		};
		case  Mood::happy:
		{
			mouth = new Arc{ Point{centre.x, centre.y + mouthCentre},
				mouthWidth * 5 / 4, mouthWidth, 180, 360 };
			mouth->set_color(Color::black);

			break;
		};
		case Mood::sad:
		{
			mouth = new Arc{ Point{centre.x, centre.y + mouthCentre},
				mouthWidth * 2, mouthWidth, 0, 180 };
			mouth->set_color(Color::black);
			break;
		};
		case Mood::angry:
		{
			mouth = new Arc{ Point{centre.x, centre.y + mouthCentre},
				mouthWidth * 2, mouthWidth, 0, 180 };
			mouth->set_color(Color::black);

			int eyebrowTopX = (R * 4) / 10;
			int eyebrowBottomX = (R * 1) / 10;
			int eyebrowTopY = (R * 7) / 10;
			int eyebrowBottomY = (R * 4) / 10;

			lEyebrow = new Line{ Point{centre.x - eyebrowTopX, centre.y - eyebrowTopY}, 
				Point{centre.x - eyebrowBottomX, centre.y - eyebrowBottomY } };
			lEyebrow->set_color(Color::black);
			rEyebrow = new Line{ Point{centre.x + eyebrowTopX, centre.y - eyebrowTopY},
				Point{centre.x + eyebrowBottomX, centre.y - eyebrowBottomY } };
			rEyebrow->set_color(Color::black);
			win.attach(*lEyebrow);
			win.attach(*rEyebrow);

			cout << 4 << endl;
			break;
		};
		case Mood::suprised:
		{
			mouth = new Ellipse{ Point{centre.x, centre.y + mouthCentre},
			mouthWidth, mouthWidth / 2 };
			mouth->set_color(Color::black);
			mouth->set_fill_color(Color::white);
			break;
		};

	}

	win.attach(*mouth);

};

void EmptyFace::setMood(Mood m)
{
	mood = m;
}

void EmptyFace::setWhink(bool w)
{
	whink = w;
}

