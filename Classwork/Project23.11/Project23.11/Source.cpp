#include <iostream>
#include <string>

using namespace std;
//
//class Car {
//	private:
//		string name;
//		unsigned int price;
//		string color;
//	
//	public:
//		Car():name(""), price(0), color("Black") {
//
//		}
//
//		Car(string n, unsigned int p, string c): name(n), price(p), color(c) {
//		}
//
//		string getName() {
//			return name;
//		}
//
//		int getPrice() {
//			return price;
//		}
//
//		string getColor() {
//			return color;
//		}
//
//		void setData() {
//			cout << "Name" << endl;
//			getline(cin, name);
//			cout << "Price" << endl;
//			cin >> price;
//			cout << "Color" << endl;
//			cin.ignore();
//			getline(cin, color);
//		}
//
//		void setPrice(int p) {
//			price = p;
//		}
//
//		void setName(int n) {
//			name = n;
//		}
//
//		void setColor(int c) {
//			color = c;
//		}
//
//		void print() {
//			cout << color << ' ' << name << " is $" << price << endl;
//		}
//};
//
//int main() {
//
//	Car* cars = new Car[3];
//
//	for (int i = 0; i < 3; i++) {
//		cars[i].setData();
//	}
//
//	for (int i = 0; i < 3; i++) {
//
//		cars[i].print();
//
//	}
//
//	string color;
//
//	cout << "Enter color: " << endl;
//	cin.ignore();
//	getline(cin, color);
//
//	for (int i = 0; i < 3; i++) {
//		cout << cars[i].getColor() << endl;
//		if (color == cars[i].getColor()) {
//			cars[i].print();
//		}
//	}
//
//	for (int i = 0; i < 3; i++) {
//		if ("Grey" == cars[i].getColor()) {
//			cars[i].setPrice(cars[i].getPrice() * 0.9);
//			cars[i].print();
//		}
//	}
//
//	return 0;
//}



class Student {

private:
	string name;
	string group;
	int id;

public:
	Student() : name(""), group(""), id(0) {

	}

	Student(string n, string g, int i): name(n), group(g), id(i) {}

	string getName() {
		return name;
	}

	string getGroup() {
		return group;
	}

	int getId() {
		return id;
	}

	void setName(string n) {
		name = n;
	}

	void setGroup(string g) {
		group = g;
	}

	void setId(int i) {
		id = i;
	}

	void inputData() {
		 
		cout << "Name:" << endl;
		cin >> name;
		cout << "Group:" << endl;
		cin >> group;
		cout << "Id:" << endl;
		cin >> id;

	}

	void print() {
		cout << name << ' ' << group << " Id: " << id << endl;

	}

};

void sort(Student* arr, int n)
{
	Student temp;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j + 1 < n - i; j++)
		{

			if (arr[j].getId() > arr[j + 1].getId())
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

}

int main() {

	int n;
	cin >> n;

	Student *students = new Student[n];

	for (int i = 0; i < n; i++) {
		students[i].inputData();
	}

	string group;
	cout << "Enter group:" << endl;
	cin >> group;
	//a
	for (int i = 0; i < n; i++) {
		if (group == students[i].getGroup()) {
			students[i].print();
		}
	}
	//b 
	string name;
	cout << "Enter name:" << endl;
	cin >> name;
	for (int i = 0; i < n; i++) {
		if (name == students[i].getName()) {
			students[i].print();
		}
	}

	//c
	cout << "Enter name:" << endl;
	cin >> name;
	int new_id;
	for (int i = 0; i < n; i++) {
		if (name == students[i].getName()) {
			cout << "Enter new id:" << endl;
			cin >> new_id;
			students[i].setId(new_id);

			
		}
	}

	//d
	sort(students, n);
	for (int i = 0; i < n; i++) {

		students[i].print();

	}

	return 0;
}