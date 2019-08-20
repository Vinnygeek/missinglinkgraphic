#include<iostream>
#include<stdlib.h>
using namespace std;
#include"../headers/Objetos.h"
#define POS 5
    float rotateAngle = 0;
    int actualPosition = 0;
    int timerFuncTest = 0;
    float positionCamMatrix[5][3] = {20.0f, 20.0f, 20.0f, 10.0f, 6.0f, 23.0f,
         -10.0f, 6.0f, 3.0f, 10.0f, 6.0f, -17.0f, 30.0f, 6.0f, 3.0f};
    float camPosx = 20.0f; float camPosy = 20.0f; float camPosz = 20.0f; //20 20 20
    float camEyex = 10.0f; float camEyey = 6.0f; float camEyez = 3.0f; // 10 6 3
    float camUpx = 0.0f; float camUpy = 1.0f; float camUpz = 0.0f; 

    Cubo::Cubo(float posX, float posY, float posZ, float cSize, float angleRot){
        this->posX = posX; this->posY = posY; this->posZ = posZ; this->cSize = cSize; this->angleRot = angleRot;
        x = posX; y = posY; z = posZ;
        //Primeira Face (Top)
        vertices[0][0] = cSize/2; vertices[0][1] = cSize/2; vertices[0][2] = -cSize/2;
        vertices[1][0] = -cSize/2; vertices[1][1] = cSize/2; vertices[1][2] = -cSize/2;
        vertices[2][0] = -cSize/2; vertices[2][1] = cSize/2; vertices[2][2] = cSize/2;
        vertices[3][0] = cSize/2; vertices[3][1] = cSize/2; vertices[3][2] = cSize/2;

        //Segunda Face
        vertices[4][0] = cSize/2; vertices[4][1] = -cSize/2; vertices[4][2] = cSize/2;
        vertices[5][0] = -cSize/2; vertices[5][1] = -cSize/2; vertices[5][2] = cSize/2;
        vertices[6][0] = -cSize/2; vertices[6][1] = -cSize/2; vertices[6][2] = -cSize/2;
        vertices[7][0] = cSize/2; vertices[7][1] = -cSize/2; vertices[7][2] = -cSize/2;

        //Terceira Face
        vertices[8][0] = cSize/2; vertices[8][1] = cSize/2; vertices[8][2] = cSize/2;
        vertices[9][0] = -cSize/2; vertices[9][1] = cSize/2; vertices[9][2] = cSize/2;
        vertices[10][0] = -cSize/2; vertices[10][1] = -cSize/2; vertices[10][2] = cSize/2;
        vertices[11][0] = cSize/2; vertices[11][1] = -cSize/2; vertices[11][2] = cSize/2;

        //Quarta Face
        vertices[12][0] = cSize/2; vertices[12][1] = -cSize/2; vertices[12][2] = -cSize/2;
        vertices[13][0] = -cSize/2; vertices[13][1] = -cSize/2; vertices[13][2] = -cSize/2;
        vertices[14][0] = -cSize/2; vertices[14][1] = cSize/2; vertices[14][2] = -cSize/2;
        vertices[15][0] = cSize/2; vertices[15][1] = cSize/2; vertices[15][2] = -cSize/2;

        //Quinta Face
        vertices[16][0] = -cSize/2; vertices[16][1] = cSize/2; vertices[16][2] = cSize/2;
        vertices[17][0] = -cSize/2; vertices[17][1] = cSize/2; vertices[17][2] = -cSize/2;
        vertices[18][0] = -cSize/2; vertices[18][1] = -cSize/2; vertices[18][2] = -cSize/2;
        vertices[19][0] = -cSize/2; vertices[19][1] = -cSize/2; vertices[19][2] = cSize/2;
        //Sexta Face

        vertices[20][0] = cSize/2; vertices[20][1] = cSize/2; vertices[20][2] = -cSize/2;
        vertices[21][0] = cSize/2; vertices[21][1] = cSize/2; vertices[21][2] = cSize/2;
        vertices[22][0] = cSize/2; vertices[22][1] = -cSize/2; vertices[22][2] = cSize/2;
        vertices[23][0] = cSize/2; vertices[23][1] = -cSize/2; vertices[23][2] = -cSize/2;

    }
        
    void Cubo::createCubo(){ 
        glBegin(GL_QUADS);         
        glLoadIdentity();                 // Reset the model-view matrix
        //glTranslatef(posX, posY, posZ);    
        cout<<"Yposition = "<<y<<endl;
        system("pause");
        glColor3f(0.5f, 0.5f, 0.5f);     // grey
        glVertex3f( vertices[0][0] + x, vertices[0][1] + y, vertices[0][2] + z);
        glVertex3f( vertices[1][0] + x, vertices[1][1] + y, vertices[1][2] + z);
        glVertex3f( vertices[2][0] + x, vertices[2][1] + y, vertices[2][2] + z);
        glVertex3f( vertices[3][0] + x, vertices[3][1] + y, vertices[3][2] + z);
    
        // Bottom face (y = -1.0f)
        glColor3f(.5f, 0.5f, 0.5f);     // grey
        glVertex3f( vertices[4][0] + x, vertices[4][1] + y, vertices[4][2] + z);
        glVertex3f( vertices[5][0] + x, vertices[5][1] + y, vertices[5][2] + z);
        glVertex3f( vertices[6][0] + x, vertices[6][1] + y, vertices[6][2] + z);
        glVertex3f( vertices[7][0] + x, vertices[7][1] + y, vertices[7][2] + z);
    
        // Front face  (z = 1.0f)
        glColor3f(1.0f, 0.0f, 0.0f);     // Red
        glVertex3f( vertices[8][0] + x, vertices[9][1] + y, vertices[8][2] + z);
        glVertex3f( vertices[9][0] + x, vertices[9][1] + y, vertices[9][2] + z);
        glVertex3f( vertices[10][0] + x, vertices[10][1] + y, vertices[10][2] + z);
        glVertex3f( vertices[11][0] + x, vertices[11][1] + y, vertices[11][2] + z);
    
        // Back face (z = -1.0f)
        glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
        glVertex3f( vertices[12][0] + x, vertices[12][1] + y, vertices[12][2] + z);
        glVertex3f( vertices[13][0] + x, vertices[13][1] + y, vertices[13][2] + z);
        glVertex3f( vertices[14][0] + x, vertices[14][1] + y, vertices[14][2] + z);
        glVertex3f( vertices[15][0] + x, vertices[15][1] + y, vertices[15][2] + z);    
        // Left face (x = -1.0f)
        glColor3f(0.0f, 1.0f, 0.0f);     // Green
        glVertex3f( vertices[16][0] + x, vertices[16][1] + y, vertices[16][2] + z);
        glVertex3f( vertices[17][0] + x, vertices[17][1] + y, vertices[17][2] + z);
        glVertex3f( vertices[18][0] + x, vertices[18][1] + y, vertices[18][2] + z);
        glVertex3f( vertices[19][0] + x, vertices[19][1] + y, vertices[19][2] + z);    
        // Right face (x = 1.0f)
        glColor3f(1.0f, 1.0f, 1.0f);     // White
        glVertex3f( vertices[20][0] + x, vertices[20][1] + y, vertices[20][2] + z);
        glVertex3f( vertices[21][0] + x, vertices[21][1] + y, vertices[21][2] + z);
        glVertex3f( vertices[22][0] + x, vertices[22][1] + y, vertices[22][2] + z);
        glVertex3f( vertices[23][0] + x, vertices[23][1] + y, vertices[23][2] + z);    
        glEnd();  // End of drawing color-cube
    }

    void Cubo::rotateXaxis(){}

    void Cubo::rotateYaxis(){
           for(int i = 0; i < 24;i++){
            float auxx = vertices[i][0]; float auxz = vertices[i][2];
            float aux = auxx*cos(angleRot) + auxz*sin(angleRot);
            vertices[i][0] = aux;
            aux = -auxx*sin(angleRot) + auxz*cos(angleRot);
            vertices[i][2] = aux;
            //vertices[i][0] = cos(angleRot)*vertices[i][0] + sin(angleRot)*vertices[i][2];
            //vertices[i][2] = -sin(angleRot)*vertices[i][0] + cos(angleRot)*vertices[i][2];
            }
        createCubo();
    }

    void Cubo::rotateZaxis(){}


 _3D_Camera::_3D_Camera(float xEye, float yEye, float zEye, 
    float xCenter, float yCenter, float zCenter,
    float xUp, float yUp, float zUp){
    this->xEye = xEye; this->yEye = yEye; this->zEye = zEye;
    this->xUp = xUp; this->yUp = yUp; this->zUp = zUp;    
    this->xCenter = xCenter; this->yCenter = yCenter;
    this->zCenter = zCenter;
}

