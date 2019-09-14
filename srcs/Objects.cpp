#include<iostream>
using namespace std;
#include"../headers/Objects.h"

    Cubo::Cubo(float posX, float posY, float posZ, float cSize, float angleRot, string col1,string col2, string col3, string col4){
        this->posX = posX; this->posY = posY; this->posZ = posZ; this->cSize = cSize; this->angleRot = angleRot;
        x = posX; y = posY; z = posZ;
        this->col1 = col1; this->col2 = col2; this->col3 = col3; this->col4 = col4;
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
	    glEnable(GL_BLEND);
	    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glColor4f(0.0f, 0.0f, 1.0f,0.1f);     // Blue
        glVertex3f( vertices[0][0] + x, vertices[0][1] + y, vertices[0][2] + z);
        glVertex3f( vertices[1][0] + x, vertices[1][1] + y, vertices[1][2] + z);
        glVertex3f( vertices[2][0] + x, vertices[2][1] + y, vertices[2][2] + z);
        glVertex3f( vertices[3][0] + x, vertices[3][1] + y, vertices[3][2] + z);
    
        // Bottom face (y = -1.0f)
        glColor4f(.0f, 0.5f, 0.0f,0.7f);     // Orange
        glVertex3f( vertices[4][0] + x, vertices[4][1] + y, vertices[4][2] + z);
        glVertex3f( vertices[5][0] + x, vertices[5][1] + y, vertices[5][2] + z);
        glVertex3f( vertices[6][0] + x, vertices[6][1] + y, vertices[6][2] + z);
        glVertex3f( vertices[7][0] + x, vertices[7][1] + y, vertices[7][2] + z);
    
        // Front face  (z = 1.0f)
        if(col1 == "vm"){
            glColor4f(1.0f, 0.0f, 0.0f,0.5f);
        }else if(col1 == "vd"){
            glColor4f(0.0f, 3.0f, 0.0f,0.1f);
        }else if(col1== "am"){
            glColor4f(1.0f, 1.0f, 0.0f,0.3f);    
        }else if(col1=="br"){
            glColor4f(1.0f, 1.0f, 1.0f,0.1f);
        }else if(col1 == "pr"){
            glColor4f(0.0f, 0.0f, 0.0f,0.1f);
        } 
        glVertex3f( vertices[8][0] + x, vertices[9][1] + y, vertices[8][2] + z);
        glVertex3f( vertices[9][0] + x, vertices[9][1] + y, vertices[9][2] + z);
        glVertex3f( vertices[10][0] + x, vertices[10][1] + y, vertices[10][2] + z);
        glVertex3f( vertices[11][0] + x, vertices[11][1] + y, vertices[11][2] + z);
    
        // Back face (z = -1.0f)
        if(col3 == "vm"){
            glColor4f(1.0f, 0.0f, 0.0f,0.5f);
        }else if(col3 == "vd"){
            glColor4f(0.0f, 3.0f, 0.0f,0.1f);
        }else if(col3== "am"){
            glColor4f(1.0f, 1.0f, 0.0f,0.3f);    
        }else if(col3=="br"){
            glColor4f(1.0f, 1.0f, 1.0f,0.1f);
        }else if(col3 == "pr"){
            glColor4f(0.0f, 0.0f, 0.0f,0.1f);
        } 
        glVertex3f( vertices[12][0] + x, vertices[12][1] + y, vertices[12][2] + z);
        glVertex3f( vertices[13][0] + x, vertices[13][1] + y, vertices[13][2] + z);
        glVertex3f( vertices[14][0] + x, vertices[14][1] + y, vertices[14][2] + z);
        glVertex3f( vertices[15][0] + x, vertices[15][1] + y, vertices[15][2] + z);    
        // Left face (x = -1.0f)

        if(col2 == "vm"){
            glColor4f(1.0f, 0.0f, 0.0f,0.5f);
        }else if(col2 == "vd"){
            glColor4f(0.0f, 3.0f, 0.0f,0.1f);
        }else if(col2== "am"){
            glColor4f(1.0f, 1.0f, 0.0f,0.3f);    
        }else if(col2=="br"){
            glColor4f(1.0f, 1.0f, 1.0f,0.1f);
        }else if(col2 == "pr"){
            glColor4f(0.0f, 0.0f, 0.0f,0.1f);
        } 
        glVertex3f( vertices[16][0] + x, vertices[16][1] + y, vertices[16][2] + z);
        glVertex3f( vertices[17][0] + x, vertices[17][1] + y, vertices[17][2] + z);
        glVertex3f( vertices[18][0] + x, vertices[18][1] + y, vertices[18][2] + z);
        glVertex3f( vertices[19][0] + x, vertices[19][1] + y, vertices[19][2] + z);    
        // Right face (x = 1.0f)
        
        if(col4 == "vm"){
            glColor4f(1.0f, 0.0f, 0.0f,0.5f);
        }else if(col4 == "vd"){
            glColor4f(0.0f, 3.0f, 0.0f,0.1f);
        }else if(col4== "am"){
            glColor4f(1.0f, 1.0f, 0.0f,0.3f);    
        }else if(col4=="br"){
            glColor4f(1.0f, 1.0f, 1.0f,0.1f);
        }else if(col4 == "pr"){
            glColor4f(0.0f, 0.0f, 0.0f,0.1f);
        } 
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

void _3D_Camera::createCam(float anglex, float angle){
    glLoadIdentity();
    gluLookAt( xEye, yEye, zEye, xCenter, yCenter, zCenter, xUp, yUp, zUp);
    glRotatef(anglex*50,1,0,0);
    glRotatef(angle*50,0,1,0);
    //glScalef(3,3,3);    
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