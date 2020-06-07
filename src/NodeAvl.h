/* 
 * File:   NodeAvl.h
 * Author: pedro
 * Created on June 6, 2020, 15:33  
 */
#ifndef NODEAVL_H
#define NODEAVL_H

template  <class T>
class NodeAvl
{
private:
    T dato;
    NodeAvl<T>* izquierda;
    NodeAvl<T>* derecha;
    int altura;
public:
    NodeAvl();
    NodeAvl(T);
    void setIzquierda(NodeAvl<T>*);
    void setDerecha(NodeAvl<T>*);
    void setDato(T);
    NodeAvl<T>* getIzquierda();
    NodeAvl<T>* getDerecha();
    T getDato();
    ~NodeAvl();
};
#endif /*NODEAVL_H*/
