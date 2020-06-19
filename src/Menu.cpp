/* 
 * File:   Menu.cpp
 * Author: pedro
 * Created on June 11, 2020, 10:27 AM
 */

#include "Menu.h"
#include "Reporte.h"
#include "Ordenamiento.h"

Menu::Menu(ListaDoble<Transaccion *> *historialT_, MatrizDispersa *matriz_, Lista<Usuario *> *catalago_) : historialT(historialT_), matriz(matriz_), catalogo(catalago_)
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
        Usuario *tmp = matriz->searchM(departamento, empresa, nombreUsu); //obtiene el usario en esa posicion
        if (tmp && tmp->getNombre() == nombreUsu && tmp->getPassword() == password)
        {
            menuUsuario(tmp, departamento, empresa);
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
    string opEr, depa = "", empresa = "", pause;
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
            cout << "Ingrese el nombre del deparatamento: ";
            getline(cin, depa);
            getline(cin, depa);
            cout << endl;
            if (depa != "")
            {
                Reporte().reporteDepartamento(matriz, depa);
            }
            system("clear");
            break;
        case 4:
            system("clear");
            cout << "Ingrese el nombre de la empresa: ";
            getline(cin, empresa);
            getline(cin, empresa);
            cout << endl;
            if (empresa != "")
            {
                Reporte().reporteEmpresa(matriz, empresa);
            }
            system("clear");
            break;
        case 5:
            system("clear");
            if (historialT->getSize() > 0)
                Reporte().ReporteListaDobleCircular(historialT, "RTransacciones");
            break;
        case 6:
            system("clear");
            rActivosUsuario();
            system("clear");
            break;
        case 7:
            system("clear");
            repRentaUsuario();
            system("clear");
            break;
        case 8:
            system("clear");
            ordenar();
            system("clear");
            break;
        default:
            system("clear");
            break;
        }
    } while (option != 9);
}

//menu Usuario logeado
void Menu::menuUsuario(Usuario *usuario, string departamento_, string empresa_)
{
    system("clear");
    int option;
    string opEr;
    do
    {
        cout << "|======================+MENU USUARIO+========================|\n";
        cout << "|\t*1.  Agregar Activo*\t\t\t\t     |\n";
        cout << "|\t*2.  Eliminar Activo*\t\t\t\t     |\n";
        cout << "|\t*3.  Modificar Activo*\t\t\t\t     |\n";
        cout << "|\t*4.  Rentar Activo*\t\t\t             |\n";
        cout << "|\t*5.  Activos Rentados*\t\t\t             |\n";
        cout << "|\t*6.  Mis Activos Rentados*\t\t             |\n";
        cout << "|\t*7.  Visualizar Arbol*\t\t\t             |\n";
        cout << "|\t*8.  Cerrar Sesion*\t\t\t             |\n";
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
                crearActivo(usuario->getArbolAvl(), usuario->getNombre());
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
            rentaActivo(usuario, departamento_, empresa_);
            system("clear");
            break;
        case 5:
            system("clear");
            activosRentados(usuario, departamento_, empresa_);
            system("clear");
            break;
        case 6:
            system("clear");
            misActivosRentados(usuario);
            system("clear");
            break;
        case 7:
            system("clear");
            if (usuario->getArbolAvl()->getRaiz())
                Reporte().reporteAVL(usuario->getArbolAvl()->getRaiz(), usuario->getNombre());
            system("clear");
            break;
        default:
            system("clear");

            break;
        }
    } while (option != 8);
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
        Usuario *n_usuario = new Usuario(nombre, password);
        bool secreo = matriz->insertMatrix(departamento, empresa, n_usuario);
        if (secreo)
        {
            catalogo->add_endS(n_usuario);
            cout << "\n\nUsuario " << nombre << " creado con exito!\n\n Pulse cualquier tecla y Enter!  ";
            string t;
            cin >> t;
            system("clear");
        }
        else
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
void Menu::crearActivo(TAVL<Activo *, string> *avl, string usu)
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
        Activo *newA = new Activo(nombre, descripcion, usu);
        avl->insertar(newA, newA->getIdActivo());
        cout << "Activo Creado!!\n";
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
    //Reporte().inorden(avl->getRaiz());
    Reporte().preorden(avl->getRaiz());
    cout << "\nIngrese el ID del activo a eliminar: ";
    getline(cin, id);
    getline(cin, id);
    atmp = avl->buscar(id);
    if (id != "" && atmp)
    {
        cout << "\nActivo Eliminado!!\n";
        cout << "ID: " << atmp->getDato()->getIdActivo() << "\n";
        cout << "Nombre: " << atmp->getDato()->getNombre() << "\n";
        cout << "Descripcion: " << atmp->getDato()->getDescripcion() << "\n\n";
        cout << "Presion una tecla y enter ";
        avl->eliminar(id); //esta posicion para boora despues de utilizado los datos
        cin >> pause;
    }
    else
    {
        cout << "No existe el ID para eliminar\n\nPulsa cualquier tecla y Enter :";
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
    cout << "ID: " << activo->getIdActivo() << "\tNombre: " << activo->getNombre() << "\n\tDescripcion: " << activo->getDescripcion() << "\n\n";
    cout << "Ingresar la nueva Descripcion: ";
    getline(cin, nueva_descrip);
    getline(cin, nueva_descrip);
    if (activo)
    {
        activo->setDescripcion(nueva_descrip);
        cout << "Activo modificado!\n";
        cout << "ID: " << activo->getIdActivo() << "\tNombre: " << activo->getNombre() << "\tDescripcion: " << activo->getDescripcion() << "\n";
        cout << "Pulse cualquier tecla y Enter para regresar! ";
        cin >> nueva_descrip;
    }
}

