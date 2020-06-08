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
    if (nodo == nullptr)
        return 0;
    return nodo->getAltura();
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
    return altura(nodo->getIzquierda()) - altura(nodo->getDerecha());
}

//Función recursiva para insertar una clave en el
//árbol y devuelve la nueva raíz del árbol
template <typename T, typename G>
NodeAvl<T, G> *TAVL<T, G>::insertarInterno(NodeAvl<T, G> *nodo, T dato, G llave)
{
    //se inserta como en un arbol binario de busque normal
    if (nodo == 0)
    {
        return (new NodeAvl<T, G>(dato, llave));
        std::cout << llave << "\n";
    }
    if (llave < nodo->getLlave())
        nodo->setIzquierda(insertarInterno(nodo->getIzquierda(), dato, llave));
    else if (llave > nodo->getLlave())
        nodo->setDerecha(insertarInterno(nodo->getDerecha(), dato, llave));
    else //la clave esta repetida y no se permite
        return nodo;

    //actualizar la altura de este nodo
    nodo->setAltura(1 + getMaximo(altura(nodo->getIzquierda()), altura(nodo->getDerecha())));
    //std::cout<<getMaximo(altura(nodo->getIzquierda()), altura(nodo->getDerecha())) <<std::endl;

    /*Obtener el factor de equilibrio para verificar si este
    * nodo no esta desequilibrado
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
void TAVL<T, G>::insertar(T dato, G llave)
{
    raiz = insertarInterno(raiz, dato, llave);
}

//recorrido en preorden
template <typename T, typename G>
void TAVL<T, G>::pre_orden(NodeAvl<T, G> *raiz)
{
    if (raiz != nullptr)
    {
        std::cout << raiz->getLlave() << "\t";
        pre_orden(raiz->getIzquierda());
        pre_orden(raiz->getDerecha());
    }
}

//metodo publico para el recorrido en preorden
template <typename T, typename G>
void TAVL<T, G>::preOrden()
{
    pre_orden(raiz);
    std::cout << std::endl;
}

//metodo que devuelve el valor minimo
template <typename T, typename G>
NodeAvl<T, G> *TAVL<T, G>::nodoValorMinimo(NodeAvl<T, G> *nodo)
{
    NodeAvl<T, G> *actual = nodo;
    while (actual->getIzquierda() != NULL)
        actual = actual->getIzquierda();
    return actual;
}

//metodo recursivo para la eliminacion en el arbol avl
template <typename T, typename G>
NodeAvl<T, G> *TAVL<T, G>::eliminarNodo(NodeAvl<T, G> *nodo, G llave)
{
    //eliminar como en el arbol binario d busqueda
    if (nodo == nullptr)
        return nodo;

    // Si la clave a eliminar es más pequeña
    // que la clave de la raíz, entonces se encuentra
    // en el subárbol izquierdo
    if (llave < nodo->getLlave())
        nodo->setIzquierda(eliminarNodo(nodo->getIzquierda(), llave));

    // Si la clave a eliminar es más grande
    // que la clave de la raíz, entonces se encuentra
    // en el subárbol derecho
    else if (llave > nodo->getLlave())
        nodo->setDerecha(eliminarNodo(nodo->getDerecha(), llave));

    // si la clave es la misma que la raíz, entonces
    // Este es el nodo que se eliminará
    else
    {
        //nodo con solo un hijo o sin hijo
        if (nodo->getIzquierda() == nullptr || nodo->getDerecha() == nullptr)
        {
            NodeAvl<T, G> *tmp = nodo->getIzquierda() ? nodo->getIzquierda() : nodo->getDerecha();

            //caso no tiene hijos
            if (tmp == nullptr)
            {
                tmp = nodo;
                nodo = NULL;
            }
            else              //en caso de que tiene un hijo
                *nodo = *tmp; //copiamos el contenido del hijo
            delete tmp;       //liberamos el espacio en momoria
        }
        else
        {
            // nodo con dos hijos: obtener el orden
            // sucesor (el más pequeño en el subárbol derecho) o sea el menor de los mayores
            NodeAvl<T, G> *tmp = nodoValorMinimo(nodo->getDerecha());

            //copiar el sucesor a este nodo
            nodo->setDato(tmp->getDato());
            nodo->setLlave(tmp->getLlave());

            //eliminar en inorden el sucesor
            nodo->setDerecha(eliminarNodo(nodo->getDerecha(), tmp->getLlave()));
        }
    }
    //cuando el nodo es igual a null
    if (nodo == nullptr)
        return nodo;

    //actualizar la altura de este nodo
    nodo->setAltura(1 + getMaximo(altura(nodo->getIzquierda()), altura(nodo->getDerecha())));
    //std::cout<<getMaximo(altura(nodo->getIzquierda()), altura(nodo->getDerecha())) <<std::endl;

    /*Obtener el factor de equilibrio para verificar si este
    * nodo no esta desequilibrado
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

//metodo publico para eliminar
template <class T, class G>
void TAVL<T, G>::eliminar(G llave)
{
    raiz = eliminarNodo(raiz, llave);
}

//metodo que devuelve el nodo raiz para reporte
template <typename T, typename G>
NodeAvl<T, G>* TAVL<T, G>::getRaiz(){return raiz;}

//destructor
template <typename T, typename G>
TAVL<T, G>::~TAVL() {}