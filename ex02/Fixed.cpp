#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int nbr) : value(nbr << fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float nbr) : value(roundf(nbr * (1 << fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : value(other.value) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	if (this != &other)
	{
		this->value = other.value;
		std::cout << "Copy assignment operator called" << std::endl;
	}
	return *this;
}

float	Fixed::toFloat() const {
	std::cout << "toFloat function called" << std::endl;
	return static_cast<float>(value) / (1 << fractionalBits);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& num) {
	std::cout << "ostream operator<< function called" << std::endl;
	os << num.toFloat();
	return os;
}

bool	Fixed::operator<(const Fixed& other) const {
	std::cout << "operator< function called" << std::endl;
	return value < other.value;
}

bool	Fixed::operator>(const Fixed& other) const {
	std::cout << "operator> function called" << std::endl;
	return value > other.value;
}

bool	Fixed::operator<=(const Fixed& other) const {
	std::cout << "operator<= function called" << std::endl;
	return value <= other.value;
}

bool	Fixed::operator>=(const Fixed& other) const {
	std::cout << "operator>= function called" << std::endl;
	return value >= other.value;
}

bool	Fixed::operator==(const Fixed& other) const {
	std::cout << "operator== function called" << std::endl;
	return value == other.value;
}

bool	Fixed::operator!=(const Fixed& other) const {
	std::cout << "operator!= function called" << std::endl;
	return value != other.value;
}

Fixed	Fixed::operator+(const Fixed& other) const {
	std::cout << "operator+ function called" << std::endl;
	return (static_cast<float>(value) + other.value) / (1 << fractionalBits);
}

Fixed	Fixed::operator-(const Fixed& other) const {
	std::cout << "operator- function called" << std::endl;
	return (static_cast<float>(value) - other.value) / (1 << fractionalBits);
}

Fixed	Fixed::operator*(const Fixed& other) const {
	std::cout << "operator* function called" << std::endl;
	return (static_cast<float>(value) * static_cast<float>(other.value) / (1 << (2 * fractionalBits)));
}

Fixed	Fixed::operator/(const Fixed& other) const {
	std::cout << "operator/ function called" << std::endl;
	return (static_cast<float>(value) / static_cast<float>(other.value) / (1 << fractionalBits));
}

Fixed	Fixed::operator++() {
	std::cout << "pre-increment operator++ function called" << std::endl;
	this->value++;
	return *this;
}

Fixed	Fixed::operator--() {
	std::cout << "pre-decrement operator-- function called" << std::endl;
	this->value--;
	return *this;
}

Fixed	Fixed::operator++(int) {
	std::cout << "post-increment operator++ function called" << std::endl;
	Fixed	tmp = *this;
	++(*this);
	return tmp;
}

Fixed	Fixed::operator--(int) {
	std::cout << "post-decrement operator-- function called" << std::endl;
	Fixed	tmp = *this;
	--(*this);
	return tmp;
}

const Fixed&	Fixed::min(const Fixed& num1, const Fixed& num2) {
	std::cout << "min function called" << std::endl;
	if (num1.value > num2.value)
		return num2;
	return num1;
}

const Fixed&	Fixed::max(const Fixed& num1, const Fixed& num2) {
	std::cout << "max function called" << std::endl;
	if (num1.value < num2.value)
		return num2;
	return num1;
}
