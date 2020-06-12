/* 
 * File:   Usuario.cpp
 * Author: pedro
 * Created on June 7, 2020, 11:23  
 */

#include "Usuario.h"
#include <string>

using std::string;

//constructor sin parametro
Usuario::Usuario(){
    arbolAvl = new TAVL<Activo*, string>();
}

//constructor con parametros
Usuario::Usuario(string nombre_, string password_):nombre(nombre_), password(password_){
    arbolAvl = new TAVL<Activo*, string>();
}

//setters
void Usuario::setNombre(string getNombre_){
    nombre = getNombre_;
}

void Usuario::setPassword(string password_){
    password = password_;
}

//getters
string Usuario::getNombre(){return nombre;}

string Usuario::getPassword(){return password;}

TAVL<Activo*, string>* Usuario::getArbolAvl(){return arbolAvl;}

Usuario::~Usuario()
{
}



