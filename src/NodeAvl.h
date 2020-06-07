/* 
 * File:   NodeAvl.h
 * Author: pedro
 * Created on June 6, 2020, 15:33  
 */
#ifndef NODEAVL_H
#define NODEAVL_H

template  <class T, class G>
class NodeAvl
{
private:
    T dato;
    G llave;
    NodeAvl<T, G>* izquierda;
    NodeAvl<T, G>* derecha;
    int altura;
public:
    NodeAvl();
    NodeAvl(T, G);
    void setIzquierda(NodeAvl<T, G>*);
    void setDerecha(NodeAvl<T, G>*);
    void setDato(T);
    void setAltura(int);
    void setLlave(G);
    NodeAvl<T, G>* getIzquierda();
    NodeAvl<T, G>* getDerecha();
    T getDato();
    G getLlave();
    int getAltura();
    ~NodeAvl();
};
#endif /*NODEAVL_H*/
