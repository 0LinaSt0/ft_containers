/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:43:22 by msalena           #+#    #+#             */
/*   Updated: 2022/09/03 14:20:42 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/tests_hpp/testsVec.hpp"
#include "includes/tests_hpp/testsStack.hpp"
#include "includes/tests_hpp/testsMap.hpp"
// #include "includes/tests_hpp/testsUtidls.hpp"
#include "includes/containers.hpp"
// #include "Lapa_tests/map_tests.hpp"
// #include <algorithm>
// #include <set>
// #include <iostream>
#include <unistd.h>

namespace ft{
	void	print_preview(const std::string& outString, valueType type){
		std::cout << "\033[35m"
				<< "\t ~~~~~~~~~~~~TESTS_FOR_"
				<< outString;
		if (type == STRING){
			std::cout << "(STRING)~~~~~~~~~~~~";
		} else if (type == CHAR) {
			std::cout << "(CHAR)~~~~~~~~~~~~";
		} else {
			std::cout << "(INT)~~~~~~~~~~~~";
		}
		std::cout << "\033[0m \n" << std::endl;
	}
}
	int main (void){
		using namespace ft;
		// // valueType	type = STRING;
		valueType	type = CHAR;
		// // valueType	type = INT;
		print_preview("VECTOR", type);
		vectorChecker(type);
		// checkerForStack();
		// checkForMap();

		// MAP_TESTS::RUN_MAP_TESTS();


	}



