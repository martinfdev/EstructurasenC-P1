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
    int idTransaccion, id_unico, tiempo_renta; //el tiempo de renta es en dias
    std::string usuario_que_renta, departamento, empresa, fecha_renta;   
public:
    Transaccion();//sin parametros
    Transaccion(int, int, int, std::string, std::string, std::string, std::string);
    ~Transaccion();
};






#endif /*TRANSACCION_H*/