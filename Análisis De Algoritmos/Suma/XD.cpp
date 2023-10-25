#include <iostream>
#include <vector>
#include <Windows.h>
#include <cstdlib>  // Necesario para rand() y srand()
#include <ctime>    // Necesario para time()
#include <fstream>
#include <string>

using namespace std;
// Función para llenar un vector con números aleatorios
void llenarVectorConRandom(vector<int> &vector, int n, int min_value, int max_value) {
    // Inicializar la semilla para los números aleatorios
    srand(static_cast<unsigned int>(time(0)));

    // Llenar el vector con números aleatorios
    for (int i = 0; i < n; i++) {
        int random_number = rand() % (max_value - min_value + 1) + min_value;
        vector.push_back(random_number);
    }
}
// Devuelve verdadero si existe una subsecuencia de `A[0…n]` con la suma dada
bool subsetSum(vector<int> const &A, int n, int k)
{
    // devuelve verdadero si la suma se convierte en 0 (subconjunto encontrado)
    if (k == 0) {
        return true;
    }
 
    // caso base: no quedan elementos o la suma se vuelve negativa
    if (n < 0 || k < 0) {
        return false;
    }
 
    // Caso 1. Incluir el elemento actual `A[n]` en el subconjunto y repetir
    // para los elementos restantes `n-1` con el total restante `k-A[n]`
    bool include = subsetSum(A, n - 1, k - A[n]);
 
    // Caso 2. Excluir el elemento actual `A[n]` del subconjunto y repetir para
    // los elementos restantes `n-1`
    bool exclude = subsetSum(A, n - 1, k);
 
    // devuelve verdadero si podemos obtener un subconjunto incluyendo o excluyendo el
    // elemento actual
    return include || exclude;
}
 
// Problema de suma de subconjuntos
int main()
{
    // Entrada: un conjunto de elementos y una suma
    vector<int> A;
    int k = 14;
 	LARGE_INTEGER frequency;
    LARGE_INTEGER start, end;
    // número total de elementos
    ofstream archivoSalida("tiempo4.txt",ios::out);
 	
    for(int i = 10; i<=1000000;i++){
    	llenarVectorConRandom(A,i,-100000,100000);
    	int n = A.size();
    	
    	QueryPerformanceFrequency(&frequency);
        
        QueryPerformanceCounter(&start);
    	subsetSum(A,n,k);
    	QueryPerformanceCounter(&end);
        
        /**
        cout << "Elementos ordenados para k = " << k << ": ";
        for (int i = 0; i < k; i++) {
            cout << a[i] << " ";
        }
        cout << endl;**/
        
        
        double segundos = static_cast<double>(end.QuadPart - start.QuadPart)/ frequency.QuadPart;
        cout << segundos << endl;
    	A.clear();
    	
    	archivoSalida << "Tamaño: "<<i <<", tiempo: "<< segundos << endl;       		
	}
	archivoSalida.close();
    return 0;
}
