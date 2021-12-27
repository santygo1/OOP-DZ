#pragma once

#include "Reservation.h"
#include <iostream>

class Room
{
public:
	Room(int roomNumber);

	~Room();

	void setRoomNumber(int roomNumber); //изменить номер комнаты

	int getRoomNumber(); //получить номер комнаты

	bool isFree(); //возвращает true - если комната незарезервированна, false - в противном

	Reservation* getReservation();// возвращает обьект брони если он есть , nullptr в противном

	void reserveBy(Visitor* visitor); // зарезервировать комнату на имя

	void deleteReservation(); // удалить бронь
	

private:
	void setReservation(Reservation* reservation); // установить бронь
	int roomNumber;
	Reservation* reservation = nullptr;
};

