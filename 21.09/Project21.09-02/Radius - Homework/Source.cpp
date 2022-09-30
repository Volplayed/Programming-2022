#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace std;

int main()
{
	float pi = M_PI;
	float radius;
	cout << "Enter radius: " << endl;
	cin >> radius;
	
	float l = pi * radius * 2;
	float s = pi * radius * radius;
	float v = 2 * pi * radius * radius * radius / 3;

	cout << "Length: " << l << " Squere: " << s << " Volume: " << v << endl;


	return 0;
}