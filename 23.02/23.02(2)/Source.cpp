#include <iostream>
#include <string>

using namespace std;

class Student {
private:
	string name;
	unsigned int id;
	string spec;
public:
	Student(): name(""), id(0), spec("") {}
	Student(string n, unsigned int i, string s): name(n), id(i), spec(s) {}
	Student(const Student& student): name(student.name), id(student.id), spec(student.spec) {}
	
	string getSpec() {
		return spec;
	}
	string getName() {
		return name;
	}

	friend istream& operator>>(istream& is, Student& student) {
		cout << "Enter name, id and speciality: ";
		is >> student.name >> student.id >> student.spec;

		return is;
	}

	friend ostream& operator<<(ostream& os, Student& student) {
		os << student.name << " - " << student.spec << endl;

		return os;
	}
};

class Course {
private:
	string name;
	unsigned int id;
	string spec;

public:
	Course() : name(""), id(0), spec("") {}
	Course(string n, unsigned int i, string s) : name(n), id(i), spec(s) {}
	Course(const Course& course) : name(course.name), id(course.id), spec(course.spec) {}

	string getSpec() {
		return spec;
	}
	string getName() {
		return name;
	}

	friend istream& operator>>(istream& is, Course& course) {
		cout << "Enter name, id and speciality: ";
		is >> course.name >> course.id >> course.spec;

		return is;
	}

	friend ostream& operator<<(ostream& os, Course& course) {
		os << course.name << " - " << course.spec << endl;

		return os;
	}
};

class University {
private:
	string name;
	string place;
	Student* students;
	Course* courses;
	int sCount;
	int cCount;

public:
	University(): name(""), place(""), sCount(0), cCount(0) {
		students = new Student[100];
		courses = new Course[100];
	}
	University(string n, string p, Student* s, Course* c, int c1, int c2) : name(n), place(p), students(s), courses(c), sCount(c1), cCount(c2) {}

	void addStudent() {
		Student s;
		cin >> s;

		students[sCount] = s;
		sCount++;
	}

	void addCourse() {
		Course c;
		cin >> c;
		courses[cCount] = c;
		cCount++;
	}

	void removeStudent() {
		cout << "Enter student name: ";
		string n;
		cin >> n;

		int i;
		for (i = 0; i < 100; i++) {
			if (students[i].getName() == n) {
				break;
			}
		}

		for (int j = i; j < 99; j++) {
			students[j] = students[j + 1];
		}

		sCount -= 1;
	}

	void removeCourse() {
		cout << "Enter course name: ";
		string n;
		cin >> n;

		int i;
		for (i = 0; i < 100; i++) {
			if (courses[i].getName() == n) {
				break;
			}
		}

		for (int j = i; j < 99; j++) {
			courses[j] = courses[j + 1];
		}
		cCount -= 1;
	}

	Student* getStudentsOnCourse(string n) {
		string spec;

		for (int i = 0; i < 100; i++) {
			if (courses[i].getName() == n) {
				spec = courses[i].getSpec();
			}
		}

		Student* filtered = new Student[100];
		int k = 0;

		for (int j = 0; j < 100; j++) {
			if (students[j].getSpec() == spec) {
				cout << students[j];
				filtered[k] = students[j];
				k++;
			}
		}

		return filtered;
	}

	Course* getCourseByStudent(string n) {
		string spec;

		for (int i = 0; i < 100; i++) {
			if (students[i].getName() == n) {
				spec = students[i].getSpec();
			}
		}

		Course* filtered = new Course[100];
		int k = 0;

		for (int j = 0; j < 100; j++) {
			if (courses[j].getSpec() == spec) {
				cout << courses[j];
				filtered[k] = courses[j];
				k++;
			}
		}

		return filtered;
	}

	void printStudents() {
		for (int i = 0; i < 100; i++) {
			if (students[i].getName() != "") {

				cout << students[i];
			}
			else {
				break;
			}
		}
	}

	void printCourses() {
		for (int i = 0; i < 100; i++) {
			if (courses[i].getName() != "") {
				cout << courses[i];
			}
			else {
				break;
			}
		}
	}
};

void getCoursesByStudent(University uni) {
	cout << "Enter student name: ";
	string n;
	cin >> n;

	uni.getCourseByStudent(n);
}

void getStudentsOnCourse(University uni) {
	cout << "Enter course name: ";
	string n;
	cin >> n;

	uni.getStudentsOnCourse(n);
}

int main() {
	University uni;

	while (true) {
		int p;
		cout << "0 - list of students\n1 - list of courses\n2 - add student\n3 - remove student\n4 - add course\n5 - remove course\n6 - get courses by student\n7 - get students on course" << endl;
		cin >> p;
		switch (p) {
		case 0:
			uni.printStudents();
			break;
		case 1:
			uni.printCourses();
			break;
		case 2:
			uni.addStudent();
			break;
		case 3:
			uni.removeStudent();
			break;
		case 4:
			uni.addCourse();
			break;
		case 5:
			uni.removeCourse();
			break;
		case 6:
			getCoursesByStudent(uni);
			break;
		case 7:
			getStudentsOnCourse(uni);
			break;
		}
	}

	return 0;
}