#include <iostream>
#include <Windows.h>
#include <time.h> 

using namespace std;

unsigned bits(int x, int k, int j)
{
	return(x>>k)&~(~0<<j);
}

void intercambio(int *a, int i, int j) {
	
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    
}

void llenar(int a[], int N) {
	
    srand(time(NULL));

    for (int i = 0; i < N; i++) {
        a[i] = rand();
    }
}

void cambiosResiduos(int *a, int izq, int der, int b)
{
	int i, j;
	if(der > izq && b>=0)
	{
		i = izq; j = der;
		while(j!=i)
		{
			while(!bits(a[i],b,1) && i<j) i++;
			while(bits(a[j],b,1) && j>i) j--;
			intercambio(a,i,j);
		}
		if(!bits(a[der],b,1))j++;
		
		cambiosResiduos(a,izq,j-1,b-1);
		cambiosResiduos(a,j,der,b-1);
	}
}

int main() {
	int *a, k;
	LARGE_INTEGER frequency;
    LARGE_INTEGER start, end;
	
    for (k = 50; k <= 10000; k += 50) {
    	
    	
        a = new int[k];
        llenar(a, k);
        
        QueryPerformanceFrequency(&frequency);

        QueryPerformanceCounter(&start);
        cambiosResiduos(a,0,k-1,32);
        QueryPerformanceCounter(&end);


        double segundos = static_cast<double>(end.QuadPart - start.QuadPart) / frequency.QuadPart;
        cout  << segundos <<endl;

        delete[] a;
    }

    return 0;
	
}
