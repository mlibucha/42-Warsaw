/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlibucha <mlibucha@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:56:56 by e                 #+#    #+#             */
/*   Updated: 2025/12/10 14:06:44 by mlibucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <stdexcept>

template <typename T>
class Array {
private:
    T* _arr;
    std::size_t _size;

public:
    Array() : _arr(0), _size(0) {}

    explicit Array(std::size_t n) : _arr(0), _size(n) {
        if (_size == 0) {
            _arr = 0;
        } else {
            _arr = new T[_size]();
        }
    }

    Array(const Array& other) : _arr(0), _size(other._size) {
        if (_size == 0) {
            _arr = 0;
        } else {
            _arr = new T[_size]();
            for (std::size_t i = 0; i < _size; ++i) {
                _arr[i] = other._arr[i];
            }
        }
    }

    Array& operator=(const Array& other) {
        if (this != &other) {
            T* newArr = 0;
            if (other._size != 0) {
                newArr = new T[other._size]();
                for (std::size_t i = 0; i < other._size; i++) {
                    newArr[i] = other._arr[i];
                }
            }
            delete[] _arr;
            _arr = newArr;
            _size = other._size;
        }
        return *this;
    }

    ~Array() {
        delete[] _arr;
    }

    std::size_t size() const {
        return _size;
    }

    T& operator[](std::size_t idx) {
        if (idx >= _size) throw std::out_of_range("Array index out of bounds");
        return _arr[idx];
    }

    const T& operator[](std::size_t idx) const {
        if (idx >= _size) throw std::out_of_range("Array index out of bounds");
        return _arr[idx];
    }
};

#endif