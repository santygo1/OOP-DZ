#ifndef GUITARSPEC_H
#define GUITARSPEC_H

#include <iostream>
#include <string>

using namespace std;

enum class Type { ACOUSTIC, ELECTRIC,BASS,UNKNOWN};
ostream& operator<<(ostream& os, Type type) {
	switch (type)
	{
	case Type::ACOUSTIC:
		os << "Акустика";
		break;
	case Type::ELECTRIC:
		os << "Електрогитара";
		break;
	case Type::BASS:
		os << "Бас-гитара";
		break;
	case Type::UNKNOWN:
		os << "Неизвестно";
		break;
	}
	return os;
}
enum class Creator{ FENDER, MARTIN, GIBSON, COLLINGS, OLSON, RYAN, PRS, ANY, UNKNOWN };
ostream& operator<<(ostream& os, Creator builder) {
	switch (builder)
	{
	case Creator::FENDER :
		os << "FENDER";
		break;
	case Creator::MARTIN:
		os << "MARTIN";
		break;
	case Creator::GIBSON:
		os << "GIBSON";
		break;
	case Creator::COLLINGS:
		os << "COLLINGS";
		break;
	case Creator::OLSON:
		os << "OLSON";
		break;
	case Creator::RYAN:
		os << "RYAN";
		break;
	case Creator::PRS:
		os << "PRS";
		break;
	case Creator::ANY:
		os << "ANY";
		break;
	case Creator::UNKNOWN:
		os << "Неизвестно";
		break;
	}
	return os;
}
enum class Wood { INDIAN_ROSEWOOD, BRAZILIAN_ROSEWOOD, MAHOGANY, MAPLE, COCOBOLO, CEDAR, ADIRONDACK, ALDER, SITKA, UNKNOWN};
ostream& operator<<(ostream& os, Wood wood) {
	switch (wood)
	{
	case Wood::INDIAN_ROSEWOOD:
		os << "INDIAN_ROSEWOOD";
		break;
	case Wood::BRAZILIAN_ROSEWOOD:
		os << "BRAZILIAN_ROSEWOOD";
		break;
	case Wood::MAHOGANY:
		os << "MAHOGANY";
		break;
	case Wood::MAPLE:
		os << "MAPLE";
		break;
	case Wood::COCOBOLO:
		os << "COCOBOLO";
		break;
	case Wood::CEDAR:
		os << "CEDAR";
		break;
	case Wood::ADIRONDACK:
		os << "ADIRONDACK";
		break;
	case Wood::ALDER:
		os << "ALDER";
		break;
	case Wood::SITKA:
		os << "SITKA";
		break;
	case Wood::UNKNOWN:
		os << "Неизвестно";
		break;
	}
	return os;
}

class GuitarSpec
{
private:
	string model;
	Type type = Type::UNKNOWN;
	Creator creator = Creator::UNKNOWN;
	Wood topWood = Wood::UNKNOWN;
	Wood backWood = Wood::UNKNOWN;
	int numStrings = 0;
public:
	GuitarSpec() = default;


	GuitarSpec(Creator creator, string model,
		Type type, int numStrings, Wood backWood, Wood topWood) {
		this->creator = creator;
		this->model = model;
		this->type = type;
		this->numStrings = numStrings;
		this->backWood = backWood;
		this->topWood = topWood;
	}

	GuitarSpec(const GuitarSpec& obj) {
		model = obj.model;
		type = obj.type;
		creator = obj.creator;
		topWood = obj.topWood;
		backWood = obj.backWood;
		numStrings = obj.numStrings;
	}

	class Builder {
	private:
		GuitarSpec* spec;
	public:
		Builder() {
			spec = new GuitarSpec();
		}

		Builder& model(const string& model) {
			spec->model = model;
			return *this;
		}

		Builder& topWood(const Wood& topWood) {
			spec->topWood = topWood;
			return *this;
		}

		Builder& backWood(const Wood& backWood) {
			spec->backWood = backWood;
			return *this;
		}

		Builder& numStrings(const int& numStrings) {
			spec->numStrings = numStrings;
			return *this;
		}

		Builder& creator(const Creator& creator) {
			spec->creator = creator;
			return *this;
		}

		Builder& type(const Type& type) {
			spec->type = type;
			return *this;
		}

		GuitarSpec* build() {
			return spec;
		}
	};

	Creator getCreator() {
		return creator;
	}

	string getModel() {
		return model;
	}

	Type getType() {
		return type;
	}

	Wood getBackWood() {
		return backWood;
	}

	Wood getTopWood() {
		return topWood;
	}

	int getNumStrings() {
		return numStrings;
	}

	bool mathes(GuitarSpec* otherSpec) {
		if (creator == Creator::UNKNOWN || creator == otherSpec->creator) return true;
		if (model.size() == 0 || model == otherSpec->model) return true;
		if (type == Type::UNKNOWN || type == otherSpec->type) return true;
		if (numStrings == 0 || numStrings == otherSpec->numStrings) return true;
		if (backWood == Wood::UNKNOWN || backWood == otherSpec->backWood) return true;
		if (topWood == Wood::UNKNOWN || backWood == otherSpec->topWood) return true;
		return false;
	}
};

ostream& operator<<(ostream& os, GuitarSpec& guitar) {
	os << "	Производитель: " << guitar.getCreator() << endl;
	os << "	Модель: " <<( guitar.getModel().length() != 0 ? guitar.getModel(): "Неизвестно") << endl;
	os << "	Тип гитары: " << guitar.getType() << endl;
	os << "	Дерево верхней поверхности: " << guitar.getTopWood() << endl;
	os << "	Дерево задней поверхности: " << guitar.getBackWood() << endl;
	if (guitar.getNumStrings() != 0)
		os << "	Количество струн: " << guitar.getNumStrings()<<endl;
	return os;
}

#endif //GUITARSPEC_H

