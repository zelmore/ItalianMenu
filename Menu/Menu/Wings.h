#include <iostream>
#include <string>
#include <map>
#include "Menu.h"
using namespace std;

#ifndef WINGS_H
#define WINGS_H

enum WingsType { TRADITIONAL = 1, BONELESS };//enum for the different types of wings
map <WingsType, string> wingtypeMap = { { TRADITIONAL, "Yummy Traditional Bone-in" },  //map for the different types of wings for the toString
{ BONELESS, "Delicious Boneless" } };

class Wings : public MenuItem
{
private:
	WingsType type;
	int quantity;
public:
	Wings(WingsType Type, int number)//constructor
	{
		type = Type;
		quantity = number;
	}

	int getQuantity()//method for the quantity of wings
	{
		return quantity;//returns the quantity
	}

	double getPrice()//method for getting the price
	{
		switch (type)//switch statement for getting the price by multiplying the base price by the getQuantity method
		{
		case TRADITIONAL:
			return 0.60 * quantity;
		case BONELESS:
			return 0.70 * quantity;
			break;
		default:
			return .70*quantity;
		}
	}

	string toString()//toString method
	{
		string WingsString = "\nYou ordered " + to_string(quantity) + " " + wingtypeMap.find(type)->second + " wings for $" + to_string(getPrice());
		return WingsString;
	}
};

#endif;