#include <iostream>
#include "Zombie.hpp"

int main(void)
{
    Zombie *heapLazyZombie;
    Zombie fasterZombie;

    heapLazyZombie = NULL;
    heapLazyZombie = heapLazyZombie->newZombie("Heap Lazy Zed");
    fasterZombie.randomChump("Faster Zed");
    delete heapLazyZombie;
    
    return 0;
}
