#include <iostream>

using namespace std;

//number 19
//A)

//int main()
//{
//	int  i;
//	int n;
//
//	//user input
//	cout << "Enter i and n: ";
//	cin >> i >> n;
//
//	double sum = 0;
//	double ans;
//
//	cout << "Enter elements: ";
//	//main loop
//	for (int j = 1; j <= n; ++j)
//	{
//		double a;
//		cin >> a;
//		if (j != i)
//		{
//			sum += a;
//		}
//	}
//
//	//answer calculation
//	ans = sum / (n - 1);
//
//	cout << "Arithmetical mean: " << ans;
//
//	return 0;
//}


//B)

int main()
{
	//user input
	int n;
	cout << "Enter number: ";
	cin >> n;

	//main loop
	for (double x = 1; x <= 1.0 + n * 0.1; x += 0.1)
	{
		double y = (x * x - 3 * x + 2) / pow((2 * pow(x, 3) - 1), 0.5);

		cout << "y = " << y << " when x = " << x << endl;
	}

	return 0;
}