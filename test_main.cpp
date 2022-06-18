/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:43:22 by msalena           #+#    #+#             */
/*   Updated: 2022/06/18 15:18:47 by msalena          ###   ########.fr       */
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

		// ft::vector<char>	vec2(5, 'a');
		// printVecParams(&vec2);
		// vec2.clear();
		// printVecParams(&vec2);
		// sizeNConstructor(&vec2);
		
	}
		std::cout << "\n\n~~~~~~~~~~~~~~ORIGINAL~~~~~~~~~~~~~~" << std::endl;
	{
		// std::vector<int>	vec1;
		// defaultConstructor(&vec1);
		
		// std::vector<char>	vec2(5, 'a');
		// std::cout << "myvector contains:";
		// 	for (unsigned i=0; i<vec2.size(); i++)
		// 		std::cout << ' ' << vec2[i];
		// 	std::cout << '\n';
		
		// printVecParams(&vec2);
		// vec2.erase (vec2.begin()+4);
		// vec2.clear();
		// printVecParams(&vec2);
		
		// sizeNConstructor(&vec2);
		std::vector<int> foo(500);
		std::vector<int> foo1(400);
		
		printVecParams(&foo);
		foo.swap(foo1);
		printVecParams(&foo);
	}

}
