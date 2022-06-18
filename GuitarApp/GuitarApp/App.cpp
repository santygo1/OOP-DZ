#include "List.h"
#include "GuitarSpec.h"
#include "Guitar.h"
#include "Inventory.h"
#include "Shop.h"
#include "Buyer.h"

#include <iostream>
#include <string>

using namespace std;

void initializeInventoryForShop(Inventory* inventory) {
	GuitarSpec* guitar = new GuitarSpec(Creator::FENDER, "fa-100", Type::ACOUSTIC, 6, Wood::MAHOGANY, Wood::ALDER);
	inventory->addGuitar("fb21sa23", 12000, guitar);

	GuitarSpec* guitar3 = new GuitarSpec(Creator::GIBSON, "super 400", Type::ELECTRIC, 12, Wood::INDIAN_ROSEWOOD, Wood::INDIAN_ROSEWOOD);
	inventory->addGuitar("z2123", 14000, guitar3);

	GuitarSpec* guitar4 = new GuitarSpec(Creator::MARTIN, "LX1", Type::ACOUSTIC, 6, Wood::ALDER, Wood::ALDER);
	inventory->addGuitar("oP-231", 20000, guitar4);
}

int main() {
	
	setlocale(LC_ALL, "rus");

	//�������� �� ���� ���������� �������� ������� ��� ������� ������ �� ����� ����(� ������ ���������)
	Inventory* inventory = new Inventory();
	initializeInventoryForShop(inventory);
	Shop* shop = new Shop("�����������", inventory);

	//�� ��������������� �������� � �� ����������� ������ ����� ������ ������
	Buyer buyer("�����", 12000);
	
	// ���� ���������� ������� ��� ������ �� �������� ��������� � ������ ���������� ������
	// ������� ���������� ����� ������ ���� ������ � �������� ������������ �� ��������
	GuitarSpec* spec1 = GuitarSpec::Builder().topWood(Wood::MAHOGANY).build();
	buyer.buyGuitar(shop, spec1);
	delete spec1;
	// ������ � ���������� ���� ����� ������(���� ��� ������� ����� � �� ����� �� ������) 
	cout << "��������� ���������� " << buyer.getName() << ":" << endl;
	buyer.printInventory();
	cout << "� �������� ���������� " << buyer.getName() <<" " << buyer.getMoney()<< " ���." << endl;

	// ���������� ��������� �� �������� � ������ �� ������� ������������������ �������������
	GuitarSpec* spec2 = GuitarSpec::Builder().type(Type::ELECTRIC).numStrings(12).build();
	//C���� �������� �����
	buyer.setMoney(25000);
	//� ����� ������� � ��� �� �������
	buyer.buyGuitar(shop, spec2);
	delete spec2;

	// ��� ������� � ������ � ���� ���� ����� ������(���� ��� ������� ����� � �� ����� �� ������) 
	cout << "��������� ���������� " << buyer.getName() << ":" << endl;
	buyer.printInventory();
	cout << "� �������� ���������� " << buyer.getName() << " " << buyer.getMoney() << " ���." << endl;
	// ��������� �����������
	buyer.printInventory();

	// ������ ������ ������ ���������� �� ��� �� ������� ����� �� ��� ������ 
	// � �� ������ ������ ������ � 20 ��������
	GuitarSpec* spec3 = GuitarSpec::Builder().numStrings(20).build();
	// ��� ��� �� ����� ������� �����
	buyer.setMoney(100000);
	buyer.buyGuitar(shop, spec3);
	// �� ��� ����� ������ � �������� ���
	delete spec3;
	// �������� �������� �� ����� ���������� ���� �� ����
	cout << "��������� ���������� " << buyer.getName() << ":" << endl;
	buyer.printInventory();
	cout << "� �������� ���������� " << buyer.getName() << " " << buyer.getMoney() << " ���." << endl;

	delete shop;
	
	return 0;
}
