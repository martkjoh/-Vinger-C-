#include "test.h"
#include "masterVisual.h"

void testCallByValue() 
{
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << result << endl;
}

void testByCallByRefrence()
{
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    cout << "v0: " << v0;
    incrementByCalueNumTimesRef(v0, increment, iterations);
    int result = v0;
    cout 
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << result << endl;
}

void testVecotrSorting()
{
    vector<int> percentages (0);
    int n = 6;
    randomizeVector(percentages, n);
    printVector(percentages);
    cout << medianOfVector(percentages) << endl;
    sortVector(percentages);
    printVector(percentages);
}

void testString()
{
    int n = 8;
    vector<int> gradeCount (0);
    string grades = randomizeString(n, 'A', 'F');
    cout << grades << endl;
    for (char i = 'A'; i <= 'F'; i++)
    {
        gradeCount.push_back(countChar(grades, i));
    }
    printVector(gradeCount);
    double average = 0;
    for (int i = 0; i < n; i++)
    {
        average += (5 - i) * gradeCount[i];
    }
    average = average / n;
    cout << average;
}

void testReadInputToString()
{
    string str = readInputToString(5, 'A', 'F');
    cout << str;
}

void playMastermindText()
{

    constexpr int size = 4;
    constexpr int letters = 6;
    int tries = 0;
    int numOftries = 10;
    string code = randomizeString(size, 'A', 'A' + letters - 1);
    while (true)
    {
        string guess = readInputToString(size, 'A', 'A' + letters - 1);
        int correctPosistion = checkPosition(code, guess);
        int correctCharacter = checkCharacters(code, guess);
        if (correctPosistion < size)
        {
            cout << "Feil, prøv igjen! Du hadde " << correctCharacter << " riktig(e) karakter(er), " 
            << "hvorav " << correctPosistion << " var på riktig posisjon." << endl;
        } 
        else
        {
            cout << "Riktig! Koden var " << code << endl;
            break;
        }
        if (tries == numOftries) 
        {
            cout << "Beklager, du gikk tom for forsøk. Koden var " << code << endl;
            break;
        }
        tries++;
        cout << "Du har " << numOftries - tries << " forsøk igjen" << endl << endl; 
    }
}


void playMastermindGraphics()
{

    constexpr int size = 4;
    constexpr int letters = 6;
    int tries = 0;
    int numOftries = 10;
    string code = randomizeString(size, 'A', 'A' + letters - 1);
    while (true)
    {
        string guess = readInputToString(size, 'A', 'A' + letters - 1);
        int correctPosistion = checkPosition(code, guess);
        int correctCharacter = checkCharacters(code, guess);
        if (correctPosistion < size)
        {
            cout << "Feil, prøv igjen! Du hadde " << correctCharacter << " riktig(e) karakter(er), " 
            << "hvorav " << correctPosistion << " var på riktig posisjon." << endl;
        } 
        else
        {
            cout << "Riktig! Koden var " << code << endl;
            break;
        }
        if (tries == numOftries) 
        {
            cout << "Beklager, du gikk tom for forsøk. Koden var " << code << endl;
            break;
        }
        tries++;
        cout << "Du har " << numOftries - tries << " forsøk igjen" << endl << endl; 
    }
}