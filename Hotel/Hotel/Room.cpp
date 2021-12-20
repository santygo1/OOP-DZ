#include "Room.h"


Room::Room(int roomNumber)
{
	this->roomNumber = roomNumber;
}

Room::~Room()
{
	deleteReservation();
}

void Room::setRoomNumber(int roomNumber)
{
	if (roomNumber >= 0) {
		std::cout << "����� ������� �" << this->roomNumber << " ��� ������� �� " << roomNumber << std::endl;
		this->roomNumber = roomNumber;
	}
	else {
		std::cout << "����� ������� �" << this->roomNumber << "�� ��� ������� ( ����� ������� �� ����� ���� ������������� )" << std::endl;
	}
}

int Room::getRoomNumber()
{
	return roomNumber;
}

bool Room::isFree()
{
	if (reservation != nullptr) {
		return false;
	}
	return true;
}

void Room::setReservation(Reservation* reservation)
{
	deleteReservation();
	this->reservation = reservation;
}

Reservation* Room::getReservation()
{
	return reservation;
}

void Room::reserveBy(Visitor* visitor)
{
	if (reservation == nullptr) {
		setReservation(new Reservation(this->roomNumber, visitor));
		std::cout << "������� �" << roomNumber << " ���� ������������� �� ��� " << visitor->getName() << std::endl;
	}else{
		std::cout << "������� �" << roomNumber << " ��� ������ � �� ���� ������������� �� ��� " << visitor->getName() << std::endl;
	}
}

void Room::deleteReservation()
{
	if(this->reservation!= nullptr) delete reservation;
}
