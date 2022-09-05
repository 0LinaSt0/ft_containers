/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsForMap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 19:01:12 by msalena           #+#    #+#             */
/*   Updated: 2022/08/31 22:09:41 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tests_hpp/testsMap.hpp"

namespace ft{

	template <class ft_map, class std_map>
		void	memberTestsMap(ft_map &my_map, std_map &orig_map,
								ft_map &my_tmp, std_map &orig_tmp){
			constructorsCheckMap(my_tmp, orig_tmp);
			insertCheckMap(my_map, orig_map, my_tmp, orig_tmp);
			// eraseCheck(my_map, orig_map);
			// beginCheckMap(my_map, orig_map);
			// checkEndMap(my_map, orig_map);
			// rbeginCheckMap(my_map, orig_map);
			// rendCheckMap(my_map, orig_map);
			// atCheckMap(my_map, orig_map);
			// findCheckMap(my_map, orig_map);
			// countCheckMap(my_map, orig_map);
			// lower_boundCheckMap();
			// upper_boundCheckMap();
			// equal_boundCheckMap();
			// clearChechMap(my_map, orig_map);
			// swapCheckMap(my_map, orig_map, my_tmp, orig_tmp);
		}

	template <class ft_map, class std_map>
		void	checkerForMap(ft_map &my_map, std_map &orig_map,
								ft_map &my_tmp, std_map &orig_tmp){
			stdout_result("Member_functions: ", colors::yellow);
			std::cout << std::endl;
			memberTestsMap(my_map, orig_map, my_tmp, orig_tmp);
			// stdout_result("Compare_maps: ", colors::yellow);
			// std::cout << std::endl;
			// checkCompareMaps(my_map, orig_map, my_tmp, orig_tmp);
			// stdout_result("Iterators'_operators: ", colors::yellow);
			// std::cout << std::endl;
			// checkIteratorsMaps(my_map, orig_map);
			// stdout_result("Compare_iterators: ", colors::yellow);
			// std::cout << std::endl;
			// checkCompareItersMaps(my_map, orig_map);
			// stdout_result("RevIterators'_operators: ", colors::yellow);
			// std::cout << std::endl;
			// checkRevIteratorsMaps(my_map, orig_vec);
			// stdout_result("Compare_revIterators: ", colors::yellow);
			// std::cout << std::endl;
			// checkCompareRevItersMaps(my_map, orig_map);
		}

	void	mapChecker(valueType key_type){
		tmpMaps	tmp_maps;

		if (key_type == STRING){
			// ft::map<std::string, int>	my_map_str;
			// std::map<std::string, int>	orig_map_str;

			// std::string	str = "hoy";
			// char c = 'A';

			// for (int i = 0;
			// 		i < factor;
			// 		i++){
			// 	my_map_str[str] = int();
			// 	orig_map_str[str] = int();
			// 	if (c == '~'){
			// 		c = 'A';
			// 		str.erase(str.begin()+1, str.begin()+3);
			// 	}
			// 	str += c;
			// 	c++;
			// }

			// checkerForMap(my_map_str, orig_map_str,
			// 				tmp_maps.getFtStringMap(),
			// 				tmp_maps.getStdStringMap());
		} else if (key_type == CHAR) {
			ft::map<char, std::string>	my_map_char;
			std::map<char, std::string>	orig_map_char;

			for (char i = 0; (i < 64 && i < factor); i++){
				my_map_char[i] = std::string();
				orig_map_char[i] = std::string();
			}

			checkerForMap(my_map_char, orig_map_char,
							tmp_maps.getFtCharMap(),
							tmp_maps.getStdCharMap());
		} else if (key_type == INT) {
			ft::map<int, char>	my_map_int;
			std::map<int, char>	orig_map_int;

			for (int i = 0;
					i < 1073741824 && i < factor;
					i++){
				my_map_int[i] = char();
				orig_map_int[i] = char();
			}
			
			checkerForMap(my_map_int, orig_map_int,
							tmp_maps.getFtIntMap(),
							tmp_maps.getStdIntMap());
		} else {
			std::cout << "error: please, give me STRING, CHAR or INT type"
							<< std::endl;
		}
	}

}

