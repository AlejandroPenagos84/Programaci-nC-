//Integrantes: Javier Alejandro Penagos Hernández, Laura Sofia Amado Gonzalez

#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>

void llenar(int a[], int N) {
	
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        a[i] = rand(); // Llena el arreglo con números aleatorios
    }
    
}

void MergeLists(int list[], int start1, int end1, int start2, int end2) {
	
    int finalStart = start1;
    int finalEnd = end2;
    int indexC = 0;
    int* result = new int[end2 - start1 + 1]; // Utiliza asignación dinámica

    while (start1 <= end1 && start2 <= end2) {
    	
        if (list[start1] < list[start2]) {
            result[indexC] = list[start1];
            start1++;
        } else {
            result[indexC] = list[start2];
            start2++;
        }
        indexC++;
        
    }

    while (start1 <= end1) {
    	
        result[indexC] = list[start1];
        start1++;
        indexC++;
        
    }

    while (start2 <= end2) {
    	
        result[indexC] = list[start2];
        start2++;
        indexC++;
        
    }

    indexC = 0;
    for (int i = finalStart; i <= finalEnd; i++) {
    	
        list[i] = result[indexC];
        indexC++;
        
    }

    delete[] result; // Libera la memoria asignada dinámicamente
}

void MergeSort(int list[], int first, int last) {
	
    if (first < last) {
        int middle = (first + last) / 2;
        MergeSort(list, first, middle);
        MergeSort(list, middle + 1, last);
        MergeLists(list, first, middle, middle + 1, last);
    }
    
}

int main() {
	
    int* arr;
    LARGE_INTEGER frequency;
    LARGE_INTEGER start, end;

    for (int k = 50; k <= 10000; k += 50) {
    	
        arr = new int[k];
        llenar(arr, k);

        /**std::cout << "Elementos para k = " << k << ": ";
        for (int i = 0; i < k; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;**/

        QueryPerformanceFrequency(&frequency);

        QueryPerformanceCounter(&start);
        MergeSort(arr, 0, k - 1); // Pasa el tamaño k directamente
        QueryPerformanceCounter(&end);

        /**std::cout << "Elementos ordenados para k = " << k << ": ";
        for (int i = 0; i < k; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;**/
        
        double segundos = static_cast<double>(end.QuadPart - start.QuadPart)/ frequency.QuadPart;
        //std::cout << "En K: " << k << " se demora: "<< segundos << std::endl;
        std::cout << segundos << std::endl;

        delete[] arr;
        
    }

    return 0;
}


