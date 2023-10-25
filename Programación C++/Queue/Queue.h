#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <stdexcept>

template <class T>
struct Node
{
  T data;
  Node<T> *previous, *next;
};

template <class T>
class Queue
{
private:
  Node<T> *header, *z;
  int size;

public:
  Queue();
  int Size() { return size; };
  void Enqueue(T data, char adress);
  T Dequeue(char adress);
  T getDato(int pos);
  bool IsEmpty() { return header->next == z; }
};

template <class T>
Queue<T>::Queue()
{
  header = new Node<T>;
  z = new Node<T>;

  header->next = z;
  z->previous = header;

  z->next = z;
  size = 0;
}

template <class T>
void Queue<T>::Enqueue(T data, char adress)
{
  Node<T> *newNode, *temp, *aux;
  newNode = new Node<T>;
  newNode->data = data;

  if (adress == 'I')
  {
    aux = z->previous;

    z->previous = newNode;
    newNode->next = z;

    newNode->previous = aux;
    aux->next = newNode;
  }
  else if (adress == 'D')
  {
    aux = header->next;

    header->next = newNode;
    newNode->previous = header;

    newNode->next = aux;
    aux->previous = newNode;
  }
  size++;
}

template <class T>
T Queue<T>::getDato(int pos)
{
  if (pos < 1 || pos > size)
  {
    throw std::out_of_range("Posici√≥n inv√°lida.");
  }
  else
  {
    Node<T> *aux = header->next;
    for (int i = 1; i < pos; i++)
    {
      aux = aux->next;
    }

    return aux->data;
  }
}

template <class T>
T Queue<T>::Dequeue(char adress)
{
  Node<T> *temp, *aux;
  T data;
  if (header->next != z)
  {
    if (adress == 'I')
    {
       temp = z->previous;
      aux = temp->previous;
      data = temp->data;

      aux->next = z;
      z->previous = aux;

      delete temp;
    }
    else if (adress == 'D')
    {
      temp = header->next;
      aux = temp->next;
      data = temp->data;
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <stdexcept>

template <class T> struct Node {
  T data;
  Node<T> *previous, *next;
};

template <class T> class Queue {
private:
  Node<T> *header, *z;
  int size;

public:
  Queue();
  int Size() { return size; };
  void Enqueue(T data, char adress);
  T Dequeue(char adress);
  T getDato(int pos);
  bool IsEmpty() { return header->next == z; }
};

template <class T> Queue<T>::Queue() {
  header = new Node<T>;
  z = new Node<T>;

  header->data = T();

  header->next = z;
  z->previous = header;

  z->next = z;
  z->data = T();
  size = 0;
}

template <class T> void Queue<T>::Enqueue(T data, char adress) {
  Node<T> *newNode, *temp, *aux;
  newNode = new Node<T>;
  newNode->data = data;

  if (adress == 'I') {
    aux = z->previous;

    z->previous = newNode;
    newNode->next = z;

    newNode->previous = aux;
    aux->next = newNode;
  } else if (adress == 'D') {
    aux = header->next;

    header->next = newNode;
    newNode->previous = header;

    newNode->next = aux;
    aux->previous = newNode;
  }
  size++;
}

template <class T> T Queue<T>::getDato(int pos) {
  if (pos < 1 || pos > size) {
    throw std::out_of_range("PosiciÛn inv·lida.");
  } else {
    Node<T> *aux = header->next;
    for (int i = 1; i < pos; i++) {
      aux = aux->next;
    }

    return aux->data;
  }
}

template <class T> T Queue<T>::Dequeue(char adress) {
  Node<T> *temp, *aux;
  T data;
  if (header->next != z) {
    if (adress == 'I') {
      temp = header->next;
      aux = temp->next;
      data = temp->data;

      aux->previous = header;
      header->next = aux;

      delete temp;
    } else if (adress == 'D') {
      temp = z->previous;
      aux = temp->previous;
      data = temp->data;

      aux->next = z;
      z->previous = aux;

      delete temp;
    }
  }
  size--;
  return data;
}

#endif

      aux->previous = header;
      header->next = aux;

      delete temp;
    }
  }
  size--;
  return data;
}

#endif
