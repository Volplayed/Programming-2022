#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Exhibit {
protected:
	string name;
	string author;
public:
	Exhibit() :name(""), author("") {}
	Exhibit(string n, string a) :name(n), author(a) {}

	virtual void Input(istream& is) {
		is >> name >> author;
	}
	virtual void Output(ostream& os) {
		os << name << " - " << author << endl;
	}

	friend ostream& operator<<(ostream& os, Exhibit& exhibit) {
		exhibit.Output(os);
		return os;
	}
	friend istream& operator>>(istream& is, Exhibit& exhibit) {
		exhibit.Input(is);
		return is;
	}

	virtual int GetType() = 0;

	string GetAuthor() {
		return author;
	}

	virtual string GetMaterial() = 0;

};

class Picture : public Exhibit {
private:
	int size;
	string style;
public:
	Picture() :size(0), style("") {}

	void Input(istream& is) {
		is >> name >> author >> size >> style;
	}
	void Output(ostream& os) {
		os << name << " - " << author << " Type: Picture " << size << " Style: " << style << endl;
	}
	int GetType() {
		return 1;
	}
	string GetMaterial() {
		cout << "Picture has no variable 'material'";
		return NULL;
	}
};

class Sculpture : public Exhibit {
private:
	string material;
public:
	Sculpture(): material("") {}

	void Input(istream& is) {
		is >> name >> author >> material;
	}
	void Output(ostream& os) {
		os << name << " - " << author << " Type: Sculpture " << material << endl;
	}
	int GetType() {
		return 2;
	}
	string GetMaterial() {
		return material;
	}
};


int main() {

	vector<Exhibit*> vector;

	ifstream file("data.txt");
	Exhibit* temp;

	//read
	while (!file.eof()) {
		int type;
		file >> type;

		if (type == 1) {
			temp = new Picture;
		}
		else {
			temp = new Sculpture;
		}
		temp->Input(file);

		vector.push_back(temp);
	}

	file.close();

	//sort
	sort(vector.begin(), vector.end(), [](Exhibit* ex1, Exhibit* ex2) {return ex1->GetAuthor() < ex2->GetAuthor(); });

	ofstream file1("return.txt");

	for (int i = 0; i < vector.size(); i++) {
		vector[i]->Output(file1);
	}

	//user input
	cout << "Enter author name: ";
	string input;
	cin >> input;
	bool flag = false;

	for (int i = 0; i < vector.size(); i++) {
		if (vector[i]->GetAuthor() == input && vector[i]->GetType() == 1) {
			vector[i]->Output(cout);
			flag = true;
		}
	}
	if (!flag) {
		cout << "Author " << input << " is not found";
	}

	int counter = 0;

	for (int i = 0; i < vector.size(); i++) {
		if (vector[i]->GetType() == 2) {
			if (vector[i]->GetMaterial() == "Marble") {
				counter++;
			}
		}
	}

	cout << endl << "There are " << counter << " marble " << (counter == 1 ? "sculpture!" : "sculpures!");

	return 1;
}