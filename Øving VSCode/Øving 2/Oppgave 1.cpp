#include "..//std_lib_facilities.h"

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
	cout << "Den totale summen blir: " << s << '\n';
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
		cout << "Summen kan ikke vaere negativ, prov igjen: ";
		cin >> nok;
	}
	cout << setprecision(2) << fixed << nok << " kr er " << 9.75 * nok << " euro\n";
}

void gangeTabell()
{
	cout << "Opp til hvor mye skal gangetabellen skal skrives? ";
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << setw(5) << i * j;
		}
		cout << '\n';
	}
}

double discriminant(double a, double b, double c)
{
	return b * b - 4 * a * c;
}

void printRealRoots(double a, double b, double c)
{	
	double d = discriminant(a, b, c);
	if (d > 0) 
	{
		double x1 = (-b + sqrt(d)) / (2 * a);
		double x2 = (-b - sqrt(d)) / (2 * a);
		cout << "x1 = " << x1 << '\n';
		cout << "x2 = " << x2 << '\n';
	}
	else if (d == 0)
	{
		double x = (-b + sqrt(d)) / (2 * a);
		cout << "x = " << x << '\n';
	}
	else cout << "Ingen reelle losninger";
}

void solveQuadraticEquations()
{
	cout << "Skriv inn 3 tall a, b c som gir poylnomet a*x**2 + b*x + c = 0 \n";
	double a;
	double b;
	double c;
	cin >> a >> b >> c;
	printRealRoots(a, b, c);
}

vector<double> calculateSeries(double totaltLan, double rente, double avdrag)
{
	double resterendeLan = totaltLan;
	vector<double> innbetalinger;
	for (double i = 0; i < avdrag; i++)
	{
		double innbetaling = totaltLan / avdrag + rente / 100 * resterendeLan;
		resterendeLan -= innbetaling;
		innbetalinger.push_back(innbetaling);
	}
	return innbetalinger;
}

vector<double> calculateAnnuity(double totaltLan, double rente, double avdrag)
{
	vector<double> innbetalinger;
	for (double i = 0; i < avdrag; i++)
	{
		double innbetaling = totaltLan * (rente / 100) / (1 - pow(1 + rente / 100, -avdrag));
		innbetalinger.push_back(innbetaling);
	}
	return innbetalinger;
}

void laneKalkulator()
{
	cout << "Skriv inn storrelsen pa lanet: ";
	double totaltLan;
	cin >> totaltLan;
	cout << "Skriv inn renten: ";
	double rente;
	cin >> rente;
	cout << "Skriv inn antall nedbetalinger: ";
	double avdrag;
	cin >> avdrag;
	
	vector<double> annuitet = calculateAnnuity(totaltLan, rente, avdrag);
	vector<double> serie = calculateSeries(totaltLan, rente, avdrag);
	double sumAnnuitet = 0;
	double sumSerie = 0;

	int width = 10;

	cout << setw(width) << left << "ar";
	cout << setw(width) << left << "Annuitet";
	cout << setw(width) << left << "Serie";
	cout << setw(width) << left << "Differanse\n";

	
	for (int i = 0; i < avdrag; i++)
	{
		cout << setw(width) << setprecision(2) << fixed << right << i + 1;
		cout << setw(width) << right << setprecision(2) << fixed << annuitet[i];
		cout << setw(width) << right << setprecision(2) << fixed << serie[i];
		cout << setw(width) << right << setprecision(2) << annuitet[i] - serie[i] << '\n';
		sumAnnuitet += annuitet[i];
		sumSerie += serie[i];
	}
	
	cout << setw(width) << left << "Total";
	cout << setw(width) << right << setprecision(2) << fixed << sumAnnuitet;
	cout << setw(width) << right << setprecision(2) << fixed << sumSerie;
	cout << setw(width) << right << setprecision(2) << fixed << sumAnnuitet - sumSerie << '\n';
}

int main()
{
	cout << "Velg funskjon: \n";
	cout << "0) Avslutt \n";
	cout << "1) Summer to tall\n";
	cout << "2) Smmer flere tall\n";
	cout << "3) Konverter NOK til EURO\n";
	cout << "4) Skriv ut en gangetabell\n";
	cout << "5) Los en andregradsligning\n";
	cout << "6) Bruk lanekalkulatoren\n";
	cout << "Angi valg (0 - 6): ";

	int brukerValg;
	cin >> brukerValg;
	
	while (brukerValg)
	{
		if (brukerValg == 1) inputIntegerAndPrintSum();
		else if (brukerValg == 2) inputIntegersUsingLoopAndPrintSum();
		else if (brukerValg == 3) nokToEuro();
		else if (brukerValg == 4) gangeTabell();
		else if (brukerValg == 5) solveQuadraticEquations();
		else if (brukerValg == 6) laneKalkulator();
		else
		{
			cout << "Ugyldig valg; prov igjen.\n";
		}
		cout << "Angi nytt valg: ";
		cin >> brukerValg;
	}

	return 0;
}