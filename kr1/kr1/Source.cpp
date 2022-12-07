#include <iostream>

#define _USE_MATH_DEFINES
#include <string>
#include <math.h>
using namespace std;


class Circle {
private:
	string color;
	double r;

public:
	Circle():color("white"), r(0){}
	Circle(const Circle& circle):color(circle.color), r(circle.r){}
	Circle(string col, double rad):color(col), r(rad){}

	friend istream& operator>>(istream& is, Circle& circle) {
		cout << "Enter circle color:" << endl;
		is >> circle.color;
		cout << "Enter circle radius:" << endl;
		is >> circle.r;

		return is;
	}

	friend ostream& operator<<(ostream& os, Circle& circle) {
		cout << "The cirlce is " << circle.color << " with radius = " << circle.r << endl;
		return os;
	}

	//compare area with other circles
	bool operator==(Circle& circle) {
		if (circle.area() == area()) {
			return true;
		}
		return false;
	}

	bool operator!=(Circle& circle) {
		if (circle.area() != area()) {
			return true;
		}
		return false;
	}
	bool operator>=(Circle& circle) {
		if (circle.area() <= area()) {
			return true;
		}
		return false;
	}
	bool operator<=(Circle& circle) {
		if (circle.area() >= area()) {
			return true;
		}
		return false;
	}
	bool operator>(Circle& circle) {
		if (circle.area() < area()) {
			return true;
		}
		return false;
	}
	bool operator<(Circle& circle) {
		if (circle.area() > area()) {
			return true;
		}
		return false;
	}


	//comapre radius with double number
	bool operator<(double& k) {
		if (r < k) {
			return true;
		}
		return false;
	}

	string getColor() {
		return color;
	}

	double getR() {
		return r;
	}

	void setColor(string col) {
		color = col;
	}

	void setR(double r_) {
		r = r_;
	}

	double area() {
		return M_PI * pow(r, 2);
	}
};

int main() {
	int n = 7;

	Circle* circles = new Circle[n];

	for (int i = 0; i < n; i++) {
		cout << "Circle - " << i + 1 << endl;
		cin >> circles[i];
	}

	for (int i = 0; i < n; i++) {
		if (circles[i].getColor() == "blue") {
			cout << "Area of blue circle " << circles[i].area() << endl;;
		}
	}

	Circle max = circles[0];
	for (int i = 0; i < n; i++) {
		if (max < circles[i]) {
			max = circles[i];
		}
	}
	cout << "Max circle area:" << endl;
	cout << max;

	double k;
	cout << "Enter max radius to change color:" << endl;
	cin >> k;

	for (int i = 0; i < n; i++) {
		if (circles[i] < k) {
			circles[i].setColor("red");
		}
	}

	for (int i = 0; i < n; i++) {
		cout << circles[i];
	}

	return 0;
}