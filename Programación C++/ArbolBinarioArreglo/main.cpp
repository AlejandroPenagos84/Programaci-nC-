#include <iostream>
#include "Arbol.h"

int main() {
    Arbol *arbol = new Arbol(19);

    // Insertar las claves y datos asociados.
    arbol->Insertar(180, "A");
    arbol->Insertar(150, "B");
    arbol->Insertar(250, "C");
    arbol->Insertar(160, "D");
    arbol->Insertar(100, "E");
    arbol->Insertar(50, "F");
    arbol->Insertar(30, "G");
    arbol->Insertar(70, "H");
    arbol->Insertar(200, "I");
    arbol->Insertar(140, "J");
    arbol->Insertar(240, "J");

    // Imprimir los recorridos.
    Queue<Nodo> s;

    // Dar opciones al usuario para buscar o eliminar.
    while (true) {
        int opcion;
        std::cout << "Opciones: " << std::endl;
        std::cout << "1. Buscar elemento" << std::endl;
        std::cout << "2. Eliminar elemento" << std::endl;
        std::cout << "3. Salir" << std::endl;
        std::cout << "Ingrese el número de la opcion: ";
        std::cin >> opcion;

        if (opcion == 1) {
            // Opción para buscar un elemento.
            int clave_buscar;
            std::cout << "Ingrese la clave a buscar: ";
            std::cin >> clave_buscar;
            if(arbol->Buscar(clave_buscar).info.empty()){
                std::cout<<"No encontrado"<<std::endl;
            }else{
                std::cout<<"Número: "<<arbol->Buscar(clave_buscar).num<<"\nInformación: "<<arbol->Buscar(clave_buscar).info<<std::endl;
            }
            // Llamar a la función de búsqueda e imprimir el resultado si se encuentra.
            // Puedes implementar la función de búsqueda en la clase Arbol.
        } else if (opcion == 2) {
            // Opción para eliminar un elemento.
            int clave_eliminar;
            std::cout << "Ingrese la clave a eliminar: ";
            std::cin >> clave_eliminar;
            std::cout<<"Se elimino: "<<arbol->Eliminar(clave_eliminar)<<std::endl;
            // Imprimir los recorridos después de la eliminación.
            std::cout << "Recorrido Inorden despues de eliminar:" << std::endl;
            s = arbol->inorden();
            while (!s.IsEmpty()) {
                Clave aux = s.Dequeue().clave;
                std::cout <<"Numero: " << aux.num << std::endl;
                std::cout <<"Informacion: "<< aux.info << std::endl;
            }

            std::cout << "Recorrido Preorden despues de eliminar:" << std::endl;
            s = arbol->preorden();
            while (!s.IsEmpty()) {
                Clave aux = s.Dequeue().clave;
                std::cout <<"Numero: " << aux.num << std::endl;
                std::cout <<"Informacion: "<< aux.info << std::endl;
            }

            std::cout << "Recorrido PosOrden despues de eliminar:" << std::endl;
            s = arbol->posorden();
            while (!s.IsEmpty()) {
                Clave aux = s.Dequeue().clave;
                std::cout <<"Numero: " << aux.num << std::endl;
                std::cout <<"Informacion: "<< aux.info << std::endl;
            }

            std::cout << "Recorrido por Niveles después de eliminar:" << std::endl;
            s = arbol->recorridoNiveles();
            while (!s.IsEmpty()) {
                Clave aux = s.Dequeue().clave;
                std::cout <<"Numero: " << aux.num << std::endl;
                std::cout <<"Informacion: "<< aux.info << std::endl;
            }

            std::cout << "----------------------------------------" << std::endl;
        } else if (opcion == 3) {
            break; // El usuario desea salir.
        } else {
            std::cout << "Opcion no valida. Intente de nuevo." << std::endl;
        }
    }

    return 0;
}