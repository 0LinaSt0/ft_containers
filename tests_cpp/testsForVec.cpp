/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsForVec.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:36:43 by msalena           #+#    #+#             */
/*   Updated: 2022/07/16 23:13:59 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tests_hpp/testsVec.hpp"



void	checkVecConstructors(){
		{/* <<<<<<<<<<<<<<< Tests for constructor_iterator >>>>>>>>>>>>>>>*/
			ft::vector<std::string>	vec(3, "Hola");

			std::cout << "example # 1 constructor_val" << std::endl;
			/*status*/printVecParams(vec, false);
							/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */

			/* <<<<<<<<<<<<<<< Tests for constructor_iterator >>>>>>>>>>>>>>>*/
			ft::vector<char>	vec1(0);
			vec1.push_back('a');
			vec1.push_back('b');
			vec1.push_back('v');
			vec1.push_back('g');

			ft::vector<char>	vec11(vec1.begin(),( vec1.end() - 1));

			std::cout << "example # 2 constructor_iterators" << std::endl;
			/*status*/printVecParams(vec11, false);
							/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */

			/* <<<<<<<<<<<<<<< Tests for constructor_iterator >>>>>>>>>>>>>>>*/
				ft::vector<int>	vec2(3, 5);
				ft::vector<int>	vec21(vec2);

				std::cout << "example # 3 constructor_copy" << std::endl;
				/*status*/printVecParams(vec21, false);
							/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */

		}
			std::cout << "\n\n~~~~~~~~~~~~~~ORIGINAL~~~~~~~~~~~~~~" << std::endl;
		{
			/* <<<<<<<<<<<<<<< Tests for constructor_iterator >>>>>>>>>>>>>>>*/
			std::vector<std::string>	vec(3, "Hola");

			std::cout << "example # 1 constructor_val" << std::endl;
			/*status*/printVecParams(vec, false);
							/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */

			/* <<<<<<<<<<<<<<< Tests for constructor_iterator >>>>>>>>>>>>>>>*/
			std::vector<char>	vec1(0);
			vec1.push_back('a');
			vec1.push_back('b');
			vec1.push_back('v');
			vec1.push_back('g');

			std::vector<char>	vec11(vec1.begin(), (vec1.end() - 1));

			std::cout << "example # 2 constructor_iterators" << std::endl;
			/*status*/printVecParams(vec11, false);
							/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */

			/* <<<<<<<<<<<<<<< Tests for constructor_iterator >>>>>>>>>>>>>>>*/
				std::vector<int>	vec2(3, 5);
				std::vector<int>	vec21(vec2);

				std::cout << "example # 3 constructor_copy" << std::endl;
				/*status*/printVecParams(vec21, false);
							/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */
		}
	}

void	checkerForVector(void){
	// checkConstructors();

	{
		std::cout << "\t~~~~~~~~~~~~~~MY_VECTOR~~~~~~~~~~~~~~" << std::endl;

		// ft::vector<int>	vector(3, 5);
		// ft::vector<std::string>	vec(5, "aboba");

		// ft::vector<char>	vec1(6, 'd');
		ft::vector<int>	vec1(10, 2);

		eraseCheck(vec1, false);

		/*~~~~Check_itertors~~~~*/
		// ft::vector<int>	vec;
		// ft::reverse_iterator<ft::vector<int>::iterator>	rev;
		// for(char i=0; i<10; i++){
		// 	vec.push_back(i);
		// }

		// ft::vector<char>	vec;
		// ft::reverse_iterator<ft::vector<char>::iterator>	rev;
		// for(char i='a'; i<'i'; i++){
		// 	vec.push_back(i);
		// }

		// /*status*/printVecParams(vec, false);
		// checkIterators(vec, rev);
		/*~~~~~~~~~~~~~~~~~~~~*/
	}
	{
		std::cout << "\n\n\t~~~~~~~~~~~~~~ORIG_VEC~~~~~~~~~~~~~~" << std::endl;
		// std::vector<char>	foo(5, 'a');
		// std::vector<std::string>	foo(5, "aboba");

			std::vector<int>	vec1(10, 2);

		eraseCheck(vec1, true);
		/*~~~~Check_itertors~~~~*/
		// std::vector<int>	myvec(5, 5);
		std::vector<int>	vector;
		// // std::reverse_iterator<std::vector<int>::iterator>	rev;
		// for(char i=0; i<10; i++){
		// 	vec.push_back(i);
		// }

		// std::vector<int>::iterator	myvecBeg(myvec.begin());
		// std::vector<int>::iterator	myvecEnd(myvec.end());


		// printVecParams(vec, true);

		// vec.insert(vec.begin(), myvecBeg, myvecEnd);
		// printVecParams(vec, true);

		// std::vector<char>	vec;
		// std::reverse_iterator<std::vector<char>::iterator>	rev;
		// for(char i='a'; i<'i'; i++){
		// 	vec.push_back(i);
		// }

		// /*status*/printVecParams(vec, true);
		// checkIterators(vec, rev);
		/*~~~~~~~~~~~~~~~~~~~~*/

		// std::vector<char>	foo1(6, 'd');
		// // std::vector<int>	foo1(3, 'd');

		// printVecParams(foo, true);

	}
}


