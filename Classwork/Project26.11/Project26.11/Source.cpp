#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

using namespace std;

struct Point {

	int x;
	int y;
	friend istream& operator>>(istream& is, Point& point) {
		is >> point.x >> point.y;
		return is;
	}

	friend ostream& operator<<(ostream& os, Point& point) {
		os << "(" << point.x << ',' << point.y << ')';
		return os;
	}

};


class Circle {

private:
	Point point;
	int radius;

public:
	Circle() : point(), radius(0) {

	}

	Circle(Point p, int r) : point(p), radius(r) {

	}

	Circle(const Circle& circle) : point(circle.point), radius(circle.radius) {

	}

	friend istream& operator>>(istream& is, Circle& circle) {
		is >> circle.radius;

		is >> circle.point;

		return is;
	}

	friend ostream& operator<<(ostream& os, Circle& circle) {
		os << circle.point << " r=" << circle.radius << endl;
		return os;
	}

	//gets
	Point getCenter() {

		return point;

	}

	int getRadius() {
		return radius;
	}

	//sets

	void setCenter(Point p) {
		point = p;
	}

	void setRadius(int r) {

		radius = r;

	}
	
	double area() {
		return 3.14 * pow(radius, 2);
	}

	double length() {
		return 2 * 3.14 * radius;
	}

	int coordinateQuarter() {
		if (point.x >= 0 && point.y >= 0) {
			return 1;
		}
		else if (point.x <= 0 &&point.y >= 0) {
			return 2;
		}
		else if (point.x <= 0 && point.y <= 0) {
			return 3;
		}
		else {
			return 0;
		}

	}

	bool checkIntersection(Circle other) {
		double distance = sqrt(pow(abs(point.x - other.point.x), 2) + pow(abs(point.y - other.point.y), 2));

		if (distance <= radius + other.radius) {
			return true;
		}
		return false;
	}


	//comparation operators
	bool operator==(Circle& other) {

		if (area() == other.area()) {
			return true;
		}
		return false;
	}

	bool operator!=(Circle& other) {

		if (area() != other.area()) {
			return true;
		}
		return false;
	}

	bool operator>(Circle& other) {

		if (area() > other.area()) {
			return true;
		}
		return false;
	}
	bool operator<(Circle& other) {

		if (area() < other.area()) {
			return true;
		}
		return false;
	}
	bool operator>=(Circle& other) {

		if (area() >= other.area()) {
			return true;
		}
		return false;
	}
	bool operator<=(Circle& other) {

		if (area() <= other.area()) {
			return true;
		}
		return false;
	}


};

void sortCircles(Circle* circles, int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (circles[j] < circles[j + 1]) {
				Circle temp = circles[j];
				circles[j] = circles[j + 1];
				circles[j + 1] = temp;
			}
		}
	}
}

int main() {
	int n = 10;
	Circle* circles = new Circle[n];

	ifstream ifs;
	ofstream ofs("output.txt");

	ifs.open("data.txt");
	
	for (int i = 0; i < n; i++) {

		ifs >> circles[i];

	}

	sortCircles(circles, n);

	for (int i = 0; i < n; i++) {

		ofs << circles[i];

	}


	//count intersections
	int circleIndex;
	cout << "Enter circle index you want to compare with (0-9)" << endl;
	cin >> circleIndex;
	int count = 0;

	for (int i = 0; i < n; i++) {

		if (i != circleIndex) {
			if (circles[circleIndex].checkIntersection(circles[i])) {
				count++;

			
			}
		}

	}

	ofs << "There are " << count << " intersections with " << circles[circleIndex];

	//get first coordinate quarter Circles
	ofs << "These circle lengths are in first quarter:";
	for (int i = 0; i < n; i++) {
		if (circles[i].coordinateQuarter() == 1) {
			ofs << circles[i].length() << endl;
		}
	}


	ifs.close();
	ofs.close();

	return 0;
}