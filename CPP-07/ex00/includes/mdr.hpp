/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mdr.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwong <fwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 16:33:36 by fwong             #+#    #+#             */
/*   Updated: 2023/11/22 19:23:26 by fwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MDR_HPP
# define MDR_HPP

#include <iostream>

template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
const T& min(const T& a, const T& b) {
    return (b < a) ? b : a;
}

template<typename T>
const T& max(const T& a, const T& b) {
    return (a > b) ? a : b;
}

#endif