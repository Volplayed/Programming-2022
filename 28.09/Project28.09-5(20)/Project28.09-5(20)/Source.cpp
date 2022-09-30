#include <iostream>
#include <math.h>
using namespace std;

//Перевірити, чи введені три натуральні числа можуть бути послідовними членами деякої арифметичної  послідовності

int main()
{
	unsigned int x, y, z; //input numbers

	cout << "Enter x: ";
	cin >> x;
	cout << endl << "Enter y: ";
	cin >> y;
	cout << endl << "Enter z: ";
	cin >> z;

	unsigned int lst[] = {x, y, z};
	
	bool answer = false;

	int d1 = lst[1] - lst[0];
	int d2 = lst[2] - lst[0];
	cout << d1 << endl << d2;

	if (d1 / d2 == 2 || d2 / d1 == 2)
	{
		answer = true;
	}
	else if (d1 / d2 == -1)
	{
		answer = true;
	}

	
	
	
	cout << endl << answer;

	return 0;
}