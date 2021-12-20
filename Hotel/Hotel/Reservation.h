#pragma once

#include "Visitor.h"

class Reservation
{
public:
	Reservation(int roomNumber, Visitor* visitor);

	~Reservation();

	int getRoomNumber(); // получить номер комнаты

	Visitor* getVisitor(); // получить посетителя владеющий комнатой

	void setVisitor(Visitor* visitor); // изменить владельца комнаты

private:
	int roomNumber;
	Visitor* visitor;
};

