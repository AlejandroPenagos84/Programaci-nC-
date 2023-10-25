//Javier Alejandro Penagos Hernández   20221020028
//Laura Sofia Amado Gonzalez		   20212020034
#include <iostream>

using namespace std;

int main(int argc, char** argv){
	
	int N, i, j, **a;
	
	cout<< "Ingresa el tamaño de el arreglo: ";
	cin>> N;
	
	int sumabytes = sizeof(a) + 3 * sizeof(int) + N*(N*sizeof(int))+sizeof(*a);
	cout<< "Total el numero de Bytes es: "<< sumabytes<<"\n";
	
	a =  new int *[N];
	
	for(i=0; i<N; i++){
		
		a[i] = new int [N];
		
		for(j=0;j<N; j++)
			a[i][j] = j * i;		
	}
		
	for(i=0; i<N; i++){
			
		for(j=0;j<N;j++)
			//cout<< a[i][j];
		delete a[i];	
	}
	
    delete []a;
	
	return 0;
}
	
