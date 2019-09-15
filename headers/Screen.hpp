#include"../headers/Objects.h"
#include"../headers/xmlParser.h"
#include<vector>
#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

#define POS 5
#ifndef __SCREEN_HPP__
#define __SCREEN_HPP__

/**
 * @brief Esta classe será o motor de todo o funcionamento do jogo, dentre suas principais funções
 * estão a leitura e escrita de arquivos XML, gerenciamento de eventos de mouse e teclado e exibição
 * gráfica do jogo por meio da API Opengl e biblioteca glut.
 * 
 */
class Screen{
    public:

        /**
         * @brief Constrói um motor screen para o jogo
         * 
         */
        Screen();

        /**
         * @brief Método para renderizar os objetos criados.
         * 
         */
        void renderer(void);

        /**
         * @brief Método para redimensionar a janela de exibição.
         * 
         * @param w Largura da tela.
         * @param h Altura da tela.
         */
        void changeSize(int w, int h);

        /**
         * @brief Este método serve para lidar com os eventos das teclas especiais do teclado 
         * 
         * @param key Botão pressionado pelo usuário.
         * @param x parâmetro auxiliar.
         * @param y parâmetro auxiliar.
         */
        void directionalKeysHandeler(int key, int x, int y);

        /**
         * @brief Este método serve para a temporização dos eventos do jogo.
         * 
         * @param value Tempo em milisegundos de atraso programado
         * @param func_ptr Ponteiro para função de callback.;
         */
        void Timer(int value, void (*func_ptr)(int));

        /**
         * @brief Este método lida com a posição angular da câmera durante o jogo por meio do mouse.
         * 
         * @param button Botão especificado.
         * @param state Estado do botão especificado(Pressionado ou em descanço).
         * @param x Posição x do cursor na tela.
         * @param y Posição y do cursor na tela
         */
        void mouseHandle(int button, int state, int x, int y);

        /**
         * @brief Este método lida com os evetos do teclado alfanumérico, utilizado para rotacionar os cubos e mover
         * a face preta no jogo
         * 
         * @param Key Tecla pressionada. 
         * @param x Variável auxiliar.
         * @param y Variável auxiliar.
         */
        void keyboardHandle(unsigned char Key, int x, int y);

        /**
         * @brief Este método carrega o estado inicial do jogo. Por padrão o estado inicial
         * é aquele salvo pelo jogador na partida anterior.
         * 
         */
        void loadInitialState();

        /**
         * @brief Carrega o estado atual do jogo, útil quando o jogador salva o estado regularmente e
         * deseja carregar o último estado salvo. Os dados são gravados em um arquio XML
         * 
         */
        void loadActualState();

        /**
         * @brief Este método carrega o jogo solucionado.
         * O jogo é carregado de um arquivo XML
         * 
         */
        void loadSolution();

        /**
         * @brief Este método serve para o usuário salvar o estado atual do seu jogo para continuar a
         * solução em outro momento. O estado é salvo em um arquivo XML.
         * 
         */
        void saveActualState();

        /* Implementar posteriormente
        void pushMovement();
        void popMovement();

        */
        /**
         * @brief Função utilizada para embaralhar o cubo. Aqui é utilizada como semente, para a função aleatória, o tempo do computado
         * 
         */
        void shuffleCube();
        
        /**
         * @brief Método utilizado para depuração onde é mostrada a matriz com as cores de cada face do cubo.
         * 
         */
        void showMatrice();

        //New Function
        /**
         * @brief Função de callback da API para lidar com o movimento. Este método é utilizado no reposicionamento.
         * da cầmera de acordo com o mouse.
         * 
         * @param X posição x do movimento. 
         * @param Y posição y do movimento.
         */
        void motion(int x, int y);
        //void solveGame();
        //void showSolution();
    
        float rotateAngle,rotateAngle2, rotateglobal;
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
        //New Function
        bool move,rotation,updown;
        int prevx,prevy;
        float anglemotion;
        float anglexmotion;

    private:
};

#endif