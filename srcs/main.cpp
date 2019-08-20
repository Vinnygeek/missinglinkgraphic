#include"../headers/Objetos.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

    int main(int argc, char **argv){
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
        glutInitWindowPosition(100,100);
        glutInitWindowSize(500,500);
        glutCreateWindow("Exercicio1a - Computacao Grafica");

        glutDisplayFunc(renderer);
        glutReshapeFunc(changeSize);
        glutIdleFunc(renderer);
        glutSpecialFunc(directionalKeysHandeler);
        glutTimerFunc(1, Timer, 1);
        glEnable(GL_DEPTH_TEST);
        glutMainLoop();
        return 0;
    }
