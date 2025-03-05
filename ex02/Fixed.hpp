/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:55:09 by andmart2          #+#    #+#             */
/*   Updated: 2025/03/05 20:34:26 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
  private:
	int _fixedPoint;
	static const int _fractionalBits = 8;

  public:
	/*	DEFAULT CONSTRUCTOR	*/
	Fixed();

	/*	INT AND FLOAT CONSTRUCTOR	*/
	Fixed(const int val);
	Fixed(const float val);

	/*	COPY CONSTRUCTOR	*/
	Fixed(const Fixed &copy);

	/*	COPY ASSIGNMENT OPERATOR OVERLOAD	*/
	Fixed &operator=(const Fixed &other);

	/*	DESTRUCTOR	*/
	~Fixed();

	/*	MEMBER FUNCTIONS	*/
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	/*	COMPARISON OPERATORS MEMBER FUNCTIONS	*/
	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	/*	ARITHMETIC OPERATORS MEMBER FUNCTIONS	*/
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	/*	PRE AND POST INCREMENT/DECREMENT	*/
	Fixed operator++();
	Fixed operator++(int);
	Fixed operator--();
	Fixed operator--(int);

	/*	STATIC MEMBER FUNCTIONS	*/
	static Fixed &min(Fixed &f1, Fixed &f2);
	static const Fixed &min(const Fixed &f1, const Fixed &f2);
	static Fixed &max(Fixed &f1, Fixed &f2);
	static const Fixed &max(const Fixed &f1, const Fixed &f2);
};

/*	OVERLOAD OF INSERTION OPERATOR	*/
std::ostream &operator<<(std::ostream &os, const Fixed &dt);

#endif