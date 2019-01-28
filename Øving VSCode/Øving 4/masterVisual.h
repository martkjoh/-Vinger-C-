// #pragma once

#include "..//grafikk//Simple_window.h"

// Storing game's gui data

struct MastermindWindow : Simple_window 
{ 
	//using Simple_window::Simple_window;
	MastermindWindow(Point xy, int w, int h, const string& title) : Simple_window(xy, w, h, title) {};
	
    // storing rectangles for code and guesses
    Vector_ref<Rectangle> vr;
    // storing feedback-pins as circles 
	Vector_ref<Circle> vc;	
};

void addGuess(MastermindWindow& mwin,
			  const string code, const int size, const char startLetter, const int round);

void hideCode(MastermindWindow& mwin, int size);

void addFeedback(MastermindWindow& mwin,
				 const int correctPosition, const int wrongPosition, const int size, const int round);
