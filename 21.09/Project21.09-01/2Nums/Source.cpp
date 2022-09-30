#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n1;
	int n2;
	cout << "Enter first number:" << endl;
	cin >> n1;
	cout << endl << "Enter second number:" << endl;
	cin >> n2;
	
	float a_average = (n1 + n2) / 2;

	float g_average = sqrt(n1 * n2);

	cout << "Arithmetic: " << a_average << " Geometric: " << g_average;


	return 0;
}