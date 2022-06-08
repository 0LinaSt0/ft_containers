/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:43:22 by msalena           #+#    #+#             */
/*   Updated: 2022/06/08 17:49:10 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vector.hpp"
#include "includes/vectorIterator.hpp"
#include <vector>
#include <iostream>
#include <string>
// #include <stddef.h>
#include <memory>

template <class T>
	void	printVecParams (T *vec){
		std::cout << "\nSTATUS\n"
				<< "	vecAddress: " << &(*vec) << "\n"
				<< "	count elem: " << vec->size() << "\n"
				<< "	capaxity size: " << vec->capacity() << "\n"
				<< "	emptyFlag: " << vec->empty()
				<< std::endl;
	}
template <class T>
	// TESTS FOR DEFAULTE CONSTRUCTOR
	void	defaultConstructor(T *vec){
		/*status*/printVecParams(vec);
		vec->reserve(16);
		(*vec)[20] = 3;
		/*status*/printVecParams(vec);
		std::cout << (*vec)[20] << std::endl;
	}

template <class T>
	// TESTS FOR CONSTRUCTOR WITH 'n' ELEMS
	void	sizeNConstructor(T *vec){
		/*status*/printVecParams(vec);
		vec->resize(4);
		/*status*/printVecParams(vec);
		vec->resize(10);
		/*status*/printVecParams(vec);
	}

int main (void){
	{
	}

	{
		// ft::vector<int>	vec1;
		// defaultConstructor(&vec1);

		ft::vector<char>	vec2(5, 'a');
		sizeNConstructor(&vec2);
		
	}
		std::cout << "\n\n~~~~~~~~~~~~~~ORIGINAL~~~~~~~~~~~~~~" << std::endl;
	{
		// std::vector<int>	vec1;
		// defaultConstructor(&vec1);
		
		std::vector<char>	vec2(5, 'a');
		sizeNConstructor(&vec2);
	}

}
