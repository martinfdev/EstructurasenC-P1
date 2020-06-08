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
    void pre_orden(NodeAvl<T, G>*);
    NodeAvl<T, G>* nodoValorMinimo(NodeAvl<T, G>*);
    NodeAvl<T, G>* eliminarNodo(NodeAvl<T, G>*, G);

public:
    TAVL();
    void insertar(T, G);
    NodeAvl<T, G>* getRaiz();
    void preOrden();
    void eliminar(G);
    ~TAVL();
};
#endif /*TAVL_H*/