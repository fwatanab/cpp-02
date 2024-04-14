#include "Fixed.hpp"

// default construct
Fixed::Fixed() : value(0) {}

// int construct
Fixed::Fixed(const int nbr) : value(nbr << fractionalBits) {}

// float construct
Fixed::Fixed(const float nbr) : value(roundf(nbr * (1 << fractionalBits))) {}

// default destruct
Fixed::~Fixed() {}

// copy construct
Fixed::Fixed(const Fixed& other) : value(other.value) {}

// copy assignment operator
Fixed&	Fixed::operator=(const Fixed& other) {
	if (this != &other)
		this->value = other.value;
	return *this;
}

float	Fixed::toFloat() const {
	return static_cast<float>(value) / (1 << fractionalBits);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& num) {
	os << num.toFloat();
	return os;
}

bool	Fixed::operator<(const Fixed& other) const {
	return value < other.value;
}

bool	Fixed::operator>(const Fixed& other) const {
	return value > other.value;
}

bool	Fixed::operator<=(const Fixed& other) const {
	return value <= other.value;
}

bool	Fixed::operator>=(const Fixed& other) const {
	return value >= other.value;
}

bool	Fixed::operator==(const Fixed& other) const {
	return value == other.value;
}

bool	Fixed::operator!=(const Fixed& other) const {
	return value != other.value;
}

Fixed	Fixed::operator+(const Fixed& other) const {
	return (static_cast<float>(value) + other.value) / (1 << fractionalBits);
}

Fixed	Fixed::operator-(const Fixed& other) const {
	return (static_cast<float>(value) - other.value) / (1 << fractionalBits);
}

Fixed	Fixed::operator*(const Fixed& other) const {
	return (static_cast<float>(value) * static_cast<float>(other.value) / (1 << (2 * fractionalBits)));
}

Fixed	Fixed::operator/(const Fixed& other) const {
	return (static_cast<float>(value) / static_cast<float>(other.value) / (1 << fractionalBits));
}

Fixed	Fixed::operator++() {
	this->value++;
	return *this;
}

Fixed	Fixed::operator--() {
	this->value--;
	return *this;
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp = *this;
	++(*this);
	return tmp;
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp = *this;
	--(*this);
	return tmp;
}

const Fixed&	Fixed::min(const Fixed& num1, const Fixed& num2) {
	if (num1.value > num2.value)
		return num2;
	return num1;
}

const Fixed&	Fixed::max(const Fixed& num1, const Fixed& num2) {
	if (num1.value < num2.value)
		return num2;
	return num1;
}
