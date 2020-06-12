/* 
 * File:   Activo.h
 * Author: pedro 
 */
#ifndef ACTIVO_H
#define ACTIVO_H
#include <string>

class Activo
{
private:
    std::string id_activo, nombre, descripcion;
    bool disponible = true;

public:
    Activo(/* args */);
    Activo(std::string, std::string);
    void setNombre(std::string);
    void setDescripcion(std::string);
    void setDisponibilidad(bool);
    std::string getNombre();
    std::string getDescripcion();
    std::string getIdActivo();
    bool getDisponibilidad();
    ~Activo();
};
#endif /*ACTIVO_H*/
