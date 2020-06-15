

#include "Activo.h"
#include "MD5.h"
#include <string>

//constructor
Activo::Activo()
{
}

//constructor con parametros
Activo::Activo(std::string nombre_, std::string descripcion_, std::string duenio_):nombre(nombre_), descripcion(descripcion_), id_activo(md15(nombre_)), duenio(duenio_){
    tiempo = 0;
}

//setters--------------------------------------------------------------------------------------------------
void Activo::setNombre(std::string nombre_) {
    nombre = nombre_;
    id_activo = md15(nombre_);
}

void Activo::setDescripcion(std::string descripcion_){
    descripcion = descripcion_;
}

void Activo::setDisponibilidad(bool disponible__){
    disponible = disponible__;
}

void Activo::setDuenio(string duenio_){
    duenio= duenio_;
}

void Activo::setTiempo(int tiempo_){
    tiempo = tiempo_;
}

//getters -------------------------------------------------------------------------------------------------
std::string Activo::getIdActivo(){return id_activo;}

std::string Activo::getNombre(){return nombre;}

std::string Activo::getDescripcion(){return descripcion;}

bool Activo::getDisponibilidad(){return disponible;}

std::string Activo::getDuenio(){return duenio;}

int Activo::getTiempo(){return tiempo;}

//destructor
Activo::~Activo()
{}

