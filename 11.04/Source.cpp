#include <iostream>
#include <math.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void halfSort(vector<T>& vec, int i) {
	if (i < 0 || i >= vec.size()) {
		ostringstream os;
		os << "Invalid argument: " << i << "; 'i' is out of range";
		throw invalid_argument(os.str());
	}
	auto it = vec.begin();
	advance(it, i);
	sort(vec.begin(), it);

}

int main() {
	try {
		vector<double> vec1;
		vector<string> vec2;

		int n;


		//input
		cout << "Enter vector lenghts: ";
		cin >> n;

		if (n <= 0 || cin.fail()) {
			throw(length_error("Wrong vector length"));
		}

		cout << "Enter " << n << " doubles:\n";
		for (int i = 0; i < n; i++) {
			double k;
			cin >> k;

			if (cin.fail()) {
				throw(invalid_argument("Please enter double"));
			}

			vec1.push_back(k);
		}
		cout << "Enter " << n << " strings:\n";
		for (int i = 0; i < n; i++) {
			string k;
			cin >> k;

			if (cin.fail()) {
				throw(invalid_argument("Please enter string"));
			}
			vec2.push_back(k);
		}

		int ii;
		cout << "Enter i: ";
		cin >> ii;
		
		if (cin.fail()) {
			throw(invalid_argument("Please enter int"));
		}

		cout << endl << endl;



		for (int i = 0; i < vec1.size(); i++) {
			cout << vec1[i] << endl;
		}
		halfSort(vec1, ii);
		cout << "-----------------------\n";
		for (int i = 0; i < vec1.size(); i++) {
			cout << vec1[i] << endl;
		}

		cout << "-----------------------\n";

		for (int i = 0; i < vec2.size(); i++) {
			cout << vec2[i] << endl;
		}
		halfSort(vec2, ii);
		cout << "-----------------------\n";
		for (int i = 0; i < vec2.size(); i++) {
			cout << vec2[i] << endl;
		}
	}
	catch (invalid_argument& e) {
		cerr << "Invalid argument: " << e.what() << endl;
	}
	catch (length_error& e) {
		cerr << "Length error: " << e.what() << endl;
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
	}
	return 0;
}