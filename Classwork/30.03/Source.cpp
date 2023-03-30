#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <fstream>
#include <iomanip>

using namespace std;

string Tab(double (*func)(double), double min, double max, double step) {
	ostringstream table;
	table.precision(2);
	table <<  "|___________________|\n";
	table << "|" << setw(8) << "x" << "|" << setw(10) << "func(x)" << "|" << endl;
	table << "|___________________|\n";
	for (double i = min; i < max + step; i += step) {
		table << "|" << setw(8) << i << "|" << setw(10) << func(i) << "|" << endl;
		table << "|___________________|\n";
	}
	table << endl << endl << endl;
	return table.str();
}

double f(double x) {
	return pow(x, 3) + pow(x, 2) - 8 * x + 9;
}

int main() {

	ofstream file("return.txt");
	file << "sinX" << endl;
	file << Tab(sin, -1, 3, 0.5);
	file << "cosX" << endl;
	file << Tab(cos, -1, 3, 0.5);
	file << "x^3 + x^2 - 8x + 9" << endl;
	file << Tab(f, -1, 3, 0.5);
	file << "sinX + 8tgX - 24x^2" << endl;
	file << Tab([](double x) {return sin(x) + 8 * tan(x) - 24 * pow(x, 2); }, -1, 3, 0.5);

	file.close();
	return 0;
}