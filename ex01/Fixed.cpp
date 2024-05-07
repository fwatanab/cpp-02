#include "Fixed.hpp"

// default construct
Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

// int construct
Fixed::Fixed(const int nbr) : value(nbr << fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

// float construct
Fixed::Fixed(const float nbr) : value(roundf(nbr * (1 << fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

// default destruct
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// copy construct
Fixed::Fixed(const Fixed& other) : value(other.value) {
	std::cout << "Copy constructor called" << std::endl;
}

// copy assignment operator
Fixed&	Fixed::operator=(const Fixed& other) {
	if (this != &other)
	{
		this->value = other.value;
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return *this;
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "getRawBits member function called" << std::endl;
	value = raw;
}

float	Fixed::toFloat() const {
	return static_cast<float>(value) / (1 << fractionalBits);
}

int	Fixed::toInt() const {
	return value >> fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& num) {
	os << num.toFloat();
	return os;
}
