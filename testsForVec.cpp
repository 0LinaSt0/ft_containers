/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsForVec.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:36:43 by msalena           #+#    #+#             */
/*   Updated: 2022/07/13 20:06:04 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/testsVec.hpp"

void	checkConstructors(){
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
	
}
	{
		std::cout << "\t~~~~~~~~~~~~~~MY_VECTOR~~~~~~~~~~~~~~" << std::endl;

		// ft::vector<char>	vec(5, 'a');
		// ft::vector<std::string>	vec(5, "aboba");
		
		// ft::vector<char>	vec1(6, 'd');
		// ft::vector<int>	vec1(3, 'd');

		
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

		// std::vector<int> v;
		// vec.assign(1100, 11);
		// ft::vector<int> tmp(500, 5), tmp2(1000, 10), tmp3(1500, 15), tmp4(3000, 30);
		// // g_start1 = timer();
		// v.push_back(vec[2]);
		// v.push_back(vec.size());
		// v.push_back(vec.capacity());
		// long *adr1 = reinterpret_cast<long *>(&vec);
		// long *adr2 = reinterpret_cast<long *>(&tmp);
		// vec.swap(tmp);
		// if (reinterpret_cast<long *>(&vec) == adr1 && reinterpret_cast<long *>(&tmp) == adr2)
		// 	v.push_back(1);
		// v.push_back(vec[2]);
		// v.push_back(vec.size());
		// v.push_back(vec.capacity());
		// vec.swap(tmp3);
		// v.push_back(vec[2]);
		// v.push_back(vec.size());
		// v.push_back(vec.capacity());
		// std::swap(vec, tmp2);
		// v.push_back(vec[2]);
		// v.push_back(vec.size());
		// v.push_back(vec.capacity());
		// std::swap(vec, tmp4);
		// // g_end1 = timer();
		// v.push_back(vec[2]);
		// v.push_back(vec.size());
		// v.push_back(vec.capacity());

		ft::vector<int>	myvec(5, 5);
		ft::vector<int>	vec;
		std::reverse_iterator<std::vector<int>::iterator>	rev;
		for(char i=0; i<10; i++){
			vec.push_back(i);
		}

		ft::vector<int>::iterator	myvecBeg(myvec.begin());
		ft::vector<int>::iterator	myvecEnd(myvec.end());


		printVecParams(vec, false);

		vec.insert(vec.begin(), myvecBeg, myvecEnd);
		printVecParams(vec, false);

		// /*status*/printVecParams(vec, false);

		
	}
	{
		std::cout << "\n\n\t~~~~~~~~~~~~~~ORIGINAL~~~~~~~~~~~~~~" << std::endl;
		// std::vector<char>	foo(5, 'a');
		// std::vector<std::string>	foo(5, "aboba");
		
		
		/*~~~~Check_itertors~~~~*/
		std::vector<int>	myvec(5, 5);
		std::vector<int>	vec;
		// std::reverse_iterator<std::vector<int>::iterator>	rev;
		for(char i=0; i<10; i++){
			vec.push_back(i);
		}

		std::vector<int>::iterator	myvecBeg(myvec.begin());
		std::vector<int>::iterator	myvecEnd(myvec.end());


		printVecParams(vec, true);

		vec.insert(vec.begin(), myvecBeg, myvecEnd);
		printVecParams(vec, true);

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

// ~~~~~~~~~~~~~~~~SWAAAAAAAAAP
		// std::vector<int> v;
		// vec.assign(1100, 11);
		// std::vector<int> tmp(500, 5), tmp2(1000, 10), tmp3(1500, 15), tmp4(3000, 30);
		// // g_start1 = timer();
		// v.push_back(vec[2]);
		// v.push_back(vec.size());
		// v.push_back(vec.capacity());
		// long *adr1 = reinterpret_cast<long *>(&vec);
		// long *adr2 = reinterpret_cast<long *>(&tmp);
		// vec.swap(tmp);
		// if (reinterpret_cast<long *>(&vec) == adr1 && reinterpret_cast<long *>(&tmp) == adr2)
		// 	v.push_back(1);
		// v.push_back(vec[2]);
		// v.push_back(vec.size());
		// v.push_back(vec.capacity());
		// vec.swap(tmp3);
		// v.push_back(vec[2]);
		// v.push_back(vec.size());
		// v.push_back(vec.capacity());
		// std::swap(vec, tmp2);
		// v.push_back(vec[2]);
		// v.push_back(vec.size());
		// v.push_back(vec.capacity());
		// std::swap(vec, tmp4);
		// // g_end1 = timer();
		// v.push_back(vec[2]);
		// v.push_back(vec.size());
		// v.push_back(vec.capacity());
		// /*status*/printVecParams(vec, true);
// ~~~~~~~~~~~~~~~~SWAAAAAAAAAP
		
	}
}


