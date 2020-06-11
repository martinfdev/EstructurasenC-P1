/* 
 * File:   Init.cpp
 * Author: pedro
 * Created on June 4, 2020, 11:11 AM
 */
#include <iostream>
#include <stdlib.h>
#include "Init.h"
#include "Node.cpp"
#include "NodeAvl.cpp"
#include "NodeM.cpp"
#include "ListaDoble.cpp"
#include "TAVL.cpp"
#include "Lista.cpp"
#include "Activo.cpp"
#include "Graphviz.cpp"
#include "Reporte.cpp"
#include "Usuario.cpp"
#include "MatrizDispersa.cpp"
#include "MD5.cpp"

using std::string;

Init::Init()
{
}

//metodo para hcer pruebas de funcionalidad
void Init::test()
{
  /* 
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
    ld->insertarUltimoC("9");
    ld->insertarUltimoC("10");
    ld->insertarUltimoC("11");
    ld->insertarUltimoC("12");
    ld->insertarUltimoC("13");
    //ld->reportStringC("listaCircular");
    Reporte *rep = new Reporte();
    rep->ReporteListaDobleCircular(ld, "listaDoblecircular");
    */

  /*Activo *ac = new Activo("Silla", "silla secretaria");
    cout << "Id Activo\t" << ac->getIdActivo() << endl;
    cout << "Id Nombre\t" << ac->getNombre() << endl;
    cout << "Id Descripcion\t" << ac->getDescripcion() << endl;
    */

  /*
   NodeAvl<string, string> *nodo =  new NodeAvl<string, string>("datos", "llave");
   cout<<nodo->getDato()<<endl;
   cout<<nodo->getLlave()<<endl;
   */
  /*
  TAVL<Activo*, string> *t = new TAVL<Activo*, string>();
  t->insertar(0, "A");
  t->insertar(0, "B");
  t->insertar(0, "C");
  t->insertar(0, "D");
  t->insertar(0, "E");
  t->insertar(0, "F");
  t->insertar(0, "G");
  t->insertar(0, "H");
  t->insertar(0, "Z");
  t->preOrden();
  t->eliminar("D");
  t->preOrden();
  Reporte *rep = new Reporte();
  rep->reporteAVL(t->getRaiz());
  */

  /*
  string a, b;
  a = "Antonio";
  b = "Pedro";

  if (a > b)
    std::cout << a << std::endl;
  else
   std::cout << b <<std::endl; 
  */
  MatrizDispersa *md = new MatrizDispersa();
  md->insertMatrix("Guatemala","AS", new Usuario("Pedro", "password"));
  md->insertMatrix("Guatemala","LARSA", new Usuario("M", "password"));
  md->insertMatrix("Guatemala","RSA", new Usuario("G", "password"));
  md->insertMatrix("Huehue","LARSA", new Usuario("Z", "password"));
  md->insertMatrix("Huehue","LARSA", new Usuario("HG", "password"));
  md->insertMatrix("Huehue","LARSA", new Usuario("A", "password"));
  md->insertMatrix("Huehue","LARSA", new Usuario("B", "password"));
  md->insertMatrix("Huehue","LARSA", new Usuario("C", "password"));
  md->insertMatrix("Huehue","LARSA", new Usuario("D", "password"));
  md->insertMatrix("Huehue","LARSA", new Usuario("D", "password"));
 /* md->insertMatrix("Guatemala","LARSA", new Usuario("GE", "password"));
  md->insertMatrix("Guatemala","LARSA", new Usuario("Gloria", "password"));
  md->insertMatrix("Guatemala","LARSA", new Usuario("Lucy", "password"));
  md->insertMatrix("Guatemala","LARSA", new Usuario("Eu", "password"));
 */
  md->report();
}
Init::~Init() {}