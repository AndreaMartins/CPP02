/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:59:57 by andmart2          #+#    #+#             */
/*   Updated: 2025/03/05 20:35:04 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
  private:
	const Fixed _x;
	const Fixed _y;

  public:
	Point();
	Point(const float x, const float y);
	/*	COPY CONSTRUCTOR	*/
	Point(const Point &copy);
	/*	COPY ASSIGNMENT OPERATOR OVERLOAD	*/
	Point &operator=(const Point &other);

	const Fixed getX() const;
	const Fixed getY() const;

	~Point();
};

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif