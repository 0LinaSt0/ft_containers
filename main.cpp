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
#include "includes/tests_hpp/testsUtils.hpp"
// #include "includes/containers.hpp"
// #include "Lapa_tests/map_tests.hpp"
// #include <algorithm>
// #include <set>
// #include <iostream>

namespace ft{
	int main (void){
		// valueType	type = STRING;
		// valueType	type = CHAR;
		valueType	type = INT;
		checkerForVector(type);
		// checkerForStack();
		// checkForMap();

		// MAP_TESTS::RUN_MAP_TESTS();

		return (0);
	}
}



