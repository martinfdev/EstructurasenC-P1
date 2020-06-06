/* 
 * File:   Init.cpp
 * Author: pedro
 * Created on June 4, 2020, 11:11 AM
 */
#include <iostream>
#include <stdlib.h>
#include "Init.h"
#include "Node.cpp"
#include "ListaDoble.cpp"
#include "Lista.cpp"
#include "Activo.cpp"
#include "Graphviz.cpp"

using namespace std;

Init::Init()
{
    //prueba lista circular doble y grafico
    ListaDoble<std::string> *ld = new ListaDoble<std::string>();
    ld->insertarUltimoC("1");
    ld->insertarUltimoC("2");
    ld->insertarUltimoC("3");
    ld->insertarUltimoC("4");
    ld->insertarUltimoC("5");
    ld->insertarUltimoC("6");
    ld->insertarUltimoC("7");
    ld->insertarUltimoC("8");
    ld->reportStringC("listaCircular");


    
    /*Activo *ac = new Activo("Silla", "silla secretaria");
    cout << "Id Activo\t" << ac->getIdActivo() << endl;
    cout << "Id Nombre\t" << ac->getNombre() << endl;
    cout << "Id Descripcion\t" << ac->getDescripcion() << endl;
    */


}

//metodo para hcer pruebas de funcionalidad
void Init::test()
{
}

Init::~Init() {}