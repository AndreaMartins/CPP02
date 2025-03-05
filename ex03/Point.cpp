/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:59:53 by andmart2          #+#    #+#             */
/*   Updated: 2025/03/05 20:35:00 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
}

Point::Point(const Point &copy) : _x(copy.getX()), _y(copy.getY())
{
}

Point &Point::operator=(const Point &other)
{
	if (this != &other)
		std::cout << "Copy assignment error: cannot assign a constant variable" << std::endl;
	return (*this);
}

const Fixed Point::getX() const
{
	return (_x);
}

const Fixed Point::getY() const
{
	return (_y);
}

Point::~Point()
{
}