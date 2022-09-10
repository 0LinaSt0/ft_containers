/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsSet.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:58:29 by marvin            #+#    #+#             */
/*   Updated: 2022/09/10 20:23:10 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tests_hpp/testsSet.hpp"

namespace ft{

	template <class ft_set, class std_set>
		void	memberTestsSet(ft_set &my_set, std_set &orig_set,
								ft_set &my_tmp, std_set &orig_tmp){
			constructorsCheckSet(my_tmp, orig_tmp);
			insertCheckSet(my_set, orig_set, my_tmp, orig_tmp);
			eraseCheckSet(my_set, orig_set);
			beginCheckSet(my_set, orig_set);
			endCheckSet(my_set, orig_set);
			rbeginCheckSet(my_set, orig_set);
			rendCheckSet(my_set, orig_set);
			findCheckSet(my_set, orig_set);
			countCheckSet(my_set, orig_set, my_tmp, orig_tmp);
			lower_boundCheckSet(my_set, orig_set);
			upper_boundCheckSet(my_set, orig_set);
			equal_rangeCheckSet(my_set, orig_set);
			clearCheckSet(my_set, orig_set);
			swapCheckSet(my_set, orig_set, my_tmp, orig_tmp);
		}

	template <class ft_set, class std_set>
		void	checkerForSet(ft_set &my_set, std_set &orig_set,
								ft_set &my_tmp, std_set &orig_tmp){
			stdout_result("Member_functions: ", colors::yellow);
			std::cout << std::endl;
			memberTestsSet(my_set, orig_set, my_tmp, orig_tmp);
			stdout_result("Compare_sets: ", colors::yellow);
			std::cout << std::endl;
			compareCheckSets(my_set, orig_set, my_tmp, orig_tmp);
			stdout_result("Iterators'_operators: ", colors::yellow);
			std::cout << std::endl;
			iteratorsCheckSets(my_set, orig_set);
			stdout_result("Compare_iterators: ", colors::yellow);
			std::cout << std::endl;
			compareCheckItersSets(my_set, orig_set);
			stdout_result("RevIterators'_operators: ", colors::yellow);
			std::cout << std::endl;
			revIteratorsCheckSets(my_set, orig_set);
			stdout_result("Compare_revIterators: ", colors::yellow);
			std::cout << std::endl;
			compareCheckRevItersSets(my_set, orig_set);
		}

	void	setChecker(valueType key_type){
		iterator::iter = 1;
		tmpSets	tmp_sets;

		if (key_type == STRING){
			ft::set<std::string>	my_set_str;
			std::set<std::string>	orig_set_str;

			std::string	str = "hoy";
			char c = 'A';

			for (int i = 0;
					i < factor;
					i++){
				my_set_str.insert(str);
				orig_set_str.insert(str);
				if (c == '~'){
					c = 'A';
					str.erase(str.begin()+1, str.begin()+3);
				}
				str += c;
				c++;
			}

			checkerForSet(my_set_str, orig_set_str,
							tmp_sets.getFtStringSet(),
							tmp_sets.getStdStringSet());
		} else if (key_type == CHAR) {
			ft::set<char>	my_set_char;
			std::set<char>	orig_set_char;

			for (char i = 0; (i < 64 && i < factor); i++){
				my_set_char.insert(i);
				orig_set_char.insert(i);
			}

			checkerForSet(my_set_char, orig_set_char,
							tmp_sets.getFtCharSet(),
							tmp_sets.getStdCharSet());
		} else if (key_type == INT) {
			ft::set<int>	my_set_int;
			std::set<int>	orig_set_int;

			for (int i = 0;
					i < 1073741824 && i < factor;
					i++){
				my_set_int.insert(i);
				orig_set_int.insert(i);
			}

			checkerForSet(my_set_int, orig_set_int,
							tmp_sets.getFtIntSet(),
							tmp_sets.getStdIntSet());
		} else {
			std::cout << "error: please, give me STRING, CHAR or INT type"
							<< std::endl;
		}
	}

}
