/* 
 * File:   Menu.cpp
 * Author: pedro
 * Created on June 11, 2020, 10:27 AM
 */

#include "Menu.h"
#include "Reporte.h"

Menu::Menu(ListaDoble<Transaccion *> *historialT_, MatrizDispersa *matriz_) : historialT(historialT_), matriz(matriz_)
{
}

//menu para inicio de sesion
void Menu::menuIni()
{
    system("clear");
    // menuUsuario(nullptr);
    int option;
    string opEr, pause;
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
            system("clear");
            break;

        default:
            system("clear");
            break;
        }
    } while (option != 2);
}

//login para iniciar menus
void Menu::login()
{
    system("clear");
    string nombreUsu, password, departamento, empresa;
    cout << "------------+MENU RENTA ACTIVOS+----------------\n";
    cout << "|\t        +Login+\t\t\t       |\n";
    cout << "|______________________________________________|\n\n";
    cout << "Ingresar Usuario: ";
    getline(cin, nombreUsu);
    getline(cin, nombreUsu);
    cout << "\n";
    cout << "Ingresar Password: ";
    getline(cin, password);
    cout << "\n";
    cout << "Ingresar Departamento: ";
    getline(cin, departamento);
    cout << "\n";
    cout << "Ingresar Empresa: ";
    getline(cin, empresa);
    cout << "\n";
    Usuario *us = matriz->getAdmin(); //obtiene el usuario administrador
    if (us && us->getNombre() == nombreUsu && us->getPassword() == password)
    {
        system("clear");
        menuAdmin();
    }
    else
    {
        Usuario *tmp = matriz->searchM(departamento, empresa); //obtiene el usario en esa posicion
        if (tmp && tmp->getNombre() == nombreUsu && tmp->getPassword() == password)
        {
            menuUsuario(tmp);
        }
        else
        {
            cout << "El Usuario no existe!! presione cualquier tecla y Enter\n\n";
            cin >> nombreUsu;
        }
    }
}

