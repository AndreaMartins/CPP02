/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:59:45 by andmart2          #+#    #+#             */
/*   Updated: 2025/03/05 20:34:45 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	_fixedPoint = 0;
}

Fixed::Fixed(const int val)
{
	// std::cout << "Int constructor called" << std::endl;
	_fixedPoint = val << _fractionalBits;
}
Fixed::Fixed(const float val)
{
	// std::cout << "Float constructor called" << std::endl;
	_fixedPoint = roundf(val * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed &copy)
{
	// std::cout << "Copy constructor called" << std::endl;
	_fixedPoint = copy.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_fixedPoint = other.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (_fixedPoint);
}

void Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPoint = raw;
}

float Fixed::toFloat(void) const
{
	// std::cout << "Float constructor called" << std::endl;
	return ((float)_fixedPoint / (float)(1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
	// std::cout << "Int constructor called" << std::endl;
	return (_fixedPoint >> _fractionalBits);
}

/*	COMPARISON OPERATORS MEMBER FUNCTIONS	*/
bool Fixed::operator>(const Fixed &other) const
{
	return (_fixedPoint > other.getRawBits());
}

bool Fixed::operator<(const Fixed &other) const
{
	return (_fixedPoint < other.getRawBits());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (_fixedPoint >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (_fixedPoint <= other.getRawBits());
}

bool Fixed::operator==(const Fixed &other) const
{
	return (_fixedPoint == other.getRawBits());
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (_fixedPoint != other.getRawBits());
}

/*	ARITHMETIC OPERATORS MEMBER FUNCTIONS	*/
Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result = this->toFloat() + other.toFloat();
	return (result);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result = this->toFloat() - other.toFloat();
	return (result);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result = this->toFloat() * other.toFloat();
	return (result);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed result = this->toFloat() / other.toFloat();
	return (result);
}

/*	PRE AND POST INCREMENT/DECREMENT	*/
Fixed Fixed::operator++()
{
	++_fixedPoint;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp;

	tmp = *this;
	_fixedPoint++;
	return (tmp);
}

Fixed Fixed::operator--()
{
	--_fixedPoint;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp;

	tmp = *this;
	_fixedPoint--;
	return (tmp);
}

/*	STATIC MEMBER FUNCTIONS	*/
Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	return (f1.toFloat() <= f2.toFloat() ? f1 : f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	return (f1.toFloat() <= f2.toFloat() ? f1 : f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	return (f1.toFloat() >= f2.toFloat() ? f1 : f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	return (f1.toFloat() >= f2.toFloat() ? f1 : f2);
}

/*	OVERLOAD OF INSERTION OPERATOR	*/
std::ostream &operator<<(std::ostream &out, const Fixed &val)
{
	return (out << val.toFloat());
}