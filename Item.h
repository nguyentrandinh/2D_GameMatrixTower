#pragma once
#include<iostream>
#include"Map.h"
#include <algorithm>
class Pickaxe;
using namespace std;
 class Item
{
public:
	string type;
	string ver;
	string name;
	int ammount;
	bool isinbar;
	Item(string type,string name)
	{
		cout << "Khoi tao class item\n";
		this->type = type;
		this->name = name;
		ammount = 1;
	}
	Item()
	{
	}
	virtual void UseItem(Map*& am, pair<int, int>waysee, Health* &health)
	{
	}
	virtual void UseItem(Map* &am, pair<int, int>waysee,vector<Item*> &itemm)
	{
	}
};
//class Pickaxe:public Item {
//public:
//	Pickaxe(string type):Item(type)
//	{
//		
//	}
//	void UseItem(Map* &am,pair<int,int>waysee, vector<Item*> &itemm) override
//	{
//		if (time >= 1)
//		{
//			bool check = false;
//			if (am->matrix[waysee.first][waysee.second] == '#')
//			{
//				am->matrix[waysee.first][waysee.second] = PATH;
//				for (const auto& item : itemm) {
//					if (item->type == "Stone") {
//						// Phần tử được tìm thấy
//						check = true;
//						item->ammount++;
//						break; // Nếu bạn chỉ quan tâm đến phần tử đầu tiên thỏa mãn điều kiện
//						
//						
//					}
//				}
//				if(check==false)
//					itemm.push_back(new Item("Stone"));
//			}
//			time--;
//		}
//		return;
//	}
//};

