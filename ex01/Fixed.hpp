#ifndef PIXED_HPP
#define PIXED_HPP

#include <iostream>

class	Fixed {
	private:
		int					value;
		static const int	fractionalBits = 8;
	public:
		Fixed();
		FIxed(int nbr);
		FIxed(float nbr);
		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& other);
		~Fixed();
		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat();
		int		toInt();
};

#endif
