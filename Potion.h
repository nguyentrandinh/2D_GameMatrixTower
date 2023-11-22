#pragma once
#include"Item.h"
#include <chrono>
#include<thread>
#include <iostream>
using namespace std::chrono_literals;
using namespace std;
using namespace std::this_thread;
class Potion:public Item
{
public:
	int timebuff;
	Potion(string type,string name) :Item(type,name),timebuff(5)
	{
	}
	virtual void buf(Stat& stat)
	{}
};
class HealthPoiton :public Potion
{
public:
	void buf(Stat &stat) override
	{
		while (timebuff >= 1) {
			sleep_for(1s);
			stat.health->HealHealth(10);
			timebuff--;
		}
		
	}
	HealthPoiton(string type,string name) :Potion(type,name)
	{
		cout << "Khoi tao class HealthPotion\n";
	}
	void UseItem(Map*& am, pair<int, int>waysee, Stat& stat) override
	{
		if (ammount >= 1)
		{
			stat.health->HealHealth(0);
			ammount--;

			thread buff(&HealthPoiton::buf, this, std::ref(stat));
			buff.detach();
		}
	}
	
};
class EnergyPotion :public Potion
{
public:
	EnergyPotion(string type, string name) :Potion(type, name)
	{
		cout << "Khoi tao class EnergyPotion\n";
	}
	void buf(Stat& stat) override
	{
		while (timebuff >= 1) {
			sleep_for(1s);
			stat.energy->HealEnergy(10);
			timebuff--;
		}

	}
	void UseItem(Map*& am, pair<int, int>waysee, Stat& stat) override
	{
		if (ammount >= 1)
		{
			stat.energy->HealEnergy(0);
			ammount--;
			thread buff(&EnergyPotion::buf, this, std::ref(stat));
			buff.detach();
		}
	}

};
