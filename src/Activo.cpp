

#include "Activo.h"
#include "MD5.cpp"
#include <string>

//constructor
Activo::Activo()
{
}

//constructor con parametros
Activo::Activo(std::string nombre_, std::string descripcion_):nombre(nombre_), descripcion(descripcion_), id_activo(md15(nombre_)){}

//setters--------------------------------------------------------------------------------------------------
void Activo::setNombre(std::string nombre_){
    nombre = nombre;
    id_activo = md15(nombre_);
}

void Activo::setDescripcion(std::string descripcion_){
    descripcion = descripcion_;
}

//getters -------------------------------------------------------------------------------------------------
std::string Activo::getIdActivo(){return id_activo;}

std::string Activo::getNombre(){return nombre;}

std::string Activo::getDescripcion(){return descripcion;}

//destructor
Activo::~Activo()
{}
