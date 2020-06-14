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
#include "TAVL.h"

using std::string;

class Menu
{
private:
    ListaDoble<Transaccion *> *historialT;
    MatrizDispersa *matriz;
    void login();
    void menuAdmin();
    void menuUsuario(Usuario *);
    void crearUsuario();
    void crearActivo(TAVL<Activo *, string> *);
    void eliminarActivo(TAVL<Activo *, string> *);
    void modificarActivo(TAVL<Activo*, string>*);
    void modificandoActivo(Activo*);

public:
    Menu(ListaDoble<Transaccion *> *, MatrizDispersa *);
    void menuIni(); //menu de inicio de sesion
    ~Menu();
};

#endif //MENU_H
