// #include "..//std_lib_facilities.h"
#include <iostream> // cout/cin
#include <cmath>    // cos/sin
#include <iomanip>  // setw

using namespace::std;

double acclY();
double acclX();

double velY(double, double);
double velX(double, double);

double posX(double, double, double);
double posY(double, double, double);

void printTime(double);

double flightTime(double);

bool testDeviation(double, double, double);

void getUserInput(double&, double&);

double degToRad(double);

double getVelX(double, double);
double getVelY(double, double);

void getVelVector(double, double, double&, double&);

double getDistanceTraveled(double, double);

double targetPractice(double, double, double);

void playTargetPractice();

