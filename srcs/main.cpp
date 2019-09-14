#include"../headers/Screen.hpp"

Screen* Screen_ptr;

    void renderer(){Screen_ptr->renderer();}
    void changeSize(int w, int h){Screen_ptr->changeSize(w,h);}
    void directionalKeysHandeler(int key, int x, int y){Screen_ptr->directionalKeysHandeler(key, x, y);}
    void Timer(int value){Screen_ptr->Timer(value, &Timer);}
    void MouseHandle(int button, int state, int x, int y){Screen_ptr->mouseHandle(button,state,x,y);}
    void MyKeyboardFunc(unsigned char Key, int x, int y){Screen_ptr->keyboardHandle(Key, x, y);}
    void motion(int x, int y){Screen_ptr->motion(x,y);}

    int main(int argc, char **argv){
        Screen myScreen;
        Screen_ptr = &myScreen;
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
        glutInitWindowPosition(100,100);
        glutInitWindowSize(500,500);
        glutCreateWindow("Exercicio1a - Computacao Grafica");

        glutDisplayFunc(renderer);
        glutReshapeFunc(changeSize);
        glutIdleFunc(renderer);
        glutMouseFunc(MouseHandle);
        glutMotionFunc(motion);
        glutKeyboardFunc(MyKeyboardFunc);
        glutSpecialFunc(directionalKeysHandeler);
        glutTimerFunc(1, Timer, 1);
        glEnable(GL_DEPTH_TEST);
        glutMainLoop();
        return 0;
    }