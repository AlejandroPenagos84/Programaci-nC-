#include <iostream>
#include "ListaDoble.h"

int main(int argc, char **argv)
{
	DoubleLinkedList<int, std::string> est;

	est.AddDirectly(10, "Juan");
	est.AddDirectly(5, "Luis");
	est.AddDirectly(20, "Martha");
	est.AddDirectly(15, "Ana");
	est.AddDirectly(7, "Flor");
	est.AddDirectly(7, "Flor");
	est.AddDirectly(7, "Flor");
	est.AddDirectly(19, "Carlos");
	est.AddDirectly(20, "Martha");
	for (int i = 1; i <= est.Size(); i++)
	{
		std::cout << est.getCode(i) << "-";
		std::cout << est.getName(i) << std::endl;
	}

	std::cout << std::endl;

	est.SetNameCode(5, "Manuel");
	est.RemoveCode(7);
	est.RemovePos(2);
	for (int i = 1; i <= est.Size(); i++)
	{
		std::cout << est.getCode(i) << "-";
		std::cout << est.getName(i) << std::endl;
	}

	std::cout << std::endl;

	return 0;
}
