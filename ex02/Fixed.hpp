#ifndef PIXED_HPP
#define PIXED_HPP

#include <iostream>
#include <fstream>
#include <cmath>

class	Fixed {
	private:
		int					value;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		Fixed(int nbr);
		Fixed(float nbr);
		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& other);
		~Fixed();
		float	toFloat() const;
		bool	operator<(const Fixed& other) const;
		bool	operator>(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;
		Fixed	operator+(const Fixed& other) const;
		Fixed	operator-(const Fixed& other) const;
		Fixed	operator*(const Fixed& other) const;
		Fixed	operator/(const Fixed& other) const;
		Fixed	operator++();
		Fixed	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
		static const Fixed&	min(const Fixed& num1, const Fixed& num2);
		static const Fixed&	max(const Fixed& num1, const Fixed& num2);
		static Fixed&	min(Fixed& num1, Fixed& num2);
		static Fixed&	max(Fixed& num1, Fixed& num2);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& num);

#endif
