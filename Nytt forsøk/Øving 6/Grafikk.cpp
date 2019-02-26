#include "Grafikk.h"

void graphTemps(string filePath)
{
	ifstream file{ filePath };
	if (!file) throw runtime_error("File path " + filePath + " invalid");

	vector<Temps> temps;

	while (file)
	{
		temps.push_back(Temps{ file });
	}

	Point topLeftCorner{ 0, 0 };
	int width = 1500;
	int height = 720;
	int sideBorders = width / 20;
	int topBorders = height / 20;
	int scaling = 12;
	string lableSpaceing = "                       ";

	Point origin = { sideBorders, height / 2 };
	Point bottomOfY = { sideBorders , height - topBorders };

	Open_polyline max;
	Open_polyline min;

	for (int i = 0; i < temps.size(); i++)
	{
		max.add(Point{ static_cast<int>((i * (width - 2 * sideBorders)) / (temps.size() - 1)) + sideBorders,
			static_cast<int>(-temps[i].max) * scaling + height / 2 });
		min.add(Point{ static_cast<int>((i * (width - 2 * sideBorders)) / (temps.size() - 1)) + sideBorders,
			static_cast<int>(-temps[i].min) * scaling + height / 2 });
	}

	Graph_lib::Axis xAx{ Graph_lib::Axis::x, origin, width - 2 * sideBorders, 12,
		lableSpaceing + "Jan" + lableSpaceing + "Feb" + lableSpaceing + "Mar" + lableSpaceing + "Apr" + lableSpaceing +
		"Mai" + lableSpaceing + "Jun" + lableSpaceing + "Jul" + lableSpaceing + "Aug" + lableSpaceing +
		"Sep" + lableSpaceing + "Okt" + lableSpaceing + "Nov" + lableSpaceing + "Des" };

	xAx.label.move(-450, 0);

	Graph_lib::Axis yAx{ Graph_lib::Axis::y, bottomOfY, height - 2 * topBorders, 5, "degrees celsius" };


	Simple_window window{ topLeftCorner, width, height, "Test" };

	xAx.set_color(Color::black);
	yAx.set_color(Color::black);
	max.set_color(Color::red);
	min.set_color(Color::blue);

	window.attach(xAx);
	window.attach(yAx);
	window.attach(max);
	window.attach(min);

	window.wait_for_button();
}