#include <iostream>
#include <string>
using namespace std;

//«а введеним номером м≥с€ц€ року, вивести його назву

string months[] = {
	"January",
	"February",
	"March",
	"April",
	"May",
	"June",
	"July",
	"August",
	"September",
	"October",
	"November",
	"December"
	};

int main()
{
	int n; //month num
	cout << "Enter number of month: " << endl;
	cin >> n;
	if (n <= 0 || n > 12) {
		cout << endl << "Wrong number.";
		return 1;
	}

	cout << endl << "It`s " << months[n - 1];
	return 0;
}