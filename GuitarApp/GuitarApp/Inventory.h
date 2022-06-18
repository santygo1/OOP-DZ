#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
using namespace std;

class Inventory
{
private:
	List<Guitar>* guitars;
public:
	Inventory() {
		guitars = new List<Guitar>;
	}

	~Inventory() {
		delete guitars;
	}

	void addGuitar(string serialNumber, int price,GuitarSpec* spec) {
		Guitar* guitar = new Guitar(serialNumber, price, spec);
		guitars->push_back(*guitar);
	}

	void addGuitar(Guitar* guitar) {
		guitars->push_back(*guitar);
	}

	Guitar* getGuitar(string serialNumber) {
		for (auto i = guitars->begin(); i != guitars->end(); ++i) {
			Guitar guitar = *i;
			if (guitar.getSerialNumber() == serialNumber) {
				return &guitar;
			}
		}
		return nullptr;
	}

	Guitar* getGuitar(int index) {
		int current = 0;
		for (auto i = guitars->begin(); i != guitars->end(); ++i) {
			if (current == index) {
				Guitar guitar = *i;
				return &guitar;
			}
			current++;
		}
		return nullptr;
	}

	List<Guitar>* search(GuitarSpec* searchSpec) {
		List<Guitar>* matchingGuitars = new List<Guitar>();
		for (auto i = guitars->begin(); i != guitars->end(); ++i)
		{
			Guitar guitar = *i;

			if (guitar.getSpec()->mathes(searchSpec))
				matchingGuitars->push_back(guitar);
		}
		return matchingGuitars;
	}

};

#endif //INVENTORY_H

