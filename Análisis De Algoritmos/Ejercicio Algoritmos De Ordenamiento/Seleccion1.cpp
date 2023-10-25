//Javier Alejandro Penagos Hernández. 20221020028.
//Laura Sofia Amado Gonzalez. 20212020034.
#include <iostream>
#include <Windows.h>

using namespace std;

int *Llenar(int* a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = n - i;
    }
    return a;
}

int *Seleccion(int *a, int N) {
    int i, j, min;
    
    int temp;

    for (i = 0; i < N-1; i++) {
        min = i;
        for(j=i+1;j<N;j++){
        	if(a[j]<a[min])min=j;
		}
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    return a;   
}
    


int main() {

    int *arreglo;
    LARGE_INTEGER frequency;
    LARGE_INTEGER start_time, end_time;

    for (int N = 10; N <= 1000; N += 10) {

        arreglo = new int[N];
        arreglo = Llenar(arreglo, N);

        QueryPerformanceFrequency(&frequency);
		
        QueryPerformanceCounter(&start_time);
        arreglo = Seleccion(arreglo, N);
        QueryPerformanceCounter(&end_time);
		
        double tiempo = static_cast<double>(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
        cout<<tiempo << endl;

        delete[] arreglo;
    }
    return 0;
}

