#include"../headers/Objects.h"
#include"../headers/xmlParser.h"
#include<vector>
#include<iostream>
using namespace std;

#define POS 5
#ifndef __SCREEN_HPP__
#define __SCREEN_HPP__

class Screen{
    public:
        Screen();
        void renderer(void);
        void changeSize(int w, int h);
        void directionalKeysHandeler(int key, int x, int y);
        void Timer(int value, void (*func_ptr)(int));
        void mouseHandle(int button, int state, int x, int y);
        void keyboardHandle(unsigned char Key, int x, int y);
        void camReposition();

        void loadActualState();

        void saveActualState();
        void pushMovement();
        void popMovement();
        void shuffleCube();
        
        void showMatrice();

        //New Function
        void motion(int x, int y);
        //void loadState();
        //void saveState();
        //void shuffle();
        //void solveGame();
        //void showSolution();
        //void undo();
    
        float rotateAngle,rotateAngle2, rotateglobal;
        int actualPosition;
        int timerFuncTest;
        int count;
        float positionCamMatrix[5][3] = {20.0f, 20.0f, 20.0f, 10.0f, 6.0f, 23.0f,
            -10.0f, 6.0f, 3.0f, 10.0f, 6.0f, -17.0f, 30.0f, 6.0f, 3.0f};
        float camPosx, camPosy, camPosz; //20 20 20
        float camEyex, camEyey, camEyez; // 10 6 3
        float camUpx, camUpy, camUpz; 
        bool clock;
        bool halt;
        char currentKey;
        int pulseKeys[6] = {0,0,0,0,0,0};
        vector<vector<string>> myCubeMatrix;
        vector<vector<string>> myCubeMatrixBuffer;
        int actualCol;

        //New Function
        bool move,rotation,updown;
        int prevx,prevy;
        float anglemotion;
        float anglexmotion;

    private:
};

#endif