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
    
public:
    Reporte();
    void ReporteListaDobleCircular(ListaDoble<std::string> *, std::string);
    void ReporteListaSimple(Lista<int>*);
    ~Reporte();
};
#endif /*REPORTE_H*/