#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

using namespace std;

string ukr(string name) {
	return "З днем народження " + name;
}
string eng(string name) {
	return "Happy birthday " + name;
}
string jap(string name) {
	return "お誕生日おめでとう " + name;
}

void happyBirthday(string(*lang)(string), string name) {

	ostringstream os;
	os << lang(name);

	ofstream file("greeting.txt");
	
	if (!file.is_open()) {
		throw runtime_error("Failed to open file!");
	}

	file << os.str();

	file.close();

}

void start(string name) {
	int lang;
	cout << "Enter the language(1 - english, 2 - ukrainian, 3 - japanese)" << endl;
	cin >> lang;
	try {
		switch (lang)
		{
		case 1:
			happyBirthday(eng, name);
			break;
		case 2:
			happyBirthday(ukr, name);
			break;
		case 3:
			happyBirthday(jap, name);
			break;
		default:
			throw(invalid_argument("No such language avaliable"));
			break;
		}
	}
	catch (const invalid_argument& e) {
		cerr << "Error: " << e.what() << endl;
		start(name);
	}

	catch (const runtime_error& e) {
		cerr << "Error: " << e.what() << endl;
		abort();
	}
}

//check if wrong symbols in name
void wrongName(string name) {
	if (name.size() > 1019) {
		throw(length_error("Name is too long"));
	}
}

string getName() {
	string name;
	cout << "Enter the name" << endl;
	cin >> name;

	try {
		wrongName(name);
		return name;
	}
	catch (const length_error& e) {
		cerr << "Error: " << e.what() << endl;
		return getName();
	}

}

int main() {
	start(getName());
	return 0;
}