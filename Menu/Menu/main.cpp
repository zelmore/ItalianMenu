/*
Menu.cpp
Zachary Elmore
7/14/16
This program is used to take orders from the menu list and output the total price to the user
*/

#include <iostream>
#include <string>
#include <vector>
#include "Menu.h"
#include "Pizza.h"
#include "Sandwhich.h"
#include "Wings.h"
#include "Bread.h"
using namespace std;

int main()
{
	cout << "Welcome to Little Italy!" << endl;

	vector <MenuItem*> order;

	char anotherItem;
	int choice;

	do
	{
		cout << "\nWhat would you like to order?:\n1: Pizza\n2: samiches\n3: wings\n4: bread" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			int option;

			cout << "\nWhat Size would you like?\n1: Personal ($5.99)\n2: Medium ($6.99)\n3: Large ($12.99)\n4: Family ($14.99)"
				<< endl;
			cin >> option;

			Pizza *myPizza = new Pizza(PizzaSize(option), HandTossed);

			order.push_back(myPizza);

			cout << myPizza->toString();
		}
		break;

		case 2:
		{
			int option;

			cout << "\nWhat length? \n1: Six Inch ($6.00)\n2: Foot Long ($8.00)" << endl;
			cin >> option;

			Sandwhich *mySandwhich = new Sandwhich(SandwhichLength(option));

			order.push_back(mySandwhich);

			cout << mySandwhich->toString();
		}
		break;

		case 3:
		{
			int option;
			int quantity;

			cout << "What type of wings?\n1: Traditional ($0.60 per wing)\n2: Boneless ($0.70 per wing)" << endl;
			cin >> option;

			cout << "\nHow Many wings would you like? [1-100]: ";
			cin >> quantity;

			while (quantity < 1 || quantity > 100)
			{
				cout << "ERROR!!! Invalid amount, please enter an amount within the range. [1-100]: ";
				cin >> quantity;
			}

			Wings *myWings = new Wings(WingsType(option), quantity);

			order.push_back(myWings);

			cout << myWings->toString();
		}
		break;

		case 4:
		{
			int option;

			cout << "What type of bread?\n1: Cheesy ($7.99)\n2: Garlic ($6.99)" << endl;
			cin >> option;

			Bread *myBread = new Bread(BreadType(option));

			order.push_back(myBread);

			cout << myBread->toString();
		}
		break;

		}

		cout << ".\nDo you want another item? [Y/N]: ";
		cin >> anotherItem;
	}

	while (anotherItem == 'Y' || anotherItem == 'y');

	double total = 0;

	for (int i = 0; i < order.size(); i++) {
		cout << order[i]->toString();
		total += order[i]->getPrice();
	}

	cout << "\n\nYour total is...\n" << order.size() << " Items, with a total of $" << total << endl;

	cin.ignore();
	cin.get();
	return 0;
}