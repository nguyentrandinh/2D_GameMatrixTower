#pragma once
#include<iostream>
#include<utility>
#include<gl/glut.h>
using namespace std;
class Health {
private:
	unsigned int Max = 100;
	unsigned int curHeath;
public:
	bool GetDamage(unsigned int ammount)
	{
		if (curHeath >= ammount)
		{
			curHeath -= ammount;
			return 1;
		}
		else
		{
			curHeath = 0;
			return 0;//die
		}
	}
	void HealHealth(unsigned int ammount)
	{
		curHeath += ammount;
		if (curHeath > Max)
			curHeath = Max;
	}
	void IncreaseMaxHealth(unsigned int ammount)
	{
		Max += ammount;
	}
	void DecreaseMaxHealth(unsigned int ammount)
	{
		Max -= ammount;
	}
	Health()
	{
		curHeath = Max;
		cout << "Khoi tao class Health\n";
	}
	Health(unsigned int a)
	{
		cout << "Khoi tao class Health\n";
		Max = a;
		curHeath = a/2;
	}
	void display()
	{
		pair<int, int>x1 = make_pair<int, int>(40, 20);
		pair<int, int>x2 = make_pair<int, int>(140, 40);		
		glColor3f(1, 1, 1);
		glRectf(x1.first, x1.second, x2.first, x2.second);
		int LengthBar = x2.first - x1.first;
		float perHealth = static_cast<float>(curHeath) / Max;
		int ShowcurHealth = static_cast<int>(perHealth * LengthBar);
		pair<int, int>xcur1 = make_pair<int, int>(40, 20);
		pair<int, int>xcur2 = make_pair<int, int>(40+ ShowcurHealth, 40);
		glColor3f(1, 0, 0);
		glRectf(xcur1.first, xcur1.second, xcur2.first, xcur2.second);
	}
};
