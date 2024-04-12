#include "FixedPoint.hpp"

FixedPoint::FixedPoint() : value(0) {
	std::cout << "construct" << std::endl;
}

FixedPoint::~FixedPoint() {}

FixedPoint::FixedPoint(const FixedPoint& other) : value(other.value) {
	std::cout << "copy construct" << std::endl;
}

FixedPoint&	FixedPoint::operator=(const FixedPoint& other) {
	std::cout << "operator" << std::endl;
	return *this;
}
