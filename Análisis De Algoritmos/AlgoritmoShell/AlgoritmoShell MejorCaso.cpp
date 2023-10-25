
#include <iostream>
#include <Windows.h>

using namespace std;


int *Llenar(int* a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = i+1;
    }
    return a;
}

int *ordenshell(int *a, int N) {
	
	int i, j, h;
	int v;
	
	//Calcular la secuencia de incrementos de Shell
	for(h=1; h<=N/9; h=3*h+1);
	
	for(;h>0; h/=3){
		
	    for(i=h; i<N; i++) {
		     v = a[i];
			 j = i;
			 
			while(j>h-1 && a[j-h]>v) {
			     a[j] = a[j-h];
			     j -= h;
		    }
	 
            a[j] = v;
        }
    }
    return a;
}

int main() {
	
	int *a, k;
	LARGE_INTEGER frequency;
    LARGE_INTEGER start, end;
	
    for (k = 100; k <= 10000; k += 50) {
    	
        a = new int[k];
        Llenar(a, k);
        
        /*
        cout << "Elementos para k = " << k << ": ";
        for (int i = 0; i < k; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        */
        
        QueryPerformanceFrequency(&frequency);
        
        QueryPerformanceCounter(&start);
        a = ordenshell(a, k);
        QueryPerformanceCounter(&end);
        
    	/*
        //Imprimir los elementos ordenados
        cout << "Elementos ordenados para k = " << k << ": ";
        for (int i = 0; i < k; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        */
        
        double segundos = static_cast<double>(end.QuadPart - start.QuadPart)/ frequency.QuadPart;
        cout << segundos << endl;
        
        delete[] a;
    }

    return 0;
	
}


