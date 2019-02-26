#pragma once

#include "Graph.h"
#include "GUI.h"
#include "Graph_lib.h"


constexpr int xmax = 1000;
constexpr int ymax = 600;
constexpr int R = ymax / 6;


enum class Mood
{
	neutral, happy, sad, angry, suprised
};


using namespace Graph_lib;

// An abstract class. Concrete classes derived from this base class
// has to implement the member function attach_to().
class Emoji
{
protected:
	// Disable copying. Disable slicing, etc.
	Emoji(const Emoji&) = delete;
	Emoji& operator=(const Emoji&) = delete;

	// Deleting the copy constructor also deletes the default constructor.
	// Emoji needs a default constructor.
	Emoji() {}
	// Emoji() = default; // is an alternative way of achieving the same.

	// The pure virtual function that has to be overriden for a deriving class
	// to be instantiable. Every class deriving from Emoji is supposed to
	// attach all its Shapes to a window. This makes the class abstract.
	virtual void attachTo(Graph_lib::Window& win) = 0;

	// Relevant because Vector_ref can own Emojis and automatically cleans up.
	// Subject will be visited later in the course.
	virtual ~Emoji() {}
};


// A face without any features
// Just a yellow circle

class Face : public Emoji
{
	private:
		Circle base;

	protected:
		Face(Point& c, int r);

		Point centre;

		void attachTo(Graph_lib::Window& win) override;
};


// A face with just two eyes.
// Inherits: Protected: initializer for a base "Face"

class EmptyFace : public Face
{
	private:
		Circle lEyeOpen;
		Arc lEyeClosed;
		Circle rEye;
		Line* lEyebrow;
		Line* rEyebrow;
		Mood mood;
		Shape* mouth;
		bool whink;

	public:
		EmptyFace(Point c, int r);

		void attachTo(Graph_lib::Window& win) override;
		void setMood(Mood m);
		void setWhink(bool w);
};
