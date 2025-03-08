/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andmart2 <andmart2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:59:45 by andmart2          #+#    #+#             */
/*   Updated: 2025/03/08 21:07:30 by andmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const Fixed &fixed) {
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
    if (this != &fixed)
        this->_value = fixed.getRawBits();
    return *this;
}

Fixed::Fixed(const int value) {
    _value = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
    _value = roundf(value * (1 << _fractionalBits));
}

Fixed::~Fixed() {}

bool Fixed::operator>(const Fixed &fixed) const { 
    return _value > fixed._value;
}

bool Fixed::operator<(const Fixed &fixed) const {
    return _value < fixed._value;
}

bool Fixed::operator>=(const Fixed &fixed) const {
    return _value >= fixed._value;
}

bool Fixed::operator<=(const Fixed &fixed) const {
    return _value <= fixed._value;
}

bool Fixed::operator==(const Fixed &fixed) const {
    return _value == fixed._value;
}

bool Fixed::operator!=(const Fixed &fixed) const {
    return _value != fixed._value;
}

Fixed Fixed::operator+(const Fixed &fixed) const {
    return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) const {
    return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const {
    return Fixed(this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) const {
    return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++() {
    _value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp = *this;
    _value++;
    return tmp;
}

Fixed &Fixed::operator--() {
    _value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp = *this;
    _value--;
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a < b)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b)
        return a;
    return b;
}

int Fixed::getRawBits(void) const {
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
}

float Fixed::toFloat(void) const {
    return (float)_value /(1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _value >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}