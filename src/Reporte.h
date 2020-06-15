/* 
 * File:   Reporte.h
 * Author: pedro
 *
 * Created on June 5, , 00:50 AM
*/
#ifndef REPORTE_H
#define REPORTE_H
#include "ListaDoble.h"
#include "Lista.h"
#include "Activo.h"
#include "Transaccion.h"
#include <string>

class Reporte
{
private:
    void reporteArbolAvl(NodeAvl<Activo*, string>*, Graphviz*);
    string getDisponible(bool);
public:
    Reporte();
    void ReporteListaDobleCircular(ListaDoble<Transaccion*> *, std::string);
    void ReporteListaSimple(Lista<int>*);
    void reporteAVL(NodeAvl<Activo*, string>*);
    void reporteMtrizDispersa();
    void inorden(NodeAvl<Activo*, string>*);
    void preorden(NodeAvl<Activo*, string>*);
    Lista<Activo*>* getListaActivos();
    ~Reporte();
};
#endif /*REPORTE_H*/