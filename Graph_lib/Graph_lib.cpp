#ifndef WIN32
// If this is not a Windows computer, read this file.

#include "Graph_lib.h"

void Graph_lib::Arc::draw_lines() const
{
	if (color().visibility()) {
		fl_color(color().as_int());
		fl_arc(point(0).x, point(0).y, w, h, start_deg, end_deg);
	}
}

#endif
