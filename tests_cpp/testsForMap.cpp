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
		void	memberTestsMap(ft_map &my_vec, std_map &orig_vec,
								ft_map &my_tmp, std_map &orig_tmp){
			checkConstructorsMap(my_tmp, orig_tmp);
			insertCheck(my_vec, orig_vec, my_tmp, orig_tmp);
			eraseCheck(my_vec, orig_vec);
			beginCheckMap(my_vec, orig_vec);
			checkEndMap(my_vec, orig_vec);
			rbeginCheckMap(my_vec, orig_vec);
			rendCheckMap(my_vec, orig_vec);
			atCheckMap(my_vec, orig_vec);
			findCheckMap(my_vec, orig_vec);
			countCheckMap(my_vec, orig_vec);
			lower_boundCheckMap();
			upper_boundCheckMap();
			equal_boundCheckMap();
			clearChechMap(my_vec, orig_vec);
			swapCheckMap(my_vec, orig_vec, my_tmp, orig_tmp);
		}

	template <class ft_map, class std_map>
		void	checkerForMap(ft_map &my_vec, std_map &orig_vec,
								ft_map &my_tmp, std_map &orig_tmp){
			stdout_result("Member_functions: ", colors::yellow);
			std::cout << std::endl;
			memberTestsMap(my_vec, orig_vec, my_tmp, orig_tmp);
			stdout_result("Compare_maps: ", colors::yellow);
			std::cout << std::endl;
			checkCompareMaps(my_vec, orig_vec, my_tmp, orig_tmp);
			stdout_result("Iterators'_operators: ", colors::yellow);
			std::cout << std::endl;
			checkIteratorsMaps(my_vec, orig_vec);
			stdout_result("Compare_iterators: ", colors::yellow);
			std::cout << std::endl;
			checkCompareItersMaps(my_vec, orig_vec);
			stdout_result("RevIterators'_operators: ", colors::yellow);
			std::cout << std::endl;
			checkRevIteratorsMaps(my_vec, orig_vec);
			stdout_result("Compare_revIterators: ", colors::yellow);
			std::cout << std::endl;
			checkCompareRevItersMaps(my_vec, orig_vec);
		}

	void	mapChecker(valueType key_type){
		tmpMaps	tmp_maps;

		if (key_type == STRING){
			ft::map<std::string, int>	my_map_str;
			std::map<std::string, int>	orig_map_str;

			std::string	str = "hoy";
			char c = 'A';

			for (size_t i = 0;
					i < factor;
					i++, c++){
				my_map_str[i] = str;
				orig_map_str[i] = str;
				if (c == '~') {
					c == 'A';
					str.erase(str.begin()+8, str.begin()+30)
				}
				str += c;
			}

			checkerForMap(my_map_str, orig_map_str,
							tmp_maps.getFtStringMap(),
							tmp_maps.getStdStringMap());
		} else if (key_type == CHAR) {
			ft::map<char, std::string>	my_map_char;
			std::map<char, std::string>	orig_map_char;

			for (char i = 0; (i < 64 && i < factor); i++){
				my_map_char[i] = i;
				orig_map_char[i] = i;
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
				my_map_int[i] = i;
				orig_map_int[i] = i;
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

