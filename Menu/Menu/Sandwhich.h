#include <iostream>
#include <string>
#include <map>
#include "Menu.h"
using namespace std;

#ifndef SANDWHICH_H
#define SANDWHICH_H

enum SandwhichLength { SIXINCH = 1, FOOTLONG };//enum for the different lengths/sizes of the sandwhich
map <SandwhichLength, string> SsizeMap = { { SIXINCH, "Six Inch" }, //map for the different sandwhich lengths for the toString
										{ FOOTLONG, "Foot Long" } };

class Sandwhich : public MenuItem
{
private:
	SandwhichLength length;
public:
	Sandwhich(SandwhichLength Length)//constructor
	{
		length = Length;
	}

	double getPrice()//method for getting the price
	{
		switch (length)//switch statement for getting the price of each length
		{
		case SIXINCH:
			return 6.00;
		case FOOTLONG:
			return 8.00;
			break;
		}
	}

	string toString()//tostring method for the sandwhich order
	{
		string SandwhichString = "\nYou ordered a " + SsizeMap.find(length)->second + " sub-sandwhich for $" + to_string(getPrice());
		return SandwhichString;
	}
};

#endif;