#include<iostream>
#include<vector>
#include"../headers/tinyxml2.h"

using namespace std;
using namespace tinyxml2;

#ifndef __XMLPARSER_H__
#define __XMLPARSER_H__

class Attributes{
    public:
        Attributes(string Attrname, string AttrValue);
        string getAttrName();
        string getAttrValue();
        void setAttrName(string newName);
        void setAttrValue(string newValue);
    private:
        string AttrName;
        string AttrValue;
};

class Node{
    public:
        Node(string nodeName);
        string getnodeName();
        int getAttr_vecsize();
        string getAttr_vecName(int elemId);
        string getAttr_vecValue(int elemId);
        vector<Attributes> getattr_vec();
        void setNodeName(string newName);
        void addAttr(Attributes newAttr);
        void removeAttr(string toRemoveAttr);
    private:
        string nodeName;
        vector<Attributes> attr_vec;
};

class XmlParser{
    public:
        string filename;
        string noRaiz;
        XMLDocument xmlDoc;
        XMLNode* myRoot;
        XMLError errorFlag;
        XMLElement* myElement;
};

class XmlReader: public XmlParser{
    public:
        XmlReader(string fileName,string NoRaiz);
        string getFilename();
        void setFilename(string newFileName);
        int loadFile();
        int loadNode(string nodeName);
        string getNodeValue(string nodeName, string nodeAttrName);
};

class XmlWriter: public XmlParser{
    public:
        XmlWriter(string fileName,string NoRaiz);
        void addNode(Node newNode);
        void writeTotheFile();
    private:
        vector<Node> nodeList;
};

#endif