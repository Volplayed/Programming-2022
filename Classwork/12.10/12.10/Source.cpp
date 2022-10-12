#include <iostream>
#include <math.h>
#include <string>

using namespace std;

//celsius -> fahrenheit 1

//int main()
//{
//	for (int c = 0; c <= 100; ++c)
//	{
//		double f = 9.0 / 5.0 * c + 32;
//
//		cout << "C: " << c << " F: " << f << endl;
//	}
//
//	return 0;
//}


//biggest k 2

//int main() {
//
//	int m;
//	cout << "Enter m: ";
//	cin >> m;
//	cout << endl;
//	int k = 0;
//	while (pow(4, k) < m)
//	{
//		k += 1;
//	}
//	cout << k;
//	return 0;
//}


//fibonacci 3

//int fib(int n)
//{
//	if (n == 1)
//	{
//		return 0;
//	}
//
//	if (n == 2)
//	{
//		return 1;
//	}
//
//	return fib(n - 1) + fib(n - 2);
//
//}

//int main()
//{
//	int num;
//	cout << "Enter num: ";
//	cin >> num;
//	cout << endl << fib(num);
//
//	return 0;
//}

//natural num 4

//int main()
//{
//    int a, reversed_number = 0, remainder;
//
//    cout << "Enter an integer: ";
//    cin >> a;
//
//    while (a != 0) {
//        remainder = a % 10;
//        reversed_number = reversed_number * 10 + remainder;
//        a /= 10;
//    }
//
//    cout << "Reversed Number = " << reversed_number;
//   return 0;
//}


//euclide 5

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    int a, b;
    cout << "Enter a and b: " << endl;
    cin >> a >> b;


    cout << "GCD(" << a << ", " << b << ") = " << gcd(a, b)
        << endl;

    return 0;
}