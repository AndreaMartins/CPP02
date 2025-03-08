/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:58:55 by andmart2          #+#    #+#             */
/*   Updated: 2025/03/08 21:08:18 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(5, 10);
    
    Point inside(5, 5);
    Point outside(30, 5);
    Point onEdge(5, 0);
    Point vertex (0, 0);   
    
    std::cout << "Inside: " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Outside: " << bsp(a, b, c, outside) << std::endl;
    std::cout << "On edge: " << bsp(a, b, c, onEdge) << std::endl;
    std::cout << "Vertex: " << bsp(a, b, c, vertex) << std::endl;

    return 0; 
}