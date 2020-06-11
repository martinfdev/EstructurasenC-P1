
#ifndef NODEM_H
#define NODEM_H
#include "Usuario.h"
#include <string>

using std::string;
class NodeM
{
private:
    NodeM *left;
    NodeM *right;
    NodeM *up;
    NodeM *down;
    NodeM *behind;
    NodeM *front;
    Usuario *dato;
    string x, y;

public:
    NodeM(Usuario*);
    NodeM(string, string, Usuario*);
    void setLeft(NodeM*);
    void setRight(NodeM *);
    void setUp(NodeM *);
    void setDown(NodeM *);
    void setFront(NodeM *);
    void setBehind(NodeM *);
    void setData(Usuario*);
    NodeM *getLeft();
    NodeM *getRight();
    NodeM *getUp();
    NodeM *getDown();
    NodeM *getFront();
    NodeM *getBehind();
    Usuario* getData();
    string getX();
    string getY();
    ~NodeM();
};
#endif //NODEM_H
