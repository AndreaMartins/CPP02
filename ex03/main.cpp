/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:58:55 by andmart2          #+#    #+#             */
/*   Updated: 2025/03/05 20:34:53 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

int	main(void)
{
	Point A(0, 0);
	Point B(4, 0);
	Point C(0, 4);
	Point P(1, 1);
	Point Q(-5, 10);

	if (bsp(A, B, C, P))
		std::cout << "Point P is inside triangle ABC." << std::endl;
	else
		std::cout << "Point P is outside triangle ABC." << std::endl;
	if (bsp(A, B, C, Q))
		std::cout << "Point P is inside triangle ABC." << std::endl;
	else
		std::cout << "Point P is outside triangle ABC." << std::endl;
	return (0);
}