#pragma once
#include<iostream>
#include<vector>
#include<gl/glut.h>
#include"Stat.h"
#include"Item.h"
#include"Potion.h"
#include"Weapon.h"
#include<string>
using namespace std;
void renderBitmapString1(float x, float y, void* font, string string1, int a, int b, int c)
{
	glColor3f(a, b, c);
	glRasterPos2f(x, y);
	for (char c : string1)
	{
		glutBitmapCharacter(font, c);
	}
}
class ItemBar
{
public:
	vector<Item*> item;
	int MaxSlot = 10;
	int SelectSlot=1;
	double weight;
	bool popup = false;
	int pop = 0;
	ItemBar()
	{
		cout << "Khoi tao class ItemBar\n";
		item.push_back(new HealthPoiton("Potion","HealthPotion"));
		item.push_back(new Pickaxe("Weapon","Pickaxe"));
		item.push_back(new Item("Item","Stone"));
		
		
	}
	bool isItemValid(int index)
	{
		return index < item.size(); // Kiểm tra xem index có nằm trong phạm vi của vector không
	}
	void drawRectangle(float x1, float y1, float x2, float y2)
	{
		glColor3f(0.5, 0.5, 1);
		glLineWidth(6);
		glBegin(GL_LINE_LOOP); // Bắt đầu vẽ đường viền
		glVertex2f(x1 - 1, y1 + 1);    // Đỉnh trái dưới
		glVertex2f(x2 + 1, y1 + 1);    // Đỉnh phải dưới
		glVertex2f(x2 + 1, y2 - 1);    // Đỉnh phải trên
		glVertex2f(x1 - 1, y2 - 1);    // Đỉnh trái trên
		glEnd();               // Kết thúc vẽ đường viền
	}
	void CheckTimeItem(int index)
	{
		if (item[index]->ammount < 1)
		{
			item.erase(item.begin()+index);
		}
		else
			return;
	}
	void drawItemBar()
	{
		if (popup == true&&isItemValid(pop))
		{
			pair<int, int> xyz(0, 200);
			pair<int, int> xyz2(90, 500);
			glColor3f(1, 1, 1);
			glRectf(xyz.first, xyz.second, xyz2.first, xyz2.second);
			renderBitmapString1(0, 220, GLUT_BITMAP_HELVETICA_10, "Name:", 0, 0, 0);
			string tmp2 = item[pop]->name;
			renderBitmapString1(30, 220, GLUT_BITMAP_HELVETICA_10, tmp2, 0, 0, 0);
			renderBitmapString1(0, 230, GLUT_BITMAP_HELVETICA_10, "Type:", 0, 0, 0);
			string tmp = item[pop]->type;
			renderBitmapString1(30, 230, GLUT_BITMAP_HELVETICA_10, tmp, 0, 0, 0);
			renderBitmapString1(0, 240, GLUT_BITMAP_HELVETICA_10, "Ammount:", 0, 0, 0);
			string tmp1 = to_string(item[pop]->ammount);
			renderBitmapString1(60, 240, GLUT_BITMAP_HELVETICA_10, tmp1, 0, 0, 0);
		}
		pair<int, int>x1 = make_pair<int, int>(100, 540);
		pair<int, int>x2 = make_pair<int, int>(130, 570);
		for (int i = 0; i < MaxSlot; ++i)
		{
			if (isItemValid(i) == true)
			{
				CheckTimeItem(i);
			}
			if(SelectSlot==i+1)
				drawRectangle(x1.first, x1.second, x2.first, x2.second);
			if (isItemValid(i)==false)
			{
				glColor3f(0, 1, 0);
				glRectf(x1.first, x1.second, x2.first, x2.second);
			}
			if (isItemValid(i) == true)
			{
				if (item[i]->type == "Item")
				{
					glColor3f(1, 1, 1);
					glRectf(x1.first, x1.second, x2.first, x2.second);
				}
				if (item[i]->type == "Weapon")
				{
					glColor3f(1, 1, 0);
					glRectf(x1.first, x1.second, x2.first, x2.second);
				}
				else
				{
					glColor3f(1, 1, 1);
					glRectf(x1.first, x1.second, x2.first, x2.second);
				}

			}
			x1.first += 31;
			x2.first += 31;
		}
	}
	bool pointInFrame(int x, int y, int frameX, int frameY, int width, int height) {
		return (x >= frameX && x <= frameX + width && y >= frameY && y <= frameY + height);
	}
	void MotionPopupItemBar(int x, int y) {
		
		pair<int, int>first;
		for (int i = 0; i < 10; ++i) {
			first.first = 100 + i * 31;
			first.second= 540;
			if (pointInFrame(x, y, first.first, first.second, 30, 30)) {
				popup = true;
				pop = i;
				return;
			}
			else
				popup = false;
		}
	}
};

