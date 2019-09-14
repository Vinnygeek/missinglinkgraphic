#include"../headers/Engine.h"
#include"../headers/Objetos.h"
#include<iostream>
    using namespace std;
Engine::Engine(int argc, char **argv){
    this->argc = argc;
    this->argv = argv;
    setInitialConfig();
}

void Engine::setInitialConfig(){
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
        glutInitWindowPosition(100,100);
        glutInitWindowSize(500,500);
        glutCreateWindow("Missing Link Graphic");
}

void Engine::play(){

}

void Engine::loadState(){

}

void Engine::saveState(){

}

void Engine::render(void){
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

void Engine::ChangeSize(GLsizei w, GLsizei h){
    if (h == 0)
    h = 1;
    float ratio = w * 1.0 / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Configura a tela viewport para todo o quadrado da tela
    glViewport(0, 0, w, h);
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);
}


void Engine::KeyboardHandle(unsigned char key, int x, int y){

}

void Engine::MouseHandle(int button, int state, int x, int y){

}

void Engine::SpecialKeyHandle(int key, int x, int y){

}

void Engine::timer(int value){
    //directionalKeysHandeler(GLUT_KEY_LEFT,0,0);
    if(rotateAngle >= 6.283f)
        rotateAngle = 0;
        //rotateAngle += 0.209f;
    rotateAngle += 0.314f;
    
    glutPostRedisplay();
    glutTimerFunc(100,Timer, 1);
}

void Engine::directionalKeysHandeler(int key, int x, int y){
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

void Engine::camReposition(){
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