#include <iostream>
#include <string>
#include <vector>

using namespace::std;

void test(int *test)
{
	cout << *test * *test << endl;
}

int main()
{
	int a = 2;
	test(&a);
	return 0;
}

