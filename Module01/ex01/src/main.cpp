#include <iostream>
#include "zombie.hpp"
#include "zombieHorde.hpp"

int main(void)
{
    int quantity = 5;
    Zombie *heapLazyZombie;
    Zombie *buchOfZombies;

    randomChump("Fast Zed");
    buchOfZombies = zombieHorde(quantity, "Cabeca de vento");
    for (int idx = 0; idx < quantity; idx++)
        buchOfZombies[idx].announce();
    heapLazyZombie = newZombie("Heap Lazy Zed");
    delete heapLazyZombie;

    delete [] buchOfZombies;
    return 0;
}
