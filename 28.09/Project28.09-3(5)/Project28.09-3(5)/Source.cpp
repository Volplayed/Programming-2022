#include <iostream>

using namespace std;

//������ x � ����� �����, ��������� �������� ������


int main()
{
	double x; //input num
	cout << "Enter number: " << endl;
	cin >> x;

	double ur; //under root

	ur = pow(x, 8.0) + pow(8.0, x);

	if (ur < 0)
	{
		cout << endl << "Error! Can`t take root of negative number";
		return 1;
	}

	long double f; //function result
	f = pow( ur, 1.0 / 8.0);

	cout << endl << "Result: " << f;
	return 0;
}