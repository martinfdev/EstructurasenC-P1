/* 
 * File:   Menu.cpp
 * Author: pedro
 * Created on June 11, 2020, 10:27 AM
 */

#include "Menu.h"

Menu::Menu(ListaDoble<Transaccion *> *historialT_, MatrizDispersa *matriz_) : historialT(historialT_), matriz(matriz_)
{
}

//menu para inicio de sesion
void Menu::menuIni()
{
    menuAdmin();
    /* int option;
    string opEr;
    do
    {
        cout << "------------+MENU RENTA ACTIVOS+---------------\n";
        cout << "|\t    +1.  Iniciar Sesion+\t       |\n";
        cout << "|\t    +2.  Salir+\t\t\t       |\n";
        cout << "|______________________________________________|\n";
        cout << "\n\n";
        cout << "Ingrese Opcion : ";
        std::cin >> opEr;
        option = atoi(opEr.c_str());
        switch (option)
        {
        case 1:
            system("clear");
            login();
            break;

        default:
            system("clear");
            break;
        }
    } while (option != 2); 
    */
}

//login para iniciar menus
void Menu::login()
{
    cout << "------------+MENU RENTA ACTIVOS+---------------\n";
    cout << "|\t        +Login+\t\t\t       |\n";
    cout << "|______________________________________________|\n\n";
    string nombreUsu, password, departamento, empresa;
    cout << "Ingrsar Usuario: ";
    cin >> nombreUsu;
    cout << "\n";
    cout << "Ingresar Password: ";
    cin >> password;
    cout << "\n";
    cout << "Ingresar Departamento: ";
    cin >> departamento;
    cout << "\n";
    cout << "Ingresar Empresa: ";
    cin >> empresa;
    cout << "\n";
    Usuario *us = matriz->getAdmin(); //obtiene el usuario administrador
    if (us && us->getNombre() == nombreUsu && us->getPassword() == password)
    {
        system("clear");
        menuAdmin();
        string paue;
        cin >> paue;
    }
    else
    {
        Usuario *tmp = matriz->searchM(departamento, empresa); //obtiene el usario en esa posicion
        if (tmp && tmp->getNombre() == nombreUsu && tmp->getPassword() == password)
        {
        }
        else
            cout << "El Usuario no existe!!";
    }
}

//menu administrador *** operaciones de adminstrador
void Menu::menuAdmin()
{
    string opEr;
    int option;
    do
    {
        cout << "|======================+MENU ADMISTRADOR+========================|\n";
        cout << "|\t*1.  Registrar Usuario*\t\t\t\t         |\n";
        cout << "|\t*2.  Reporte Matriz Dispersa*\t\t\t         |\n";
        cout << "|\t*3.  Reporte activos Dispibles de un Departamento*       |\n";
        cout << "|\t*4.  Reporte Activos Disponibles de una Empresa*         |\n";
        cout << "|\t*5.  Reporte Transacciones*\t\t\t         |\n";
        cout << "|\t*6.  Reporte Activos de un Usuario*\t\t         |\n";
        cout << "|\t*7.  Activos Rentados por un Usuario*\t\t         |\n";
        cout << "|\t*8.  Ordenar Transacciones*\t\t\t         |\n";
        cout << "|\t*9.  Cerrar Sesion*\t\t\t\t         |\n";
        cout << "|________________________________________________________________|\n";
        cout << "\n\n";
        cout << "Ingrese Opcion : ";
        std::cin >> opEr;
        option = atoi(opEr.c_str());
        switch (option)
        {
        case 1:
            system("clear");
            crearUsuario();
            break;
        case 2:
            system("clear");
            matriz->report();
            break;
        case 3:
            system("clear");

            break;
        case 4:
            system("clear");

            break;
        case 5:
            system("clear");

            break;
        case 6:
            system("clear");

            break;
        case 7:
            system("clear");

            break;
        case 8:
            system("clear");

            break;
        default:
            system("clear");
            break;
        }
    } while (option != 9);
}

//metodo para crear usuario admin
void Menu::crearUsuario()
{
    string nombre, password, departamento, empresa;
    cout << "|===============+MENU ADMISTRADOR CREAR USUARIO+=================|\n";
    cout << "|________________________________________________________________|\n";
    cout << "\n\n";
    cout << "-> Nombre de Usuario : ";
    std::cin >> nombre;
    cout << "-> Constraseña : ";
    std::cin >> password;
    cout << "-> Departamento: ";
    std::cin >> departamento;
    cout << "-> Empresa : ";
    std::cin >> empresa;
    if (nombre != "" && password != "" && departamento != "" && empresa != "")
    {
        matriz->insertMatrix(departamento, empresa, new Usuario(nombre, password));
        cout << "Usuario " << nombre << " creado con exito!\n\n";
    }
    else
        cout << "No se pudo crear unsuario falto algun campo!!\n\n";
}

Menu::~Menu()
{
}
