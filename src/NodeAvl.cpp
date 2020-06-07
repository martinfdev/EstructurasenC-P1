/* 
 * File:   NodeAvl.cpp
 * Author: pedro
 * Created on June 6, 2020, 15:33  
 */

#include "NodeAvl.h"

//constructor sin parametro
template <typename T>
NodeAvl<T>::NodeAvl(){}

//sobrecargad e constructor
template <typename T>
NodeAvl<T>::NodeAvl(T dato_):dato(dato_){}

//setters
template <typename T>
void NodeAvl<T>::setIzquierda(NodeAvl<T>* inzquierda_){
    izquierda = inzquierda_;
}

template <typename T>
void NodeAvl<T>::setDerecha(NodeAvl<T>* derecha_){
    derecha = derecha_
}

template <typename T>
void NodeAvl<T>::setDato(T dato_){
    dato = dato_;
}

//getters
template <typename T>
T NodeAvl<T>::getDato(){return dato;}

template <typename T>
NodeAvl<T>* NodeAvl<T>::getIzquierda(){return izquierda;}

template <typename T>
NodeAvl<T>* NodeAvl<T>::getDerecha(){return derecha;}

//destructor
template <typename T>
NodeAvl<T>::~NodeAvl(){}
