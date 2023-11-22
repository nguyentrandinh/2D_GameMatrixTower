#pragma once
#include"Health.h"
#include"Energy.h"
#include"Experience.h"
class Stat {
public:
	Health* health;
	Energy* energy;
	Experience* Exp;
	
	Stat()
	{
		cout << "Khoi tao class Stat\n";
		health = new Health(100);
		energy = new Energy(100);
		Exp = new Experience();
	}
	void display()
	{
		health->display();
		energy->display();
	}
};


