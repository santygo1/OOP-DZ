#pragma once

#include "Visitor.h"

class Reservation
{
public:
	Reservation(int roomNumber, Visitor* visitor);

	~Reservation();

	int getRoomNumber(); // �������� ����� �������

	Visitor* getVisitor(); // �������� ���������� ��������� ��������

	void setVisitor(Visitor* visitor); // �������� ��������� �������

private:
	int roomNumber;
	Visitor* visitor;
};

