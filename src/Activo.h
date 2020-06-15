/* 
 * File:   Activo.h
 * Author: pedro 
 */
#ifndef ACTIVO_H
#define ACTIVO_H
#include <string>
using std::string;

class Activo
{
private:
    int tiempo;
    std::string id_activo, nombre, descripcion, duenio;
    bool disponible = true;

public:
    Activo(/* args */);
    Activo(string, string, string);
    void setNombre(string);
    void setDescripcion(string);
    void setDisponibilidad(bool);
    void setDuenio(string);
    void setTiempo(int);
    string getNombre();
    string getDescripcion();
    string getIdActivo();
    string getDuenio();
    int getTiempo();
    bool getDisponibilidad();
    ~Activo();
};
#endif /*ACTIVO_H*/
