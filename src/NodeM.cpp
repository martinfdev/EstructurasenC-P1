
#include "NodeM.h"
#include <string>

using std::string;

NodeM::NodeM(Usuario *dato_) : dato(dato_)
{
    this->down = this->up = this->left = this->right = behind = front = nullptr;
}

NodeM::NodeM(string x_, string y_, Usuario *dato_) : dato(dato_), x(x_), y(y_)
{
    this->down = this->up = this->left = this->right = behind = front = nullptr;
}

void NodeM::setLeft(NodeM *left)
{
    this->left = left;
}

void NodeM::setRight(NodeM *right)
{
    this->right = right;
}

void NodeM::setUp(NodeM *up)
{
    this->up = up;
}

void NodeM::setDown(NodeM *down)
{
    this->down = down;
}

void NodeM::setFront(NodeM *front_)
{
    front = front_;
}

void NodeM::setBehind(NodeM *behind_)
{
    behind = behind_;
}

void NodeM::setData(Usuario *dato_)
{
    dato = dato_;
}

Usuario *NodeM::getData()
{
    return dato;
}

string NodeM::getX() { return x; }

string NodeM::getY() { return y; }

NodeM *NodeM::getRight() { return right; }

NodeM *NodeM::getLeft() { return left; }

NodeM *NodeM::getUp() { return up; }

NodeM *NodeM::getDown() { return down; }

NodeM *NodeM::getBehind() { return behind; }

NodeM *NodeM::getFront() { return front; }

NodeM::~NodeM() {}
