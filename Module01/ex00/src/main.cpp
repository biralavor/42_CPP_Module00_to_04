#include <iostream>
#include "zombie.hpp"

int main(void)
{
    Zombie *heapLazyZombie;
    Zombie fasterZombie("Faster Zed");

    heapLazyZombie = newZombie("Heap Lazy Zed");
    delete heapLazyZombie;

    return 0;
}
