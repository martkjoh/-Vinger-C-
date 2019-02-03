#include "masterVisual.h"

#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

// Application layout in fractions (percentage) of window width and height
// Horisontally:
constexpr double guess_w = 0.75;			 // width of field for guess as fraction of window_width
constexpr double feedback_w = 1.0 - guess_w; // width of field for feedback as fraction of window_width. Note how this
											 // code is better than setting the value to 0.25
constexpr double roomAroundGuess = guess_w / 6.0;
constexpr double guessDisplay_w = (1.0 - 2 * roomAroundGuess) * guess_w;
constexpr double gapBetweenColors = 0.20;

// Vertically:
constexpr double top_part_h = 1.0 / 6.0;		 // height of top part as fraction of window_height
constexpr double play_part_h = 1.0 - top_part_h; // height of play part as fraction of window_height
constexpr int maxTries = 10;					 // max no of guesses that can be displayed
constexpr double guessHeight = (play_part_h / maxTries);
constexpr double vRoomAboveGuess = guessHeight / 10.0; // vertical Room Above Guess
constexpr double oneColor_h = guessHeight - 2 * vRoomAboveGuess;

void addGuess(MastermindWindow& mwin, const string code, const int size, const char startLetter, const int round)
{
	// Must be placed here since it depends on parameter size
	const double oneColor_w = (guessDisplay_w / size) * (1.0 - gapBetweenColors);
	const int tlDispOneColorY = static_cast<int>(((round * guessHeight) + vRoomAboveGuess) * mwin.y_max());

	for (int i = 0; i < size; ++i) {
		const int tlDispOneColorX = static_cast<int>((roomAroundGuess + (i * (guessDisplay_w / size))) * mwin.x_max());

		mwin.vr.push_back(new Graph_lib::Rectangle{ Point{tlDispOneColorX, tlDispOneColorY}, static_cast<int>(oneColor_w * mwin.x_max()),
										static_cast<int>(oneColor_h * mwin.y_max()) });
		mwin.vr[mwin.vr.size() - 1].set_fill_color(Color{ code[i] - startLetter + 1 });
		mwin.attach(mwin.vr[mwin.vr.size() - 1]);
	}
}

void hideCode(MastermindWindow& mwin, int size)
{
	// Similar to showCode, but simpler
	mwin.vr.push_back(
		new Graph_lib::Rectangle{ Point{static_cast<int>(roomAroundGuess * mwin.x_max()), static_cast<int>(vRoomAboveGuess * mwin.y_max())},
					  static_cast<int>((guessDisplay_w - ((guessDisplay_w / size) * gapBetweenColors)) * mwin.x_max()),
					  static_cast<int>(oneColor_h * mwin.y_max()) });
	mwin.vr[mwin.vr.size() - 1].set_fill_color(Color::black);
	mwin.attach(mwin.vr[mwin.vr.size() - 1]);
}

// correctPosition: hvor mange bokstaver er på riktig sted?
// correctCharacter: hvor mange bokstaver er riktige, uavhangig av posisjon?
void addFeedback(MastermindWindow& mwin, const int correctPosition, const int correctCharacter, const int size, const int round)
{
	const int centerY = (0.5 + round) * guessHeight * mwin.y_max(); // Regn ut sirklenes y-koordinat (sentrum)
	for (int i = 0; i < size; i++) {
		const int centerX = ((guess_w) + (feedback_w * i) / (size))* mwin.x_max(); // Regn ut sirkelens x-koordinat (sentrum)

		mwin.vc.push_back(new Circle{ Point{centerX, centerY}, 8 });

		if (i < correctPosition) {
			mwin.vc[mwin.vc.size() - 1].set_fill_color(Color::white);
			// Sett farge for korrekt plassering
		}
		else //if (i < (correctPosition + max(0, correctCharacter - correctPosition))) 
		{
			mwin.vc[mwin.vc.size() - 1].set_fill_color(Color::black);
			// Sett farge for korrekt bokstav, men feil plassering
		}

		mwin.attach(mwin.vc[mwin.vc.size() - 1]);
		// Koble sirkelen til vinduet (attach)

	}
}