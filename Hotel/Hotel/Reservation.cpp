#include "Reservation.h"
Reservation::Reservation(int roomNumber, Visitor* visitor)
{
	this->roomNumber = roomNumber;
	this->visitor = visitor;
}

Reservation::~Reservation()
{
	delete visitor;
}

int Reservation::getRoomNumber()
{
	return roomNumber;
}

Visitor* Reservation::getVisitor()
{
	return visitor;
}

void Reservation::setVisitor(Visitor* visitor)
{
	delete this->visitor;
	this->visitor = visitor;
}
