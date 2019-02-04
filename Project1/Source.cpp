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

	int buy(Stock item)
	{
		if (item.quantity > 0)
		{
			gold -= item.item.price;
		}
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

	potions.item.name = { "potio" };
	potions.item.price = 5;
	potions.quantity = 5;

	shop.gold = 500;
	shop.swordStock = swords;
	shop.shieldStock = shields;
	shop.potionStock = potions;

	cout << "Hello, what is your name Player?" << endl;

	string pName;
	cin >> pName;

	char pChoice;
	char pPlaying = 'Y';
	int op;

	int timesLooped = 0;

	while (pPlaying == 'Y' || pPlaying == 'y')
	{
		if (timesLooped == 0)
		{
			cout << "Well " << pName << " welcome to my shop, my name is George!" << endl;
			cout << "What would you like to buy?" << endl;
			cout << "1) I would like to buy a sword!" << endl;
			cout << "2) I would like to buy a shield!" << endl;
			cout << "3) I would like to buy a potion!" << endl;
			cout << "4) I am leaving." << endl;
		}

		if (timesLooped > 0)
		{
			if (shop.swordStock.quantity < 1)
			{
				cout << "Would you like to buy anything else!?" << endl;
				cout << "1) I would like to buy another sword!" << endl;
				cout << "2) I would like to buy a shield!" << endl;
				cout << "3) I would like to buy a potion!" << endl;
				cout << "4) I am leaving." << endl;
			}
			else if (shop.shieldStock.quantity < 1)
			{
				cout << "What would you like to buy?" << endl;
				cout << "1) I would like to buy a sword!" << endl;
				cout << "2) I would like to buy another shield!" << endl;
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
		}

		switch (op)
			case 1:
			case 2:
			case 3:
			case 4:


		timesLooped++
	}
}
