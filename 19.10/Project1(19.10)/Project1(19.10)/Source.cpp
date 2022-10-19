#include <iostream>
#include <math.h>

using namespace std;

//19

int main()
{

	//variables init
	double x;
	double h;
	double e = pow(10, -5);
	double x_lst[10], s_lst[10], y_lst[10], p_lst[10];


	//user input
	cout << "Enter x: ";
	cin >> x;
	cout << "Enter h: ";
	cin >> h;
	double sum = 0;
	for (int i = 0; i < 10; ++i)
	{
		x_lst[i] = x + h * i;

		y_lst[i] = log((1 + x) / (x));




		for (int k = 1; (pow(x, k) / k) - (pow(x, k - 2) / (k - 2)) >= e; k += 2)
		{
			sum += pow(x, k) / k;
			s_lst[i] = sum * 2;
		}
		sum = 0;
		p_lst[i] = abs((s_lst[i] - y_lst[i]) / y_lst[i]) * 100;

	}

	cout << endl << "X   S   Y   Pohybka";

	for (int i = 0; i < 10; ++i)
	{
		cout << endl << x_lst[i] << "  " << s_lst[i] << "  " << y_lst[i] << "  " << p_lst[i];
	}



	return 0;
}