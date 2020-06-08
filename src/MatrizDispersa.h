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
    void show(NodeM*);
    void insertNode(NodeM*, NodeM*, NodeM*);
    NodeM* lastNodeColumn(NodeM*);
    NodeM* lastNodeRow(NodeM*);
    NodeM* NodeColumnMed(NodeM*, string);
    NodeM* NodeRowMed(NodeM*, string);
    string sameX();
    bool posxyBusy(NodeM*, string, string);
    Graphviz* graph;
public:
    MatrizDispersa();
    void insertMatrix(string, string, string);
    bool isEmpty();
    int getSizeX();
    int getSizeY();  
    void showY();
    void showX();
    void showMatrix();
    void report();
    NodeM *search(int);
    ~MatrizDispersa();
};
#endif
