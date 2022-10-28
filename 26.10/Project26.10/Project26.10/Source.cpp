#include <iostream>

using namespace std;

//func init
int dividers_sum(int num)
{
	//init
	unsigned int sum = 0;

	for (int i = 1; i < num; ++i)
	{
		if (num % i == 0)
		{
			sum += i;

		}
	}

	return sum;

}

void friends(int n1, int n2)
{
	//init
	int sum1;
	int sum2;


	sum1 = dividers_sum(n1);
	sum2 = dividers_sum(n2);

	if (sum1 == n2 && sum2 == n1)
	{
		cout << "Pair (" << n1 << ", " << n2 << ") are 'friends'" << endl;
	}

}

int main()
{
	//init
	int n;


	cout << "Enter n: ";
	cin >> n;

	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			friends(i, j);
		}
	}

	return 0;
}
