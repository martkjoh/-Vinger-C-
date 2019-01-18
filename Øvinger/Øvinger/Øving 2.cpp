#include "std_lib_facilities.h"

void inputAndPrintInteger()
{
	cout << "Skriv inn et heltall: ";
	int n;
	cin >> n;
	cout << "Du skrev: " << n << "\n";
}


int inputInteger()
{
	cout << "Skriv inn et tall: ";
	int n;
	cin >> n;
	return n;
}


void inputIntegerAndPrintSum()
{
	int n = inputInteger();
	int m = inputInteger();
	cout << "Summen av tallene: " << n + m << '\n';

}


bool isOdd(int n)
{
	return n % 2;
}

string printBool(bool b)
{
	if (b) return "true";
	else return "false";
}

void printHumanReadableTime(int s)
{
	int t = 0;
	int m = 0;
	t = s / 3600;
	m = (s / 60) % 60;
	s = s % 60;
	cout << t << " timer, " << m << " minutter, og " << s << " sekunder.";
}

void inputIntegersUsingLoopAndPrintSum()
{
	cout << "Skriv in hvor mange tall som skal legges sammen: ";
	int n;
	cin >> n;
	int s = 0;
	for (int i = 1; i <= n; i++)
	{
		s += inputInteger();
	}
	cout << "Den totale summen blir: " << s;
}

double inputDouble()
{
	cout << "Skriv inn et tall: ";
	double x;
	cin >> x;
	return x;
}

void nokToEuro()
{
	double nok = inputDouble();
	while (nok < 0)
	{
		cout << "Summen kan ikke være negativ, prøv igjen: ";
		cin >> nok;
	}
	cout << setprecision(2) << fixed << nok << " kr er " << 9.75 * nok << " euro\n";
}




int main()
{

	cout << "Velg funskjon: \n 0) Avslutt \n 1) Summer to tall\n 2) Smmer flere tall\n Konverter NOK til EURO\n Angi valg (0-3): ";
	int brukerValg;
	cin >> brukerValg;
	while (brukerValg)
	{
		if (brukerValg == 1) inputIntegerAndPrintSum();
		if (brukerValg == 2) inputIntegersUsingLoopAndPrintSum();
		if (brukerValg == 3) nokToEuro();
		else
		{
			cout << "Ugyldig valg; prøv igjen.\n";
			continue;
		}
		cout << "Angi nytt valg: ";
		cin >> brukerValg;
	}





	return 0;
}