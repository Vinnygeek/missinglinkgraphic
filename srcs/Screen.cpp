#include <GL/glut.h>
#include "../headers/Screen.hpp"
#include<iostream>

using namespace std;

Screen::Screen(){
        rotateAngle = 0; rotateAngle2 = 0; rotateglobal = 0;
        actualPosition = 0;
        timerFuncTest = 0;
        camPosx = 20.0f; camPosy = 20.0f; camPosz = 20.0f; 
        camEyex = 10.0f; camEyey = 6.0f; camEyez = 3.0f; 
        camUpx = 0.0f; camUpy = 1.0f; camUpz = 0.0f; 
        clock = true; halt = false;
        currentKey = '0';
        count = 0;
        loadActualState();

        //motion function
        rotation = false;
        move = false;
        updown = false;
        prevx = 0;
        prevy = 0;
        anglemotion = 0;
        anglexmotion = 0;
}

void Screen::keyboardHandle(unsigned char Key, int x, int y){
     switch(Key){
        case 'e': //rotate top right - clockwise
            if(halt == false){
                halt = true;
                currentKey = 'e';
            }
        break;

        case 'q': // rotate top left - anticlockwise  
            if(halt == false){
                halt = true;
                currentKey = 'q';
            }
        break;

        case 'd': //rotate bottom right - clockwise
                if(halt == false){
                halt = true;
                currentKey = 'd';
            }
        break;

        case 'a': // rotate botom left - anticlockwise
                if(halt == false){
                halt = true;
                currentKey = 'a';
            }
        break;
        
        case 'w': //Moving the black face up
             if(halt == false){
                halt = true;
                currentKey = 'w';
             }
        break;
        
        case 's': //Moving the black face down
            if(halt == false){
                halt = true;
                currentKey = 's';
             }       
        break;
    }
}

void Screen::directionalKeysHandeler(int key, int x, int y){
     float fraction = 0.1f;
     switch (key) {
        case GLUT_KEY_LEFT :
            rotateglobal += 0.209f;
        break;

        case GLUT_KEY_RIGHT :
            rotateglobal -= 0.209f;           
        break;

        case GLUT_KEY_F1 :
            //Shuffle the cube
            shuffleCube();
        break;

        case GLUT_KEY_F2 :
           //Load the actual config
           loadActualState();
        break;

        case GLUT_KEY_F3 :
          //Load the solution config
          loadSolution();
        break;

        case GLUT_KEY_F4 :
          //Save actual config
          saveActualState();
        break;

    }
}

void Screen::changeSize(int w, int h){
    if (h == 0)
    h = 1;
    float ratio = w * 1.0 / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Change viewport
    glViewport(0, 0, w, h);
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);
}
//Alterar o renderer de forma a carregar as configurações do arquivo xml lido
//Também deve-se prever no renderer o menu
void Screen::renderer(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);  
    //Creating the 3D unit vectors
    _3D_World_Base worldBasis(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
    worldBasis.createBasis();
    
    //Top Cube
    Cubo myCubo(8.0f,11.0f,1.0f,6.0f,rotateAngle + rotateglobal,myCubeMatrix[0][0],myCubeMatrix[0][1],
    myCubeMatrix[0][2],myCubeMatrix[0][3]); //10, 6, 3
    myCubo.rotateYaxis();

    //Middleup Cube
    Cubo myCubo2(8.0f,5.0f,1.0f,6.0f,rotateglobal,myCubeMatrix[1][0],myCubeMatrix[1][1],
    myCubeMatrix[1][2],myCubeMatrix[1][3]); //10, 6, 3
    myCubo2.rotateYaxis();

    //MiddleDownCube
    Cubo myCubo3(8.0f,-1.0f,1.0f,6.0f,rotateglobal,myCubeMatrix[2][0],myCubeMatrix[2][1],
    myCubeMatrix[2][2],myCubeMatrix[2][3]); //10, 6, 3
    myCubo3.rotateYaxis();

    //BottomCube
    Cubo myCubo4(8.0f,-7.0f,1.0f,6.0f,rotateAngle2 + rotateglobal,myCubeMatrix[3][0],myCubeMatrix[3][1],
    myCubeMatrix[3][2],myCubeMatrix[3][3]); //10, 6, 3
    myCubo4.rotateYaxis();
    //----------------------------------------------------------------------------------------

    //Criando e posicionando a câmera
    _3D_Camera myCamera(camPosx, camPosy, camPosz, camEyex, camEyey, camEyez, camUpx, camUpy, camUpz);
    myCamera.createCam(anglexmotion,anglemotion);
    glutSwapBuffers();
}


