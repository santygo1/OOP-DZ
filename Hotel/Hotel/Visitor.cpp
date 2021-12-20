#include "Visitor.h"

Visitor::Visitor(std::string name,int cardID,int age ):Human(name,age)
{
	this->cardID = cardID;
}

int Visitor::getCardID()
{
	return cardID;
}

