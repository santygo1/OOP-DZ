#pragma once

#include <string>
class Human
{
public:
	Human(std::string name,int age = 10);

	std::string getName();
	int getAge();

private:
	std::string name;
	int age;
};

