//Integrantes: Javier Alejandro Penagos Hernández, Laura Sofia Amado Gonzalez
#include <iostream>
#include <Windows.h>
#include <stdlib.h> 
#include <time.h>

using namespace std;

void llenar(int *a, int N) {
	
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        a[i] = rand()% 41 + 10;//Llena el arreglo con números aleatorios
    }
}



int numDigitos(int a[], int N) {
	int max = 0;
	for (int i = 0; i < N; i++) {
		int cont = 0;
		int numero = a[i];
		
		if (numero == 0) {
			cont = 1;
		} else {
			while (numero != 0) {
				numero /= 10;
				cont++;
			}
		}
		
		if (cont > max) {
			max = cont;
		}
	}
	
	return max;
}

int obtenerDigitoRecursivo(int numero, int posicion) {
    if (posicion == 0) {
        return numero % 10;
    } else {
        return obtenerDigitoRecursivo(numero / 10, posicion - 1);
    }
}
	
	
void countSort(int *arr, int n, int exp)
{

    int output[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[obtenerDigitoRecursivo(arr[i], exp)]++;


    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];


    for (i = n - 1; i >= 0; i--) {
        output[count[obtenerDigitoRecursivo(arr[i], exp)] - 1] = arr[i];
        count[obtenerDigitoRecursivo(arr[i], exp)]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}				


void OrdenacionPorBase(int *a,int n){
	int max = numDigitos(a,n);
	
	for(int exp = 1; exp<=max;exp++){
		countSort(a,n,exp);
	}
}

int main(int argc, char *argv[]) {
	
	LARGE_INTEGER frequency;
    LARGE_INTEGER start, end;
    int *a;
	for(int N = 50; N<=50;N+=50){
		
		a = new int[N];
		
		llenar(a,N);
		for(int i = 0; i<N; i++){
			cout<<a[i]<<"-";
		}
		cout<<"\n\n\n";
		  
        QueryPerformanceFrequency(&frequency);    
        QueryPerformanceCounter(&start);
        
		OrdenacionPorBase(a,N);
		QueryPerformanceCounter(&end);
		
		
		for(int i = 0; i<N; i++){
			cout<<a[i]<<"-";
		}
		
		double segundos = static_cast<double>(end.QuadPart - start.QuadPart)/ frequency.QuadPart;
        cout << segundos << endl;
		delete []a;
	}
	
	
	return 0;

}

