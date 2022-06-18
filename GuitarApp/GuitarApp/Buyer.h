#ifndef DEBUG_H
#define DEBUG_H
class Offer;

#include "Shop.h"
class Buyer
{
private:
	string name;
	int money;
	List<GuitarSpec>* inventory;

	class Offer {
	private: 
		Buyer* buyer;
		Shop* shop;
		GuitarSpec* spec;
	public:

		Offer(Buyer* buyer, Shop* shop, GuitarSpec* spec) {
			this->buyer = buyer;
			this->shop = shop;
			this->spec = spec;
			cout <<buyer->getName()<<" ����� ������ �  � �������� \"" << shop->getTitle() << 
				"\" ������ �� ���������� ����������������: " << endl << *spec ;
		}

		void doPurchase() {
			cout << "=========================================================================================" << endl;
			cout << buyer->getName() << ", ������������ ��� � ����� �������� \"" << shop->getTitle() << endl;
			List<Guitar>* searchingResult = shop->getInventory()->search(spec);
			if (searchingResult->size() == 0)
			{
				cout << buyer->getName() << ", � ���������, ����� ������ ��� � ����� ��������. ��������� � ��������� ���. " << endl;
				return;
			}
			cout << buyer->getName() << ", �� ������ ������� � ����� �������� ������� ��������� ������" << endl;
			int index = 0;
			for (auto it = searchingResult->begin(); it != searchingResult->end(); ++it)
			{
				cout << "������ " << index << ":" << endl;
				Guitar guitar = *it;
				cout <<"-"<< guitar;
				index++;
			}

			cout << "����� ������ �� ������ �� ������? (������� ������ ������ �� 0 �� " << index-1 << ")" << endl;
			int choose = 0;
			do {
				
				if (!cin) {
					cout << "������� ���������� ������� �����:" << endl;
					cin.clear();
					cin.ignore(32767, '\n');
				}
				if (choose < 0 || choose >= index)
					cout << "�� �� �������� � ������ ����������  ��� ��� ��� �������(������� -1)" << endl;

				cin >> choose;

			} while (!cin || (choose != -1 && (choose < 0 || choose >= index)));

			if (choose == -1) {
				cout << "��� ���� ��� ��� �� ������� �� ���� �� ����� �����. ��������� � ��� � ������ ���." << endl;
				return;
			}
			cout << "���������� �����, ��������� �� �����." << endl;
			index = 0;
			auto it = searchingResult->begin();
			for (int index = 0; index != choose; index++) ++it;
			Guitar choosed = (*it);

			if (buyer->getMoney() < choosed.getPrice()) {
				cout << buyer->getName() << " � ��������� � ��� �� ������� ����� �� ��� ������. ��������� � ��������� ���" << endl;
				return;
			}

			GuitarSpec buyerGuitar = *(choosed.getSpec());
			buyer->setMoney(buyer->getMoney() - choosed.getPrice());
			cout << "����������� ��� � �������� ������: " << endl;
			cout << buyerGuitar << endl;
			buyer->addGuitar(buyerGuitar);
			cout << "=========================================================================================" << endl;
		}
	};
public:

	Buyer(string name, int money) {
		this->name = name;
		this->money = money;
		inventory = new List<GuitarSpec>;
	}
	~Buyer() {
		delete inventory;
	}

	string getName() {
		return name;
	}

	int getMoney() {
		return money;
	}
	
	void setMoney(int money) {
		this->money = money;
	}

	void setName(string name) {
		this->name = name;
	}

	void buyGuitar(Shop* shop, GuitarSpec* spec) {
		Offer of(this, shop, spec);
		of.doPurchase();		
	}

	void addGuitar(GuitarSpec guitar) {
		inventory->push_back(guitar);
	}

	void printInventory() {
		cout << (*inventory);
	}
};


#endif