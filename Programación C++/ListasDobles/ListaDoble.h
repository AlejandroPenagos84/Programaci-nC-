#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#include <iostream>
#include <stdexcept>

template <class T, class S>
struct Node
{
	T code;
	S name;
	Node<T, S> *previous, *next;
};

template <class T, class S>
class DoubleLinkedList
{
private:
	Node<T, S> *header, *z;
	int size;

public:
	DoubleLinkedList();
	int Size();
	void AddDirectly(T code, S name);
	bool RemovePos(int pos);
	bool RemoveCode(T data);
	bool SetNameCode(T data, S newData);
	void SetNamePos(int pos, S data);
	T getCode(int pos);
	S getName(int pos);
};

template <class T, class S>
int DoubleLinkedList<T, S>::Size() { return size; }

template <class T, class S>
DoubleLinkedList<T, S>::DoubleLinkedList()
{
	header = new Node<T, S>;
	z = new Node<T, S>;

	// Asigna valores nulos a los campos code y name de header y z
	header->code = T();  // Asigna el valor nulo para el tipo T
	header->name = S();  // Asigna el valor nulo para el tipo S

	z->code = T();       // Asigna el valor nulo para el tipo T
	z->name = S();       // Asigna el valor nulo para el tipo S

	header->next = z;
	z->previous = header;

	z->next = NULL;  // Utiliza nullptr en lugar de NULL
	size = 0;
}

template <class T, class S>
void DoubleLinkedList<T, S>::AddDirectly(T code, S name)
{

	Node<T, S> *newNode, *temp, *aux;
	newNode = new Node<T, S>;
	newNode->code = code;
	newNode->name = name;

	temp = header;

	while (temp != z)
	{
		if(temp->code != T()){
			if(code < temp->code){
				break;
			}
		}
		temp = temp->next;		
	}

	aux = temp->previous;

	newNode->next = temp;
	newNode->previous = aux;

	aux->next = newNode;
	temp->previous = newNode;

	size++;
}

template <class T, class S>
T DoubleLinkedList<T, S>::getCode(int pos)
{
	if (pos < 1 || pos > size)
	{
		return -1;
		throw std::out_of_range("Invalid position.");
	}
	else
	{
		Node<T, S> *aux = header->next;
		for (int i = 1; i < pos; i++)
		{
			aux = aux->next;
		}

		return aux->code;
	}
}

template <class T, class S>
S DoubleLinkedList<T, S>::getName(int pos)
{
	S data;
	if (pos < 1 || pos > size)
	{
		throw std::out_of_range("Invalid position.");
	}
	else
	{
		Node<T, S> *aux = header->next;
		for (int i = 1; i < pos; i++)
			aux = aux->next;
		data = aux->name;
	}
	return data;
}

template <class T, class S>
bool DoubleLinkedList<T, S>::RemovePos(int pos)
{
	if (pos <= size)
	{
		Node<T, S> *temp, *aux, *aux1;

		temp = header->next;

		for (int i = 1; i < pos; i++)
			temp = temp->next;

		aux = temp->next;
		aux1 = temp->previous;

		aux1->next = aux;
		aux->previous = aux1;
		size--;

		delete temp;
		return true;
	}
	else
	{
		throw std::out_of_range("Invalid position.");
		return false;
	}
}

template <class T, class S>
bool DoubleLinkedList<T, S>::RemoveCode(T data)
{
	Node<T, S> *temp, *aux, *aux1;

	temp = header;

	while (temp != z && temp->code != data)
		temp = temp->next;

	if (temp == z)
	{
		return false;
	}
	else
	{
		aux = temp->next;
		aux1 = temp->previous;

		aux1->next = aux;
		aux->previous = aux1;
		size--;

		delete temp;
		return true;
	}
}

template <class T, class S>
void DoubleLinkedList<T, S>::SetNamePos(int pos, S data)
{
	if (pos < 1 || pos > size)
	{
		throw std::out_of_range("Invalid position.");
	}
	else
	{
		Node<T, S> *aux = header->next;
		for (int i = 1; i < pos; i++)
			aux = aux->next;
		aux->name = data;
	}
}

template <class T, class S>
bool DoubleLinkedList<T, S>::SetNameCode(T data, S newData)
{

	Node<T, S> *aux = header;
	while (aux != z && aux->code != data)
		aux = aux->next;

	if (aux == z)
	{
		return false;
	}
	else
	{
		aux->name = newData;
		return true;
	}
}
#endif
