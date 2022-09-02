/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsForVec.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:36:43 by msalena           #+#    #+#             */
/*   Updated: 2022/09/03 00:09:15 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tests_hpp/testsVec.hpp"

namespace ft{

	template <class ft_vec, class std_vec>
		void	memberTests(ft_vec &my_vec, std_vec &orig_vec,
								ft_vec &my_tmp, std_vec &orig_tmp){
			assignCheck(my_vec, orig_vec, my_tmp, orig_tmp);
			push_backCheck(my_vec, orig_vec, my_tmp, orig_tmp);
			insertCheck(my_vec, orig_vec, my_tmp, orig_tmp);
			pop_backCheck(my_vec, orig_vec);
			eraseCheck(my_vec, orig_vec);
			// checkResize(my_vec, orig_vec);
			checkReserve(my_vec, orig_vec);
			checkBegin(my_vec, orig_vec);
			checkEnd(my_vec, orig_vec);
			checkRbegin(my_vec, orig_vec);
			checkRend(my_vec, orig_vec);
			checkBegin(my_vec, orig_vec);
			checkAt(my_vec, orig_vec);
			checkFront(my_vec, orig_vec);
			checkBack(my_vec, orig_vec);
			clearChech(my_vec, orig_vec);
			swapCheck(my_vec, orig_vec, my_tmp, orig_tmp);
		}

	template <class ft_vec, class std_vec>
		void	checkerForVector(ft_vec &my_vec, std_vec &orig_vec,
									ft_vec &my_tmp, std_vec &orig_tmp){
			(void)my_vec;
			(void)orig_vec;
			stdout_result("Member_functions: ", colors::yellow);
			std::cout << std::endl;

			checkVecConstructors(my_tmp, orig_tmp);

			memberTests(my_vec, orig_vec, my_tmp, orig_tmp);
			stdout_result("Compare_vector: ", colors::yellow);
			std::cout << std::endl;
			checkCompareVectors(my_vec, orig_vec, my_tmp, orig_tmp);
			stdout_result("Iterators_operators: ", colors::yellow);
			std::cout << std::endl;
			checkIterators(my_vec, orig_vec);
			stdout_result("Compare_iterators: ", colors::yellow);
			std::cout << std::endl;
			checkCompareIters(my_vec, orig_vec);
			stdout_result("RevIterators_operators: ", colors::yellow);
			std::cout << std::endl;
			checkRevIterators(my_vec, orig_vec);
			stdout_result("Compare_revIterators: ", colors::yellow);
			std::cout << std::endl;
			checkCompareRevIters(my_vec, orig_vec);
		}



	void	vectorChecker(valueType type){
		tmpVectors	tmp_vecs;

		if (type == STRING){
			ft::vector<std::string>		my_vec_str(factor);
			std::vector<std::string>	orig_vec_str(factor);

			for (size_t i = 0; i < factor; i++){
				my_vec_str[i] = "siempre";
				orig_vec_str[i] = "siempre";
			}

			checkerForVector(my_vec_str, orig_vec_str,
								tmp_vecs.getFtStringVec(),
								tmp_vecs.getStdStringVec());
		} else if (type == CHAR) {
			ft::vector<char>	my_vec_char(factor);
			std::vector<char>	orig_vec_char(factor);

			for (size_t i = 0; i < factor; i++){
				my_vec_char[i] = 'g';
				orig_vec_char[i] = 'g';
			}

			checkerForVector(my_vec_char, orig_vec_char,
								tmp_vecs.getFtCharVec(),
								tmp_vecs.getStdCharVec());
		} else if (type == INT) {
			ft::vector<int>		my_vec_int(factor);
			std::vector<int>	orig_vec_int(factor);

			for (size_t i = 0; i < factor; i++){
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



