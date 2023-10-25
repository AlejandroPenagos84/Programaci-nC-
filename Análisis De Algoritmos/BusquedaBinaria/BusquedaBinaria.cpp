#include<iostream>
#include <sstream>
#include <Windows.h>


using namespace std;

int busquedaBinaria(const int *arreglo, int tamano, int clave)
{
  int Iarriba = tamano-1;
  int Iabajo = 0;
  int Icentro;
  while (Iabajo <= Iarriba)
    {
      Icentro = (Iarriba + Iabajo)/2;
      if (arreglo[Icentro] == clave)
 			return Icentro;
      else
 if (clave < arreglo[Icentro])
   Iarriba=Icentro-1;
 else
   Iabajo=Icentro+1;
    }
  return -1;
}

int *Llenar(int* a,int n){
	for(int i=0;i<n;i++){
		a[i]=(i+1);
	}
	return a;
}

int main(int argc, char *argv[]) {
	LARGE_INTEGER frequency;
    LARGE_INTEGER start_time, end_time;
    

	
	int *arreglo;
	int r;
	
	for(int N = 10;N<=1000;N+=10){
	
		arreglo = new int[N];
		arreglo = Llenar(arreglo,N);
	
		QueryPerformanceFrequency(&frequency);
		
		QueryPerformanceCounter(&start_time);
		r = busquedaBinaria(arreglo,N,N);
		QueryPerformanceCounter(&end_time);
	
		double tiempo = static_cast<double>(end_time.QuadPart - start_time.QuadPart)/ frequency.QuadPart;
        cout<<tiempo<<endl;
		
		delete[]arreglo;
	}
	return 0;
}