void Screen::Timer(int value, void (*func_ptr)(int)){
    //directionalKeysHandeler(GLUT_KEY_LEFT,0,0);

    if(currentKey == 'e'){
        //to delete too
        string aux1,aux2,aux3,aux4;
        if(pulseKeys[0] == 3){
            pulseKeys[0] = 0;
            halt = false;
            currentKey = '0';

            //Begin delete
            //return the rotate angle to zero
            rotateAngle = 0;
            aux1 = myCubeMatrix[0][1]; aux2 = myCubeMatrix[0][2]; aux3 = myCubeMatrix[0][3]; aux4 = myCubeMatrix[0][0];
			myCubeMatrix[0][0] = aux1; myCubeMatrix[0][1] = aux2; myCubeMatrix[0][2] = aux3; myCubeMatrix[0][3] = aux4;
            //End Delete
        }else{
            rotateAngle += 0.5235987f;
            pulseKeys[0] = pulseKeys[0] + 1;
            //if(rotateAngle >= 6.283f)
            //    rotateAngle = 0;
        }    
        showMatrice();
    }
    else if(currentKey == 'q'){
        string aux1,aux2,aux3,aux4;
        if(pulseKeys[1] == 3){
            pulseKeys[1] = 0;
            halt = false;
            currentKey = '0';
            rotateAngle = 0;
            aux1 = myCubeMatrix[0][3]; aux2 = myCubeMatrix[0][0]; aux3 = myCubeMatrix[0][1]; aux4 = myCubeMatrix[0][2];
			myCubeMatrix[0][0] = aux1; myCubeMatrix[0][1] = aux2; myCubeMatrix[0][2] = aux3; myCubeMatrix[0][3] = aux4;
        
        }else{
            rotateAngle -= 0.5235987f;
            pulseKeys[1] = pulseKeys[1] + 1;
            //if(rotateAngle <= -6.283f)
            //    rotateAngle = 0;
        }
        showMatrice();
    }
    else if(currentKey == 'd'){
        string aux1,aux2,aux3,aux4;
        if(pulseKeys[2] == 3){
            pulseKeys[2] = 0;
            halt = false;
            currentKey = '0';
            rotateAngle2 = 0;
            aux1 = myCubeMatrix[3][1]; aux2 = myCubeMatrix[3][2]; aux3 = myCubeMatrix[3][3]; aux4 = myCubeMatrix[3][0];
			myCubeMatrix[3][0] = aux1; myCubeMatrix[3][1] = aux2; myCubeMatrix[3][2] = aux3; myCubeMatrix[3][3] = aux4;

        }else{
            rotateAngle2 += 0.5235987f;
            pulseKeys[2] = pulseKeys[2] + 1;
            //if(rotateAngle >= 6.283f)
            //    rotateAngle = 0;
        }    
        showMatrice();
    }
    else if(currentKey == 'a'){
        string aux1,aux2,aux3,aux4;
        if(pulseKeys[3] == 3){
            pulseKeys[3] = 0;
            halt = false;
            currentKey = '0';
            rotateAngle2 = 0;
            aux1 = myCubeMatrix[3][3]; aux2 = myCubeMatrix[3][0]; aux3 = myCubeMatrix[3][1]; aux4 = myCubeMatrix[3][2];
			myCubeMatrix[3][0] = aux1; myCubeMatrix[3][1] = aux2; myCubeMatrix[3][2] = aux3; myCubeMatrix[3][3] = aux4;

        }else{
            rotateAngle2 -= 0.5235987f;
            pulseKeys[3] = pulseKeys[3] + 1;
            //if(rotateAngle <= -6.283f)
            //    rotateAngle = 0;
        }
        showMatrice();
    }    
    else if(currentKey == 'w'){
            for(int i = 0; i < 4;++i){
				for(int j = 0; j < 4; j++)
					if(myCubeMatrix[i][j]=="pr"){
						string aux;
						if(i > 0){
							aux = myCubeMatrix[i-1][j];
							myCubeMatrix[i-1][j] = "pr";
							myCubeMatrix[i][j] = aux;
						}
					}
			}
        halt = false;
        currentKey = '0';
        showMatrice();
    }
    else if(currentKey == 's'){
        bool chave = true;
            for(int i = 0; i < 4 && chave;++i){
				for(int j = 0; j < 4 && chave; j++)
					if(myCubeMatrix[i][j]=="pr"){
						string aux;
						if(i < 3){
							aux = myCubeMatrix[i+1][j];
							myCubeMatrix[i+1][j] = "pr";
							myCubeMatrix[i][j] = aux;
							chave = false;
						}
					}
			}
        halt = false;
        currentKey = '0';
        showMatrice();
    }
    glutPostRedisplay();
    glutTimerFunc(100,func_ptr, 1);
}

