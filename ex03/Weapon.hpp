#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
    private:
        std::string type;
    
    public:
        Weapon(const std::string& type);
        const std::string& getType() const;
        void setType(const std::string& newType);
};

class HumanA
{
    private:
        std::string name;
        Weapon& weapon;
    
    public:
        HumanA(const std::string& name, Weapon& weapon);
        void attack() const;
};

class HumanB
{
    private:
        std::string name;
        Weapon* weapon;
    
    public:
        HumanB(const std::string& name);
        void setWeapon(Weapon& weapon);
        void attack() const;
};

#endif