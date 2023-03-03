#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
//#1
class Phone {
protected:
	string name;
	string company;
	double price;

public:
	Phone(): name(""), company(""), price(0) {}

	virtual void Input(istream& is) {
		is >> name >> company >> price;
	}

	virtual void Output(ostream& os) {
		os << name << " (" << company << ") - " << price << "$|\n";
	}

	friend istream& operator>>(istream& is, Phone& phone) {
		phone.Input(is);

		return is;
	}

	friend ostream& operator<<(ostream& os, Phone& phone) {
		phone.Output(os);

		return os;
	}

	bool operator<(Phone& other) {
		if (price < other.price) {
			return true;
		}
		return false;
	}

	double getPrice() {
		return price;
	}

	virtual int getType() = 0;

	virtual bool getAnsweringMachine() = 0;
};

class Mobile : public Phone {
private:
	string color;
	int memory;

public:
	Mobile(): color("Black"), memory(0) {}

	void Input(istream& is) {
		is >> name >> company >> price >> color >> memory;
	}
	void Output(ostream& os) {
		os << name << " " << color << " (" << company << ") - " << price << "$| Memory: " << memory << endl;
	}

	int getType() {
		return 1;
	}
	bool getAnsweringMachine() {
		return false;
	}
};

class RadioPhone : public Phone {
private:
	double radius;
	bool answeringMachine;

public:
	RadioPhone() : radius(0), answeringMachine(false) {}

	void Input(istream& is) {
		is >> name >> company >> price >> radius >> answeringMachine;
	}
	void Output(ostream& os) {
		os << name << " (" << company << ") - " << price << "$| Radius: " << radius << " Answering machine: " << ((answeringMachine) ?  "Yes" : "No") << endl;
	}

	bool getAnsweringMachine() {
		return answeringMachine;
	}
	int getType() {
		return 2;
	}

};

//#2

class Note {
protected:
	string subject;
	int number;
public:
	Note():subject(""), number(0) {}

	virtual void Input(istream& is) = 0;
	virtual void Output(ostream& os) = 0;

	friend istream& operator>>(istream& is, Note& note) {
		note.Input(is);

		return is;
	}
	friend ostream& operator>>(ostream& os, Note& note) {
		note.Output(os);

		return os;
	}

	string getSubject() {
		return subject;
	}
	int getNumber() {
		return number;
	}

	virtual string getDevice() = 0;
};

class PaperNote : public Note {
private:
	int size;
	string place;

public:
	PaperNote(): size(0), place("") {}

	void Input(istream& is) {
		is >> subject >> number >> size >> place;
	}

	void Output(ostream& os) {
		os << subject << " " << number << " Size: " << size << "; Hid in " << place << endl;
	}
	string getDevice() {
		return "";
	}
};

class ENote : public Note {
private:
	string device;
public:
	ENote() : device("") {}

	void Input(istream& is) {
		is >> subject >> number >> device;
	}

	void Output(ostream& os) {
		os << subject << " " << number << " Device: " << device << endl;
	}

	string getDevice(){
		return device;
	}
};

class Student {
private:
	string* fullName;
	string group;
	vector<Note*> notes;
public:
	Student() : group("") {
		fullName = new string[3];
	}

	friend istream& operator>>(istream& is, Student& student) {
		student.fullName = new string[3];
		is >> student.fullName[0] >> student.fullName[1] >> student.fullName[2] >> student.group;
		
		return is;
	}

	void addNote(Note* note) {
		notes.push_back(note);
	}

	vector<Note*> getNotes() {
		return notes;
	}
};


int main() {

	//#1
	/*
	vector<Phone*> arr;

	ifstream file1("data1.txt");

	while (!file1.eof()) {
		int num;
		Phone* temp;
		file1 >> num;
		if (num == 1) {
			temp = new Mobile;

		}
		else {
			temp = new RadioPhone;
		}

		temp->Input(file1);

		arr.push_back(temp);
	}
	file1.close();
	ifstream file2("data2.txt");

	while (!file2.eof()) {
		int num;
		Phone* temp;
		file2 >> num;
		if (num == 1) {
			temp = new Mobile;

		}
		else {
			temp = new RadioPhone;
		}

		temp->Input(file2);

		arr.push_back(temp);
	}

	file2.close();

	double sum = 0;

	for (int i = 0; i < arr.size(); i++) {
		sum += arr[i]->getPrice();
	}

	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = i; j < arr.size(); j++)
		{
			if (arr[i]->getPrice() < arr[j]->getPrice())
			{
				swap(arr[i], arr[j]);
			}
		}
	}

	ofstream file3("return.txt");

	for (int i = 0; i < arr.size(); i++) {
		file3 << arr[i]->getType() << " ";
		arr[i]->Output(file3);
	}

	file3 << "Sum: " << sum << endl;

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i]->getAnsweringMachine()) {
			arr[i]->Output(file3);
		}
	}
	*/

	vector<Student> arr;

	ifstream file1("student.txt");

	int c = -1;

	while (!file1.eof()) {
		int num;
		Note* temp;
		file1 >> num;
		if (num == 0) {
			
			Student* stud = new Student;
			file1 >> *stud;
			arr.push_back(*stud);
			
			c++;
		}
		else if (num == 1) {
			
			temp = new PaperNote;
			temp->Input(file1);
			arr[c].addNote(temp);
		}
		else {
			temp = new ENote;
			temp->Input(file1);
			arr[c].addNote(temp);
		}

	}

	file1.close();

	vector<Note*> allNotes;

	for (int i = 0; i < arr.size(); i++) {
		vector<Note*> tempArr = arr[i].getNotes();
		for (int j = 0; j < tempArr.size(); j++) {
			allNotes.push_back(tempArr[j]);
		}
	}

	ofstream file2("return1.txt");


	//number sort
	sort(allNotes.begin(), allNotes.end(), [](Note* a, Note* b) {return a->getNumber() < b->getNumber(); });

	for (int i = 0; i < allNotes.size(); i++) {
		allNotes[i]->Output(file2);
	}

	file2 << "-------------------------------------\n";

	//subject sort
	sort(allNotes.begin(), allNotes.end(), [](Note* a, Note* b) {return a->getSubject() < b->getSubject(); });

	for (int i = 0; i < allNotes.size(); i++) {
		allNotes[i]->Output(file2);
	}

	file2.close();

	ofstream file3("return2.txt");

	int counter = 0;

	for (int i = 0; i < allNotes.size(); i++) {
		if (allNotes[i]->getDevice() == "Mobile") {
			allNotes[i]->Output(file3);
			counter++;
		}
	}

	file3 << "Amount: " << counter << endl;

	file3.close();

	return 0;
}