//menu administrador *** operaciones de adminstrador
void Menu::menuAdmin()
{
    system("clear");
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
            system("clear");
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

//menu Usuario logeado
void Menu::menuUsuario(Usuario *usuario)
{
    system("clear");
    int option;
    string opEr;
    // if (usuario)
    //     TAVL<Activo *, string> *avl = usuario->getArbolAvl();
    do
    {
        cout << "|======================+MENU USUARIO+========================|\n";
        cout << "|\t*1.  Agregar Activo*\t\t\t\t     |\n";
        cout << "|\t*2.  Eliminar Activo*\t\t\t\t     |\n";
        cout << "|\t*3.  Modificar Activo*\t\t\t\t     |\n";
        cout << "|\t*4.  Rentar Activo*\t\t\t             |\n";
        cout << "|\t*5.  Activos Rentados*\t\t\t             |\n";
        cout << "|\t*6.  Mis Activos Rentados*\t\t             |\n";
        cout << "|\t*7.  Cerrar Sesion*\t\t\t             |\n";
        cout << "|____________________________________________________________|\n";
        if (usuario)
            cout << "Usuario: " << usuario->getNombre() << "\n";
        cout << "\n";
        cout << "Ingrese Opcion : ";
        std::cin >> opEr;
        option = atoi(opEr.c_str());
        switch (option)
        {
        case 1:
            system("clear");
            if (usuario)
                crearActivo(usuario->getArbolAvl());
            system("clear");
            break;
        case 2:
            system("clear");
            if (usuario)
                eliminarActivo(usuario->getArbolAvl());
            system("clear");
            break;
        case 3:
            system("clear");
            modificarActivo(usuario->getArbolAvl());
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
        default:
            system("clear");

            break;
        }
    } while (option != 7);
}

//metodo para crear usuario admin
void Menu::crearUsuario()
{
    system("clear");
    string nombre, password, departamento, empresa;
    cout << "|===============+MENU ADMISTRADOR CREAR USUARIO+=================|\n";
    cout << "|________________________________________________________________|\n";
    cout << "\n\n";
    cout << "-> Nombre de Usuario : ";
    getline(cin, nombre);
    getline(cin, nombre);
    cout << "-> Constraseña : ";
    getline(cin, password);
    cout << "-> Departamento: ";
    getline(cin, departamento);
    cout << "-> Empresa : ";
    getline(cin, empresa);
    if (nombre != "" && password != "" && departamento != "" && empresa != "")
    {
        matriz->insertMatrix(departamento, empresa, new Usuario(nombre, password));
        cout << "\n\nUsuario " << nombre << " creado con exito!\n\n Pulse cualquier tecla y Enter!  ";
        string t;
        cin >> t;
        system("clear");
    }
    else
    {
        cout << "No se puede crear usuario falto llenar algun campo!!\n\nPulse cualquier tecla y Enter! ";
        string p;
        cin >> p;
        system("clear");
    }
}

//metodo para crear un activo
void Menu::crearActivo(TAVL<Activo *, string> *avl)
{
    string nombre, descripcion;
    cout << "|======================+AGREGAR ACTIVO+========================|\n";
    cout << "|______________________________________________________________|\n";
    cout << "\n\n";
    cout << "Nombre Activo: ";
    getline(cin, nombre);
    getline(cin, nombre);
    cout << "\n";
    cout << "Descripcion: ";
    getline(cin, descripcion);
    cout << "\n";
    if (nombre != "" && descripcion != "")
    {
        Activo *newA = new Activo(nombre, descripcion);
        avl->insertar(newA, newA->getIdActivo());
        cout << "Activo Creado!!\n";
        // Reporte re;
        // re.reporteAVL(avl->getRaiz());
    }
    else
        cout << "No se pudo crear el activo!\n";
}

//metodo para eliminar un activo del arbol
void Menu::eliminarActivo(TAVL<Activo *, string> *avl)
{
    string id, pause;
    NodeAvl<Activo *, string> *atmp;
    cout << "|======================+ELIMINAR ACTIVO+========================|\n";
    cout << "|_______________________________________________________________|\n";
    cout << "\n";
    Reporte().inorden(avl->getRaiz());
    cout << "\nIngrese el ID del activo a eliminar: ";
    cin >> id;
    atmp = avl->buscar(id);
    if (id != "" && atmp)
    {
        avl->eliminar(id);
        cout << "\nActivo Eliminado!!\n";
        cout << "ID: " << atmp->getDato()->getIdActivo() << "\n";
        cout << "Nombre: " << atmp->getDato()->getNombre() << "\n";
        cout << "Descripcion: " << atmp->getDato()->getDescripcion() << "\n\n";
        cout << "Presion una tecla y enter ";
        cin >> pause;
        delete atmp;
    }
    else
    {
        cout << "No existe el ID para eliminar\n\nPresionsa cualquier tecla y Enter :";
        cin >> pause;
    }
}

//metodo para modificar un activo
void Menu::modificarActivo(TAVL<Activo *, string> *avl)
{
    system("clear");
    string id, pause;
    NodeAvl<Activo *, string> *ntmp;
    cout << "|======================+MODIFICAR ACTIVO+========================|\n";
    cout << "|________________________________________________________________|\n";
    cout << "\n\n";
    Reporte().inorden(avl->getRaiz());
    cout << "\n";
    cout << "Ingresar ID de Activo a modificar: ";
    cin >> id;
    ntmp = avl->buscar(id);
    if (id != "" && ntmp)
    {
        system("clear");
        modificandoActivo(ntmp->getDato());
        system("clear");
    }
    else
    {
        cout << "No existe el ID para a modifcar\n\nPresionsa cualquier tecla y Enter :";
        cin >> pause;
    }
}

//modifcando activo
void Menu::modificandoActivo(Activo *activo)
{
    string nueva_descrip;
    cout << "|=====================+MODIFICANDO ACTIVO+=======================|\n";
    cout << "|________________________________________________________________|\n";
    cout << "\n\n";
    cout <<"ID: "<<activo->getIdActivo()<<"\tNombre: "<<activo->getNombre()<<"\n\tDescripcion: "<<activo->getDescripcion()<<"\n\n";
    cout << "Ingresar la nueva Descripcion: ";
    getline(cin, nueva_descrip);
    getline(cin, nueva_descrip);
    if (activo)
    {
        activo->setDescripcion(nueva_descrip);
        cout << "Activo modificado!\n";
        cout <<"ID: "<<activo->getIdActivo()<<"\tNombre: "<<activo->getNombre()<<"\tDescripcion: "<<activo->getDescripcion()<<"\n";
        cout<<"Pulse cualquier tecla y Enter para regresar! ";
        cin >> nueva_descrip;
    }
}

Menu::~Menu()
{
}
