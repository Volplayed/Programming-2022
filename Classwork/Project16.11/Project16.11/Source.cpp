#include <iostream>
using namespace std;
enum DogBreeds {
    SHPIC,//0
    HASKY,//1
    TAKSA,//2
    NOBREED = -1

};
void add_elem(DogBreeds* array, int n) {
    for (int i = 0; i < n; ++i) {
        array[i] = DogBreeds(rand() % 3);
    }
}
void print_breeds(DogBreeds* array_1, int n) {
    for (int i = 0; i < n; ++i) {
        switch (array_1[i]) {
        case 0:
            cout << "Breed -- " << "Shpic" << endl;
            break;
        case 1:
            cout << "Breed -- " << "Hasky" << endl;
            break;
        case 2:
            cout << "Breed -- " << "Taksa" << endl;
            break;
        }
    }
}
DogBreeds str_to_dogbreed(string a) {
    //tolower(a);
    for (int i = 0; i < a.size(); ++i) {
        a[i] = tolower(a[i]);
    }
    if (a == "shpic") {
        return SHPIC;
    }
    else if (a == "hasky") {
        return HASKY;
    }
    else if (a == "taksa") {
        return TAKSA;
    }
    else {
        return NOBREED;
    }
}
//int main() {
//    int n;
//    bool res = false;
//    DogBreeds result;
//    string breed;
//    cout << "Enter n: " << endl;
//    cin >> n;
//    DogBreeds* array_breeds = new DogBreeds[n];
//    add_elem(array_breeds, n);
//    //print_breeds(array_breeds,n);
//    while (res == false) {
//        cout << "Enter a breed" << endl;
//        cin >> breed;
//        result = str_to_dogbreed(breed);
//        for (int i = 0; i < n; ++i) {
//            if (result == array_breeds[i]) {
//                cout << "Breed has been found" << endl;
//                res = true;
//                break;
//            }
//        }
//        if (res == false) {
//            cout << "Breed has not been found" << endl;
//        }
//    }
//    return 0;
//}


struct ZooDog {
    DogBreeds breed;
    int age;
};

string dogbreed_to_string(DogBreeds a) {
    //tolower(a);

    if (a == SHPIC) {
        return "Shpic";
    }
    else if (a == HASKY) {
        return "Hasky";
    }
    else if (a == TAKSA) {
        return "Taksa";
    }
}

ZooDog* inputDogs(int n) {
    ZooDog* dogs = new ZooDog[n];
    DogBreeds breed;
    int age = -1;
    string str;

    for (int i = 0; i < n; ++i)
    {
        cout << "Enter breed age" << endl;
        cin >> str;
        cin >> age;
        breed = str_to_dogbreed(str);
        if (breed == -1) {
            cout << "Wrong breed, try again!" << endl;
            --i;
        }
        else {
            dogs[i].breed = breed;
            dogs[i].age = age;
        }
    }

    return dogs;
}

ZooDog* sort(ZooDog* dogs, int n)
{
    int i = 1;
    while (i < n)
    {
        for (int j = i; dogs[j - 1].age > dogs[i].age; j--) {
            ZooDog temp = dogs[j];
            dogs[j ] = dogs[j - 1];
            dogs[j - 1] = temp;
        }
        i++;
    }
    

    return dogs;
}

void printDogs(ZooDog* dogs, int n) {
    for (int i = 0; i < n; i++) {
        cout << dogbreed_to_string(dogs[i].breed) << " - " << dogs[i].age << endl;
    }
}

int main() {

    int n = 5;
    ZooDog* dogs = inputDogs(n);
    ZooDog* sorted = sort(dogs, n);
    printDogs(sorted, n);

    return 0;
}