//rentar activos
void Menu::rentaActivo(Usuario *usuario, string departamento, string empresa)
{
    int option;
    string entrada;
    do
    {
        cout << "|=====================+RENTA ACTIVO+=======================|\n";
        cout << "|\t*1.  Rentar Activo*\t\t\t\t   |\n";
        cout << "|\t*2.  Regresar *\t\t\t\t\t   |\n";
        cout << "|___________________CATALOGO DE ACTIVOS____________________|\n";
        cout << "\n";
        //llamamos el mentodo de la clase reporte para imprimir el catalogo
        Reporte().printCatalogoActivos(catalogo, usuario);
        cout << "Ingrese Opcion: ";
        cin >> entrada;
        option = atoi(entrada.c_str());
        switch (option)
        {
        case 1:
            rentandoActivo(usuario, departamento, empresa);
            break;
        default:
            system("clear");
            break;
        }
    } while (option != 2);
}

//submenu rentando
void Menu::rentandoActivo(Usuario *usuario, string departamento, string empresa)
{
    Activo *dev = 0;
    string id;
    cout << "|=====================+RENTANDO ACTIVO+=======================|\n\n";
    cout << "Ingresar ID de Activo a Rentar: ";
    getline(cin, id);
    getline(cin, id);
    dev = Reporte().getActivoRenta(catalogo, id);
    if (dev)
    {
        cout << "Activo a Rentar\n";
        cout << "ID: " << dev->getIdActivo() << "\tNombre: " << dev->getNombre() << "\tDescripcion: " << dev->getDescripcion() << "\n\n";
        string temporal;
        int dia_renta = 0;
        cout << "Ingresar dias por rentar: ";
        getline(cin, temporal);
        dia_renta = atoi(temporal.c_str());
        if (dia_renta > 0)
        {
            dev->setTiempo(dia_renta);
            dev->setDisponibilidad(false);
            usuario->getActivoRen()->insertarUltimo(dev);
            historialT->insertarUltimoC(new Transaccion(dev->getIdActivo(), usuario->getNombre(), departamento, empresa, dia_renta));
        }
    }
    system("clear");
}

//activos rentados lista
void Menu::activosRentados(Usuario *usuario, string departamento, string empresa)
{
    int option;
    string entrada;
    do
    {
        cout << "|=====================+ACTIVOS RENTADOS+=======================|\n";
        cout << "|\t*1.  Registrar Devolucion*\t\t\t       |\n";
        cout << "|\t*2.  Regresar *\t\t\t\t\t       |\n";
        cout << "|______________________________________________________________|\n";
        cout << "\n";
        //llamamos el mentodo de la clase reporte para imprimir el catalogo
        ListaDoble<Activo *> *lar = usuario->getActivoRen();
        for (size_t i = 0; i < lar->getSize(); i++)
        {
            Activo *tmpa = lar->getDataNext();
            if (tmpa)
                cout << "ID: " << tmpa->getIdActivo() << ";\t Nombre: " << tmpa->getNombre() << ";\t\t Tiempor de Renta: " << tmpa->getTiempo() << "\n";
        }
        cout << "Ingrese Opcion: ";
        cin >> entrada;
        option = atoi(entrada.c_str());
        switch (option)
        {
        case 1:
            devolverActivo(usuario);
            break;
        default:
            system("clear");
            break;
        }
    } while (option != 2);
}