void _3D_Camera::createCam(){
    glLoadIdentity();
    gluLookAt( xEye, yEye, zEye, xCenter, yCenter, zCenter, xUp, yUp, zUp);
}

_3D_World_Base::_3D_World_Base(float xPos,float yPos, float zPos, 
    float xColor, float yColor, float zColor){
    this->xPos = xPos; this->yPos = yPos; this->zPos = zPos;
} 

void _3D_World_Base::createBasis(){ 
    glBegin(GL_LINES);
        glLoadIdentity(); //Deve estar dentro do glBegin;               
        glColor3f(1.0f, 0.0f, 0.0f);     // Red
        glVertex3f( 0.0f,  0.0f, 0.0f);
        glVertex3f( 2.0f,  0.0f, 0.0f);
        glColor3f(0.0f, 1.0f, 0.0f);     // Green
        glVertex3f( 0.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 2.0f, 0.0f);        
        glColor3f(0.0f, 0.0f, 1.0f);     // Blue
        glVertex3f(0.0f,  0.0f,  0.0f);
        glVertex3f(0.0f,  0.0f, 2.0f);
    glEnd();  // End of drawing color-cube
}

void Timer(int value){
    //directionalKeysHandeler(GLUT_KEY_LEFT,0,0);
    if(rotateAngle >= 6.283f)
        rotateAngle = 0;
        //rotateAngle += 0.209f;
    rotateAngle += 0.314f;
    
    glutPostRedisplay();
    glutTimerFunc(100,Timer, 1);
}

