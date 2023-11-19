#pragma once
#include<iostream>
#include<utility>
#include<gl/glut.h>
using namespace std;
class Energy {
private:
	unsigned int Max = 50;
	unsigned int curEnergy;
public:
	bool UseEnergy(unsigned int ammount)
	{
		if (curEnergy >= ammount)
		{
			curEnergy -= ammount;
			return 1;
		}
		else
			return 0;//Don't have enough energy
	}
	void HealEnergy(unsigned int ammount)
	{
		curEnergy += ammount;
		if (curEnergy > Max)
			curEnergy = Max;
	}
	void IncreaseMaxEnergy(unsigned int ammount)
	{
		Max += ammount;
	}
	void DecreaseMaxEnergy(unsigned int ammount)
	{
		Max -= ammount;
	}
	Energy()
	{
		curEnergy = Max;
		cout << "Khoi tao class Energy\n";
	}
	Energy(unsigned int a)
	{
		Max = a;
		curEnergy = a;
	}
	void display()
	{
		pair<int, int>x1 = make_pair<int, int>(40, 50);
		pair<int, int>x2 = make_pair<int, int>(140, 70);
		glColor3f(1, 1, 1);
		glRectf(x1.first, x1.second, x2.first, x2.second);
		int LengthBar = x2.first - x1.first;
		float perEnergy = static_cast<float>(curEnergy) / Max;
		int ShowcurEnergy = static_cast<int>(perEnergy * LengthBar);
		pair<int, int>xcur1 = make_pair<int, int>(40, 50);
		pair<int, int>xcur2 = make_pair<int, int>(40 + ShowcurEnergy, 70);
		glColor3f(0, 1, 1);
		glRectf(xcur1.first, xcur1.second, xcur2.first, xcur2.second);
	}
};
