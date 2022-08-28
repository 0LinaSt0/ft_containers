/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:43:22 by msalena           #+#    #+#             */
/*   Updated: 2022/08/28 10:33:15 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/tests_hpp/testsVec.hpp"
#include "includes/tests_hpp/testsStack.hpp"
#include "includes/tests_hpp/testsMap.hpp"
#include "includes/containers.hpp"
#include "Lapa_tests/map_tests.hpp"
#include <algorithm>
// #include <set>
// #include <iostream>

struct A{
	std::string a;
	A(std::string a){this->a = a;}
};

int main (void){

	// checkerForVector();
	// checkerForStack();
	checkForMap();

	// MAP_TESTS::RUN_MAP_TESTS();

}



