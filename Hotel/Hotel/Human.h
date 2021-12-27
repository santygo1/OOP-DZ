#pragma once

#include <string>
class Human
{
public:
	Human(std::string name,int age = 10);

	std::string getName();
	int getAge();

	std::string getStatus() {
		return "Не посетитель отеля";
	}

	template<typename T>
	void changeName(T name);

private:
	std::string name;
	int age;
};

template<typename T>
inline void Human::changeName(T name)
{
	this->name = name;
}
