//Integrantes: Javier Alejandro Penagos Hernández, Laura Sofia Amado Gonzalez

#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	
	int N, i, j, *a;
	
	    cout<< "Ingresa el tamano de el arreglo: ";
	    cin>> N;
	    
	    int sumabytes = N * sizeof(int) + sizeof(a) + 3 * sizeof(int);
	    cout<< "Total el numero de Bytes es: "<< sumabytes<<"\n";
	    
		for(i=0;i<N;i++){
		    a = new int [N];
		    
		    for(j=0; j<N; j++){
			    a[j] = j*i;
			    cout<< a[j];
		    }
		    
			delete []a;	
	    }
	    
	return 0;
	
}

