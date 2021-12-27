#include "Hotel.h"

Hotel::Hotel(std::string title)
{
	this->title = title;
}

Hotel::Hotel(const Hotel& hotel)
{
	title = title;
	rooms = hotel.rooms;
}

Hotel& Hotel::operator=(const Hotel& hotel)
{
	if (this == &hotel) {
		return *this;
	}

	title = hotel.title;
	rooms = hotel.rooms;

	return *this;
}

Hotel::~Hotel()
{
	for (Room* currentRoom : rooms) {
		delete currentRoom;
	}
}

void Hotel::addRoom(Room* room)
{
	if (!hasRoom(room->getRoomNumber())) {
		rooms.insert(room);
		std::cout << "Комната №" << room->getRoomNumber() << " была добавлена в отель " << "\"" << title << "\"" << std::endl;
	}
	else {
		std::cout << "Комната №" << room->getRoomNumber() << " уже есть в отеле " << "\"" << title << "\"" << std::endl;
	}
}

void Hotel::removeRoom(int roomNumber)
{
	if (hasRoom(roomNumber)) {
		rooms.erase(getRoom(roomNumber));
		std::cout << "Комната №" << roomNumber << " была удалена из отеля " << "\"" << title << "\"" << std::endl;
	}
	else {
		std::cout << "Комнаты №" << roomNumber << " нет в отеле " << "\"" << title << "\"" << std::endl;
	}
}

int Hotel::getRoomsCount()
{
	return rooms.size();
}

bool Hotel::hasRoom(int roomNumber)
{
	if (getRoom(roomNumber) != nullptr) return true;
	return false;
}

Room* Hotel::getRoom(int roomNumber)
{
	for (Room* currentRoom : rooms) {
		if (currentRoom->getRoomNumber() == roomNumber) return currentRoom;
	}

	return nullptr;
}

std::set<Room*> Hotel::getRooms()
{
	return rooms;
}

std::set<Room*> Hotel::getReservedRooms()
{
	std::set<Room*> reservedRooms;

	for (Room* currentRoom : rooms) {
		if (!currentRoom->isFree()) {
			reservedRooms.insert(currentRoom);
		}
	}

	return reservedRooms;
}

std::set<Room*> Hotel::getFreeRooms()
{
	std::set<Room*> freeRooms;

	for (Room* currentRoom : rooms) {
		if (currentRoom->isFree()) {
			freeRooms.insert(currentRoom);
		}
	}

	return freeRooms;
}

void Hotel::setTitle(std::string title)
{
	this->title = title;
}


std::string Hotel::getTitle()
{
	return title;
}

