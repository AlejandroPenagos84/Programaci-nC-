//Javier Alejandro Penagos Hernández   20221020028
//Laura Sofia Amado Gonzalez		   20212020034


#include <cstdlib>
#include <iostream>
using namespace std;

struct nodo {int x,y;
             nodo *sig;};


int main(int argc, char** argv) {
	
	nodo **arr, *Aux;
	int N, tam, j, i;
	
	cout<<"Escriba el valor de N ";
	cin>>N;
	cout<<"Escriba el valor de tam ";
	cin>>tam;
	
	int sumabytes = 4*sizeof(int)+N*sizeof(*arr)+N*(tam*sizeof(*Aux))+sizeof(Aux)+sizeof(arr);
	
	cout<<"La suma de los bytes es: "<<sumabytes<<"\n";	
	arr= new nodo *[N];
	for(i=0; i<N; i++)
		arr[i]=NULL;
	
	for(i=0; i<N; i++)
    {for(j=1; j<=tam; j++)
	 {Aux=new nodo;
	  Aux->x=j;
	  Aux->y=N+j*i;
	  Aux->sig = arr[i];
	  arr[i]= Aux; }	
	}
	
    for(i=0; i<N; i++)
	{Aux = arr[i];
	 cout<<"lista "<<i<<endl;
	 
	 while(Aux!=NULL)
		{cout<<Aux->x<<" "<<Aux->y<<endl;
	 	 Aux=Aux->sig; 
		}
	 for(Aux=arr[i]->sig; Aux!=NULL; Aux=Aux->sig) 
	     {delete arr[i];
		arr[i]=Aux; }
	
	delete arr[i];
	}
	
	delete []arr;
	
	system("PAUSE");
    return EXIT_SUCCESS;
	
}
