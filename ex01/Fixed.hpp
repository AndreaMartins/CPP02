/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:51:14 by andmart2          #+#    #+#             */
/*   Updated: 2025/03/05 19:53:10 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int					_fixedPoint;
		static const int	_fractionalBits = 8;
	public:
		/*	CONSTRUCTORS	*/
		Fixed();
		Fixed(const int val);
		Fixed(const float val);
		
		/*	COPY CONSTRUCTOR	*/
		Fixed(const Fixed &copy);
		
		/*	COPY ASSIGNMENT OPERATOR OVERLOAD	*/
		Fixed& operator=(const Fixed &other);
		
		/*	DESTRUCTOR	*/
		~Fixed();
		
		/*	MEMBER FUNCTIONS	*/
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream& os, const Fixed& dt);

#endif