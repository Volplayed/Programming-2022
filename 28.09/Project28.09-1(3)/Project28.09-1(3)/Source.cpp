#include <iostream>

using namespace std;

//������ - ������� �����().
//��������� - ����� ������� ����� � - ����� ������� ������,
//�� ������� �� ������� ���� �� ���� �������(� ������ ������� ���),
//���� ������� ������ ����������� ��  �������.

int main()
{	
	double f; //angle

	cout << "Enter angle: " << endl;

	cin >> f;
		
	if (f < 0)
	{
		f = 0;
	}
	if (f > 360)
	{
		f = 360;
	}

	int h; //hours
	h = f / 30;
	int m; //minutes
	m = (f / 0.5) - h * 60;

	cout << endl << "Hours: " << h << " Minutes: " << m << endl;

	return 0;
}