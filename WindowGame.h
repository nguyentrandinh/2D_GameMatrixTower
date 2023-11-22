#pragma once
#include<iostream>
#include<vector>
#include<string.h>
#include<GL/glut.h>
#include"Map.h"
#include"Character.h"
#include<string>
#include<math.h>
#include<thread>
int mouseX;
int mouseY;
#define W 700
#define H 600

void renderBitmapString(float x, float y, void* font, string string1, int a, int b, int c)
{
    glColor3f(a, b, c);
    glRasterPos2f(x, y);
    for (char c : string1)
    {
        glutBitmapCharacter(font, c);
    }
}
void Init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, W, H, 0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    a->drawMap();
    Layer2MatrixCharacter->display(a->matrix);
    renderBitmapString(100, 100, GLUT_BITMAP_TIMES_ROMAN_24, to_string(mouseX), 1, 1, 1);
    renderBitmapString(100, 90, GLUT_BITMAP_TIMES_ROMAN_24, to_string(mouseY), 1, 1, 1);
    glutPostRedisplay();
    glutSwapBuffers();
    glFlush();
}
void handleKeyPress(unsigned char key, int x, int y)
{
    Layer2MatrixCharacter->Moving(key, x, y);
    Layer2MatrixCharacter->SelectSlotBar(key, x, y);
    Layer2MatrixCharacter->UseItem(key, x, y);
}
void handleKeyReleased(unsigned char key, int x, int y)
{
    glutPostRedisplay();
}
void mouseMotion(int x, int y) {
    // Cập nhật vị trí chuột khi di chuyển chuột
    
    mouseX = x;
    mouseY = y;
    Layer2MatrixCharacter->checkWayeyes(x, y);
    Layer2MatrixCharacter->Bar.MotionPopupItemBar(mouseX, mouseY);
}