void Screen::mouseHandle(int button, int state, int x, int y){
         rotation = (button - GLUT_LEFT_BUTTON) || (state-GLUT_DOWN);
         rotation = !rotation;
         if(rotation) prevx = x;
         
         updown = (button - GLUT_MIDDLE_BUTTON) ||(state - GLUT_DOWN);
         updown = !updown;
         if(updown) prevy = y;

         move = (button - GLUT_RIGHT_BUTTON)||(state - GLUT_DOWN);
         move = !move;
         if(move) prevy = y;

    glutPostRedisplay();
}

void Screen::camReposition(){
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


void Screen::loadActualState(){
    XmlReader myReader("data/xmlfiles/estadoatual.xml","estado_solucao");
    myReader.loadFile();
    myReader.loadNode("row1");

    vector<string> myfirstCube;
	myfirstCube.push_back(myReader.getNodeValue("row1","col1"));
	myfirstCube.push_back(myReader.getNodeValue("row1","col2"));
	myfirstCube.push_back(myReader.getNodeValue("row1","col3"));
	myfirstCube.push_back(myReader.getNodeValue("row1","col4"));

    vector<string> mysecCube;
	mysecCube.push_back(myReader.getNodeValue("row2","col1"));
	mysecCube.push_back(myReader.getNodeValue("row2","col2"));
	mysecCube.push_back(myReader.getNodeValue("row2","col3"));
	mysecCube.push_back(myReader.getNodeValue("row2","col4"));

	vector<string> mythirdCube;
	mythirdCube.push_back(myReader.getNodeValue("row3","col1"));
	mythirdCube.push_back(myReader.getNodeValue("row3","col2"));
	mythirdCube.push_back(myReader.getNodeValue("row3","col3"));
	mythirdCube.push_back(myReader.getNodeValue("row3","col4"));

    vector<string> myfourthCube;
	myfourthCube.push_back(myReader.getNodeValue("row4","col1"));
	myfourthCube.push_back(myReader.getNodeValue("row4","col2"));
	myfourthCube.push_back(myReader.getNodeValue("row4","col3"));
	myfourthCube.push_back(myReader.getNodeValue("row4","col4"));

    myCubeMatrix.push_back(myfirstCube);
	myCubeMatrix.push_back(mysecCube);
	myCubeMatrix.push_back(mythirdCube);
	myCubeMatrix.push_back(myfourthCube);

    //string qtdNodes = myReader.getNodeValue("info","qtd");
    for(int i = 0; i < 4;++i){
        for(int j = 0; j < 4; j++)
            if(myCubeMatrix[i][j] == "vms" || myCubeMatrix[i][j] == "vmm1" || myCubeMatrix[i][j] == "vmm2" || myCubeMatrix[i][j] == "vmi")
                myCubeMatrix[i][j] = "vm";
            else if(myCubeMatrix[i][j] == "ams" || myCubeMatrix[i][j] == "amm1" || myCubeMatrix[i][j] == "amm2" || myCubeMatrix[i][j] == "ami")    
                myCubeMatrix[i][j] = "am";
            else if(myCubeMatrix[i][j] == "vds" || myCubeMatrix[i][j] == "vdm1" || myCubeMatrix[i][j] == "vdm2" || myCubeMatrix[i][j] == "vdi")
                myCubeMatrix[i][j] = "vd";
            else if(myCubeMatrix[i][j] == "brs" || myCubeMatrix[i][j] == "brm1" || myCubeMatrix[i][j] == "bri")
                myCubeMatrix[i][j] = "br";
            else if(myCubeMatrix[i][j] == "vzo")
                myCubeMatrix[i][j] = "pr";
    
    //For Debbugging;
    showMatrice();
    }
}

void Screen::pushMovement(){

}

void Screen::popMovement(){

}

void Screen::shuffleCube(){
    srand(time(NULL));
    for(int i = 0; i < 200; i++){
        string aux;
        int a = rand()%4;
        int b = rand()%4;
        int c = rand()%4;
        int d = rand()%4;
        aux = myCubeMatrix[a][b];
        myCubeMatrix[a][b] = myCubeMatrix[c][d];
        myCubeMatrix[c][d] = aux;

    }

}

void Screen::showMatrice(){
    for(int i = 0; i < 4;++i){
        for(int j = 0; j < 4; j++)
            cout<<myCubeMatrix[i][j]<<" ";
            cout<<endl;
    
    }
}

void Screen::motion(int x, int y){
    if(rotation) anglemotion += 0.015*(x-prevx);

    if(updown) anglexmotion += 0.015*(y-prevy);

    if(move) camPosz += 0.1*(prevy-y);
    prevy = y;
    prevx = x;

}

void Screen::saveActualState(){

}

void Screen::loadSolution(){
    
}