//submenu delvolviendo los activos rentados
void Menu::devolverActivo(Usuario *usuario)
{
    Activo *dev = 0;
    string id;
    cout << "|=====================+DEVOLVER ACTIVO+======================|\n\n";
    cout << "Ingresar ID de Activo a devolver: ";
    getline(cin, id);
    getline(cin, id);
    dev = Reporte().getActivoRenta(catalogo, id);
    if (dev)
    {
        cout << "Activo devuelto: \n";
        cout << "ID: " << dev->getIdActivo() << "\tNombre: " << dev->getNombre() << "\t\tDescripcion: " << dev->getDescripcion() << "\n\n";
        usuario->getActivoRen()->borrarParametro(dev);
        dev->setDisponibilidad(true);
        dev->setTiempo(0);
    }
    system("clear");
}

//menu que muestra los activos de un usuario rentados
void Menu::misActivosRentados(Usuario *usuario)
{
    cout << "|===============+MIS ACTIVOS RENTADOS+=================|\n";
    cout << "|______________________________________________________|\n";
    cout << "\n\n";
    Reporte().printMisActivosRentados(usuario->getArbolAvl()->getRaiz());
    cout << "\nPulse cualquier tecla y enter para salir: ";
    string salir;
    cin >> salir;
    system("clear");
}

//metodo dondo se genera los reportes de los activos de un usuario en espesifico
void Menu::rActivosUsuario()
{
    string departamento, empresa, usuario, pause;
    cout << "Nombre del departamento: ";
    getline(cin, departamento);
    getline(cin, departamento);
    cout << "\nNombre de la empresa:";
    getline(cin, empresa);
    cout << "\nNombre del usuario:";
    getline(cin, usuario);
    Usuario *user = 0;
    user = matriz->searchM(departamento, empresa, usuario);
    if (user)
        Reporte().reporteAVL(user->getArbolAvl()->getRaiz(), usuario);
    else
    {
        cout << "\nUsuario no existe!!\n\nPresione enter para seguir ";
        getline(cin, pause);
    }
}

//metodo para el reporte de rentas de un usuario
void Menu::repRentaUsuario()
{
    string departamento, empresa, usuario, pause;
    cout << "Nombre del departamento: ";
    getline(cin, departamento);
    getline(cin, departamento);
    cout << "\nNombre de la empresa:";
    getline(cin, empresa);
    cout << "\nNombre del usuario:";
    getline(cin, usuario);
    Usuario *user = 0;
    user = matriz->searchM(departamento, empresa, usuario);
    if (user)
        Reporte().reporteActivosRentadoUsuario(user->getActivoRen(), usuario);
    else
    {
        cout << "\nUsuario no existe!!\n\nPresione enter para seguir ";
        getline(cin, pause);
    }
}

//submenu de ordenas Transacciones
void Menu::ordenar()
{
    int option;
    string entrada;
    do
    {
        cout << "|=====================+ORDENAR TRANSACCIONES+=======================|\n";
        cout << "|\t*1.  Ordenar Ascendente*\t\t\t\t    |\n";
        cout << "|\t*2.  Ordenar Descendente *\t\t\t\t    |\n";
        cout << "|\t*3.  Regresar *\t\t\t\t\t\t    |\n";
        cout << "|___________________________________________________________________|\n";
        cout << "\n";
        cout << "Ingrese Opcion: ";
        cin >> entrada;
        option = atoi(entrada.c_str());
        switch (option)
        {
        case 1:
            system("clear");
            if (historialT->getSize()>0)
            {
                Ordenamiento().ordenarListaDobleA(historialT);
                Reporte().ReporteListaDobleCircular(historialT, "RTransaccionesAs");
            }
            system("clear");
            break;
        case 2:
            system("clear");
            if (historialT->getSize()>0)
            {
                Ordenamiento().ordenarListaDobleA(historialT);
                Ordenamiento().ordenarListaDobleDes(historialT);
                Reporte().ReporteListaDobleCircular(historialT, "RTransaccionesDes");
            }
            system("clear");
            break;
        default:
            system("clear");
            break;
        }
    } while (option != 3);
}

//destructor
Menu::~Menu()
{
}
