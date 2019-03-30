#include <iostream>
#include <string>
#include <map>
#include "Menu.h"
using namespace std;

#ifndef PIZZA_H
#define PIZZA_H

enum PizzaSize { PERSONNAL = 1, MEDIUM, LARGE, FAMILY };//enum for the different sizes of the pizza
enum PizzaStyle { HandTossed, Thin, DeepDish };
map <PizzaSize, string> PsizeMap = { { PERSONNAL, "Personnal (10 In)" }, //a map for the different pizza sizes for the toString
									{ MEDIUM, "Medium (14 In)" },
									{ LARGE, "Large (18 In)" },
									{ FAMILY, "Family (20 In)" } };

class Pizza : public MenuItem
{
private:
	PizzaSize size;
	PizzaStyle style;
public:
	Pizza(PizzaSize Size, PizzaStyle Style)//constructor
	{
		style = Style;
		size = Size;
	}

	double getPrice()//funtion to get the price for each size of the pizza
	{
		switch (size)//switch statement to get the price for each size of the pizza
		{
		case PERSONNAL:
			return 5.99;
		case MEDIUM:
			return 6.99;
		case LARGE:
			return 12.99;
		case FAMILY:
			return 14.99;
			break;
		}
	}

	string toString()//toSting method for the pizza order
	{
		string PizzaString = "\nYou ordered a " + PsizeMap.find(size)->second + " Pizza for $" + to_string(getPrice());
		return PizzaString;
	}
};
#endif;