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

	//Недалеко от дома покупателя появился магазин где продают гитары на любой вкус(в рамках разумного)
	Inventory* inventory = new Inventory();
	initializeInventoryForShop(inventory);
	Shop* shop = new Shop("МУЗЫКАЛЬНЫЙ", inventory);

	//Он заинтересовался покупкой и на накопленные деньги решил купить гитару
	Buyer buyer("Данил", 12000);
	
	// Друг покупателя говорил что гитары из махагони недорогие и звучат достаточно хорошо
	// Поэтому покупатель решил купить себе гитару с передней поверхностью из Махагони
	GuitarSpec* spec1 = GuitarSpec::Builder().topWood(Wood::MAHOGANY).build();
	buyer.buyGuitar(shop, spec1);
	delete spec1;
	// Теперь у покупателя есть новая гитара(если ему хватает денег и он хочет ее купить) 
	cout << "Коллекция покупателя " << buyer.getName() << ":" << endl;
	buyer.printInventory();
	cout << "В кошельке покупателя " << buyer.getName() <<" " << buyer.getMoney()<< " руб." << endl;

	// Покупатель наигрался на акустике и теперь он захотел ДВЕНАДЦАТИСТРУННУЮ электрогитару
	GuitarSpec* spec2 = GuitarSpec::Builder().type(Type::ELECTRIC).numStrings(12).build();
	//Cнова отложиле денег
	buyer.setMoney(25000);
	//И решил сходить в тот же магазин
	buyer.buyGuitar(shop, spec2);
	delete spec2;

	// Ему повезло и теперь у него есть новая гитара(если ему хватает денег и он хочет ее купить) 
	cout << "Коллекция покупателя " << buyer.getName() << ":" << endl;
	buyer.printInventory();
	cout << "В кошельке покупателя " << buyer.getName() << " " << buyer.getMoney() << " руб." << endl;
	// Коллекция пополнилась
	buyer.printInventory();

	// Ставки растут теперь покупателю не уже не хватает струн на его гитаре 
	// И он решает купить гитару с 20 струнами
	GuitarSpec* spec3 = GuitarSpec::Builder().numStrings(20).build();
	// Ему уже не жалко никаких денег
	buyer.setMoney(100000);
	buyer.buyGuitar(shop, spec3);
	// Но увы такой гитары в магазине нет
	delete spec3;
	// Остается грустить со своей коллекцией один на один
	cout << "Коллекция покупателя " << buyer.getName() << ":" << endl;
	buyer.printInventory();
	cout << "В кошельке покупателя " << buyer.getName() << " " << buyer.getMoney() << " руб." << endl;

	delete shop;
	
	return 0;
}
