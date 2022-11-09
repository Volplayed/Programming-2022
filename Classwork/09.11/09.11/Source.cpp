#include <iostream>
#include <string>

using namespace std;

//numbers with commas #1

//int main()
//{
//	//init
//	string str;
//	int sum = 0;
//	int i = 0;
//
//	string temp = "";
//
//	//input
//
//	cin >> str;
//
//	while (i < str.length()) {
//		if (str[i] != ',' && str[i] != '.')
//		{
//			temp += str[i];
//			++i;
//
//		}
//		else
//		{
//
//			++i;
//
//			sum += stoi(temp);
//			temp = "";
//		}
//
//	}
//
//	cout << sum;
//
//	return 0;
//}


//numbers with commas

//string* find_nums(string str)
//{
//    string temp = "";
//    string* arr = new string[str.length()];
//    int k = 0;
//    for (int i = 0; i < str.length(); i++) {
//        switch (str[i]) {
//        case '0':
//            temp += str[i];
//            break;
//        case '1':
//            temp += str[i];
//            break;
//        case '2':
//            temp += str[i];
//            break;
//        case '3':
//            temp += str[i];
//            break;
//        case '4':
//            temp += str[i];
//            break;
//        case '5':
//            temp += str[i];
//            break;
//        case '6':
//            temp += str[i];
//            break;
//        case '7':
//            temp += str[i];
//            break;
//        case '8':
//            temp += str[i];
//            break;
//        case '9':
//            temp += str[i];
//            break;
//        default:
//            arr[k] = temp;
//            temp = "";
//            k++;
//            break;
//        }
//    }
//    return arr;
//}
//
//string find_longest(string* arr, string str) {
//    int maxi = 0;
//    int max = arr[maxi].length();
//
//    for (int i = 0; i < str.length(); ++i) {
//        if (arr[i].length() > max)
//        {
//            max = arr[i].length();
//            maxi = i;
//        }
//    }
//    return arr[maxi];
//}
//
//int main()
//{
//    string str;
//
//    getline(cin, str);
//
//    cout << find_longest(find_nums(str), str);
//
//    return 0;
//}


//words size

string* get_words(string str)
{
    string temp = "";
    string* arr = new string[str.size()];
    int k = 0;
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] != ' ' && str[i] != '.') {
            temp += str[i];
        }
        else {
            arr[k] = temp;
            k++;
            temp = "";
        }
    }
    return arr;
}

int* get_sizes(string* words, string str)
{
    int* arr = new int[str.size()];

    for (int i = 0; i < str.size(); ++i)
    {
        arr[i] = words[i].size();
    }

    return arr;
}



int count_fl(string* words, string str, int* sizes)
{

    int fl = 0;

    for (int i = 0; i < str.size(); ++i) {
        if (words[i][0] == words[i][sizes[i] - 1] && words[i] != "")
        {
            fl++;
        }
    }

    return fl;
}

int main()
{
    string str;

    getline(cin, str);

    string* words = get_words(str);

    int* sizes = get_sizes(words, str);
    int i = 0;
    while (sizes[i] != 0)
    {
        cout << sizes[i] << ' ';
        ++i;
    }

    cout << endl << count_fl(words, str, sizes);

    return 0;
}