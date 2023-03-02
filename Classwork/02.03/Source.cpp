#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
protected:
	string name;
	int age;
public:
	Person():name(""), age(0) {}
	Person(string n, int a): name(n), age(a) {}

	virtual void input(istream& is) {
		is >> name >> age;
	}

	virtual void output(ostream& os) {
		os << name << " " << age;
	}

	friend ostream& operator<<(ostream& os, Person& person) {
		person.output(os);

		return os;
	}

	virtual double getIncome() = 0;

	friend istream& operator>>(istream& is, Person& person) {
		person.input(is);

		return is;
	}

	friend bool operator<(Person& other, Person& other1) {
		if (other.name < other1.name) {
			return true;
		}
		return false;
	}

};

class Student:public Person {
private:
	int group;
	double scolarship;

public:
	Student():group(0), scolarship(0) {}
	void input(istream& is) {
		is >> name >> age >> group >> scolarship;
	}
	void output(ostream& os) {
		os << name << " " << age << " " << group << " " << scolarship << endl;
	}
	double getIncome() {
		return scolarship;
	}

};

class Worker:public Person {
private:
	double income;
public:
	Worker(): income(0) {}

	void input(istream& is) {
		is >> name >> age >> income;
	}
	void output(ostream& os) {
		os << name << " " << age << " " << income << endl;
	}

	double getIncome() {
		return income;
	}

};

int main() {

	vector<Person*> arr;

	ifstream file("data.txt");

	while (!file.eof()) {
		int num;
		Person* temp;
		file >> num;
		if (num == 1) {
			temp = new Student;

		}
		else {
			temp = new Worker;
		}

		temp->input(file);

		arr.push_back(temp);
	}
	double sum = 0;

	for (int i = 0; i < arr.size(); i++) {

		sum += arr[i]->getIncome();
	}
	cout << sum << endl;

	sort(arr.begin(), arr.end(), [](Person* a, Person* b) {return a < b; });

	for (int i = 0; i < arr.size(); i++) {

		arr[i]->output(cout);
	}

	return 0;
}