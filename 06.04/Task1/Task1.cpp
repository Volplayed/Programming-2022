#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <math.h>

using namespace std;


ostringstream Modified(double* arr, size_t n, double (*f)(double)) {
	ostringstream os;
	os << setprecision(2) << fixed;
	os << "|" << setw(3) << "i" << setw(3) << "|" << setw(8) << "A[i]" << setw(4) << "|" << setw(9) << "F(A[i])" << setw(3) << "|" << endl;
	for (int i = 0; i < n; i++) {
		os << "|" << setw(3) << i << setw(3) << "|" << setw(8) << arr[i] << setw(4) << "|" << setw(9)  <<  f(arr[i]) << setw(3) << "|" << endl;
	}
	return os;
}

double Sqr(double x) {
	return x * x;
}

int main() {
	size_t n;
	cin >> n;



	double* arr = new double[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	ofstream file("return.txt");


	file << "x^2" << endl;
	file << Modified(arr, n, Sqr).str() << endl;
	file << "sin(x) + cos(x) - tg(x)" << endl;
	file << Modified(arr, n, [](double x) {return sin(x) + cos(x) - tan(x); }).str() << endl;
	file << "round(x)" << endl;
	file << Modified(arr, n, round).str();
	

	return 0;
}