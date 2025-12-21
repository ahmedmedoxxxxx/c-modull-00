#include "Zombie.hpp"

int main ()
{
    Zombie *new_zombie = newZombie("foo");
    new_zombie->announce();
    randomChump ("foo");
    return (0);
}