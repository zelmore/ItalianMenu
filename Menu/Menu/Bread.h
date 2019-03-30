#include <iostream>
#include <string>
#include <map>
#include "Menu.h"
using namespace std;

#ifndef BREAD_H
#define BREAD_H

enum BreadType { CHEESY = 1, GARLIC };//enum for different types of bread
map <BreadType, string> BtypeMap = { { CHEESY, "Cheesy" },//map for the different types of bread for the toString
									{ GARLIC, "Garlic" } };

class Bread : public MenuItem
{
private:
	BreadType type;
public:
	Bread(BreadType Type)//constructor
	{
		type = Type;;
	}

	double getPrice()//method for getting the price
	{
		switch (type)//switch statement for the prices
		{
		case CHEESY:
			return 7.99;
		case GARLIC:
			return 6.99;
			break;
		}
	}

	string toString()//method for the toString
	{
		string BreadString = "\nYou ordered " + BtypeMap.find(type)->second + " bread for $" + to_string(getPrice());
		return BreadString;
	}
};

#endif;