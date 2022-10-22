#include <iostream>
#include <math.h>

using namespace std;

// matrix input, matrix print, odd columns print, diagonal, min element per row, swap rows, descending columns count

int main()
{
	//const init
	const int m = 4;
	const int n = 4;

	//variables init
	double matrix[m][n];
	double min_values[m];

	for (int i = 0; i < m; ++i)
	{

		for (int j = 0; j < n; ++j)
		{

			cin >> matrix[i][j];

		}


	}

	cout << "--------------------------------" << endl;

	//print
	for (int i = 0; i < m; ++i)
	{

		for (int j = 0; j < n; ++j)
		{

			cout << matrix[i][j]  << ' ';

		}

		cout << endl;

	}

	//odd columns
	cout << "Odd columns" << endl;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j += 2)
		{
			cout << matrix[i][j] << ' ';
		}
		cout << endl;
	}


	//diagonal
	if (m == n)
	{
		cout << "Diagonal" << endl;
		for (int i = 0; i < m; ++i)
		{
			cout << matrix[i][i] << ' ';
		}
		cout << endl;

	}
	else {
		cout << "Cant get diagonal. Not squere matrix" << endl;
	}

	//min elem
	cout << "Min values per row" << endl;
	for (int i = 0; i < m; ++i)
	{
		min_values[i] = matrix[i][0];
		for (int j = 0; j < n; ++j)
		{
			if (matrix[i][j] < min_values[i])
			{
				min_values[i] = matrix[i][j];
			}
		}
		cout << min_values[i] << endl;

	}

	
	//descending column
	cout << "Descending columns";
	int counter = 0;
	bool flag = true;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m - 1; ++j)
		{
			if (matrix[j][i] < matrix[j + 1][i])
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			counter++;
		}
		flag = true;
	}
	cout << endl << counter << endl;

	//swap rows

	int k, l;
	cout << "Enter row numbers (starting with 1):" << endl;
	cin >> k >> l;

	double row_k[n];
	double row_l[n];

	for (int i = 0; i < n; ++i)
	{
		row_k[i] = matrix[k - 1][i];
		row_l[i] = matrix[l - 1][i];

		matrix[l - 1][i] = row_k[i];
		matrix[k - 1][i] = row_l[i];
	}

	cout << "--------------------------------" << endl;

	//print
	for (int i = 0; i < m; ++i)
	{

		for (int j = 0; j < n; ++j)
		{

			cout << matrix[i][j] << ' ';

		}

		cout << endl;

	}


	return 0;
}