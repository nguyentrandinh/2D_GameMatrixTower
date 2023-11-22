#pragma once
#include"WindowGame.h"
using namespace std;
void ma(int argv, char** argc,int base) {
    glutInit(&argv, argc);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(W, H);
    glutInitWindowPosition(0, 0);
    base = glutCreateWindow("MAZE Game");
    Init();
    glutDisplayFunc(display);
    glutPassiveMotionFunc(mouseMotion);
    glutKeyboardFunc(handleKeyPress);
    glutKeyboardUpFunc(handleKeyReleased);
    a->Print();
    glutMainLoop();
}
void aloa()
{
    cout << "aloo";
}
int main(int argv, char** argc)
{
    int base1;
    thread threaddd(ma, argv, argc,base1);
    threaddd.join(); // Wait for 'ma' thread to finish
    
}
