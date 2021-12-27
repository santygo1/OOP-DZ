#pragma once

#include <string>
#include "Human.h"

class Visitor:public Human
{
public:
	Visitor(std::string name, int cardID, int age =10);

	int getCardID(); 

	virtual std::string getStatus() {
		return "���������� �����";
	}

	friend std::ostream& operator<<(std::ostream& out, const Visitor& visitor);

private:
	int cardID; // ����� ����������������� ����� ����������
};
