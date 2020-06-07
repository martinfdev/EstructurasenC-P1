/* 
 * File:   TAVL.h
 * Author: pedro
 * Created on June 6, 2020, 15:33  
 */
#ifndef TAVL_H
#define TAVL_H
#include <string>
#include "NodeAvl.h"

template<class T, class G>
class TAVL
{
private:
    NodeAvl<T, G>* raiz;
    bool datoRepetido;
    int altura(NodeAvl<T, G>*);
    G getMax(G, G);
    int getMaximo(int, int);//metodo para comparar dos enterosy devolver el maximo
    NodeAvl<T, G>* rotarDerecha(NodeAvl<T, G>*);
    NodeAvl<T, G>* rotarIzquierda(NodeAvl<T, G>*);
    int getEquilibrio(NodeAvl<T, G>*);
    NodeAvl<T, G>* insertarInterno(NodeAvl<T, G>*, T, G);
    void preOrden(NodeAvl<T, G>*);

public:
    TAVL();
    void insertar(T, G);
    NodeAvl<T, G>* getRaiz();
    ~TAVL();
};
#endif /*TAVL_H*/