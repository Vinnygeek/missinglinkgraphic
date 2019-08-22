#include"../headers/xmlParser.h"
#include"../headers/Objetos.h"

void testingXmlWriter(){
    Node primeiro("row1");
    Attributes attributo1("col1","green");
    Attributes attributo2("col2","red");
    Attributes attributo3("col3","blue");
    Attributes attributo4("col4","black");
    primeiro.addAttr(attributo1); primeiro.addAttr(attributo2);
    primeiro.addAttr(attributo3); primeiro.addAttr(attributo4);

    Node segundo("row2");
    Attributes attributo5("col1","mag");
    Attributes attributo6("col2","purp");
    Attributes attributo7("col3","ice");
    Attributes attributo8("col4","ric");
    segundo.addAttr(attributo5); segundo.addAttr(attributo6);
    segundo.addAttr(attributo7); segundo.addAttr(attributo8);

    Node terceiro("row3");
    Attributes attributo9("col1","kil");
    Attributes attributo10("col2","bgf");
    Attributes attributo11("col3","wer");
    Attributes attributo12("col4","qwe");
    terceiro.addAttr(attributo9); terceiro.addAttr(attributo10);
    terceiro.addAttr(attributo11); terceiro.addAttr(attributo12);

    XmlWriter myWriter("data/xmlfiles/estadoatual.xml","estado_atual");
    myWriter.addNode(primeiro);
    myWriter.addNode(segundo);
    myWriter.addNode(terceiro);
    myWriter.writeTotheFile();

}

void testingXmlReader(){
    XmlReader myReader("data/xmlfiles/estadosolucao.xml","estado_solucao");
    myReader.loadFile();
    myReader.loadNode("row1");
    string nodeValue = myReader.getNodeValue("row1","col1");
    string qtdNodes = myReader.getNodeValue("info","qtd");
}

using namespace std;

    int main(int argc, char **argv){
        testingXmlWriter();
        testingXmlReader();
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
        glutInitWindowPosition(100,100);
        glutInitWindowSize(500,500);
        glutCreateWindow("Exercicio1a - Computacao Grafica");

        glutDisplayFunc(renderer);
        glutReshapeFunc(changeSize);
        glutIdleFunc(renderer);
        glutSpecialFunc(directionalKeysHandeler);
        glutTimerFunc(1, Timer, 1);
        glEnable(GL_DEPTH_TEST);
        glutMainLoop();
        return 0;
    }
