#include "Human.h"

Human::Human(std::string name, int age)
{
	this->name = name;
	this->age = age;
}



std::string Human::getName()
{
	return name;
}

int Human::getAge()
{
	return age;
}
