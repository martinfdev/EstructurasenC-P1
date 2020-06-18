/* 
 * File:   Menu.h
 * Author: pedro
 * Created on June 11, 2020, 10:27 AM
 */

#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <string.h>
#include "ListaDoble.h"
#include "Transaccion.h"
#include "MatrizDispersa.h"
#include "Lista.h"
#include "TAVL.h"

using std::string;

class Menu
{
private:
    ListaDoble<Transaccion *> *historialT;
    Lista<Usuario*>* catalogo;
    MatrizDispersa *matriz;
    void login();
    void menuAdmin();
    void menuUsuario(Usuario *, string, string);
    void crearUsuario();
    void crearActivo(TAVL<Activo *, string> *, string);
    void eliminarActivo(TAVL<Activo *, string> *);
    void modificarActivo(TAVL<Activo*, string>*);
    void modificandoActivo(Activo*);
    void catalogoActivo();
    void rentaActivo(Usuario*, string, string);
    void rentandoActivo(Usuario*, string, string);
    void activosRentados(Usuario*, string, string);
    void devolverActivo(Usuario*);
    void misActivosRentados(Usuario*);
    void rActivosUsuario();
    void repRentaUsuario();
    void ordenar();
public:
    Menu(ListaDoble<Transaccion *> *, MatrizDispersa *, Lista<Usuario*> *);
    void menuIni(); //menu de inicio de sesion
    ~Menu();
};

#endif //MENU_H
