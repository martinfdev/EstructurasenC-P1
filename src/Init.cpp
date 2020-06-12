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
#include "Menu.cpp"

using std::cout;
using std::string;

Init::Init()
{
  matriz = new MatrizDispersa();
  historialT = new ListaDoble<Transaccion *>();
  start(); // metodo que incializa todo
}

//metodo donde se inicia el programa
void Init::start()
{
  menu = new Menu(historialT, matriz);
  menu->menuIni();
}

//metodo para hacer pruebas de funcionalidad
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
  //incializamos un arbol avl pasando como parametro el timpo de datos a almacenar
  //y el otro tipo de dato como llave para el almacenamiento <Tipo de dato, LLave>TAVL
  /* TAVL<Activo *, int> *t = new TAVL<Activo *, int>();
  cout << "insertar 10, 8, 9, 15, 12, 2, 1, 20, 30\n\n";
  t->insertar(0, 10);
  t->insertar(0, 8);
  t->insertar(0, 9);
  cout << "Rotacion doble Izquierda-Derecha\n";
  cout << "Pre-Orden\n";
  t->preOrden();
  cout << "\n";
  t->insertar(0, 15);
  t->insertar(0, 12);
  cout << "Rotacion doble Derecha-Izquierda\n";
  cout << "Pre-Orden\n";
  t->preOrden();
  cout << "\n";
  t->insertar(0, 2);
  t->insertar(0, 1);
  cout << "Rotacion simple Derecha \n";
  cout << "Pre-Orden\n";
  t->preOrden();
  cout << "\n";
  t->insertar(0, 20);
  t->insertar(0, 30);
  cout << "Rotacion Simple Izquierda\n";
  cout << "Pre-Orden\n";
  t->preOrden();

  cout << "Actualizar el nodo 9 a 100\n";
  t->actualizar(t->buscar(9), 100);
  cout << "Pre-Orden\n";
  t->preOrden();

  cout << "Eliminar 15\n";
  t->eliminar(15);
  cout << "Pre-Orden\n";
  t->preOrden();

  cout << "Buscar 2\n";
  if (t->buscar(2))
    cout << "true\n";
  else
    cout << "false\n";

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
  /*
  MatrizDispersa *md = new MatrizDispersa();
  md->insertMatrix("Guatemala", "ZS", new Usuario("Pedro", "password"));
  md->insertMatrix("Huehue", "LARSA", new Usuario("Lucy", "password"));
  md->insertMatrix("Guatemala", "RSA", new Usuario("M", "password"));
  md->insertMatrix("Guatemala", "LHRSA", new Usuario("G", "password"));
  md->insertMatrix("Santa_Rosa", "ARSA", new Usuario("Z", "password"));
  md->insertMatrix("Huehue", "LARSA", new Usuario("HG", "password"));
  md->insertMatrix("Mazate", "LARSA", new Usuario("A", "password"));
  md->insertMatrix("Jalapa", "LARSA", new Usuario("B", "password"));
  md->insertMatrix("Huehue", "LARSA", new Usuario("C", "password"));
  md->insertMatrix("Huehue", "LARSA", new Usuario("D", "password"));
  md->insertMatrix("Nenton", "LARSA", new Usuario("D", "password"));
  md->insertMatrix("Guatemala", "LAR", new Usuario("GE", "password"));
  md->insertMatrix("Xela", "LSA", new Usuario("Gloria", "password"));
  md->insertMatrix("Guatemala", "RS", new Usuario("Eu", "password"));
   md->report();
  Usuario *us = md->searchM("Guatemala", "LR");
  if (us)
    cout << us->getNombre() << "\n";
    else
    cout<<"false\n";
    */
  /* md->insertMatrix("Guatemala", "Zoo", new Usuario("Pedro", "p"));
   md->insertMatrix("Xela", "Axe", new Usuario("Miguel","n"));
   md->insertMatrix("Huehue","LG", new Usuario("Kevin", "k"));
   md->insertMatrix("Xela", "LG", new Usuario("Juan", "j"));
   md->insertMatrix("Xela", "Zoo", new Usuario("H", "j"));
  // md->insertMatrix("Huehue", "Zoo", new Usuario("Ar", "j"));
  // md->insertMatrix("Guatemala", "Axe", new Usuario("Juan", "j"));
  // md->insertMatrix("Huehue", "Axe", new Usuario("Juan", "j"));
  // md->insertMatrix("Guatemala", "LG", new Usuario("Juan", "j"));

   md->report();
 */
}
Init::~Init() {}