#include "fixed.hpp"
#include <iostream>

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj) : _value(obj._value)
{
    std::cout << "copy CONSTRUCTOR are called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->_value = other._value;
    }
    return *this;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
if (raw < 0)
{ 
    std::cout << "Warning: negative value!" << std::endl;  
   
}
    this->_value = raw;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}