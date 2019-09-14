#include "../headers/xmlParser.h"

Attributes::Attributes(string Attrname, string AttrValue){
    this->AttrName = Attrname; this->AttrValue = AttrValue;
}

string Attributes::getAttrName(){
    return AttrName;
}

string Attributes::getAttrValue(){
    return AttrValue;
}

void Attributes::setAttrName(string newName){
    this->AttrName = newName;
}

void Attributes::setAttrValue(string newValue){
    this->AttrValue = newValue;
}

Node::Node(string nodeName){
    this->nodeName = nodeName;
}

string Node::getnodeName(){
    return nodeName;
}

int Node::getAttr_vecsize(){
    return attr_vec.size();
}

string Node::getAttr_vecName(int elemId){
    if(elemId >= 0 && elemId < attr_vec.size())
        return attr_vec[elemId].getAttrName();
    else
        return "ERROR";
}

string Node::getAttr_vecValue(int elemId){
    if(elemId >= 0 && elemId < attr_vec.size())
        return attr_vec[elemId].getAttrValue();
    else
        return "ERROR";
}

vector<Attributes> Node::getattr_vec(){
    return attr_vec;
}

void Node::setNodeName(string newName){
    this->nodeName = newName;
}

void Node::addAttr(Attributes newAttr){
    attr_vec.push_back(newAttr);
}

XmlReader::XmlReader(string fileName,string NoRaiz){
    this->filename = fileName;
    this->noRaiz = NoRaiz;

}


string XmlReader::getFilename(){
    return filename;
}

void XmlReader::setFilename(string newFileName){
    this->filename = newFileName;
}

int XmlReader::loadFile(){
    errorFlag = xmlDoc.LoadFile(filename.c_str());
    if(errorFlag != XML_SUCCESS){
         cout<<"Error loading File the file";
         return XML_SUCCESS;
    }
    myRoot = xmlDoc.FirstChild();
    if (myRoot == nullptr) {
        cout<<"Error loading root Node"<<endl;
        return XML_ERROR_FILE_READ_ERROR;
    }
    return 0;
}

int XmlReader::loadNode(string nodeName){
    myElement = myRoot->FirstChildElement(nodeName.c_str());
    if (myElement == nullptr){
        cout<<XML_ERROR_PARSING_ELEMENT<<" Error"<<endl;
        return XML_ERROR_PARSING_ELEMENT; 
    }
}

string XmlReader::getNodeValue(string nodeName, string nodeAttrName){
    loadNode(nodeName);
    const char * szAttributeText = nullptr;
    szAttributeText = myElement->Attribute(nodeAttrName.c_str());
    if (szAttributeText == nullptr) 
        return "Error";
    return szAttributeText;
}

XmlWriter::XmlWriter(string fileName,string NoRaiz){
    this->filename = fileName;
    this->noRaiz = NoRaiz;
    myRoot = xmlDoc.NewElement(noRaiz.c_str());
    xmlDoc.InsertFirstChild(myRoot);
}

 
void XmlWriter::addNode(Node newNode){
    nodeList.push_back(newNode);
}

void XmlWriter::writeTotheFile(){
    int itemCount = 0;
    for(int i = 0; i < nodeList.size(); i++){
        myElement = xmlDoc.NewElement(nodeList[i].getnodeName().c_str());
        for(int j = 0; j < nodeList[i].getAttr_vecsize();j++){
                    myElement->SetAttribute(nodeList[i].getAttr_vecName(j).c_str(), nodeList[i].getAttr_vecValue(j).c_str());
                    
        }
        myRoot->InsertEndChild(myElement);
    itemCount++;
    }
    int sizeOfVec = nodeList.size(); //Armazena a qtd de nós
    myElement = xmlDoc.NewElement("info"); //Atualiza um novo elemento
    myElement->SetAttribute("qtd", sizeOfVec); //configura um novo atributo ao arquivo
    myRoot->InsertEndChild(myElement); //Insere o atributo criado no fim do arquivo

    errorFlag = xmlDoc.SaveFile(filename.c_str());
    if(errorFlag != XML_SUCCESS)
        cout<<"Error handling writing to file";
}
