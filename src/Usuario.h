/* 
 * File:   Usuario.h
 * Author: pedro
 * Created on June 7, 2020, 11:23  
 */

#ifndef USUARIO_H
#define USUARIO_H
#include "TAVL.h"
#include "Activo.h"
#include <string>

using std::string;

class Usuario
{
private:
    TAVL<Activo*, string> *arbolAvl;
    string nombre, password;
public:
    Usuario(/* args */);
    Usuario(string, string);
    void setNombre(string);
    void setPassword(string);
    string getNombre();
    string getPassword();
    TAVL<Activo*, string>* getArbolAvl();
    ~Usuario();
};
#endif /*USUARIO_H*/