/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsVec.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:36:43 by msalena           #+#    #+#             */
/*   Updated: 2022/09/10 20:23:01 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tests_hpp/testsVec.hpp"

namespace ft{

	template <class ft_vec, class std_vec>
		void	memberTestsVec(ft_vec &my_vec, std_vec &orig_vec,
								ft_vec &my_tmp, std_vec &orig_tmp){
			constructorsCheckVec(my_tmp, orig_tmp);
			assignCheckVec(my_vec, orig_vec, my_tmp, orig_tmp);
			push_backCheckVec(my_vec, orig_vec, my_tmp, orig_tmp);
			insertCheckVec(my_vec, orig_vec, my_tmp, orig_tmp);
			pop_backCheckVec(my_vec, orig_vec);
			eraseCheckVec(my_vec, orig_vec);
			resizeCheckVec(my_vec, orig_vec);
			reserveCheckVec(my_vec, orig_vec);
			beginCheckVec(my_vec, orig_vec);
			checkEndVec(my_vec, orig_vec);
			rbeginCheckVec(my_vec, orig_vec);
			rendCheckVec(my_vec, orig_vec);
			atCheckVec(my_vec, orig_vec);
			frontCheckVec(my_vec, orig_vec);
			backCheckVec(my_vec, orig_vec);
			clearChechVec(my_vec, orig_vec);
			swapCheckVec(my_vec, orig_vec, my_tmp, orig_tmp);
		}

	template <class ft_vec, class std_vec>
		void	checkerForVector(ft_vec &my_vec, std_vec &orig_vec,
									ft_vec &my_tmp, std_vec &orig_tmp){
			stdout_result("Member_functions: ", colors::yellow);
			std::cout << std::endl;
			memberTestsVec(my_vec, orig_vec, my_tmp, orig_tmp);
			stdout_result("Compare_vectors: ", colors::yellow);
			std::cout << std::endl;
			checkCompareVecs(my_vec, orig_vec, my_tmp, orig_tmp);
			stdout_result("Iterators'_operators: ", colors::yellow);
			std::cout << std::endl;
			checkIteratorsVecs(my_vec, orig_vec);
			stdout_result("Compare_iterators: ", colors::yellow);
			std::cout << std::endl;
			checkCompareItersVecs(my_vec, orig_vec);
			stdout_result("RevIterators'_operators: ", colors::yellow);
			std::cout << std::endl;
			checkRevIteratorsVecs(my_vec, orig_vec);
			stdout_result("Compare_revIterators: ", colors::yellow);
			std::cout << std::endl;
			checkCompareRevItersVecs(my_vec, orig_vec);
		}



	void	vectorChecker(valueType type){
		iterator::iter = 1;
		tmpVectors	tmp_vecs;

		if (type == STRING){
			ft::vector<std::string>		my_vec_str(factor);
			std::vector<std::string>	orig_vec_str(factor);

			for (int i = 0; i < factor; i++){
				my_vec_str[i] = "siempre";
				orig_vec_str[i] = "siempre";
			}

			checkerForVector(my_vec_str, orig_vec_str,
								tmp_vecs.getFtStringVec(),
								tmp_vecs.getStdStringVec());
		} else if (type == CHAR) {
			ft::vector<char>	my_vec_char(factor);
			std::vector<char>	orig_vec_char(factor);

			for (int i = 0; i < factor; i++){
				my_vec_char[i] = 'g';
				orig_vec_char[i] = 'g';
			}

			checkerForVector(my_vec_char, orig_vec_char,
								tmp_vecs.getFtCharVec(),
								tmp_vecs.getStdCharVec());
		} else if (type == INT) {
			ft::vector<int>		my_vec_int(factor);
			std::vector<int>	orig_vec_int(factor);

			for (int i = 0; i < factor; i++){
				my_vec_int[i] = i;
				orig_vec_int[i] = i;
			}

			checkerForVector(my_vec_int, orig_vec_int,
								tmp_vecs.getFtIntVec(),
								tmp_vecs.getStdIntVec());
		} else {
			std::cout << "error: please, give me STRING, CHAR or INT type"
							<< std::endl;
		}
	}

}



