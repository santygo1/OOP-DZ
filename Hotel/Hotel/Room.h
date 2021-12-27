#pragma once

#include "Reservation.h"
#include <iostream>

class Room
{
public:
	Room(int roomNumber);

	~Room();

	void setRoomNumber(int roomNumber); //�������� ����� �������

	int getRoomNumber(); //�������� ����� �������

	bool isFree(); //���������� true - ���� ������� ������������������, false - � ���������

	Reservation* getReservation();// ���������� ������ ����� ���� �� ���� , nullptr � ���������

	void reserveBy(Visitor* visitor); // ��������������� ������� �� ���

	void deleteReservation(); // ������� �����
	

private:
	void setReservation(Reservation* reservation); // ���������� �����
	int roomNumber;
	Reservation* reservation = nullptr;
};

