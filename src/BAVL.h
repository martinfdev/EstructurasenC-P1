/* 
 * File:   BAVL.h
 * Author: pedro
 * Created on June 6, 2020, 15:33  
 */
#ifndef BAVL_H
#define BAVL_H
#include <string>
#include "NodeAvl.h"

template<class T, class G>
class BAVL
{
private:
    NodeAvl<T, G>* raiz;
    bool datoRepetido;
    int altura(NodeAvl<T, G>*);
    G getMax(G, G);
    NodeAvl<T, G>* rotarDerecha(NodeAvl<T, G>*);
    NodeAvl<T, G>* rotarIzquierda(NodeAvl<T, G>*);
    int getEquilibrio(NodeAvl<T, G>*);
    NodeAvl<T, G>* insertarInterno(NodeAvl<T, G>*, G);
    void preOrden(NodeAvl<T, G>*);

public:
    BAVL();
    void insertar(T);
    NodeAvl<T, G>* getRaiz();
    ~BAVL();
};
#endif /*BAVL_H*/