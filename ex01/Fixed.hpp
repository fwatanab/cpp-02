#ifndef PIXED_HPP
#define PIXED_HPP

#include <iostream>
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
		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat() const;
		int		toInt() const;
		friend	std::ostream& operator<<(std::ostream& os, const Fixed& num);
};

#endif
