#include "cannonball.h"
#include "utilities.h"


double acclY()
{
    return -9.81;
}

double acclX()
{
    return 0;
}

double velY(double initVelY, double time)
{
    return initVelY + acclY() * time;
}

double velX(double initVelX, double time)
{
    return initVelX;
}

double posX(double initPosX, double initVelX, double time)
{
    return initPosX + initVelX * time;
}

double posY(double initPosY, double initVelY, double time)
{
    return (initPosY) + (initVelY * time) + (1. / 2. * acclY() * time * time);
}

void printTime(double sek)
{
    int min = static_cast<int>(sek) / 60;
    int hour = min / 60;
    min = min % 60;
    sek -= static_cast<double>(hour) * 3600 + static_cast<double>(min) * 60;
    cout << hour << ":" << setfill('0') << setw(2) << min << setfill(' ') << ":" << sek <<endl;
}


double flightTime(double initVelY)
{   
    return - (2 * initVelY) / acclY();
}


bool testDeviation(double compareOperand, double toOperand, double maxError)
{
    return (abs(compareOperand - toOperand) > maxError);
}

void getUserInput(double& theta, double& absVel)
{
    cout << "Skriv inn farten i m/s: ";
    cin >> absVel;
    cout << "Skriv inn vinkelen i grader: ";
    double thetaDeg;
    cin >> thetaDeg;
    theta = degToRad(thetaDeg);
}

double degToRad(double deg)
{
    return deg / 360 * 3.141592;
}

double getVelX(double theta, double absVel)
{
    return absVel * cos(theta);
}

double getVelY(double theta, double absVel)
{
    return absVel * sin(theta);
}

void getVelVector(double theta, double absVel, double& velX, double& velY)
{
    velX = getVelX(theta, absVel);
    velY = getVelY(theta, absVel);
}

double getDistanceTraveled(double velX, double velY)
{
    double time = flightTime(velY);
    double initPosX = 0;
    return posX(initPosX, velX, time);
}


double targetPractice(double distanceToTarget, double velX, double velY)
{
    return  getDistanceTraveled(velX, velY) - distanceToTarget;
}

void playTargetPractice()
{
    double distanceToTarget = randomWithLimits();
    int tries = 0;

    cout << "Velkommen til 'Treff blinken!'." << endl;
    cout << "Du velger en vinkel og en hastighet å skyte ballen med, så får du vite hvor nær du var." << endl;
    cout << "Du har 10 forsøk, lykke til!"<< endl;
    cout << "-------------------------------------" << endl;
    
    double absVel = 0;
    double theta = 0; 
    double velX = 0;
    double velY = 0;
    double distanceHitToTarget = 0;

    while (true)
    {
        getUserInput(theta, absVel);
        tries++;
        getVelVector(theta, absVel, velX, velY);
        double missedBy = targetPractice(distanceToTarget, velX, velY);
        if (abs(missedBy) < 5.)
        {
            cout << "Gratulerer! Du traff blinken på " << tries << " forsøk." << endl;
            break;
        }
    
        cout << "Beklager, du skjøt for ";
        if (missedBy < 0) cout << "kort." << endl;
        else cout << "langt." << endl;
        cout << "Tid ballen var i luftn: ";
        printTime(flightTime(velY));

        if (tries == 10)
        {
            cout << "Du har brukt opp førskene dine, prøv igjen en annen gang." << endl;
            break;
        }

        cout <<"Du har " << 10 - tries << " forsøk igjen" << endl;
        cout << "-------------------------------------" << endl;
    }
}
