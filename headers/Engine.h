#include <GL/glut.h>

class Engine{
    public:
        Engine(int argc, char **argv);
        void setInitialConfig();
        void play();
        void loadState();
        void saveState();
        void render(void);
        void ChangeSize(GLsizei w, GLsizei h);
        void KeyboardHandle(unsigned char key, int x, int y);
        void MouseHandle(int button, int state, int x, int y);
        void SpecialKeyHandle(int key, int x, int y);
        void timer(int value);
        void directionalKeysHandeler(int key, int x, int y);
        void camReposition();

        float rotateAngle = 0;
        int actualPosition = 0;
        int timerFuncTest = 0;
        float positionCamMatrix[5][3] = {20.0f, 20.0f, 20.0f, 10.0f, 6.0f, 23.0f,
            -10.0f, 6.0f, 3.0f, 10.0f, 6.0f, -17.0f, 30.0f, 6.0f, 3.0f};
        float camPosx = 20.0f; float camPosy = 20.0f; float camPosz = 20.0f; //20 20 20
        float camEyex = 10.0f; float camEyey = 6.0f; float camEyez = 3.0f; // 10 6 3
        float camUpx = 0.0f; float camUpy = 1.0f; float camUpz = 0.0f; 
        private: 

        int argc;
        char **argv;
};