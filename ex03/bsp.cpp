/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:59:30 by andmart2          #+#    #+#             */
/*   Updated: 2025/03/05 20:34:42 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed alpha;
	Fixed beta;
	Fixed gamma;
	Fixed denominator;

	denominator = (b.getY() - c.getY()) * (a.getX() - c.getX()) + (c.getX()
			- b.getX()) * (a.getY() - c.getY());
	alpha = ((b.getY() - c.getY()) * (point.getX() - c.getX()) + (c.getX()
				- b.getX()) * (point.getY() - c.getY())) / denominator;

	beta = ((c.getY() - a.getY()) * (point.getX() - c.getX()) + (a.getX()
				- c.getX()) * (point.getY() - c.getY())) / denominator;

	gamma = Fixed(1) - alpha - beta;

	return ((alpha >= Fixed(0)) && (beta >= Fixed(0)) && (gamma >= Fixed(0)));
}