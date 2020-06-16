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
    void printCatalgo(NodeAvl<Activo*, string> *);
public:
    Reporte();
    void ReporteListaDobleCircular(ListaDoble<Transaccion*> *, std::string);
    void ReporteListaSimple(Lista<int>*);
    void reporteAVL(NodeAvl<Activo*, string>*);
    void reporteMtrizDispersa();
    void inorden(NodeAvl<Activo*, string>*);
    void preorden(NodeAvl<Activo*, string>*);
    void printCatalogoActivos(Lista<Usuario*>*);
    Activo* getActivoRenta(Lista<Usuario*>*, string);
    void printMisActivosRentados(NodeAvl<Activo*, string>*);
    ~Reporte();
};
#endif /*REPORTE_H*/