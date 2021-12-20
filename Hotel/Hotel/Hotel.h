#pragma once

#include <string>
#include <set>
#include <iostream>
#include "Room.h"

class Hotel
{
public:
	Hotel(std::string title);

	Hotel(const Hotel& drop); // ����������� �����������

	Hotel& operator=(const Hotel& hotel); //�������� ������������
	
	~Hotel();

	void addRoom(Room* room); //�������� �������

	void removeRoom(int roomNumber); // ������� ������� �� ������ �������, ���� ����� ����

	int getRoomsCount(); // �������� 

	bool hasRoom(int roomNumber); // ���������� true ���� ������� ���� � �����, false � ���������

	Room* getRoom(int roomNumber); // ���������� ������ �� ������ ������� � �������� �������, nullptr ���� ����� ������� ���

	std::set<Room*> getRooms(); // �������� ��� �������
	std::set<Room*> getReservedRooms(); // �������� ����������������� �������
	std::set<Room*> getFreeRooms(); // �������� ��������� �������

	void setTitle(std::string title); // ���������� �������� �����

	std::string getTitle(); // �������� �������� �����
private:
	std::set<Room*> rooms;
	std::string title;
};

