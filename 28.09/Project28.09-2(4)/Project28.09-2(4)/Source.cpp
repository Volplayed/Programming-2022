#include <iostream>

using namespace std;

//Нехай - ціле від 1 до 365.
//Присвоїти цілій змінній  значення 1, 2, …, 6 чи 7 залежно від того,
//на який день тижня(понеділок, вівторок, …, суботу чи неділю) припадає - й день невисокосного року,
//в якому 1 січня - понеділок.

int main()
{
	int k; //day (user input)

	cout << "Enter the number from 1 tp 365 :" << endl;
	cin >> k;
	
	int n; //day of the week
	n = k - ((k / 7) * 7);

	if (n == 0)
	{
		n = 7;
	}
	cout << endl << "Day of the week: " << n;

	return 0;
}