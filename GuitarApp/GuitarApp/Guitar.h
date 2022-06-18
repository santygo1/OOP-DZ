#ifndef GUITAR_H
#define GUITAR_H

#include <iostream>
#include <string>
#include "GuitarSpec.h"

using namespace std;

class Guitar
{
private:
	string serialNumber;
	int price;
	GuitarSpec* spec;

public:
	Guitar() = default;
	
	Guitar(string serialNumber, int price, GuitarSpec* spec) {

		this->serialNumber = serialNumber;
		this->price = price;
		this->spec = spec;
	}
	
	string getSerialNumber() {
		return serialNumber;
	}

	int getPrice() {
		return price;
	}

	void setPrice(int price) {
		this->price = price;
	}

	GuitarSpec* getSpec() {
		return spec;
	}

};
ostream& operator<<(ostream& os, Guitar& guitar) {
	os << "	Серийный номер: " << guitar.getSerialNumber() << endl;
	os << "	Стоимость : " << guitar.getPrice() << " руб." << endl;
	os << *guitar.getSpec();
	return os << endl;
}

#endif //GUITAR_H

