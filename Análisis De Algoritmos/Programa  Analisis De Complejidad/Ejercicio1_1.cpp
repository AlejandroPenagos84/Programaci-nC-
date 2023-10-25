#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	
	int N, i, j, *a;
	
	    for(N=10;N<=300;N+=10){
	    
		    int sumabytes = N * sizeof(int) + sizeof(a) + 3 * sizeof(int);
		    cout<< sumabytes<<"\n";
		    
			for(i=0;i<N;i++){
			    a = new int [N];
			    
			    for(j=0; j<N; j++){
				    a[j] = j*i;
			    }
			    
				delete []a;	
		    }
		}
	return 0;
	
}
