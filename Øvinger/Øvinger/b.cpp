#include "std_lib_facilities.h"

void maxOfTwo(double a, double b)
{
	if (a < b)
	{
		cout << "A is greater than B\n";
	}
	else
	{
		cout << "B is greater than A\n";
	}
}

int fibonacci(int n)
{
	int a = 0;
	int b = 1;
	cout << "Fibonnacci numbers:\n";
	for (int x = 1; x <= n; x++)
	{
		cout << x << ", " << b << "\n";
		int temp = b;
		b += a;
		a = temp;
	}
	cout << "------\n";
	return b;
}

int squareNumberSum(int n)
{
	int totalSum = 0;
	for (int i = 0; i < n; ++i)
	{
		totalSum += i * i;
		cout << i * i << "\n";
	}
	cout << totalSum << "\n";
	return totalSum;
}

void trinagleNumbersBellow(int n)
{
	int acc = 1;
	int num = 2;
	cout << "Trinagle numbers below " << n << ":\n";
	while (acc < n)
	{
		cout << acc << '\n';
		acc += num;
		num++;
	}
	cout << '\n';
}

bool isPrime(int n)
{
	for (int j = 2; j < n; j++)
	{
		if (n%j == 0)
		{
			return false;
		}
	}
	return true;
}

void naviePrimeNumberSearch(int n)
{
	for (int number = 2; number < n; number++)
	{
		if (isPrime(number)) cout << number << " is Prime\n";
	}
}

int findGreatestDivisor(int n)
{
	for (int divisor = n - 1; divisor > 0; divisor--)
		if (n%divisor == 0) return divisor;
}


int main()
{
	cout << "Oppgave a)\n";
	double A = 1;
	double B = 8;
	maxOfTwo(A, B);
	cout << "------------------------\n";

	cout << "Oppgave c)\n";
	int n = 5;
	cout << "The " << n << "th Fibonacci number is ";
	cout << fibonacci(n) << '\n';
	cout << "------------------------\n";

	cout << "Oppgave d)\n";
	n = 6;
	squareNumberSum(n);
	cout << "------------------------\n";

	cout << "Oppgave e) \n";
	n = 22;
	trinagleNumbersBellow(n);
	cout << "------------------------\n";

	cout << "Oppgave f)\n";
	n = 6;
	cout << n << " isPrime is " << isPrime(n) << '\n';
	cout << "------------------------\n";

	cout << "Oppgave g)\n";
	n = 6;
	naviePrimeNumberSearch(n);
	cout << "------------------------\n";

	cout << "Oppgave h)\n";
	n = 33;
	cout << "The greatest divisor of " << n << " is " << findGreatestDivisor(n) << '\n';
	cout << "------------------------\n";

}