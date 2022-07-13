/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   containers.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:07:27 by msalena           #+#    #+#             */
/*   Updated: 2022/07/13 21:10:10 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINERS_HPP
#define CONTAINERS_HPP

#include <iostream>
#include <string>
#include "vector.hpp"
namespace ft{
	template <class InputIterator1, class InputIterator2>
		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
							InputIterator2 first2, InputIterator2 last2);
									
	template <class InputIterator1, class InputIterator2, class Compare>
		bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2,
								Compare comp);
}


#endif