/* 
 * File:   Transaccion.h
 * Author: pedro
 */

#include "Transaccion.h"
#include "Activo.h"
#include "MD5.h"
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

//constructor
Transaccion::Transaccion() {}

//constructor con paramentros
Transaccion::Transaccion(string activo_, string u_renta, string departamento_, string empresa_, int dias_)
    : activo(activo_), nombre_usuarioR(u_renta),
      departamento(departamento_), empresa(empresa_), tiempo_renta(dias_)
{
    fecha_renta = date();
    idT = md15(getT()+activo_);
}

//metodo que devuelva la fecha en formato string
string Transaccion::date()
{
    time_t tiempo = time(NULL);               //variables donde guardo el valor de la funcion time.
    struct tm *tlocal = localtime(&tiempo);   //estructura donde obtengo el tiempo
    char output[15];                          //array donde guardo la fecha
    strftime(output, 15, "%d-%m-%y", tlocal); //formato para guardar la fecha obtenido en *tlocal como dd/mm/yyyy
    return output;
}

//metodo para obtener tiempo en formato t_time a string se usa como cadena para generar el md5 unico
string Transaccion::getT()
{
    time_t ti;
    time(&ti);
    stringstream ss;
    ss << ti;
    return ss.str();
}

//getters
string Transaccion::getIdT(){return idT;}

string Transaccion::getIdActivo(){return activo;}

string Transaccion::getNombreUsuario(){return nombre_usuarioR;}

string Transaccion::getDepartamento(){return departamento;}

string Transaccion::getEmpresa(){return empresa;}

string Transaccion::getFecha(){return fecha_renta; }

int Transaccion::getTiempo(){return tiempo_renta;}

//destructor
Transaccion::~Transaccion() {}