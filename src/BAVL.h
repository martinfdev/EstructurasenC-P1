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
    NodeAvl<T>* raiz;
    bool datoRepetido;
    int altura(NodeAvl<T>*);
    NodeAvl<T>* nuevoNodo(G);
    NodeAvl<T>* rotarDerecha(NodeAvl<T>*, G);
    NodeAvl<T>* rotarIzquierda(NodeAvl<T>*, G);
    int getEquilibrio(NodeAvl<T>*);
    NodeAvl<T>* insertarInterno(NodeAvl<T>*, G);
    void preOrden(NodeAvl<T>*);

public:
    BAVL();
    void insertar(T);
    NodeAvl<T>* getRaiz();
    ~BAVL();
};
#endif /*BAVL_H*/