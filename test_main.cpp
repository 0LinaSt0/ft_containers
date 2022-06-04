/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:43:22 by msalena           #+#    #+#             */
/*   Updated: 2022/06/04 13:20:45 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/vector.hpp"
#include "includes/vectorIterator.hpp"
// #include <iostream>
// #include <string>
// #include <stddef.h>
// #include <memory>


int main (void){
	// int	i = 5;
	ft::vector<int>::iterator	aaa;
	ft::vector<int>::iterator	bbb;
	ft::vector<int>	veca(1, 5);
	ft::vector<char>	vec(aaa, bbb);
	
	(void) vec;
	
	// typename std::enable_if< !std::is_integral<std::string>::value, std::string >::type *ptr;
	// std::cout << ptr << std::endl;

}
