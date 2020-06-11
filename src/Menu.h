/* 
 * File:   Menu.h
 * Author: pedro
 * Created on June 11, 2020, 10:27 AM
 */

#ifndef MENU_H
#define MENU_H
#include <string>
#include "ListaDoble.h"
#include "Transaccion.h"
#include "MatrizDispersa.h"

using std::string;

class Menu
{
private:
    ListaDoble<Transaccion*> *historialT;
    MatrizDispersa *matriz;

public:
    
    Menu(ListaDoble<Transaccion*>*, MatrizDispersa*);
    void menuAdmin();
    void menuUsuario();
    ~Menu();
};



#endif //MENU_H
