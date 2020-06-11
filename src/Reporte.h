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
#include <string>

class Reporte
{
private:
    void reporteArbolAvl(NodeAvl<Activo*, int>*, Graphviz*);
public:
    Reporte();
    void ReporteListaDobleCircular(ListaDoble<std::string> *, std::string);
    void ReporteListaSimple(Lista<int>*);
    void reporteAVL(NodeAvl<Activo*, int>*);
    void reporteMtrizDispersa();
    ~Reporte();
};
#endif /*REPORTE_H*/