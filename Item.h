#pragma once
#include<iostream>
#include"Map.h"
#include <algorithm>
#include"Stat.h"
using namespace std;
 class Item
{
public:
	string type;
	string name;
	int ammount;
	Item(string type,string name):type(type), name(name), ammount(1)
	{
		cout << "Khoi tao class item\n";
	}
	virtual void UseItem(Map*& am, pair<int, int>waysee, Stat &stat)
	{
	}
	virtual void UseItem(Map* &am, pair<int, int>waysee,vector<Item*> &itemm)
	{
	}
};