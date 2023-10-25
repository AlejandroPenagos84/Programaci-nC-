//Integrantes: Javier Alejandro Penagos Hernández, Laura Sofia Amado Gonzalez

#include <iostream>

using namespace std;

struct nodo { int x,y;
	            nodo *sig;
            };
             

int main(int argc, char** argv) {
	
	int N, i, j;
	    nodo *cab = NULL, *Aux;
	    
	    cout<< "Ingresa el tamano de el arreglo: ";
	    cin>> N;
	    
	    int sumabytes = N*(sizeof(nodo)) + 3*sizeof(int) + sizeof(Aux) + sizeof(cab);
        cout<< "Total el numero de Bytes es: "<< sumabytes<<"\n";
	    
	    for(i=0;i<N;i++) 
	    	{Aux = new nodo;
	    	Aux->x = i;
	    	Aux->y = N-i;
	    	Aux->sig = cab;
	    	cab = Aux;
		    }
		
		Aux = cab;
		while(Aux!=NULL)
			{cout<< Aux->x<< Aux->y<< endl;
			  Aux=Aux->sig;
		    }
		
		for(Aux=cab->sig; Aux!=NULL; Aux=Aux->sig)
			{delete cab;
			cab = Aux;
		    }
		
	return 0;	
	
}

