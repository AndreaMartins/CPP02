/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:59:30 by andmart2          #+#    #+#             */
/*   Updated: 2025/03/08 21:07:06 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed orientation(Point const a, Point const b, Point const c) {
    return ((a.getX() - c.getX()) * (b.getY() - c.getY()) -
            (b.getX() - c.getX()) * (a.getY() - c.getY()));
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed o1 = orientation(point, a, b);
    Fixed o2 = orientation(point, b, c);
    Fixed o3 = orientation(point, c, a);

    return ((o1 > 0 && o2 > 0 && o3 > 0) || (o1 < 0 && o2 < 0 && o3 < 0));

}