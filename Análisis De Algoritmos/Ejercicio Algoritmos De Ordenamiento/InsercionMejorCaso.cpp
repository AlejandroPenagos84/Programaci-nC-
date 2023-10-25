//Javier Alejandro Penagos Hernández. 20221020028.
//Laura Sofia Amado Gonzalez. 20212020034.
#include <iostream>
#include <Windows.h>

using namespace std;

int *Llenar(int* a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = i+1;
    }
    return a;
}

int *Insercion(int *a, int N) {
    int i, j, v;

    for (i = 1; i < N; i++) {
        v = a[i];
        j = i;
        while (j > 0 && a[j - 1] > v) {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = v;
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
        arreglo = Insercion(arreglo, N);
        QueryPerformanceCounter(&end_time);

        double tiempo = static_cast<double>(end_time.QuadPart - start_time.QuadPart) / frequency.QuadPart;
        cout << tiempo << endl;

        delete[] arreglo;
    }
    return 0;
}

