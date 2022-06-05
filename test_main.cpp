/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:43:22 by msalena           #+#    #+#             */
/*   Updated: 2022/06/05 19:57:13 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vector.hpp"
#include "includes/vectorIterator.hpp"
#include <vector>
// #include <iostream>
// #include <string>
// #include <stddef.h>
// #include <memory>


int main (void){
	// int	i = 5;
	{
		// size_t	i=0;
		
		ft::vector<int>	vec(10, 5);
		// ft::vector<int>	ve2(vec);
		// ft::vector<int>	ve3(8, 1);


		std::cout << "VEC: ";
		for (ft::vector<int>::iterator	iter = vec.begin(); iter != vec.end(); iter++){
			std::cout << (*iter) << "   ";
		}
		// std::cout << std::endl;
		// std::cout << "VE2: " << ve2[0] << std::endl;
		// std::cout << "VE3: " << ve3[0] << std::endl;

		// std::cout << "\nsize: " << veca.size() << std::endl;
		// std::cout << "max_size: " << veca.max_size() << std::endl;
		
		// vec.resize(8, 1);
	}
	// 	std::cout << std::endl;
		std::cout << "~~~~~~~~~~~~~~ORIGINAL~~~~~~~~~~~~~~" << std::endl;
	{
	// 	// std::vector<int>::iterator	aaa;
	// 	// std::vector<int>::iterator	bbb;
		std::vector<int>	veca(16, 2);
		veca.reserve(20);
	// 	// std::vector<char>	vec(aaa, bbb); 
		std::vector<int>	ve2 (15, 3);

		std::cout << "BEFORE EQUEL: " << veca.capacity() << "   " << ve2.capacity() << std::endl;
		ve2 = veca;
		std::cout << "AFTER EQUEL: " << veca.capacity() << "   " << ve2.capacity() << std::endl;
		
		// for (size_t i=0; i < 19; i++){
		// 	std::cout << veca.size() << "     ";
		// 	veca.push_back(1);
		// }
	// 	std::cout << "VECA: " << veca[0] << std::endl;
	// 	// std::cout << "VEC: " << vec[0] << std::endl;
	// 	// std::cout << "VE2: " << ve2[0] << std::endl;

	// 	std::cout << "\nsize: " << veca.size() << std::endl;
	// 	std::cout << "max_size: " << veca.max_size() << std::endl;
	}

}
