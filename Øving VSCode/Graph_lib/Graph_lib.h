#pragma once

#ifndef WIN32
// If this is not a Windows computer, read this file.

// Code that extends Graph_lib for exercise 7.
// Not relevant for Windows users.

#include "Graph.h"

namespace Graph_lib {

// For a description of this class, refer to the exercise text.
class Arc : public Graph_lib::Shape
{
public:
	Arc(Point center, int w, int h, int sd, int ed)
		: w{w}, h{h}, start_deg{sd}, end_deg{ed}
	{
		add(Point{center.x - w / 2, center.y - h / 2});
	}

	void draw_lines() const override;

	void set_start(int d) { start_deg = d; }
	void set_end(int d) { end_deg = d; }
	void setw(int w) { this->w = w; }
	void seth(int h) { this->h = h; }

private:
	int w;
	int h;
	int start_deg;
	int end_deg;
};

} // namespace Graph_lib

#endif
