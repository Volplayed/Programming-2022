#include <iostream>

using namespace std;

//����� - ���� �� 1 �� 365.
//�������� ���� �����  �������� 1, 2, �, 6 �� 7 ������� �� ����,
//�� ���� ���� �����(��������, �������, �, ������ �� �����) ������� - � ���� ������������� ����,
//� ����� 1 ���� - ��������.

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