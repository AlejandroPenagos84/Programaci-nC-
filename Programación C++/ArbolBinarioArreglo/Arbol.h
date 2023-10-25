//
// Created by Alejandro Penagos on 24/10/2023.
//

#ifndef ARBOL_H
#define ARBOL_H
#include "Cola.h"
#include "Pila.h"
#include <iostream>
struct Clave
{
    int num;
    std::string info;
};

struct Nodo
{
    Clave clave;
    int izq;
    int der;
};

class Arbol
{
    Nodo *arbol;

public:
    explicit Arbol(int num)
    {
        arbol = new Nodo[num + 1];
        arbol[0].izq = 0;

        for (int i = 0; i < num; i++)
        {
            arbol[i].der = i + 1;
        }
        arbol[num].der = 0;
    }

    Nodo *getArbol() { return arbol; }
    bool Insertar(int, std::string);
    std::string Eliminar(int);
    Clave Buscar(int);
    Queue<Nodo> recorridoNiveles();
    Queue<Nodo> inorden();
    Queue<Nodo> preorden();
    Queue<Nodo> posorden();
};

bool Arbol::Insertar(int num, std::string info)
{
    if (arbol[0].der == 0)
    {
        return false;
    }
    else
    {
        Clave clave;
        clave.num = num;
        clave.info = info;

        if (arbol[0].izq == 0)
        {
            arbol[0].der = arbol[1].der;
            arbol[0].izq = 1;

            arbol[1].clave = clave;
            arbol[1].izq = arbol[1].der = 0;
            return true;
        }
        else
        {
            int raiz = arbol[0].izq;
            int padre = 0;

            while (raiz != 0)
            {
                padre = raiz;
                if (clave.num < arbol[raiz].clave.num)
                {
                    raiz = arbol[raiz].izq;
                }
                else
                {
                    raiz = arbol[raiz].der;
                }
            }

            int posLibre = arbol[0].der;
            int auxPosLibre = arbol[posLibre].der;

            arbol[posLibre].clave = clave;
            arbol[posLibre].izq = 0;
            arbol[posLibre].der = 0;

            if (arbol[posLibre].clave.num < arbol[padre].clave.num)
            {
                arbol[padre].izq = posLibre;
            }
            else
            {
                arbol[padre].der = posLibre;
            }
            arbol[0].der = auxPosLibre;
            return true;
        }
    }
}

std::string Arbol::Eliminar(int num)
{
    Clave aux;
    aux.num = 0;
    aux.info = "";

    int raiz, padre;

    if (arbol[0].izq == 0) {
        return ""; // Árbol vacío, no se encuentra la clave.
    } else {
        raiz = arbol[0].izq;
        padre = 0;

        // Buscar el nodo
        while (arbol[raiz].clave.num != num) {
            padre = raiz;
            if (num < arbol[raiz].clave.num) {
                raiz = arbol[raiz].izq;
            } else {
                raiz = arbol[raiz].der;
            }
            if (raiz == 0) {
                return ""; // La clave no se encuentra en el árbol.
            }
        }

        // Guardar la información asociada al nodo que se eliminará.
        std::string info_asociada = arbol[raiz].clave.info;

        // Caso 1: el nodo es una hoja
        if (arbol[raiz].izq == 0 && arbol[raiz].der == 0) {
            if (arbol[arbol[padre].izq].clave.num == arbol[raiz].clave.num) {
                arbol[padre].izq = 0;
            } else {
                arbol[padre].der = 0;
            }
            arbol[raiz].clave = aux;
            arbol[raiz].izq = 0;
            arbol[raiz].der = arbol[0].der;
            arbol[0].der = raiz;
        }

            // Caso 2: el nodo tiene un hijo
        else if (arbol[raiz].izq == 0 || arbol[raiz].der == 0) {
            int hijo = (arbol[raiz].izq != 0) ? arbol[raiz].izq : arbol[raiz].der;
            if (padre == 0) {
                arbol[0].izq = hijo;
            } else if (arbol[padre].izq == raiz) {
                arbol[padre].izq = hijo;
            } else {
                arbol[padre].der = hijo;
            }


            arbol[raiz].clave = aux;
            arbol[raiz].izq = 0;
            arbol[raiz].der = arbol[0].der;
            arbol[0].der = raiz;
        }

            // Caso 3: el nodo tiene dos hijos
        else {
            int sucesor = arbol[raiz].der;
            int sucesorPadre = raiz;

            while (arbol[sucesor].izq != 0) {
                sucesorPadre = sucesor;
                sucesor = arbol[sucesor].izq;
            }

            // Guardar la clave del sucesor antes de sobrescribirlo
            int sucesor_clave = arbol[sucesor].clave.num;

            // Sobrescribir el nodo con la clave del sucesor
            arbol[raiz].clave.num = sucesor_clave;

            if (arbol[sucesorPadre].izq == sucesor) {
                arbol[sucesorPadre].izq = (arbol[sucesor].der != 0) ? arbol[sucesor].der : 0;
            } else {
                arbol[sucesorPadre].der = (arbol[sucesor].der != 0) ? arbol[sucesor].der : 0;
            }

            arbol[sucesor].clave = aux;
            arbol[sucesor].izq = 0;
            arbol[sucesor].der = arbol[0].der;
            arbol[0].der = sucesor;
        }

        return info_asociada; // Devolver la información asociada del nodo eliminado.
    }
}


