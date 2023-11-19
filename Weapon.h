#pragma once
#include"Item.h"
class Weapon:public Item
{
public:
	Weapon(string type,string name) :Item(type,name)
	{

	}
};
class Pickaxe :public Weapon {
public:
	Pickaxe(string type,string name) :Weapon(type, name)
	{
		cout << "Khoi tao class Pickaxe\n";
		ammount = 200;
	}
	void UseItem(Map*& am, pair<int, int>waysee, vector<Item*>& itemm) override
	{
		if (ammount >= 1)
		{
			bool check = false;
			if (am->matrix[waysee.first][waysee.second] == '#'&& waysee.first!=0 && waysee.second!=0 && waysee.first != am->Mapsize.first-1 && waysee.second != am->Mapsize.second - 1)
			{
				am->matrix[waysee.first][waysee.second] = ' ';
				for (const auto& item : itemm) {
					if (item->name == "Stone") {
						// Phần tử được tìm thấy
						check = true;
						item->ammount++;
						break; // Nếu bạn chỉ quan tâm đến phần tử đầu tiên thỏa mãn điều kiện


					}
				}
				if (check == false)
					itemm.push_back(new Item("Item","Stone"));
			}
			ammount--;
		}
		return;
	}
};
