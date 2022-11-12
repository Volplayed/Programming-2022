#include <iostream>
#include <string>

using namespace std;


//matrix - arrays
//arrays 19

//count unique
//
//int* unique(int* arr, int n) {
//
//    int i, j;
//    int* unique = new int[n];
//    int c = 0;
//
//    for (i = 0; i < n; i++) {
//        for (j = 0; j < n; j++) {
//            if (arr[i] == unique[j] && i != j)
//                break;
//        }
//        if (j == n) {
//            unique[c] = arr[i];
//            c++;
//        }
//    }
//    return unique;
//}
//
//int count(int* arr, int n) {
//    int i, j;
//    int* unique = new int[n];
//    int c = 0;
//
//    for (i = 0; i < n; i++) {
//        for (j = 0; j < n; j++) {
//            if (arr[i] == unique[j] && i != j)
//                break;
//        }
//        if (j == n) {
//            unique[c] = arr[i];
//            c++;
//        }
//    }
//    return c;
//}
//
//void print_count(int* unique, int* arr, int c, int n)
//{
//    int counter = 0;
//    for (int i = 0; i < c + 1; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            if (unique[i] == arr[j])
//            {
//                counter++;
//            }
//        }
//        cout << "(" << unique[i] << ", " << counter << ")" << endl;
//        counter = 0;
//    }
//}
//
//int main() {
//    //init
//    int N;
//
//    cin >> N;
//
//    int* arr = new int[N];
//
//    for (int i = 0; i < N; i++) {
//        cin >> arr[i];
//    }
//
//    int* u = unique(arr, N);
//    int c = count(arr, N);
//
//    print_count(u, arr, c, N);
//
//    return 0;
//}

//matrix 19

//int** get_matrix(int n, int m) {
//	int** matrix = new int* [n];
//	for (int i = 0; i < n; i++) {
//		matrix[i] = new int[m];
//		for (int j = 0; j < m; j++) {
//			cin >> matrix[i][j];
//		}
//	}
//
//	return matrix;
//}
//
//int* max(int** matrix, int n, int m) {
//	int* max = new int[n];
//	int temp;
//
//	for (int i = 0; i < n; i++) {
//		temp = matrix[i][0];
//		for (int j = 0; j < m; j++) {
//			if (temp < matrix[i][j]) {
//				temp = matrix[i][j];
//			}
//		}
//		max[i] = temp;
//	}
//	return max;
//}
//
//int main()
//{
//	//init
//	int n, m;
//	cin >> n >> m;
//	int** matrix = get_matrix(n, m);
//	int* arr = max(matrix, n, m);
//
//	for (int i = 0; i < n; i++) {
//		cout << arr[i] << endl;
//	}
//
//	return 0;
//}

//string 19 extended version

string extend(string str)
{

	int size = str.size();

	int n;

	string result = "";

	for (int i = 1; i < size; i++) {
		switch (str[i])
		{
		case '1':
			n = str[i];
			break;
		case '2':
			n = str[i];
			break;
		case '3':
			n = str[i];
			break;
		case '4':
			n = str[i];
			break;
		case '5':
			n = str[i];
			break;
		case '6':
			n = str[i];
			break;
		case '7':
			n = str[i];
			break;
		case '8':
			n = str[i];
			break;
		case '9':
			n = str[i];
			break;
		default:
			n = 0;
			break;
		}
		if (n == 0 && str[i - 1] != '1' && str[i - 1] != '2' && str[i - 1] != '3' && str[i - 1] != '4' && str[i - 1] != '5' && str[i - 1] != '6' && str[i - 1] != '7' && str[i - 1] != '8' && str[i - 1] != '9') {
			result += str[i - 1];
		}
		else {
			for (int j = 0; j < n - 48; j++) {
				result += str[i - 1];

			}
		}
	}

	return result;

}

int main() {
	string str;
	cin >> str;

	cout << extend(str);

	return 0;
}
