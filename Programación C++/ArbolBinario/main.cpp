#include <iostream>
#include <string>
#include "Pila.h"
#include "Cola.h"


using namespace std;

struct Info {
    int info;
    string info_string;
};

struct Nodo {
    Info informacion;
    Nodo* izq;
    Nodo* der;
};

class ARBOL {
    Nodo* raiz;

public:
    ARBOL() {
        raiz = NULL;
    }

    Nodo* raiz_arbol() {
        return raiz;
    }

    Nodo* buscar_arbol(int, Nodo*, Nodo*);
    int ins_arbol(int, string);
    Nodo* retira_arbol(int);
    Queue<Nodo*> recorridoNiveles();
    Queue<Nodo*> inorden();
    Queue<Nodo*>preorden();
    Queue<Nodo*> posorden();
    void destruir(Nodo*);
    ~ARBOL() {
        destruir(raiz);
    }
};

Nodo* ARBOL::buscar_arbol(int n, Nodo* p, Nodo* q) {
    if (p == NULL)
        return q;
    if (n < p->informacion.info) {
        q = p;
        q = buscar_arbol(n, p->izq, q);
        return q;
    } else if (n > p->informacion.info) {
        q = p;
        q = buscar_arbol(n, p->der, q);
        return q;
    } else
        return NULL;
}

int ARBOL::ins_arbol(int n, string info_string) {
    Nodo* q;
    if (raiz == NULL) {
        raiz = new Nodo;
        raiz->informacion.info = n;
        raiz->informacion.info_string = info_string;
        raiz->izq = raiz->der = NULL;
        return 0;
    }
    q = buscar_arbol(n, raiz, NULL);
    if (q == NULL)
        return -1;
    Nodo* nuevo = new Nodo;
    nuevo->informacion.info = n;
    nuevo->informacion.info_string = info_string;
    nuevo->izq = nuevo->der = NULL;
    if (n < q->informacion.info)
        q->izq = nuevo;
    else
        q->der = nuevo;
    return 0;
}

Nodo* ARBOL::retira_arbol(int n) {
    Nodo* q = NULL; // Nodo padre del nodo a retirar
    Nodo* p = raiz;   // Nodo a retirar

    // Buscar el nodo que deseas retirar
    while (p != NULL && p->informacion.info != n) {
        q = p;
        if (n < p->informacion.info) {
            p = p->izq;
        } else {
            p = p->der;
        }
    }

    // Si el nodo no se encontró, retornar un valor especial
    if (p == NULL) {
        Nodo* noExiste;
        noExiste->informacion.info = -1;
        noExiste->informacion.info_string = "";
        return noExiste;
    }

    Nodo* informacion = p;

    // Caso 1: El nodo a retirar es una hoja
    if (p->izq == NULL && p->der == NULL) {
        if (q == NULL) {
            raiz = NULL; // El nodo a retirar es la raíz
        } else if (q->izq == p) {
            q->izq = NULL;
        } else {
            q->der = NULL;
        }
        delete p;
    }
        // Caso 2: El nodo a retirar tiene un solo hijo
    else if (p->izq == NULL) {
        if (q == NULL) {
            raiz = p->der; // El nodo a retirar es la raíz
        } else if (q->izq == p) {
            q->izq = p->der;
        } else {
            q->der = p->der;
        }
        delete p;
    } else if (p->der == NULL) {
        if (q == NULL) {
            raiz = p->izq; // El nodo a retirar es la raíz
        } else if (q->izq == p) {
            q->izq = p->izq;
        } else {
            q->der = p->izq;
        }
        delete p;
    }
        // Caso 3: El nodo a retirar tiene dos hijos
    else {
        Nodo* sucesor = p->der;
        Nodo* padreSucesor = p;
        while (sucesor->izq != NULL) {
            padreSucesor = sucesor;
            sucesor = sucesor->izq;
        }
        p->informacion = sucesor->informacion;
        if (padreSucesor == p) {
            padreSucesor->der = sucesor->der;
        } else {
            padreSucesor->izq = sucesor->der;
        }
        delete sucesor;
    }

    return informacion;
}


Queue<Nodo*> ARBOL::recorridoNiveles() {
    Queue<Nodo*> resultado;
    if (raiz == NULL) {
        return resultado;
    }
    Queue<Nodo*> cola;
    cola.Enqueue(raiz);
    while (!cola.IsEmpty()) {
        Nodo* nodo = cola.Front();
        cola.Dequeue();
        resultado.Enqueue(nodo);
        if (nodo->izq) {
            cola.Enqueue(nodo->izq);
        }
        if (nodo->der) {
            cola.Enqueue(nodo->der);
        }
    }
    return resultado;
}

Queue<Nodo*> ARBOL::inorden() {
    Pila<Nodo*> pila;
    Queue<Nodo*> info;
    if (raiz == NULL) {
        return info;
    }
    Nodo* temp = raiz;

    while (temp != NULL || !pila.vacia()) {
        while (temp != NULL) {
            pila.meter(temp);
            temp = temp->izq;
        }

        temp = pila.Sacar();
        info.Enqueue(temp);
        temp = temp->der;
    }
    return info;
}

Queue<Nodo*> ARBOL::preorden() {
    Pila<Nodo*> pila;
    Queue<Nodo*> info;
    if (raiz == NULL) {
        return info; // Árbol vacío, no hay nada que imprimir
    }
    Nodo* temp = raiz;

    while (temp != NULL || !pila.vacia()) {
        while (temp != NULL) {
            //cout << temp->informacion.info << " - " << temp->informacion.info_string << endl;
            pila.meter(temp);
            info.Enqueue(temp);
            temp = temp->izq;
        }
        temp = pila.Sacar();
        temp = temp->der;
    }
    return info;
}

