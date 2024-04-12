#ifndef PIXEDPOINT_HPP
#define PIXEDPOINT_HPP

#include <iostream>

class	FixedPoint {
	private:
		int	value;
		static const int	fractionalBits = 8;
	public:
		FixedPoint();
		FixedPoint(const FixedPoint& other);
		FixedPoint&	operator=(const FixedPoint& other);
		~FixedPoint();
};

#endif
