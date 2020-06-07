/* 
 * File:   NodeAvl.cpp
 * Author: pedro
 * Created on June 6, 2020, 15:33  
 */

#include "NodeAvl.h"

//constructor sin parametro
template <typename T, typename G>
NodeAvl<T, G>::NodeAvl(){
    llave = 0;
    altura = 0;
    dato = 0;
    derecha = 0;
    izquierda = 0;
}

//sobrecarga de constructor
template <typename T, typename G>
NodeAvl<T, G>::NodeAvl(T dato_, G llave_):dato(dato_), llave(llave_){
    altura = 0;
    derecha = 0;
    izquierda = 0;
}

//setters
template <typename T, typename G>
void NodeAvl<T, G>::setIzquierda(NodeAvl<T, G>* inzquierda_){
    izquierda = inzquierda_;
}

template <typename T, typename G>
void NodeAvl<T, G>::setDerecha(NodeAvl<T, G>* derecha_){
    derecha = derecha_;
}

template <typename T, typename G>
void NodeAvl<T, G>::setDato(T dato_){
    dato = dato_;
}

template <typename T, typename G>
void NodeAvl<T, G>::setAltura(int altura_){
    altura = altura_;
} 

template <typename T, typename G>
void NodeAvl<T, G>::setLlave(G llave_){
    llave = llave_;
}

//getters
template <typename T, typename G>
T NodeAvl<T, G>::getDato(){return dato;}

template <typename T, typename G>
NodeAvl<T, G>* NodeAvl<T, G>::getIzquierda(){return izquierda;}

template <typename T, typename G>
NodeAvl<T, G>* NodeAvl<T, G>::getDerecha(){return derecha;}

template <typename T, typename G>
int NodeAvl<T, G>::getAltura(){return altura;}

template <typename T, typename G>
G NodeAvl<T, G>::getLlave(){return llave;}

//destructor
template <typename T, typename G>
NodeAvl<T, G>::~NodeAvl(){}
