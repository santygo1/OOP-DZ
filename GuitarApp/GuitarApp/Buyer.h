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
			cout <<buyer->getName()<<" хочет купить в  в магазине \"" << shop->getTitle() << 
				"\" гитару со следующими характеристиками: " << endl << *spec ;
		}

		void doPurchase() {
			cout << "=========================================================================================" << endl;
			cout << buyer->getName() << ", приветствуем вас в нашем магазине \"" << shop->getTitle() << endl;
			List<Guitar>* searchingResult = shop->getInventory()->search(spec);
			if (searchingResult->size() == 0)
			{
				cout << buyer->getName() << ", к сожалению, такой гитары нет в нашем магазине. ѕриходите в следующий раз. " << endl;
				return;
			}
			cout << buyer->getName() << ", по вашему запросу в нашем магазине нашлись следующие гитары" << endl;
			int index = 0;
			for (auto it = searchingResult->begin(); it != searchingResult->end(); ++it)
			{
				cout << "√итара " << index << ":" << endl;
				Guitar guitar = *it;
				cout <<"-"<< guitar;
				index++;
			}

			cout << " акую гитару вы хотели бы купить? (¬ведите индекс гитары от 0 до " << index-1 << ")" << endl;
			int choose = 0;
			do {
				
				if (!cin) {
					cout << "’ватить реб€читьс€ введите число:" << endl;
					cin.clear();
					cin.ignore(32767, '\n');
				}
				if (choose < 0 || choose >= index)
					cout << "ќй вы ошиблись с числом попробуйте  еще раз или выйдите(¬ведите -1)" << endl;

				cin >> choose;

			} while (!cin || (choose != -1 && (choose < 0 || choose >= index)));

			if (choose == -1) {
				cout << " ак жаль что вам не подошла не одна из наших гитар. ѕриходите к нам в другой раз." << endl;
				return;
			}
			cout << "ѕрекрасный выбор, пройдемте на кассу." << endl;
			index = 0;
			auto it = searchingResult->begin();
			for (int index = 0; index != choose; index++) ++it;
			Guitar choosed = (*it);

			if (buyer->getMoney() < choosed.getPrice()) {
				cout << buyer->getName() << " к сожалению у вас не хватает денег на эту гитару. ѕриходите в следующий раз" << endl;
				return;
			}

			GuitarSpec buyerGuitar = *(choosed.getSpec());
			buyer->setMoney(buyer->getMoney() - choosed.getPrice());
			cout << "ѕоздравл€ем вас с покупкой гитары: " << endl;
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