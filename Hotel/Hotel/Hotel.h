#pragma once

#include <string>
#include <set>
#include <iostream>
#include "Room.h"

class Hotel
{
public:
	Hotel(std::string title);

	Hotel(const Hotel& drop); // конструктор копирования

	Hotel& operator=(const Hotel& hotel); //оператор присваивания
	
	~Hotel();

	void addRoom(Room* room); //добавить комнату

	void removeRoom(int roomNumber); // удалить комнату по номеру комнаты, если такая есть

	int getRoomsCount(); // получить 

	bool hasRoom(int roomNumber); // возвращает true если комната есть в отеле, false в противном

	Room* getRoom(int roomNumber); // возвращает ссылку на обьект комнаты с заданным номером, nullptr если такой комнаты нет

	std::set<Room*> getRooms(); // получить все комнаты
	std::set<Room*> getReservedRooms(); // получить зарезервированные комнаты
	std::set<Room*> getFreeRooms(); // получить свободные комнаты

	void setTitle(std::string title); // установить название отеля

	std::string getTitle(); // получить название отеля
private:
	std::set<Room*> rooms;
	std::string title;
};

