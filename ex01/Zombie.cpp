
#include "Zombie.hpp"

Zombie::Zombie() : name("") {}

Zombie::Zombie(std::string n) : name(n) {}

Zombie::~Zombie() {}

void Zombie::setName(const std::string &name)
{
    this->name = name;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}