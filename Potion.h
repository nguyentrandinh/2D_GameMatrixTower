#pragma once
#include"Item.h"
class Potion:public Item
{
public:
	Potion(string type,string name) :Item(type,name)
	{
	}
};
class HealthPoiton :public Potion
{
public:
	HealthPoiton(string type,string name) :Potion(type,name)
	{
		cout << "Khoi tao class HealthPoint\n";
		ammount = 1;
	}
	void UseItem(Map*& am, pair<int, int>waysee, Health*& health) override
	{
		if (ammount >= 1)
		{
			health->HealHealth(5);
			ammount--;
		}
	}
};

