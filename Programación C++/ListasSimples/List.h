//
// Created by Alejandro Penagos on 13/10/2023.
//

#ifndef UNTITLED_LIST_H
#define UNTITLED_LIST_H
#include <iostream>
template <class T>
struct Node
{
    T data;
    Node<T> *next;
};

template <class T>
class List
{
private:
    Node<T> *header, *z, *sentinel;
    int size;

public:
    explicit List()
    {
        header = new Node<T>;
        z = new Node<T>;
        sentinel = NULL;
        size = 0;

        header->next = z;
        z->next = z;

        header->data = T();
        z->data = T();
    }
    /*
    virtual ~List()
    {
        Node<T> *temp = header;

        while (temp != z)
        {
            header = temp;
            temp = temp->next;
            delete header;
        }
        delete z;
    }
    */

    int getSize();
    void addDirectly(T newData);
    void addFirst(T newData);
    void addLast(T newData);
    void addPos(T newData, int pos);
    void revomePos(int pos);
    void removeData(T data);
    void setPos(int pos, T newData);
    void setData(T data, T newData);
    T getData(int pos);
};

template <class T>
int List<T>::getSize() { return size; }

template <class T>
void List<T>::addFirst(T newData)
{
    Node<T> *newNode, *aux;
    newNode = new Node<T>;
    newNode->data = newData;

    aux = header->next;
    header->next = newNode;
    newNode->next = aux;

    sentinel = (newNode->next == z) ? newNode : sentinel; // Operador ternario, hace lo mismo que un if
    size++;
}

template <class T>
void List<T>::addLast(T newData)
{
    Node<T> *newNode, *aux;
    newNode = new Node<T>;
    newNode->data = newData;

    if (sentinel == NULL)
    {
        addFirst(newData);
        size--;
    }
    else
    {
        aux = sentinel->next;
        sentinel->next = newNode;
        newNode->next = aux;

        sentinel = newNode;
    }
    size++;
}

template <class T>
void List<T>::addDirectly(T newData)
{
    Node<T> *newNode, *temp, *aux;

    newNode = new Node<T>;
    newNode->data = newData;

    temp = header;

    while (temp->next != z && temp->next->data <= newData)
        temp = temp->next;

    aux = temp->next;
    temp->next = newNode;
    newNode->next = aux;

    sentinel = (newNode->next == z) ? newNode : sentinel;
    size++;
}

template <class T>
T List<T>::getData(int pos)
{
    Node<T> *temp = header->next;
    for (int i = 1; i < pos; i++)
        temp = temp->next;

    return temp->data;
}

template <class T>
void List<T>::setPos(int pos, T newData)
{
    Node<T> *temp = header->next;

    for (int i = 1; i < pos; i++)
        temp = temp->next;

    temp->data = newData;
}

template <class T>
void List<T>::addPos(T newData, int pos)
{
    Node<T> *newNode, *temp, *aux;

    newNode = new Node<T>;
    newNode->data = newData;

    temp = header->next;

    for (int i = 1; i < pos - 1; i++)
        temp = temp->next;

    aux = temp->next;
    temp->next = newNode;
    newNode->next = aux;

    sentinel = (newNode->next == z) ? newNode : sentinel;
    size++;
}

template <class T>
void List<T>::revomePos(int pos)
{
    Node<T> *temp, *aux, *deleted;
    temp = header;

    for (int i = 1; i < pos; i++)
        temp = temp->next;

    aux = temp->next->next;
    deleted = temp->next;
    temp->next = aux;

    delete deleted;
    size--;
}

template <class T>
void List<T>::setData(T data, T newData)
{
    Node<T> *temp;

    temp = header->next;
    while (temp->next != z && temp->data != data)
    {
        if (temp->data != data)
        {
            temp = temp->next;
        }
        else
        {
            break;
        }
    }
    temp->data = newData;
}

template <class T>
void List<T>::removeData(T data)
{
    Node<T> *temp, *aux, *deleted;

    temp = header->next;
    while (temp->next != z && temp->next->data != data)
    {
        if (temp->data != data)
        {
            temp = temp->next;
        }
        else
        {
            break;
        }
    }
    aux = temp->next->next;
    deleted = temp->next;
    temp->next = aux;

    delete deleted;
    size--;
}
#endif // UNTITLED_LIST_H