Clave Arbol::Buscar(int num) {
    int raiz = arbol[0].izq;
    int padre = 0;
    while (arbol[raiz].clave.num != num)
    {
        padre = raiz;
        if (num < arbol[raiz].clave.num)
        {
            raiz = arbol[raiz].izq;
        }
        else
        {
            raiz = arbol[raiz].der;
        }
        if (raiz == 0)
        {
            return arbol[raiz].clave;
        }
    }

    return arbol[raiz].clave;

}
Queue<Nodo> Arbol::inorden()
{
    Pila<Nodo> pila;
    Queue<Nodo> info;

    int raiz = arbol[0].izq;

    if (raiz == 0)
    {
        return info;
    }
    int temp = raiz;
    Nodo aux;
    while (temp != 0 || !pila.vacia())
    {
        while (temp != 0)
        {
            pila.meter(arbol[temp]);
            temp = arbol[temp].izq;
        }
        aux = pila.Sacar();
        info.Enqueue(aux);
        temp = aux.der;
    }
    return info;
}

Queue<Nodo> Arbol::preorden()
{
    Pila<Nodo> pila;
    Queue<Nodo> info;

    int raiz = arbol[0].izq;

    if (raiz == 0)
    {
        return info;
    }
    int temp = raiz;
    Nodo aux;
    while (temp != 0 || !pila.vacia())
    {
        while (temp != 0)
        {
            pila.meter(arbol[temp]);
            info.Enqueue(arbol[temp]);
            temp = arbol[temp].izq;
        }
        aux = pila.Sacar();
        temp = aux.der;
    }
    return info;
}

Queue<Nodo> Arbol::posorden()
{
    Pila<Nodo> pila;
    Queue<Nodo> info;
    int raiz = arbol[0].izq;

    Nodo actual, prev;

    int temp = raiz;
    if (raiz == 0)
    {
        return info; // Árbol vacío, no hay nada que imprimir
    }

    while (temp != 0 || !pila.vacia())
    {
        while (temp != 0)
        {
            pila.meter(arbol[temp]);
            temp = arbol[temp].izq;
        }
        actual = pila.Cima();

        if (actual.der != 0 && arbol[actual.der].clave.num != prev.clave.num)
        {
            temp = actual.der;
        }
        else
        {
            actual = pila.Sacar();
            prev = actual;
            info.Enqueue(actual);
            temp = 0;
        }
    }
    return info;
}

Queue<Nodo> Arbol::recorridoNiveles()
{
    Queue<Nodo> resultado;

    int raiz = arbol[0].izq;
    if (raiz == 0)
    {
        return resultado;
    }
    Queue<Nodo> cola;
    cola.Enqueue(arbol[raiz]);
    while (!cola.IsEmpty())
    {
        Nodo nodo = cola.Front();
        cola.Dequeue();
        resultado.Enqueue(nodo);
        if (nodo.izq != 0)
        {
            cola.Enqueue(arbol[nodo.izq]);
        }
        if (nodo.der != 0)
        {
            cola.Enqueue(arbol[nodo.der]);
        }
    }
    return resultado;
}
#endif //ARBOLBINARIOARREGLO_ARBOL_H
