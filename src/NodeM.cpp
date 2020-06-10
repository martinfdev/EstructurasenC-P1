/* 
 * File:   NodeM.cpp
 * Author: pedro
 */
#include "NodeM.h"
#include <string>
using std::string;

NodeM::NodeM(string data)
{
    this->data = data;
    this->x, this->y = 0;
    this->down = this->up = this->left = this->right = this->front = this->behind = nullptr;
}

NodeM::NodeM(int x, int y, string data)
{
    this->data = data;
    this->x = x;
    this->y = y;
    this->down = this->up = this->left = this->right = this->front = this->behind = nullptr;
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

void NodeM::setFront(NodeM *front ){
    this->front = front;
}

void NodeM::setBehind(NodeM *behind){
    this->behind = behind;
}

string NodeM::getData()
{
    return this->data;
}

int NodeM::getX() { return x; }

int NodeM::getY() { return y; }

NodeM *NodeM::getRight() { return right; }

NodeM *NodeM::getLeft() { return left; }

NodeM *NodeM::getUp() { return up; }

NodeM *NodeM::getDown() { return down; }

NodeM *NodeM::getFront() { return front; }

NodeM *NodeM::getBehind() { return behind; }

NodeM::~NodeM() {}
