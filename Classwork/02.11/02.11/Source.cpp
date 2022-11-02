#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int* arr1 = new int[n];
	int* arr2 = new int[m];
	int* arr3 = new int[m + n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}

	for (int i = 0; i < m; i++){
		cin >> arr2[i];
	}
	int i = 0, j = 0, k = 0;
	while (i < n && j < m)
	{
		if (arr1[i] < arr2[j])
		{
			arr3[k] = arr1[i];
			i++;
		}
		else
		{
			arr3[k] = arr2[j];
			j++;
		}
		k++;
	}

	while (i < n)
	{
		arr3[k] = arr1[i];
		i++;
		k++;
	}
	while (j < m)
	{
		arr3[k] = arr2[j];
		j++;
		k++;
	}

	for (int a = 0; a < n + m; a++)
	{
		cout << arr3[a] << " ";
	}

	return 0;
}