/* 
 * File:   BAVL.cpp
 * Author: pedro
 * Created on June 6, 2020, 15:33  
 */

#include "BAVL.h"
#include "string"

using std::string;

/*El template es de dos parametros T es para el tip de dato que se quiere
*guardar en el nodo y el parammetro G se usa como llave para doer guardar
*en equilibrio en el arbol AVL
*/
//constructor 
template <typename T, typename G>
BAVL<T, G>::BAVL(){
    raiz = 0;
}

//metodo para obtener la altura del arbol
template <typename T, typename G>
int BAVL<T, G>::altura(NodeAvl<T, G>* nodo){
    if (nodo)
        return nodo->getAltura();
    return 0;    
}

//retorna cual es el maximo en una comparacion de G
template <typename T, typename G>
G BAVL<T, G>::getMax(G d1, G d2){
    return (d1 > d2)?d1 : d2;
}

/*metodo para la rotacion simple a la derecha
*       a                              
*      /     Rotacion a la derecha       b
*     b      ---------------------->    / \
*    /                                 a   c
*   c                                       
*/
template <typename T, typename G>
NodeAvl<T, G>* BAVL<T, G>::rotarDerecha(NodeAvl<T, G>* nodo){
    //guadamos los nodos temporalmente tanto como la inzquier como la derecha
    NodeAvl<T> *tmpIz = nodo->getIzquierda();
    NodeAvl<T> *tmpDer = tmpIz->getDerecha();

    //realizamos la rotacion
    tmpIz->setDerecha(nodo);
    nodo->setIzquierda(tmpDer);
    
}


/*metodo para la rotacion simple a la izquierda
*                                     a
*    b     Rotacion a la izquierda     \
*   / \   <-----------------------      b
*  a   c                                 \
*                                         c
*/




//destructor
template <typename T, typename G>
BAVL<T, G>::~BAVL(){}