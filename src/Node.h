/* 
 * File:   Node.h
 * Author: pedro
 *
 * Created on June 4, 2020, 11:11 AM
*/

//clase plantilla nodo tipo de dato no definido
#ifdef NODE_H
#define NODE_H

template <class T> 
class Node
{
private:
    T data;
    Node *next, *behind;   
public:
    Node();
    Node(T);
    void setNext(Node*);
    void setBehin(Node*);
    Node* getNext();
    Node* getBehind();
    T getData();
    ~Node();
};
#endif //NODE_H

