#pragma once
#include"WindowGame.h"
using namespace std;

int main(int argv, char** argc) {
    glutInit(&argv, argc);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(W, H);
    glutInitWindowPosition(0, 0);
    int base = glutCreateWindow("MAZE Game");
    Init();
    glutDisplayFunc(display);
    glutPassiveMotionFunc(mouseMotion);
    glutKeyboardFunc(handleKeyPress);
    glutKeyboardUpFunc(handleKeyReleased);
    a->Print();
    glutMainLoop();
    
}