/* 
 * File:   Reporte.cpp
 * Author: pedro
 *
 * Created on June 5, , 00:50 AM
*/
#include "Reporte.h"
#include <string>

using std::string;

Reporte::Reporte()
{
}

//reporte de lista doblemente circular
void Reporte::ReporteListaDobleCircular(ListaDoble<std::string> *lista_circular, std::string nameDot){
Graphviz *graph = new Graphviz();
    graph->addln(graph->start_graph());
    graph->addln("rankdir=LR;");
    graph->addln("node [shape=record, color=blue, width=0.5, height=0.5]; ");
    graph->addln();
    int contador = 0, size = lista_circular->getSize();
    Node<std::string>* primero = lista_circular->getPrimero();
    string nodos, enlaces, enlacesIverso;
    if (lista_circular!=0)
    {
        Node<std::string> *aux = primero;
        do
        {
            if (contador < size - 1)
            {
                nodos = nodos + "node" + to_string(contador) + " [label=\"{<a>|" + aux->getData() + "|<b>}\"];\n";
                enlaces = enlaces + "node" + to_string(contador) + ":b:c -> node" + to_string(contador + 1) + ":a:c [arrowtail=dot, dir=both,tailclip=false];\n";
                enlacesIverso = enlacesIverso + "node" + to_string(contador + 1) + ":a:c -> node" + to_string(contador) + ":b:c [arrowtail=dot, dir=both,tailclip=false];\n";
            }
            else
            {
                nodos = nodos + "node" + to_string(contador) + " [label=\"{<a>|" + aux->getData() + "|<b>}\"];\n";
                enlaces = enlaces + "node" + to_string(contador) + ":b:c -> node" + to_string(0) + ":a:c [arrowtail=dot, dir=both,tailclip=false];\n";
                enlacesIverso = enlacesIverso + "node" + to_string(0) + ":a:c -> node" + to_string(contador) + ":b:c [arrowtail=dot, dir=both,tailclip=false];\n";
            }
            contador++;
            aux = aux->getNext();
        } while (aux != primero);
    }
    graph->addln(nodos);
    graph->addln(enlaces);
    graph->addln(enlacesIverso);
    graph->addln(graph->end());
    graph->dotGraphGenerator(nameDot, graph->getDotSource());
}


//reporte del arbol avl metodo privado por recursividad
void Reporte::reporteArbolAvl(NodeAvl<Activo*, string>* raiz, Graphviz* graph){
     static int count = 0;
    if (raiz != nullptr)
    {
        if (raiz->getIzquierda())
        {
            graph->addln((raiz->getLlave()) + " -> " + (raiz->getIzquierda()->getLlave())+";");
            reporteArbolAvl(raiz->getIzquierda(), graph);
        }
        else
        {
            graph->addln("null"+to_string(count)+" [shape=point];");
            graph->addln((raiz->getLlave())+ "-> null"+to_string(count)+";");
            count++;
        }
        if (raiz->getDerecha())
        {
            graph->addln((raiz->getLlave()) + " -> " + (raiz->getDerecha()->getLlave()));
            reporteArbolAvl(raiz->getDerecha(), graph);
        }
        else
        {
            graph->addln("null"+to_string(count)+" [shape=point];");
            graph->addln((raiz->getLlave()) +" -> null"+to_string(count)+";");
            count++;
        }
    }
}

//metodo publico para el reporte del arbol avl
void Reporte::reporteAVL(NodeAvl<Activo*, string>* raiz){
    Graphviz *graph = new Graphviz();
    graph->addln(graph->start_graph());
    graph->addln("node[fontname=\"Arial\", color=\"blue\"]");
    graph->addln("edge [color=\"green\"]");
    reporteArbolAvl(raiz, graph);
    graph->addln(graph->end());
    graph->dotGraphGenerator("ArbolAVL", graph->getDotSource());
}

Reporte::~Reporte()
{
}