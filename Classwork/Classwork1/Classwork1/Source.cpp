#include <iostream>
#include <math.h>
#include <string>

using namespace std;
//
//int main()
//{
//	double a[4];
//	double x[50];
//	double b[50];
//
//	for (int i = 0; i < 4; ++i)
//	{
//		cin >> a[i];
//	}
//
//	for (int i = 0; i < 50; ++i)
//	{
//		cin >> x[i];
//	}
//
//	for (int i = 0; i < 50; ++i)
//	{
//		b[i] = ((x[i] * x[i] - x[i] - a[0]) / (x[i] - a[0])) * ((x[i] * x[i] - x[i] - a[1]) / (x[i] - a[1])) * (x[i] - a[2]) * ((pow(x[i], 4) - x[i] + a[3]) / x[i]) + x[i] * (x[i] + a[2]);
//		cout << b[i] << endl;
//	}
//
//
//	return 0;
//}

//2

//int main()
//{
//	string s;
//
//	char ans[10000];
//
//	cin >> s;
//	
//	int a = 0;
//
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s[i] != '0' && s[i] != '5')
//		{
//			ans[a] = s[i];
//			a++;
//		}
//	}
//
//	for (int i = 0; i < a; i++)
//	{
//		cout << ans[i];
//	}
//	
//}


// 1

//int main()
//{
//	int k;
//	cin >> k;
//	int div = 1;
//	int i = 0;
//	while (k >= div)
//	{
//
//		if (k % div == 0)
//		{
//			cout << div << endl;
//		}
//		div++;
//	}
//	return 0;
//}

//2

//int main()
//{
//	int a[10000];
//	int m;
//	cin >> m;
//	bool ans;
//
//	for (int i = 0; i < m; ++i)
//	{
//		cin >> a[i];
//	}
//
//	for (int i = 0; i < m; ++i)
//	{
//		if (a[i] < a[i+1])
//		{
//			cout << "False";
//			return 0;
//		}
//	}
//	cout << "True";
//
//
//	return 0;
//}
//

int main() {
	int n;
	cin >> n;
	int nums[1000];
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	int min = nums[0];

	for (int i = 1; i < n; ++i)
	{
		if (min > nums[i])
		{
			min = nums[i];
		}
	}
	cout << "Min number: " << min;


	return 0;
}
