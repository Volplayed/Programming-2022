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

	file << os.str();

	file.close();

}


int main() {
	int lang;
	cout << "Enter the language(1 - english, 2 - ukrainian, 3 - japanese)" << endl;
	cin >> lang;

	string name;
	cout << "Enter the name" << endl;
	cin >> name;

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
		happyBirthday(eng, name);
		break;
	}

	return 0;
}