#include <iostream>
#include <string>
#include <map>
using namespace std;

#ifndef MENU_H
#define MENU_H

class MenuItem
{
public:
	virtual string toString() = 0;
	virtual double getPrice() = 0;
};
#endif;