//В текстовому файлі задані дані про деякий каталог книг та статей журналу.
//- Визначити необхідні типи(книга, стаття, каталог)
//- ввести дані з файлу, присвоюючи кожному запису номер у каталозі, згідно з прізвищем автора(за алфавітом).
//- вивести в файл1 відсортований за номерами список авторів без повторів.
//- у файл2 вивести всі статті та книги, в назві яких є вказане слово.
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <fstream>
#include <set>
using namespace std;

class Work {
protected:
	string author;
	string name;
public:
	Work() {}
	Work(string a, string n): author(a), name(n) {}

	virtual int getType() = 0;
	virtual void input(istream& is) {};
	virtual void output(ostream& os) {
		os << name;
	};

	friend istream& operator>>(istream& is, Work& work) {
		work.input(is);
		return is;
	}
	friend ostream& operator<<(ostream& os, Work& work) {
		work.output(os);
		return os;
	}

	string getAuthor() {
		return author;
	}
	string getName() {
		return name;
	}

};

class Article : public Work {
private:
	string field;
public:
	Article() {}
	Article(string a, string n, string f): Work(a, n), field(f) {}

	int getType() {
		return 1;
	}

	void input(istream& is) {
		is >> author >> name >> field;
	}
	void output(ostream& os) {
		Work::output(os);
		os << " " << field;
	}
};

class Book : public Work {
private:
	string genre;
public:
	Book() {}
	Book(string a,  string n, string g) : Work(a, n), genre(g) {}

	int getType() {
		return 2;
	}

	void input(istream& is) {
		is >> author >> name >> genre;
	}
	void output(ostream& os) {
		Work::output(os);
		os << " " << genre;
	}
};

class Catalog {
private:
	map<string, vector<Work*>> works;
public:


	void readWorks(ifstream& ifs) {

		while (!ifs.eof()) {
			int type;
			ifs >> type;
			if (type == 1) {
				Article* temp = new Article;
				temp->input(ifs);
				works[temp->getAuthor()].push_back(temp);
			}
			else if (type == 2) {
				Book* temp = new Book();
				temp->input(ifs);
				works[temp->getAuthor()].push_back(temp);
			}
		}
	}

	friend ostream& operator<<(ostream& os, Catalog& cat) {
		for (pair<string, vector<Work*>> p : cat.works) {
			os << p.first << " - ";
			for (Work* work : p.second) {
				os << *work <<" | ";
			}
			os << endl;
		}
		return os;
	}

	map<string, vector<Work*>> getWorks() {
		return works;
	}
	vector<Work*> findWorks(string text) {
		
		vector<Work*> worksWithName;

		for (pair<string, vector<Work*>> pair : works) {
			
			vector<Work*> vec = pair.second;

			vector<Work*>::iterator it = vec.begin();
			//go through vector searching for works with text in name
			while(true) {

				it = find_if(vec.begin(), vec.end(), [text](Work* w) {
					string str = w->getName();
				return str.find(text) != string::npos;
					});
				if (it != vec.end()) {
					worksWithName.push_back(*it);
					vec.erase(it);
					continue;
				}
				break;
			}
		}
		return worksWithName;
	}
};

int main() {
	Catalog cat;
	ifstream file("input.txt");
	cat.readWorks(file);
	
	file.close();
	ofstream file1("output1.txt");
	file1 << cat;
	file1.close();
	ofstream file2("output2.txt");
	string text;
	cin >> text;
	vector<Work*> works = cat.findWorks(text);
	for (Work* w : works) {
		file2 << w->getAuthor() << " - " << *w << endl;
	}
	file2.close();

	return 1;
}