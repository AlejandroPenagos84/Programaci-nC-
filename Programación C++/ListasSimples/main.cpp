#include <iostream>
#include "List.h"
int main()
{
    List<int> list;

    list.addDirectly(2);
    list.addDirectly(2);
    list.addDirectly(1);
    list.addDirectly(15);
    list.addDirectly(8);
    list.addDirectly(5);
    std::cout << list.getSize();
    for (int i = 1; i <= list.getSize(); i++)
    {
        // std::cout << "I = " << i << std::endl;
        std::cout << list.getData(i) << "-";
    }
    return 0;
}
