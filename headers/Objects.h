#include <GL/glut.h>
#include <cmath>
#include <stdlib.h>
#include <string>
using namespace std;

/**
 * @brief Esta classe serve para instanciar os cubos utilizados no jogo.
 * 
 */
class Cubo{
    public:
    /**
     * @brief Constrói um novo cubo.
     * 
     * @param posX Posição x do centro de gravidade onde será colocado o cubo no espaço.
     * @param posY Posição y do centro de gravidade onde será colocado o cubo no espaço.
     * @param posZ Posição z do centro de gravidade onde será colocado o cubo no espaço.
     * @param cSize Tamanho do cubo
     * @param angleRot ângulo de rotação de um eixo do cubo(Deve ser utilizado com base no eixo Y)
     * @param col1 Parâmetro para a configuração da cor da primeira face do cubo
     * @param col2 Parâmetro para a configuração da cor da segunda face do cubo
     * @param col3 Parâmetro para a configuração da cor da terceira face do cubo
     * @param col4 Parâmetro para a configuração da cor da quarta face do cubo
     */
        Cubo(float posX, float posY, float posZ, float cSize,float angleRot,string col1,string col2, string col3, string col4);
        
        /**
         * @brief Cria um objeto do tipo cubo no espaço com a API OpenGL e biblioteca Glut.
         * 
         */
        void createCubo();
        
        /**
         * @brief Rotaciona o cubo em torno do eixo Y de acordo com o atributo angleRot.
         * 
         */
        void rotateYaxis();

    private:
        float vertices[24][3]; //Matriz com os vértices do cubo com base no referencial de mundo
        float cSize;
        float posX, posY, posZ;
        float x,y,z;
        float angleRot;
        string col1, col2, col3, col4;
};

/**
 * @brief Esta classe lida com a visualização dos objetos do mundo por meio da câmera.
 * 
 */
class _3D_Camera{
    public:
        /**
         * @brief Constrói um novo objeto do tipo Câmera 3D
         * 
         * @param xEye posição x do olho da câmera.
         * @param yEye posição y do olho da câmera.
         * @param zEye posição z do olho da câmera.
         * @param xCenter posição x do centro da câmera.
         * @param yCenter posição y do centro da câmera.
         * @param zCenter posição z do centro da câmera.
         * @param xUp posição x do vetor up da câmera.
         * @param yUp posição y do vetor up da câmera.
         * @param zUp posição z do vetor up da câmera.
         */
        _3D_Camera(float xEye, float yEye, float zEye, 
            float xCenter, float yCenter, float zCenter,
            float xUp, float yUp, float zUp);

        /**
         * @brief Cria um objeto do tipo câmera no espaço com a API OpenGL e biblioteca Glut e a posiciona
         * de acordo com os parâmetros passados no método construtor.
         * 
         * @param anglex Ângulo de rotação x, utilizado para reposicionamento por meio do mouse.
         * @param angle Ângulo de rotação auxiliar, utilizado para reposicionamento por meio do mouse.
         */
        void createCam(float anglex, float angle);

    private:
        float xEye, yEye ,zEye;
        float xCenter, yCenter, zCenter;
        float xUp, yUp, zUp;
};

/**
 * @brief Esta classe serve para implementar objetos que criam os vetores unitarios posicionados no ponto (0,0,0) do mundo.;
 * 
 */
class _3D_World_Base{
    public:
        /**
         * @brief Construtor dos objetos.
         * 
         * @param xPos Posição x da origem do sistema.
         * @param yPos Posição y da origem do sistema.
         * @param zPos Posição z da origem do sistema.
         * @param xColor Cor do vetor unitário que apontará para a direção x.
         * @param yColor Cor do vetor unitário que apontará para a direção y.
         * @param zColor Cor do vetor unitário que apontará para a direção z.
         */
        _3D_World_Base(float xPos,float yPos, float zPos, 
            float xColor, float yColor, float zColor);

        /**
         * @brief Cria três vetores ortonormais coloridos na origem do sistema,
         * de acordo com o especificado no método construtor e com a API OpenGL e biblioteca Glut e a posiciona
         * 
         */
        void createBasis();

    private:
    float xPos,yPos,zPos;
    float xColor,yColor,zColor;
};

