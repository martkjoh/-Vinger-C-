#ifndef POINT_GUARD
#define POINT_GUARD

namespace Graph_lib {

struct Point
{
	int x;
	int y;
};

inline bool operator==(Point a, Point b)
{
	return a.x == b.x && a.y == b.y;
}

inline bool operator!=(Point a, Point b)
{
	return !(a == b);
}

} // namespace Graph_lib
#endif
