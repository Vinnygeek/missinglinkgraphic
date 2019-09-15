#include<iostream>
#include<vector>
#include"../headers/tinyxml2.h"

using namespace std;
using namespace tinyxml2;

#ifndef __XMLPARSER_H__
#define __XMLPARSER_H__

/**
 * @brief Esta classe lida com os attributos XML 
 * 
 */
class Attributes{
    public:
    /**
     * @brief Constrói objetos do tipo Attributes.
     * 
     * @param Attrname nome do atributo.
     * @param AttrValue valor do atributo.
     */
        Attributes(string Attrname, string AttrValue);

        /**
         * @brief Retorna o nome do atributo.
         * 
         * @return string nome do atributo do objeto.
         */
        string getAttrName();

        /**
         * @brief Retorna o valor do atributo.
         * 
         * @return string valor do atributo do objeto.
         */
        string getAttrValue();

        /**
         * @brief Configura um novo nome para o atributo.
         * 
         * @param newName Novo nome do atributo.
         */
        void setAttrName(string newName);

        /**
         * @brief Configura um novo nome para o valor do atributo.
         * 
         * @param newValue Novo valor do atributo.
         */
        void setAttrValue(string newValue);
    private:
        string AttrName;
        string AttrValue;
};
/**
 * @brief Esta classe serve para definir nós para serem adicionados em um arquivo xml.
 * 
 */
class Node{
    public:
        /**
         * @brief Constrói um novo nó.
         * 
         * @param nodeName Nome do nó a ser criado.
         */
        Node(string nodeName);

        /**
         * @brief Retorna o nome do nó.
         * 
         * @return string Nome do nó a ser retornado.
         */
        string getnodeName();

        /**
         * @brief Retorna o tamanho do vetor de atributos do nó.
         * 
         * @return int Tamanho do vetor de atributos.
         */
        int getAttr_vecsize();

        /**
         * @brief Retorna o nome do atributo contido no vetor de atributos.
         * 
         * @param elemId Índice a ser pesquisado no vetor.
         * @return string Nome do índice(atributo) pesquisado.
         */
        string getAttr_vecName(int elemId);

        /**
         * @brief Retorna o nome do valor contido no vetor de atributos.
         * 
         * @param elemId Índice a ser pesquisado no vetor.
         * @return string Nome do índice(valor) do atributo pesquisado.
         */
        string getAttr_vecValue(int elemId);

        /**
         * @brief Retorna o vetor de atributos do nó.
         * 
         * @return vector<Attributes> Vetor de atributos retornado.
         */
        vector<Attributes> getattr_vec();

        /**
         * @brief Configura o nome do nó.
         * 
         * @param newName Novo nome para o nó.
         */
        void setNodeName(string newName);

        /**
         * @brief Adiciona atributos ao vetor.
         * 
         * @param newAttr Objeto atributo a ser adicionado ao vetor de atributos.
         */
        void addAttr(Attributes newAttr);

        /**
         * @brief Este método remove um atributo do vetor.
         * 
         * @param toRemoveAttr Nome do atributo a ser removido do vetor de atributos do nó.
         */
        void removeAttr(string toRemoveAttr);
    private:
        string nodeName;
        vector<Attributes> attr_vec;
};

/**
 * @brief Esta classe serve de estrutura para a criação de subclasses que lidaram com leitura e escrita de arquivos
 * xml. 
 * 
 */
class XmlParser{
    public:
        string filename;
        string noRaiz;
        XMLDocument xmlDoc;
        XMLNode* myRoot;
        XMLError errorFlag;
        XMLElement* myElement;
};

/**
 * @brief Esta classe herda os atributos da classe XMLParser para a leitura de arquivos XML.
 * 
 */
class XmlReader: public XmlParser{
    public:
        /**
         * @brief Método Construtor, instancia objetos para a leitura de arquivos XML.
         * 
         * @param fileName nome do arquivo a ser aberto para leitura.
         * @param NoRaiz Nó raiz do arquivo.
         */
        XmlReader(string fileName,string NoRaiz);

        /**
         * @brief Getter para o nome do arquivo
         * 
         * @return string nome do arquivo xml de leitura.
         */
        string getFilename();

        /**
         * @brief Settter para a configuração de um novo nome para arquivos de leitura.
         * 
         * @param newFileName novo nome do arquivo de leitura.
         */
        void setFilename(string newFileName);

        /**
         * @brief Este método carrega um arquivo xml e retorna o status da operação
         * 
         * @return int Status da operação de acordo com os padrões da biblioteca 
         * tynyxml2(https://github.com/leethomason/tinyxml2)
         * 
         */
        int loadFile();

        /**
         * @brief Este método carrega um nó do arquivo xml.
         * 
         * @param nodeName Nome do nó a ser carregado.
         * @return int Status da operação.
         */
        int loadNode(string nodeName);

        /**
         * @brief Getter para o valor de um atributo do nó pesquisado no arquivo.
         * 
         * @param nodeName nome do nó.
         * @param nodeAttrName atributo.
         * @return string valor do atributo.
         */
        string getNodeValue(string nodeName, string nodeAttrName);
};

/**
 * @brief Esta classe herda os atributos da classe XmlParser, serve para escrever dados em arquivos XML.
 * 
 */
class XmlWriter: public XmlParser{
    public:
    /**
     * @brief Constroi um novo objeto do tipo XMLWriter.
     * 
     * @param fileName nome do arquivo; ex: "data/xmlfiles/actual_state.xml".
     * @param NoRaiz é o nó principal no arquivo XML.
     */
        XmlWriter(string fileName,string NoRaiz);

        /**
         * @brief Este método adiciona um novo nó ao arquivo XML.
         * 
         * @param newNode Novo nó para ser adicionado.
         */
        void addNode(Node newNode);

        /**
         * @brief Este método escreve os dados populados no arquivo xml descrito no método construtor.
         * 
         */
        void writeTotheFile();
    private:
        vector<Node> nodeList;
};

#endif