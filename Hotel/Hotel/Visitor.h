#pragma once

#include <string>
#include "Human.h"
class Visitor:public Human
{
public:
	Visitor(std::string name, int cardID, int age =10);

	int getCardID(); 

private:
	int cardID; // номер идентификационной карты посетител€
};

