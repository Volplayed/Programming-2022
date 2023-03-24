#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//-----1--------
struct Person {
	string name;
	string adress;
	Person(string n, string ad): name(n), adress(ad) {}

	bool operator<(Person& other) {
		if (name < other.name) {
			return true;
		}
		return false;
	}
	bool operator>(Person& other) {
		if (name > other.name) {
			return true;
		}
		return false;
	}

	friend ostream& operator<<(ostream& os, Person& person) {
		os << person.name;
		return os;
	}
};

template <typename T>
void sort(T* arr, size_t n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
template <typename T>
void printArr(T* arr, size_t n) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
}


//------2--------
struct Milk {
	string name;
	int fatness;

    Milk():name(""), fatness(0) {}
    Milk(string n, int f): name(n), fatness(f) {}

	friend ostream& operator<<(ostream& os, Milk& milk) {
		os << milk.name << ' ' << milk.fatness;
		return os;
	}
	friend istream& operator>>(istream& is, Milk& milk) {
		is >> milk.name >> milk.fatness;
		return is;
	}

};


//date
struct Date {

    int d;
    int m;
    int y;

    Date(int _d, int _m, int _y) : d(_d), m(_m), y(_y) {}
    // Return if year is leap year or not.
    bool isLeap()
    {
        if (y % 100 != 0 && y % 4 == 0 || y % 400 == 0)
            return true;

        return false;
    }
    bool isLeap(int year)
    {
        if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0)
            return true;

        return false;
    }

    // Given a date, returns number of days elapsed
    // from the  beginning of the current year (1st
    // jan).
    int offsetDays()
    {
        int offset = d;

        switch (m - 1)
        {
        case 11:
            offset += 30;
        case 10:
            offset += 31;
        case 9:
            offset += 30;
        case 8:
            offset += 31;
        case 7:
            offset += 31;
        case 6:
            offset += 30;
        case 5:
            offset += 31;
        case 4:
            offset += 30;
        case 3:
            offset += 31;
        case 2:
            offset += 28;
        case 1:
            offset += 31;
        }

        if (isLeap() && m > 2)
            offset += 1;

        return offset;
    }

    // Given a year and days elapsed in it, finds
    // date by storing results in d and m.

    void revoffsetDays(int offset)
    {
        int month[13] = { 0, 31, 28, 31, 30, 31, 30,
                          31, 31, 30, 31, 30, 31 };

        if (isLeap())
            month[2] = 29;

        int i;
        for (i = 1; i <= 12; i++)
        {
            if (offset <= month[i])
                break;
            offset = offset - month[i];
        }

        d = offset;
        m = i;
    }


    // Add x days to the given date.
    void addDays(int x)
    {
        int offset1 = offsetDays();
        int remDays = isLeap() ? (366 - offset1) : (365 - offset1);

        // y2 is going to store result year and
        // offset2 is going to store offset days
        // in result year.
        int y2, offset2;
        if (x <= remDays)
        {
            y2 = y;
            offset2 = offset1 + x;
        }

        else
        {
            // x may store thousands of days.
            // We find correct year and offset
            // in the year.
            x -= remDays;
            y2 = y + 1;
            int y2days = isLeap(y2) ? 366 : 365;
            while (x >= y2days)
            {
                x -= y2days;
                y2++;
                y2days = isLeap(y2) ? 366 : 365;
            }
            offset2 = x;
        }
        y = y2;

        // Find values of day and month from
        // offset of result year.
        revoffsetDays(offset2);

    }
    friend ostream& operator<<(ostream& os, Date& d) {
        os << d.d << '/' << d.m << '/' << d.y;
        return os;
    }
    friend istream& operator>>(istream& is, Date& d) {
        is >> d.d >> d.m >> d.y;
        return is;
    }

};



template <typename T>
class Good {
private:
    T good;
    Date date;
    int expirationTime;

public:

    Good() : good(), date(Date(1, 1, 2000)), expirationTime(0) {}
    Good(T g, Date d, int exp) : good(g), date(d), expirationTime(exp) {}



    friend ostream& operator<<(ostream& os, Good& g) {
        Date temp = g.getExpirationDate();
        os << g.good << ' ' << g.date << " Expiration date:" << temp << endl;
        return os;
    }
    friend istream& operator>>(istream& is, Good& g) {
        is >> g.good >> g.date >> g.expirationTime;
        return is;
    }

    Date getExpirationDate() {
        Date temp = date;
        temp.addDays(expirationTime);
        return temp;
    }


};


int main() {
	//----1-----
	/*int* arr1 = new int[3] {4, 2, 7};
	string* arr2 = new string[3]{"Hi", "So", "Sad"};
	Person* arr3 = new Person[3]{ Person("Mike", "1"), Person("John", "1"), Person("Sam", "1") };

	printArr(arr1, 3);
	printArr(arr2, 3);
	printArr(arr3, 3);

	sort(arr1, 3);
	sort(arr2, 3);
	sort(arr3, 3);

	printArr(arr1, 3);
	printArr(arr2, 3);
	printArr(arr3, 3);*/
	

	//---------2---------
    vector<Good<string>> strvec;
    vector<Good<Milk>> milkvec;

    for (int i = 0; i < 3; i++) {
        Good<string> inp;
        cin >> inp;
        strvec.push_back(inp);
    }

    for (int i = 0; i < 3; i++) {
        Good<Milk> inp;
        cin >> inp;
        milkvec.push_back(inp);
    }

    for (int i = 0; i < 3; i++) {
        cout << strvec[i];
    }

    for (int i = 0; i < 3; i++) {
        cout << milkvec[i];
    }
    

	return 1;
}