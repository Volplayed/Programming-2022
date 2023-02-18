#include <iostream>
#include <string>

using namespace std;
//bank
class Client {
private:
	string name;
	string address;
	string phone;

public:
	Client():name(""), address(""), phone("") {}
	Client(string n, string a, string p):name(n), address(a), phone(p) {}
	Client(const Client &c):name(c.name), address(c.address), phone(c.phone) {}
	
	string getName() {
		return name;
	}
	string getAddress() {
		return address;
	}
	string getPhone() {
		return phone;
	}

	friend ostream& operator<<(ostream& os, Client& client) {
		os << "Name: " << client.getName() << endl << "Address: " << client.getAddress() << endl;

		return os;
	}

};

class Bank {
private:
	Client client;
	unsigned int id;
	double balance;

public:
	Bank(): client(), id(1), balance(0) {}
	Bank(Client cli, unsigned int i, double b) :client(cli), id(i), balance(b) {}
	Bank(const Bank& b) :client(b.client), id(b.id), balance(b.balance) {}

	void addMoney(double amount) {
		balance += amount;
	}

	void withdrawMoney(double amount) {
		if (amount > balance) {
			cout << "You don't have enough money on your bank account" << endl;
		}
		else {
			balance -= amount;
		}
	}

	double getBalance() {
		cout << "Balance: " << balance << "$" << endl;
		return balance;
	}

	friend ostream& operator<<(ostream& os, Bank& bank) {
		os << bank.client << "ID: " << bank.id << endl << "Balance: " << bank.balance << endl;

		return os;
	}

	bool checkFilter(int f, string text) {
		if (f == 0) {
			if (client.getName() == text) {
				return true;
			}
		}
		else if (f == 1) {
			if (client.getAddress() == text) {
				return true;
			}
		}
		return false;
	}
};



int main() {
	Bank* banks = new Bank[10];
	Client c1("John", "Lviv", "1000000");
	Client c2("Max", "Kharkiv", "1000000");
	Client c3("Bill", "Lviv", "1000000");
	Client c4("Andrew", "Odessa", "1000000");
	Client c5("Kevin", "Dnipro", "1000000");
	Client c6("Kyle", "Rivne", "1000000");
	Client c7("Sam", "Rivne", "1000000");
	Client c8("Max", "Lviv", "1000000");
	Client c9("John", "Lviv", "1000000");
	Client c10("John", "Kyiv", "1000000");

	Bank b1(c1, 1, 156);
	Bank b2(c2, 2, 17.5);
	Bank b3(c3, 3, 1565.8);
	Bank b4(c4, 4, 12.1);
	Bank b5(c5, 5, 1004.9);
	Bank b6(c6, 6, 233);
	Bank b7(c7, 7, 200);
	Bank b8(c8, 8, 560);
	Bank b9(c9, 9, 50);
	Bank b10(c10, 10, 288.6);

	banks[0] = b1;
	banks[1] = b2;
	banks[2] = b3;
	banks[3] = b4;
	banks[4] = b5;
	banks[5] = b6;
	banks[6] = b7;
	banks[7] = b8;
	banks[8] = b9;
	banks[9] = b10;


	while (true) {
		int f;
		cout << "Search by 0 - name, 1 - address" << endl;
		cin >> f;

		string prompt;
		cout << "Enter prompt: ";
		cin >> prompt;

		Bank** filtered = new Bank*[10];
		unsigned int count = 0;

		for (int i = 0; i < 10; i++) {
			if (banks[i].checkFilter(f, prompt)) {
				filtered[count] = &banks[i];
				cout << "#" << count << endl << banks[i];
				count++;
			}
		}

		cout << "There are " << count << " accounts found\nSelect one by entering its number in list" << endl;
		int n;
		cin >> n;

		cout << "Bank account selected" << endl << *filtered[n];

		cout << "0 - to add money, 1 - to withdraw money + amount of money: ";
		int a;
		double amount;
		cin >> a >> amount;

		if (a == 0) {
			filtered[n]->addMoney(amount);
		}
		else if (a == 1) {
			filtered[n]->withdrawMoney(amount);
		}

		cout << "Operation is finished!" << endl;
	}


	return 0;
}