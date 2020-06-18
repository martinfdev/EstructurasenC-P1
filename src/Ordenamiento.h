/* 
 * File:   Ordenamiento.h
 * Author: pedro
 *
 * Created on June 5, , 00:26 AM
*/
#ifndef ORDENAMIENTO_H
#define ORDENAMIENTO_H
#include "ListaDoble.h"
#include "Transaccion.h"
#include "Lista.h"
class Ordenamiento
{
private:
public:
    Ordenamiento(/* args */);
    void ordenarListaDobleA(ListaDoble<Transaccion *> *);
    void ordenarListaDobleDes(ListaDoble<Transaccion *>* );
    ~Ordenamiento();
};

#endif /*ORDENAMIENTO_H*/