void camReposition(){
    if(actualPosition == 0){
        camUpx = 0.0f; camUpy = 1.0f; camUpz = 0.0f;//Reposicionando o vetor UP da câmera
        camPosx = positionCamMatrix[0][0]; 
        camPosy = positionCamMatrix[0][1];
        camPosz = positionCamMatrix[0][2];
    }else if(actualPosition == 1){
        camPosx = positionCamMatrix[1][0]; 
        camPosy = positionCamMatrix[1][1];
        camPosz = positionCamMatrix[1][2];
    }else if(actualPosition == 2){
        camPosx = positionCamMatrix[2][0]; 
        camPosy = positionCamMatrix[2][1];
        camPosz = positionCamMatrix[2][2];
    }else if(actualPosition == 3){
        camPosx = positionCamMatrix[3][0]; 
        camPosy = positionCamMatrix[3][1];
        camPosz = positionCamMatrix[3][2];
    }else if(actualPosition == 4){
        camPosx = positionCamMatrix[4][0]; 
        camPosy = positionCamMatrix[4][1];
        camPosz = positionCamMatrix[4][2];
    }
}

void directionalKeysHandeler(int key, int x, int y){
float fraction = 0.1f;
     switch (key) {
        case GLUT_KEY_LEFT :
            if(actualPosition == 4){
                actualPosition = 0;
                camReposition();
            }else{
                actualPosition++;
                camReposition();
            }
        break;

        case GLUT_KEY_RIGHT :
            if(actualPosition == 0){
                actualPosition = 4;
                camReposition();
            }else{
                actualPosition--;
                camReposition();
            }            
        break;

        case GLUT_KEY_UP :
            camPosx = 10.0f; camPosy = 26.0f; camPosz = 3.0f;
            camEyex = 10.0f; camEyey = 6.0f; camEyez = 3.0f;
            camUpx = 1.0f;  camUpy = 0.0f; camUpz = 0.0f;
        break;
        case GLUT_KEY_DOWN :
            camPosx = 10.0f; camPosy = -14.0f; camPosz = 3.0f;
            camEyex = 10.0f; camEyey = 6.0f; camEyez = 3.0f;
            camUpx = 1.0f;  camUpy = 0.0f; camUpz = 0.0f;
        break;
    }
}

void changeSize(int w, int h){
    if (h == 0)
    h = 1;
    float ratio = w * 1.0 / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Configura a tela viewport para todo o quadrado da tela
    glViewport(0, 0, w, h);
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);
}

void renderer(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);  
    //Criando os vetores da base
    _3D_World_Base worldBasis(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    worldBasis.createBasis();
    
    //Top Cube
    Cubo myCubo(8.0f,11.0f,1.0f,6.0f,rotateAngle); //10, 6, 3
    myCubo.rotateYaxis();
    cout<<"rotacao---------------------------"<<rotateAngle<<endl;

    //Middleup Cube
    Cubo myCubo2(8.0f,5.0f,1.0f,6.0f,-(rotateAngle)); //10, 6, 3
    myCubo2.rotateYaxis();
    cout<<"rotacao---------------------------"<<rotateAngle<<endl;
    //MiddleDownCube
    Cubo myCubo3(8.0f,-1.0f,1.0f,6.0f,rotateAngle*2); //10, 6, 3
    myCubo3.rotateYaxis();
    cout<<"rotacao---------------------------"<<rotateAngle<<endl;
    //BottomCube
    Cubo myCubo4(8.0f,-7.0f,1.0f,6.0f,(rotateAngle)/2); //10, 6, 3
    myCubo4.rotateYaxis();
    cout<<"rotacao---------------------------"<<rotateAngle<<endl;
    //Criando e posicionando a câmera
    _3D_Camera myCamera(camPosx, camPosy, camPosz, camEyex, camEyey, camEyez, camUpx, camUpy, camUpz);
    myCamera.createCam();
    glutSwapBuffers();
}