Queue<Nodo*> ARBOL::posorden() {
    Pila<Nodo*> pila;
    Queue<Nodo*> info;
    if (raiz == NULL) {
        return info; // Árbol vacío, no hay nada que imprimir
    }
    Nodo* temp = raiz;
    Nodo*prev;
    while (temp != NULL || !pila.vacia()) {
        while (temp != NULL) {
            pila.meter(temp);
            temp = temp->izq;
        }
        temp = pila.Cima();
        if(temp->der != NULL && temp->der!=prev){
            temp = temp->der;
        }else{
            temp = pila.Sacar();
            prev = temp;
            info.Enqueue(temp);
            temp = NULL;
        }
    }
    return info;
}


void ARBOL::destruir(Nodo* p) {
    // ...
}

int main() {
    ARBOL arbol;

    arbol.ins_arbol(180, "A");
    arbol.ins_arbol(150, "B");
    arbol.ins_arbol(250, "C");
    arbol.ins_arbol(160, "D");
    arbol.ins_arbol(100, "E");
    arbol.ins_arbol(50, "F");
    arbol.ins_arbol(30, "G");
    arbol.ins_arbol(70, "H");
    arbol.ins_arbol(200, "I");
    arbol.ins_arbol(140, "J");
    arbol.ins_arbol(240, "J");

    cout<<"PREORDEN"<<endl;
    Queue<Nodo*> colaPreorden = arbol.preorden();
    while(!colaPreorden.IsEmpty()){
        Nodo *nodo = colaPreorden.Dequeue();
        cout<<"\t"<<"Clave: "<<nodo->informacion.info<<endl;
        cout<<"\t"<<"Informacion: "<<nodo->informacion.info_string<<endl;
        cout<<"\t"<<"---------------------------------------------"<<endl;
    }

    cout<<"POSORDEN"<<endl;
    Queue<Nodo*> colaPosorden = arbol.posorden();
    while(!colaPosorden .IsEmpty()){
        Nodo *nodo = colaPosorden .Dequeue();
        cout<<"\t"<<"Clave: "<<nodo->informacion.info<<endl;
        cout<<"\t"<<"Informacion: "<<nodo->informacion.info_string<<endl;
        cout<<"\t"<<"---------------------------------------------"<<endl;
    }

    cout<<"INORDEN"<<endl;
    Queue<Nodo*> colaInorden = arbol.inorden();
    while(!colaInorden .IsEmpty()){
        Nodo *nodo = colaInorden.Dequeue();
        cout<<"\t"<<"Clave: "<<nodo->informacion.info<<endl;
        cout<<"\t"<<"Informacion: "<<nodo->informacion.info_string<<endl;
        cout<<"\t"<<"---------------------------------------------"<<endl;
    }

    cout<<"RECORRIDO POR NIVELES"<<endl;
    Queue<Nodo*> colaNiveles = arbol.recorridoNiveles();
    while(!colaNiveles.IsEmpty()){
        Nodo *nodo = colaNiveles.Dequeue();
        cout<<"\t"<<"Clave: "<<nodo->informacion.info<<endl;
        cout<<"\t"<<"Informacion: "<<nodo->informacion.info_string<<endl;
        cout<<"\t"<<"---------------------------------------------"<<endl;
    }

    cout<<"Se elimino: "<<arbol.retira_arbol(200)->informacion.info_string<<endl;
    cout<<"Se elimino: "<<arbol.retira_arbol(50)->informacion.info_string<<endl;
    cout<<"Se elimino: "<<arbol.retira_arbol(180)->informacion.info_string<<endl;


    cout<<"PREORDEN"<<endl;
    colaPreorden = arbol.preorden();
    while(!colaPreorden.IsEmpty()){
        Nodo *nodo = colaPreorden.Dequeue();
        cout<<"\t"<<"Clave: "<<nodo->informacion.info<<endl;
        cout<<"\t"<<"Informacion: "<<nodo->informacion.info_string<<endl;
        cout<<"\t"<<"---------------------------------------------"<<endl;
    }

    cout<<"POSORDEN"<<endl;
    colaPosorden = arbol.posorden();
    while(!colaPosorden .IsEmpty()){
        Nodo *nodo = colaPosorden .Dequeue();
        cout<<"\t"<<"Clave: "<<nodo->informacion.info<<endl;
        cout<<"\t"<<"Informacion: "<<nodo->informacion.info_string<<endl;
        cout<<"\t"<<"---------------------------------------------"<<endl;
    }

    cout<<"INORDEN"<<endl;
    colaInorden = arbol.inorden();
    while(!colaInorden .IsEmpty()){
        Nodo *nodo = colaInorden.Dequeue();
        cout<<"\t"<<"Clave: "<<nodo->informacion.info<<endl;
        cout<<"\t"<<"Informacion: "<<nodo->informacion.info_string<<endl;
        cout<<"\t"<<"---------------------------------------------"<<endl;
    }

    cout<<"RECORRIDO POR NIVELES"<<endl;
    colaNiveles = arbol.recorridoNiveles();
    while(!colaNiveles.IsEmpty()){
        Nodo *nodo = colaNiveles.Dequeue();
        cout<<"\t"<<"Clave: "<<nodo->informacion.info<<endl;
        cout<<"\t"<<"Informacion: "<<nodo->informacion.info_string<<endl;
        cout<<"\t"<<"---------------------------------------------"<<endl;
    }
}
