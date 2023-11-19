#pragma once
#include<iostream>
#include<vector>
#include<gl/glut.h>

using namespace std;

vector<char> values = { '#', 'S', 'E',' ',' '};
void drawbox(pair<int, int>x1, pair<int, int>x2, char a)
{
	if (a == ' ')
		glColor3f(1, 1, 1);
	else if (a == '#')
		glColor3f(1, 0, 1);
	else if (a == 'S')
		glColor3f(1, 1, 0.5);
	else if (a == 'E')
		glColor3f(0, 0, 0);
	else if (a == 'C')
		glColor3f(0, 1, 0);
	else
		glColor3f(1, 0, 0.3);
	glRectf(x1.first, x1.second, x2.first, x2.second);
}

class Map
{
public:
	pair<int,int> Mapsize;
	pair<int, int> Start;
	pair<int, int> End;
	vector<vector<char>> matrix;
	void drawMap()
	{
		pair<int, int>x1 = make_pair<int, int>(100, 100);
		pair<int, int>x2 = make_pair<int, int>(120, 120);
		for (int i = 0; i < Mapsize.first; ++i)
		{
			for (int j = 0; j < Mapsize.second; ++j)
			{
				if (matrix[i][j] == ' ')
					drawbox(x1, x2, ' ');
				if (matrix[i][j] == '#')
					drawbox(x1, x2, '#');
				if (matrix[i][j] == 'S')
					drawbox(x1, x2, 'S');
				if (matrix[i][j] == 'E')
					drawbox(x1, x2, 'E');
				x1.first += 21;
				x2.first += 21;
			}
			x1.first = 100;
			x2.first = 120;
			x1.second += 21;
			x2.second += 21;
		}
	}
	Map(pair<int, int> size)
	{
		cout << "Khoi tao class Map\n";
		Mapsize = size;
		matrix = random();
	}
	Map(vector<vector<char>> matrix)
	{
		cout << "Khoi tao class Map\n";
		this->matrix = matrix;
	}
	~Map()
	{
		cout << "Huy class Map\n";
	}
	vector<vector<char>> random()
	{
		vector<vector<char>> matrix(Mapsize.first, vector<char>(Mapsize.second));
		srand(time(NULL)); // Đặt seed cho hàm ngẫu nhiên
		for (int i = 1; i < Mapsize.first - 1; ++i) {
			for (int j = 1; j < Mapsize.second - 1; ++j) {

				int tmpindex = getRandomIndex();
				matrix[i][j] = values[tmpindex];
				if (matrix[i][j] == 'S')
				{
					values.erase(values.begin() + tmpindex);
					Start.first = i;
					Start.second = j;
				}
				if (matrix[i][j] == 'E')
				{
					values.erase(values.begin() + tmpindex);
					End.first = i;
					End.second = j;
				}

			}
		}
		for (int i = 0; i < Mapsize.first; ++i)
		{
			matrix[i][0] = '#';
			matrix[i][Mapsize.second - 1] = '#';
			for (int j = 0; j < Mapsize.second; ++j)
			{
				matrix[0][j] = '#';
				matrix[Mapsize.first - 1][j] = '#';
			}
		}

		return matrix;
	}
	int getRandomIndex();
	void Print()
	{
		for (int i = 0; i < Mapsize.first; ++i)
		{
			for (int j = 0; j < Mapsize.second; ++j)
			{
				cout << matrix[i][j];
			}
			cout << "\n";
		}
		cout << "\n";
		cout << Start.first << Start.second;
		cout << "\n";
		cout << End.first << End.second;

	}
};
int Map::getRandomIndex()
{
	
	int randomIndex = rand() % values.size();
	return randomIndex;
}
Map* a = new Map(make_pair<int, int>(20, 25));


