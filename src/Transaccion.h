/* 
 * File:   Transaccion.h
 * Author: pedro
 */

#ifndef TRANSACCION_H
#define TRANSACCION_H
#include <iostream>
#include <string>

class Transaccion
{
private:
    int tiempo_renta;//el tiempo de renta es en dias
    string id_T, id_activo; 
    string nombre_usuario, departamento, empresa, fecha_renta;   
public:
    Transaccion();//sin parametros
    Transaccion(string, string, string, string, string, string, int);
    string getIdT();
    string getIdActivo();
    string getNombreUsuario();
    string getDepartamento();
    string getEmpresa();
    string fecha();
    int getTiempo();
    ~Transaccion();
};






#endif /*TRANSACCION_H*/