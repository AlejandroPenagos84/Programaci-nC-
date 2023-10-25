//Integrantes: Javier Alejandro Penagos Hernández, Laura Sofia Amado Gonzalez

#include <iostream>
#include <Windows.h>
#include <stdlib.h> 
#include <time.h> 

using namespace std;


void llenar(int a[], int N) {
	
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        a[i] = rand(); //Llena el arreglo con números aleatorios
    }
}


void intercambio(int a[], int i, int j) {
	
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    
}


void ordenrapido(int a[], int izq, int der) {
	
    int i, j; int v;
    if (der> izq) {
    	
	    v= a[der]; 
		i=izq -1; 
		j=der;
        for(;;) {
		    while (a[++i] < v);
            while (a[--j] > v);
            if(i>=j) break;
            intercambio(a,i,j);
        }
        intercambio(a, i, der); 
        ordenrapido(a, izq, i-1);
        ordenrapido(a, i+1,der);
        
    }
    
}


int main() {
	
	int *a, k;
	LARGE_INTEGER frequency;
    LARGE_INTEGER start, end;
	
    for (k = 50; k <= 10000; k += 50) {
    	
    	
        a = new int[k];
        llenar(a, k);
        
        /**
        cout << "Elementos para k = " << k << ": ";
        
        for (int i = 0; i < k; i++) {
            cout << a[i] << " ";
        }
        cout << endl;**/
        
        
        QueryPerformanceFrequency(&frequency);
        
        QueryPerformanceCounter(&start);
        ordenrapido(a, 0, k - 1);
        QueryPerformanceCounter(&end);
        
        /**
        cout << "Elementos ordenados para k = " << k << ": ";
        for (int i = 0; i < k; i++) {
            cout << a[i] << " ";
        }
        cout << endl;**/
        
        
        double segundos = static_cast<double>(end.QuadPart - start.QuadPart)/ frequency.QuadPart;
        cout << segundos << endl;
        
        delete[] a;
    }

    return 0;
	
}


