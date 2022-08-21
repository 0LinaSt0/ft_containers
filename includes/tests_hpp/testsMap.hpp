/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsMap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:43:23 by msalena           #+#    #+#             */
/*   Updated: 2022/08/21 19:24:30 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_MAP_HPP
#define TESTS_MAP_HPP

#include "../map.hpp"
#include "../vector.hpp"
#include "testsVec.hpp"

void	checkForMap(void);


template < class map >
	void	printMap(map& objct){
		std::cout << "Map_size:" << objct.size()
					<< "   ->   empty_fl:" << std::boolalpha << objct.empty() 
					<< "   ->   max_size:" << objct.max_size() 
					<< std::endl;
		for (typename map::iterator it(objct.begin()); 
					it != objct.end();
					it++){
			std::cout << ((*it).first) << "  ";
		}
		std::cout << std::endl;
	}



#endif