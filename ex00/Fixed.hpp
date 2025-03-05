/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:48:39 by andmart2          #+#    #+#             */
/*   Updated: 2025/03/05 20:31:05 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
  private:
	int _fixedPoint;
	static const int _fractionalBits = 8;

  public:
	/*	DEFAULT CONSTRUTCTOR: initilizes fixedPoint to 0	*/
	Fixed();

	/*	COPY CONSTRUCTOR	*/
	Fixed(Fixed &copy);

	/*	COPY ASSIGNMENT OPERATOR OVERLOAD	*/
	Fixed &operator=(const Fixed &other);

	/*	DESTRUCTOR	*/
	~Fixed();

	/*	MEMBER FUNCTIONS	*/
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif