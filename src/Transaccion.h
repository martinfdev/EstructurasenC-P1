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
    string activo; 
    string idT, nombre_usuarioR, departamento, empresa, fecha_renta;
    string date();//retorna la fecha actual del sistema  
    string getT(); 
public:
    Transaccion();//sin parametros
    Transaccion(string, string, string, string, int);
    string getIdT();
    string getIdActivo();
    string getNombreUsuario();
    string getDepartamento();
    string getEmpresa();
    string getFecha();
    int getTiempo();
    ~Transaccion();
};
#endif /*TRANSACCION_H*/