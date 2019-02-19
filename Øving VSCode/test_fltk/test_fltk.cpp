// hello_graphics.cpp, PPP page 415
#include "../graph_lib/Graph.h"
#include "../graph_lib/Simple_window.h" 
int main() 
{

	using namespace Graph_lib;
	cout << "The New \"Hello, Graphical World!\" message\n";
	Point tl{ 100, 100 };
	Simple_window win{ tl, 600, 400, "Canvas" };

	Polygon poly;
	poly.add(Point{ 300, 200 });
	poly.add(Point{ 350, 100 });
	poly.add(Point{ 400, 200 });
	poly.set_color(Color::red);

	win.attach(poly);
}