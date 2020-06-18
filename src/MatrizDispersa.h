/* 
 * File:   MatrizDispersa.h
 * Author: pedro
 */
#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H
#include "NodeM.h"
#include "Graphviz.h"

using std::string;

class MatrizDispersa
{
private:
    NodeM *root;
    int sizeX, sizeY;
    NodeM* search_Row_Column(NodeM *, string);
    void insertSortRow(NodeM*, string);
    void insertSortColumn(NodeM*, string);
    NodeM* getXY(NodeM*, string);
    bool insertNode(NodeM*, NodeM*, NodeM*);
    NodeM* lastNodeColumn(NodeM*);
    NodeM* lastNodeRow(NodeM*);
    NodeM* NodeColumnMed(NodeM*, string);
    NodeM* NodeRowMed(NodeM*, string);
    string sameX();
    bool posxyBusy(NodeM*, string, string);
    Graphviz* graph;
    NodeM *recorridoProfundidad(NodeM*);
    NodeM *searchMatrix(string, string);
public:
    MatrizDispersa();
    bool insertMatrix(string, string, Usuario*);
    bool isEmpty();
    int getSizeX();
    int getSizeY();  
    NodeM* getY(string);
    NodeM* getX(string);
    void showMatrix();
    void report();
    Usuario* searchM(string, string, string);
    void setData(string, string, Usuario*);
    Usuario* getAdmin();
    ~MatrizDispersa();
};
#endif
