#include <iostream>
#include "Queue.h"

int main()
{
  // Crear una cola doble vacía
  Queue<int> deque;

  deque.Enqueue(5, 'I');
  for (int i = 1; i <= deque.Size(); i++)
  {
    std::cout << deque.getDato(i) << std::endl;
  }

  deque.Enqueue(10, 'I');
  std::cout << std::endl;
  for (int i = 1; i <= deque.Size(); i++)
  {
    std::cout << deque.getDato(i) << "-";
  }

  std::cout << std::endl;
  deque.Enqueue(15, 'D');

  for (int i = 1; i <= deque.Size(); i++)
  {
    std::cout << deque.getDato(i) << "-";
  }

  std::cout << std::endl;
  deque.Dequeue('D');

  for (int i = 1; i <= deque.Size(); i++)
  {
    std::cout << deque.getDato(i) << "-";
  }
  return 0;
}
