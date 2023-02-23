#include <iostream>
#include <string>

using namespace std;

class Street {
private:
	string name;
	int count;
public:
	Street():name(""), count(0) {}

	friend istream& operator>>(istream& is, Street& street) {
		cout << "Enter name and number of houses: ";
		is >> street.name >> street.count;

		return is;
	}

	friend ostream& operator<<(ostream& os, Street& street) {
		os << "The " << street.name << " street, has " << street.count << " houses.\n";

		return os;
	}

	void setName(string n) {
		name = n;
	}

	void setCount(int c) {
		count = c;
	}

	string getName() {
		return name;
	}

	int getCount() {
		return count;
	}
};

class City {
private:
	Street* streets;
	int count;
	int lastIndex;
	string name;

public:
	City() : count(0), lastIndex(0), name("") {
		streets = new Street[count];
	}

	City(Street* st, int c, int l, string n) : count(c), lastIndex(l), name(n), streets(st) {}

	City(const City& c): streets(c.streets), count(c.count), lastIndex(c.lastIndex), name(c.name) {}

	friend istream& operator>>(istream& is, City& city) {
		cout << "Enter the name of the city and street count: ";
		is >> city.name >> city.count;
		city.streets = new Street[city.count];
		for (int i = 0; i < city.count; i++) {
			is >> city.streets[i];
			city.lastIndex++;
		}

		return is;
	}

	friend ostream& operator<<(ostream& os, City& city) {
		os << "The " << city.name << ", has " << city.count << " streets.\n";

		return os;
	}

	City& operator=(const City& city) {
		if (this == &city) {
			return *this;
		}

		this->count = city.count;
		this->lastIndex = city.lastIndex;
		this->name = city.name;
		this->streets = city.streets;

		return *this;
	}

	~City() {
		delete[] streets;
	}

	Street& operator[](int index)
	{
		if (index >= count) {
			cout << "Array index out of bound, returning first street";
			return streets[0];
		}
		return streets[index];
	}

	void setName(string n) {
		name = n;
	}
	void setCount(int c) {
		count = c;
	}
	void setLastIndex(int l) {
		lastIndex = l;
	}
	void setStreets(Street* st) {
		streets = st;
	}

	string getName() {
		return name;
	}
	int getCount() {
		return count;
	}
	int getLastIndex() {
		return lastIndex;
	}
	Street* getStreets() {
		return streets;
	}

	int getNameLength() {
		return name.length();
	}

};

void sort(City* arr, int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j].getCount() < arr[j + 1].getCount()) {
				City temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int maxNameIndex(City* arr, int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].getNameLength() > arr[max].getNameLength()) {
			max = i;
		}
	}
	return max;
}

int minCountIndex(City* arr, int n) {
	int min = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].getCount() < arr[min].getCount()) {
			min = i;
		}
	}

	return min;
}

int main() {

	City* cities = new City[2];

	City c1, c2;
	cin >> c1 >> c2;
	cities[0] = c1;
	cities[1] = c2;

	sort(cities, 2);

	for (int i = 0; i < 2; i++) {
		cout << cities[i];
	}

	int* cityNameLength = new int[2];

	int max = maxNameIndex(cities, 2);

	int c = cities[max].getCount();

	for (int i = 0; i < c; i++) {
		cout << "124124";
		cout << cities[max][i];
	}

	int min = minCountIndex(cities, 2);

	City c3 = cities[min];

	cities = new City[3]{ c1, c2, c3 };

	sort(cities, 3);

	for (int i = 0; i < 3; i++) {
		cout << cities[i];
	}


	return 1;
}