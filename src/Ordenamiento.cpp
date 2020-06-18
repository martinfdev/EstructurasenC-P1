/* 
 * File:   Ordenamiento.cpp
 * Author: pedro
 *
 * Created on June 5, , 00:26 AM
*/
#include "Ordenamiento.h"

//constructor
Ordenamiento::Ordenamiento()
{
}

//metodo que ricebe una lista y lo oredan de menor a mayor
void Ordenamiento::ordenarListaDobleA(ListaDoble<Transaccion *> *lista)
{
    Lista<Transaccion *> *tmplis = new Lista<Transaccion *>();
    for (int i = 0; i < lista->getSize(); i++)
    {
        Transaccion *tratmp = lista->getDataC();
        tmplis->add_endS(tratmp);
    }
    lista->emptyList();
    Transaccion *temp_data;
    Node<Transaccion *> *aux_node = tmplis->getHeadNode();
    Node<Transaccion *> *temp = aux_node;

    while (aux_node)
    {
        temp = aux_node;
        while (temp->getNext())
        {
            temp = temp->getNext();

            if (aux_node->getData()->getIdT() > temp->getData()->getIdT())
            {
                temp_data = aux_node->getData();
                aux_node->setData(temp->getData());
                //aux_node->data = temp->data;
                temp->setData(temp_data);
                //temp->data = temp_data;
            }
        }
        aux_node = aux_node->getNext();
    }
    for (int i = 0; i < tmplis->size(); i++)
    {
        Transaccion *temporal = tmplis->getData();
        lista->insertarUltimoC(temporal);
    }
    delete tmplis;
}

//metodo que recibe una lista lista circular doblemente enlazada y la ordena menor a mayor
void Ordenamiento::ordenarListaDobleDes(ListaDoble<Transaccion *> *lista)
{
    ListaDoble<Transaccion *> temp = *lista;
    lista->emptyList();
    Node<Transaccion *> *tempNode = temp.getPrimero()->getBehind();
    Node<Transaccion *> *out = tempNode;
    do
    {
        Transaccion *dt = tempNode->getData();
        lista->insertarUltimoC(dt);
        tempNode = tempNode->getBehind();
    } while (tempNode != out);
}
//destructor
Ordenamiento::~Ordenamiento()
{
}
