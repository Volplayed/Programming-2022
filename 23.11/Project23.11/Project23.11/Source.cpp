#include <iostream>
#include <string>

using namespace std;

//enum, struct #1

enum Month {
	NONE,
	JANUARY,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
};

string get_first(string str) {
	string first_part;
	for (int i = 0; i < 3; i++) {
		first_part += tolower(str[i]);
	}

	return first_part;

}


Month str_to_month(string str) {

	string first = get_first(str);

	if (first == "jan") {
		return JANUARY;
	}
	else if (first == "feb") {
		return FEBRUARY;
	}
	else if (first == "mar") {
		return MARCH;
	}
	else if (first == "apr") {
		return APRIL;
	}
	else if (first == "may") {
		return MAY;
	}
	else if (first == "jun") {
		return JUNE;
	}
	else if (first == "jul") {
		return JULY;
	}
	else if (first == "aug") {
		return AUGUST;
	}
	else if (first == "sep") {
		return SEPTEMBER;

	}
	else if (first == "oct") {
		return OCTOBER;
	}
	else if (first == "nov") {
		return NOVEMBER;
	}
	else if (first == "dec") {
		return DECEMBER;
	}
}

string month_to_str(Month month) {
	if (month == JANUARY) {
		return "January";
	}
	else if (month == FEBRUARY) {
		return "February";
	}
	else if (month == MARCH) {
		return "March";
	}
	else if (month == APRIL) {
		return "April";
	}
	else if (month == MAY) {
		return "May";
	}
	else if (month == JUNE) {
		return "June";
	}
	else if (month == JULY) {
		return "July";
	}
	else if (month == AUGUST) {
		return "August";
	}
	else if (month == SEPTEMBER) {
		return "September";
	}
	else if (month == OCTOBER) {
		return "October";
	}
	else if (month == NOVEMBER) {
		return "November";
	}
	else if (month == DECEMBER) {
		return "December";
	}
}

void print_pairs(Month* months, int n)
{
	Month* unique = new Month[n];
	int counter = 0;
	bool flag = true;
	//add to unique
	int k = 0;

	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++) {
			if (months[i] == unique[j]) {
				flag = false;
			}
		}

		if (flag) {
			unique[k] = months[i];
			k++;
		}
		flag = true;

	}

	//count and print each

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (unique[i] == months[j]) {

				counter++;

			}
		}

		if (counter != 0) {
			cout << month_to_str(unique[i]) << " - " << counter << endl;
		}
		counter = 0;
	}


}


struct Date {
	unsigned int day;
	Month month;
	unsigned int year;

	void format_day() {
		if (day > 31) {
			day = 31;
		}
		else if (day < 1) {
			day = 1;
		}
	}

	int compare(Date other) {

		//consider all months have 31 days

		long long sum1 = (year - 1) * 365 + (month - 1) * 31 + day;

		long long sum2 = (other.year - 1) * 365 + (other.month - 1) * 31 + other.day;

		return abs(sum1 - sum2);

	}

};


int main() {

	int n;

	cin >> n;

	/*Month* months = new Month[n];

	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		months[i] = str_to_month(input);

	}

	print_pairs(months, n);*/

	Date* dates = new Date[n];

	for (int i = 0; i < n; i++) {
		Date date;
		string input;
		int day;
		cout << "Enter date (D M Y)" << endl;
		cin >> date.day >> input >> date.year;
		date.month = str_to_month(input);
		date.format_day();
		dates[i] = date;
	}


	//current date
	Date date;
	string input;
	int day;
	cout << "Enter current date (D M Y)" << endl;
	cin >> date.day >> input >> date.year;
	date.month = str_to_month(input);
	date.format_day();

	Date min_date = dates[0];

	for (int i = 0; i < n; i++) {


		if (min_date.compare(date) > date.compare(dates[i])) {
			min_date = dates[i];
		}
	}

	cout << "The closest date is - " << min_date.day << ' ' << month_to_str(min_date.month) << ' ' << min_date.year;

	return 0;
}
