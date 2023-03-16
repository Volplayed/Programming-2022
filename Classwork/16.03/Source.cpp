#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Transport {
protected:
	double engine_volume;
	string name;

public:
	Transport() :engine_volume(0), name("") {}
	Transport(double e, string n) :engine_volume(e), name(n) {}

	virtual void output(ostream& os) = 0;

	virtual int getType() = 0;

	string getName() {
		return name;
	}

	double getVolume() {
		return engine_volume;
	}
};

class WaterTransport : virtual public Transport {
protected:
	string type;
	double max_water_speed;

public:
	WaterTransport(): type(""), max_water_speed(0) {}
	WaterTransport(double e, string n, string t, double m): Transport(e, n), type(t), max_water_speed(m) {}

	void output(ostream& os) {
		os << "Name: " << name << " Volume: " << engine_volume << " Type: " << type << " Max water speed: " << max_water_speed << endl;
	}
	int getType() {
		return 1;
	}
};

class LandTransport : virtual public Transport {
protected:
	double max_speed;
	int seats;

public:
	LandTransport() : max_speed(0), seats(0) {}
	LandTransport(double e, string n, double m, int s) : Transport(e, n), max_speed(m), seats(s) {}

	void output(ostream& os) {
		os << "Name: " << name << " Volume: " << engine_volume << " Max speed: " << max_speed << " Seats: " << seats << endl;
	}

	int getType() {
		return 2;
	}
};

class Amphibian : public WaterTransport, public LandTransport {
private:
	int max_hours_water;
	int max_hours_land;
public:
	Amphibian(): max_hours_water(0), max_hours_land(0) {}
	Amphibian(double e, string n, string t, double mw, double ms, int s, int mhw, int mhl): Transport(e, n),
		WaterTransport(e, n, t, mw), LandTransport(e, n, ms, s), max_hours_water(mhw), max_hours_land(mhl) {}

	void output(ostream& os) {
		os << "Name: " << Transport::name << " Volume: " << Transport::engine_volume << " Max speed: " << LandTransport::max_speed << " Seats: " << LandTransport::seats << " Type: " << WaterTransport::type << " Max water speed: " << WaterTransport::max_water_speed  << endl;
	}
	int getType() {
		return 3;
	}

};

int main() {

	vector<Transport*> transport;

	WaterTransport t1(10, "Boat", "Lake", 15);
	LandTransport t2(45, "Motorcycle", 110, 2);
	LandTransport t3(60, "Car", 110, 2);
	WaterTransport t4(40, "Ship", "Sea", 40);
	Amphibian t5(55, "Agent 007 Car", "Sea", 60, 140, 5, 200, 5000);
	Amphibian t6(70, "Amphibian tank", "River", 30, 55, 6, 25, 400);

	transport.push_back(&t1);
	transport.push_back(&t2);
	transport.push_back(&t3);
	transport.push_back(&t4);
	transport.push_back(&t5);
	transport.push_back(&t6);

	for (int i = 0; i < transport.size(); i++) {
		transport[i]->output(cout);
	}

	sort(transport.begin(), transport.end(), [](Transport* a, Transport* b) {return a->getName() < b->getName(); });

	cout << "-----------------------------------------------------------" << endl;

	for (int i = 0; i < transport.size(); i++) {
		transport[i]->output(cout);
	}

	int min = 0;
	int max = 0;

	for (int i = 0; i < transport.size(); i++) {
		if (transport[min]->getVolume() > transport[i]->getVolume()) {
			min = i;
		}
		if (transport[max]->getVolume() < transport[i]->getVolume()) {
			max = i;
		}
	}
	cout << "-----------------------------------------------------------" << endl;
	transport[min]->output(cout);
	transport[max]->output(cout);
	cout << "-----------------------------------------------------------" << endl;
	for (int i = 0; i < transport.size(); i++) {
		if (transport[i]->getType() == 3) {
			transport[i]->output(cout);
		}
	}
	cout << "-----------------------------------------------------------" << endl;
	for (int i = 0; i < transport.size(); i++) {
		if (transport[i]->getType() == 1) {
			transport[i]->output(cout);
		}
	}


	return 0;
}