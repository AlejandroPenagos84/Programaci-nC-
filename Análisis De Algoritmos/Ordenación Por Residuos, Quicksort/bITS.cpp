#include <iostream>
#include <Windows.h>
#include <time.h> 

using namespace std;

unsigned bits(int x, int k, int j)
{
	return(x>>k)&~(~0<<j);
}

int main(){
	cout<<bits(8,3,1);
}
