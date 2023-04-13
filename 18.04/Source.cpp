
#include <iostream>
#include <deque>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
struct Utility {

    string name;
    double cost;
    virtual void Input(istream& is) {
        is >> name >> cost;
    }
    virtual void Output(ostream& os) {
        os << name << cost;
    }

    virtual int getType() = 0;

    friend istream& operator>>(istream& is, Utility& utility) {
        utility.Input(is);
        return is;
    }
    friend ostream& operator<<(ostream& os, Utility& utility) {
        utility.Output(os);
        return os;
    }
    virtual bool operator>(Utility& util) {
        return name > util.name;
    }

};

struct Water : public Utility {

    double counter;
    double volume;

    void Input(istream& is) {
        is >> name >> cost >> counter >> volume;
    }
    void Output(ostream& os) {
        os << name << ' ' << cost << ' ' << counter << ' '  << volume << endl;
    }

    int getType() {
        return 1;
    }
    bool operator>(Water& wat) {
        return name > wat.name;
    }


};
struct Gas : public Utility {

    int abonents;

    void Input(istream& is) {
        is >> name >> cost >> abonents;
    }
    void Output(ostream& os) {
        os << name << ' ' << cost << ' ' << abonents << endl;
    }
    int getType() {
        return 2;
    }
    bool operator>(Gas& gas) {
        return abonents > gas.abonents;
    }
};

void read(deque<Utility*>& dq, string path) {
    ifstream file(path);
    if (!file.is_open()) {
        throw(runtime_error("Input file could not be opened"));
    }

    while (!file.eof()) {
        int t;
        file >> t;
        if (t == 1) {
            Water* temp = new Water();
            file >> *temp;
            dq.push_front(temp);
        }
        else if (t == 2) {
            Gas* temp = new Gas();
            file >> *temp;
            dq.push_back(temp);
        }
        else {

            throw(invalid_argument("Wrong input in file"));
        }
    }
    file.close();
}

void write(deque<Utility*>& dq, string path1, string path2, string path3) {
    ofstream waterFile(path1);
    ofstream gasFile(path2);
    if (!waterFile.is_open() || !gasFile.is_open()) {
        throw(runtime_error("Output file could not be opened"));
    }

    if (dq.empty()) {
        throw(runtime_error("Deque is empty"));
    }

    deque<Utility*>::iterator i1 = dq.begin();

    while ((**i1).getType() == 1) {
        i1++;
    }

    sort(dq.begin(), i1, [](Utility* a, Utility* b) {return a->name < b->name; });
    sort(i1, dq.end(), [](Utility* a, Utility* b) {

            Gas* ga = dynamic_cast<Gas*>(a);
            Gas* gb = dynamic_cast<Gas*>(b);
            return ga->abonents > gb->abonents;

        });

    deque<Utility*>::iterator i2 = dq.begin();

    while (i2 != dq.end()) {
        if ((*i2)->getType() == 1) {
            waterFile << (**i2);
            cout << (**i2);
        }

        if ((*i2)->getType() == 2) {
            gasFile << (**i2);
            cout << (**i2);
        }
        i2++;
    }

    //max water costs
    sort(dq.begin(), i1, [](Utility* a, Utility* b) {return a->cost > b->cost; });

    deque<Utility*>::iterator i3 = dq.begin();

    ofstream maxFile(path3);
    if (!maxFile.is_open()) {
        throw(runtime_error("Output file could not be opened"));
    }

    for (int i = 0; i < 5; i++) {
        maxFile << (**i3);
        i3++;
    }
}

int main()
{
    try {
        deque<Utility*> dq;
        read(dq, "input.txt");
        write(dq, "water.txt", "gas.txt", "max.txt");
    }
    catch (invalid_argument& e) {
        cerr << "Invalid argument: " << e.what();
    }
    catch (runtime_error& e) {
        cerr << "Runtime error: " << e.what();
    }
    catch (exception& e) {
        cerr << "Exception: " << e.what();
    }

    return 0;
}
