//Write a program that simulates an RPG shop inventory.
//The shop should store how much gold it currently has.
//It should also store an array of items it can stock. 
//Each item should have the name of that item,
//the cost per item and the quantity of that item currently in the shop.
//The program should have the following options :
//a. Change the price of each item in the shop
//b. Spend gold to add stock for a specific item
//c. Sell stock for a specific item to gain more gold

#include <iostream>
#include <string>

using namespace std;

struct Item
{
	std::string name;
	int price;
};

struct Stock
{
	Item item;
	int quantity;
};

struct Shop
{
	Stock swordStock;
	Stock shieldStock;
	Stock potionStock;

	int gold;
};

struct Buyer
{
	int gold;

	int buy(Stock& item)
	{
		if (item.quantity > 0)
		{
			gold -= item.item.price;
			item.quantity -= 1;
		}
		return gold, item.quantity;
	}
};

int main()
{
	Shop shop;
	Buyer player;
	Stock swords;
	Stock shields;
	Stock potions;

	player.gold = 100;

	swords.item.name = { "Sword" };
	swords.item.price = 50;
	swords.quantity = 1;

	shields.item.name = { "Shield" };
	shields.item.price = 25;
	shields.quantity = 1;

	potions.item.name = { "Potion" };
	potions.item.price = 5;
	potions.quantity = 5;

	shop.gold = 500;
	shop.swordStock = swords;
	shop.shieldStock = shields;
	shop.potionStock = potions;

	cout << "Hello, what is your name Player?" << endl;

	string pName;
	cin >> pName;

	char pPlaying = 'Y';
	int op;

	int timesLooped = 0;

	while (pPlaying == 'Y' || pPlaying == 'y')
	{
		if (timesLooped == 0)
		{
			system("cls");
			cout << "Well " << pName << " welcome to my shop, my name is George!" << endl;
			system("pause");
			system("cls");
			cout << "What would you like to buy?" << endl;
			cout << "1) I would like to buy a sword!" << endl;
			cout << "2) I would like to buy a shield!" << endl;
			cout << "3) I would like to buy a potion!" << endl;
			cout << "4) I am leaving." << endl;
		}

		if (timesLooped > 0)
		{
			if (shop.swordStock.quantity == 0 && shop.shieldStock.quantity == 0 && shop.potionStock.quantity == 0)
			{
				cout << "What would you like to buy?" << endl;
				cout << "1) OUT OF STOCK" << endl;
				cout << "2) OUT OF STOCK" << endl;
				cout << "3) OUT OF STOCK" << endl;
				cout << "4) I am leaving." << endl;
			}
			else if (shop.swordStock.quantity == 0 && shop.shieldStock.quantity == 0 && shop.potionStock.quantity < 5)
			{
				cout << "What would you like to buy?" << endl;
				cout << "1) OUT OF STOCK" << endl;
				cout << "2) OUT OF STOCK" << endl;
				cout << "3) I would like to buy another potion!" << endl;
				cout << "4) I am leaving." << endl;
			}
			else if (shop.swordStock.quantity == 0 && shop.shieldStock.quantity == 0)
			{
				cout << "What would you like to buy?" << endl;
				cout << "1) OUT OF STOCK" << endl;
				cout << "2) OUT OF STOCK" << endl;
				cout << "3) I would like to buy a potion!" << endl;
				cout << "4) I am leaving." << endl;
			}
			else if (shop.swordStock.quantity == 0 && shop.potionStock.quantity < 5)
			{
				cout << "What would you like to buy?" << endl;
				cout << "1) OUT OF STOCK" << endl;
				cout << "2) I would like to buy a shield!" << endl;
				cout << "3) I would like to buy another potion!" << endl;
				cout << "4) I am leaving." << endl;
			}
			else if (shop.shieldStock.quantity == 0 && shop.potionStock.quantity < 5)
			{
				cout << "What would you like to buy?" << endl;
				cout << "1) I would like to but a sword" << endl;
				cout << "2) OUT OF STOCK" << endl;
				cout << "3) I would like to buy another potion!" << endl;
				cout << "4) I am leaving." << endl;
			}
			else if (shop.swordStock.quantity == 0)
			{
				cout << "Would you like to buy anything else!?" << endl;
				cout << "1) OUT OF STOCK" << endl;
				cout << "2) I would like to buy a shield!" << endl;
				cout << "3) I would like to buy a potion!" << endl;
				cout << "4) I am leaving." << endl;
			}
			else if (shop.shieldStock.quantity == 0)
			{
				cout << "What would you like to buy?" << endl;
				cout << "1) I would like to buy a sword!" << endl;
				cout << "2) OUT OF STOCK" << endl;
				cout << "3) I would like to buy a potion!" << endl;
				cout << "4) I am leaving." << endl;
			}
			else if (shop.potionStock.quantity < 5)
			{
				cout << "What would you like to buy?" << endl;
				cout << "1) I would like to buy a sword!" << endl;
				cout << "2) I would like to buy a shield!" << endl;
				cout << "3) I would like to buy another potion!" << endl;
				cout << "4) I am leaving." << endl;
			}
			else if (shop.potionStock.quantity == 0)
			{
				cout << "What would you like to buy?" << endl;
				cout << "1) I would like to buy a sword!" << endl;
				cout << "2) I would like to buy a shield!" << endl;
				cout << "3) OUT OF STOCK" << endl;
				cout << "4) I am leaving." << endl;
			}
			
			
		}

		cin >> op;
		system("cls");

		switch (op)
		{
			case 1:
			{
				player.buy(shop.swordStock);
				shop.gold += shop.swordStock.item.price;
				timesLooped++;
				break;
			}
			case 2:
			{
				player.buy(shop.shieldStock);
				shop.gold += shop.shieldStock.item.price;
				timesLooped++;
				break;
			}
			case 3:
			{
				player.buy(shop.potionStock);
				shop.gold += shop.potionStock.item.price;
				timesLooped++;
				break;
			}
			case 4:
			{
				break;
			}
		}
		if (op == 4 || player.gold <= 0)
		{
			cout << "Goodbye " << pName << " have a nice day!!!" << endl;
			break;
		}
	}
	system("pause");
	return 1;
}
