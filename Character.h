#pragma once
#include<vector>
#include<utility>
#include"ItemBar.h"
#include"Map.h"
#include <typeinfo>
using namespace std;
char Eyes;
bool isKeyPressed = false;
class Character
{
public:
    vector<vector<char>> layer2matrixmove;
	pair<int, int>position;
    pair<int, int>waysee;
    Stat stat;
    ItemBar Bar;
    Character()
	{
        cout << "Khoi tao class Character\n";
        stat.display();
	}
    Character(pair<int, int>position)
	{
		this->position = position;
        waysee = position;
        cout << "Khoi tao class Character\n";
	}
    void display( vector<vector<char>> matrix)
    { 
        layer2matrixmove.resize(matrix.size(), vector<char>(matrix[0].size()));
        layer2matrixmove[position.first][position.second] = 'C';
        pair<int, int>x1 = make_pair<int, int>(100, 100);
        pair<int, int>x2 = make_pair<int, int>(120, 120);
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[0].size(); ++j)
            {
                if (layer2matrixmove[i][j] == 'C')
                {
                    glColor3f(0, 1, 0);
                    glPointSize(10);
                    glBegin(GL_POINTS);
                    glVertex2f(x1.first + 10, x1.second + 10);
                    glEnd();
                }

                if(i==waysee.first && j==waysee.second)
                {
                    drawRectangle(x1.first, x1.second, x2.first, x2.second);
                }
                x1.first += 21;
                x2.first += 21;
            }
            x1.first = 100;
            x2.first = 120;
            x1.second += 21;
            x2.second += 21;
        }
        stat.display();
        Bar.drawItemBar();
       
    }
void Moving(unsigned char key, int x, int y)
{
    switch (key) {
    case 'w': {
        if (!isKeyPressed) {
            if (a->matrix[position.first - 1][position.second] != '#')
            {
                position.first--;
            }
            isKeyPressed = true;
        }
        isKeyPressed = false;
        layer2matrixmove.clear();
        Wayeyes("U");
        break;
    }
    case 's': {
        if (!isKeyPressed) {
            if (a->matrix[position.first + 1][position.second] != '#')
            {
                position.first++;
            }isKeyPressed = true;
        }
        isKeyPressed = false;
        layer2matrixmove.clear();
        Wayeyes("D");
        break;
    }
    case 'd': {
        if (!isKeyPressed) {
            if (a->matrix[position.first][position.second + 1] != '#')
            {
                position.second++;
            }isKeyPressed = true;
        }
        isKeyPressed = false;
        layer2matrixmove.clear();
        Wayeyes("R");
        break;
    }
    case 'a': {
        if (!isKeyPressed) {
            if (a->matrix[position.first][position.second - 1] != '#')
            {
                position.second--;
            }isKeyPressed = true;
        }
        isKeyPressed = false;
        layer2matrixmove.clear();
        Wayeyes("L");
        break;
    }
    }
    if (a->matrix[position.first][position.second] == 'E')
    {
        exit(0);
    }
   
}
void SelectSlotBar(unsigned char key, int x, int y)
{
    switch (key)
    {
    case '1':
        Bar.SelectSlot = 1;
        break;
    case '2':
        Bar.SelectSlot = 2;
        break;
    case '3':
        Bar.SelectSlot = 3;
        break;
    case '4':
        Bar.SelectSlot = 4;
        break;
    case '5':
        Bar.SelectSlot = 5;
        break;
    case '6':
        Bar.SelectSlot = 6;
        break;
    case '7':
        Bar.SelectSlot = 7;
        break;
    case '8':
        Bar.SelectSlot = 8;
        break;
    case '9':
        Bar.SelectSlot = 9;
        break;
    case '0':
        Bar.SelectSlot = 10;
        break;
    }
}
void UseItem(unsigned char key, int x, int y)
{
    switch (key) {
    case 'e':
        if (Bar.isItemValid(Bar.SelectSlot - 1) == true)
        {
            Bar.item[Bar.SelectSlot - 1]->UseItem(a,waysee,Bar.item);
            Bar.item[Bar.SelectSlot - 1]->UseItem(a, waysee, stat);
        }
        break;
    }
}
void checkWayeyes( int x, int y)
{
    double centerX = 100 + position.second * 21 + 10;
    double centerY = 120 + position.first * 21 + 10;
    double angleRadians = std::atan2(y - centerY, x - centerX);

    // Chuyển đổi góc từ radian sang độ
    double angleDegrees = -angleRadians * 180.0 / 3.14;
    if (angleDegrees >= 60 && angleDegrees <= 120)
    {
        Wayeyes("U");
    }
    else if (angleDegrees > 120 && angleDegrees <= 150)
    {
        Wayeyes("UL");
    }
    else if (angleDegrees > 150 && angleDegrees <= 180 || angleDegrees <=-150 && angleDegrees >=-180)
    {
        Wayeyes("L");
    }
    else if (angleDegrees <=-120 && angleDegrees > -150)
    {
        Wayeyes("LD");
    }
    else if (angleDegrees <= -60 && angleDegrees >-120)
    {
        Wayeyes("D");
    }
    else if (angleDegrees <= -30 && angleDegrees > -60)
    {
        Wayeyes("DR");
    }
    else if (angleDegrees < 30 && angleDegrees >= 0 || angleDegrees <0 && angleDegrees >-30)
    {
        Wayeyes("R");
    }
    else if (angleDegrees <60 && angleDegrees >=30)
    {
        Wayeyes("RU");
    }

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
void Wayeyes(string way)
{
    pair<int, int>x1 = make_pair<int, int>(100, 100);
    pair<int, int>x2 = make_pair<int, int>(120, 120);
    if (way == "U")
    {
        waysee.first = position.first - 1;
        waysee.second = position.second;
    }
    else if (way == "UL")
    {
        waysee.first = position.first - 1;
        waysee.second = position.second - 1;
    }
    else if (way == "L")
    {
        waysee.first = position.first;
        waysee.second = position.second - 1;
    }
    else if (way == "LD")
    {
        waysee.first = position.first + 1;
        waysee.second = position.second - 1;
    }
    else if (way == "D")
    {
        waysee.first = position.first + 1;
        waysee.second = position.second;
    }
    else if (way == "DR")
    {
        waysee.first = position.first + 1;
        waysee.second = position.second + 1;
    }
    else if (way == "R")
    {
        waysee.first = position.first;
        waysee.second = position.second+1;
    }
    else if (way == "RU")
    {
        waysee.first = position.first - 1;
        waysee.second = position.second + 1;
    }
    else
        return;
}
};

Character* Layer2MatrixCharacter = new Character(a->Start);