/* 
 * File:   TAVL.cpp
 * Author: pedro
 * Created on June 6, 2020, 15:33  
 */

#include "TAVL.h"
#include "string"

using std::string;

/*El template es de dos parametros T es para el tip de dato que se quiere
*guardar en el nodo y el parammetro G se usa como llave para doer guardar
*en equilibrio en el arbol AVL
*/
//constructor
template <typename T, typename G>
TAVL<T, G>::TAVL()
{
    raiz = 0;
}

//metodo para obtener la altura del arbol
template <typename T, typename G>
int TAVL<T, G>::altura(NodeAvl<T, G> *nodo)
{
    if (nodo)
        return nodo->getAltura();
    return 0;
}

//retorna cual es el maximo en una comparacion de G
template <typename T, typename G>
G TAVL<T, G>::getMax(G d1, G d2)
{
    return (d1 > d2) ? d1 : d2;
}

//retorna el valor mas alto de un dos enteros
template <typename T, typename G>
int TAVL<T, G>::getMaximo(int a, int b)
{
    return (a > b) ? a : b;
}

/*metodo para la rotacion simple a la derecha
*       c                              
*      /     Rotacion a la derecha       b
*     b      ---------------------->    / \
*    /                                 a   c
*   a                                       
*/
template <typename T, typename G>
NodeAvl<T, G> *TAVL<T, G>::rotarDerecha(NodeAvl<T, G> *nodoD)
{
    //guadamos los nodos temporalmente tanto como la inzquier como la derecha
    NodeAvl<T, G> *tmpIz = nodoD->getIzquierda();
    NodeAvl<T, G> *tmpDer = tmpIz->getDerecha(); //si existe un subarbol T

    //realizamos la rotacion
    tmpIz->setDerecha(nodoD);
    nodoD->setIzquierda(tmpDer);

    //actualizamos las alturas
    nodoD->setAltura(getMaximo(altura(nodoD->getIzquierda()), altura(nodoD->getDerecha())) + 1);
    tmpIz->setAltura(getMaximo(altura(tmpIz->getIzquierda()), altura(tmpIz->getDerecha())) + 1);

    //retornamos el nodo de equilibrio en este caso tmpInzquierda
    return tmpIz;
}

/*metodo para la rotacion simple a la izquierda
*                                     a
*    b     Rotacion a la izquierda     \
*   / \   <-----------------------      b
*  a   c                                 \
*                                         c
*/
template <typename T, typename G>
NodeAvl<T, G> *TAVL<T, G>::rotarIzquierda(NodeAvl<T, G> *nodoI)
{
    //guadamos los nodos temporalmente tanto como la inzquier como la derecha
    NodeAvl<T, G> *tmpDer = nodoI->getDerecha();
    NodeAvl<T, G> *tmpIz = tmpDer->getIzquierda(); // si existe un subarbol T

    //Realizamos las rotaciones
    tmpDer->setIzquierda(nodoI);
    nodoI->setDerecha(tmpIz);

    //actualizamos las alturas
    nodoI->setAltura(getMaximo(altura(nodoI->getIzquierda()), altura(nodoI->getDerecha())) + 1);
    tmpDer->setAltura(getMaximo(altura(tmpDer->getIzquierda()), altura(tmpDer->getDerecha())) + 1);

    //retornamos el nodo que esta equilibrado
    return tmpDer;
}

//metodo para verificar si el nodo esta equilibrado
template <typename T, typename G>
int TAVL<T, G>::getEquilibrio(NodeAvl<T, G> *nodo)
{
    if (nodo == 0)
        return 0;
    return altura(nodo->getIzquierda()) - altura(nodo->getDerecha);
}

//Función recursiva para insertar una clave en el
//árbol y devuelve la nueva raíz del árbol
template <typename T, typename G>
NodeAvl<T, G> *TAVL<T, G>::insertarInterno(NodeAvl<T, G> *nodo, T dato, G llave)
{
    //se inserta como en un arbol binario de busque normal
    if (nodo == 0)
        return (new NodeAvl<T, G>(T, G));

    if (llave < nodo->getLlave())
        nodo->setIzquierda(insertarInterno(nodo->getIzquierda(), dato, llave));
    else if (llave > nodo->getLlave())
        nodo->setDerecha(insertarInterno(nodo->getDerecha()), dato, llave);
    else //la clave esta repetida y no se permite
        return nodo;

    //actualizar la altura de este nodo
    nodo->setAltura(1 + getMaximo(altura(nodo->getIzquierda()), nodo->getDerecha()));

    /*Obtener el factor de equilibrio para verificar si el
    * nodo este nodo no esta desequilibrado
    */
    int balance = getEquilibrio(nodo);

    //verificar los cuatro casos de balance

    //rotacion simple a la derecha si el desequilibrio esta del lado izquierdo
    if (balance > 1 && llave < nodo->getIzquierda()->getLlave())
        return rotarDerecha(nodo);

    //rotacion simple a la izquierda si el desequilibrio esta del lado derecho
    if (balance < -1 && llave > nodo->getDerecha()->getLlave())
        return rotarIzquierda(nodo);

    //rotacion doble izquierda derecha
    if (balance > 1 && llave > nodo->getIzquierda()->getLlave())
    {
        nodo->setIzquierda(rotarIzquierda(nodo->getIzquierda()));
        return rotarDerecha(nodo);
    }

    //rotacion doble derecha izquierda
    if (balance < -1 && llave < nodo->getDerecha()->getLlave())
    {
        nodo->setDerecha(rotarDerecha(nodo->getDerecha()));
        return rotarIzquierda(nodo);
    }

    //retornar el nodo con los cabios de punteros hechos
    return nodo;
}

//metodo publico par insertar pide el dato y la llave pa insertar en el arbol
template <typename T, typename G>
void TAVL<T, G>::insertar(T dato, G llave){
    root = insertarInterno(raiz, dato, llave);
}


//destructor
template <typename T, typename G>
TAVL<T, G>::~TAVL() {}