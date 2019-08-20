#include <GL/glut.h>
#include <cmath>
#include <stdlib.h>

class Cubo{
    public:
        Cubo(float posX, float posY, float posZ, float cSize,float angleRot);
        void createCubo();
        void rotateXaxis();
        void rotateYaxis();
        void rotateZaxis();

    private:
        float vertices[24][3]; //Matriz com os vértices do cubo com base no referencial de mundo
        float cSize;
        float posX, posY, posZ;
        float x,y,z;
        float angleRot;
};


class _3D_Camera{
    public:
        _3D_Camera(float xEye, float yEye, float zEye, 
            float xCenter, float yCenter, float zCenter,
            float xUp, float yUp, float zUp);

        void createCam();

    private:
        float xEye, yEye ,zEye;
        float xCenter, yCenter, zCenter;
        float xUp, yUp, zUp;
};

class _3D_World_Base{
    public:
        _3D_World_Base(float xPos,float yPos, float zPos, 
            float xColor, float yColor, float zColor);

        void createBasis();

    private:
    float xPos,yPos,zPos;
    float xColor,yColor,zColor;
};

void Timer(int value);

void camReposition();

void directionalKeysHandeler(int key, int x, int y);

void changeSize(int w, int h);

void renderer(void);

