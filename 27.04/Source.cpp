#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

list<char> input() {
	list<char> lst;

	while (true) {
		char c;
		cin >> noskipws;
		cin >> c;
		if (c == '\n') {
			return lst;
		}
		lst.push_back(c);
	}

	return lst;
}

list<char> change(list<char> lst) {
	//find first .
	list<char>::iterator it; //iterator of first .

	it = find(lst.begin(), lst.end(), '.');
	if (it == lst.end()) {
		throw(invalid_argument("No dot in string"));
	}

	//delete , before first .
	while (true) {

		list<char>::iterator i = find(lst.begin(), it, ',');

		if ((*i) == '.') {
			break;
		}
		lst.erase(i);
	}
	replace(it, lst.end(), '3', '+');

	return lst;
}

void output(list<char> lst) {
	for (char c : lst) {
		cout << c;
	}
}

int main() {
	try {

		list<char> lst;
		lst = input();
		lst = change(lst);
		output(lst);
	}
	catch (invalid_argument& e) {
		cerr << "Invalid argument: " << e.what() << endl;
	}
	catch (exception& e) {
		cerr << "Exception: " << e.what() << endl;
	}
	return 0;
}