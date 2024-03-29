/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsVec.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:38:01 by msalena           #+#    #+#             */
/*   Updated: 2022/09/10 19:16:08 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_VEC_HPP
#define TESTS_VEC_HPP

#include "testsTmpClasses.hpp"
#include "../ft_vector.hpp"
#include "../ft_containers.hpp"

namespace ft{
	void	vectorChecker(valueType type);

	//~~~~~~~~~~~~~~~~~~ HELPFUL_UTILS ~~~~~~~~~~~~~~~~~~

	template <class vec>
		// Prints value of vector
		void	printVecContent(vec &vec_cont, bool isItOrigVector){
			std::cout << "	content: ";
			if (isItOrigVector){
				for (typename vec::iterator orig = vec_cont.begin();
				orig != (vec_cont.end()); orig++){
					std::cout << *orig << "  ";
				}
			} else {
				for (typename vec::iterator my(vec_cont.begin());
				my != vec_cont.end(); my++){
					std::cout << *my << "  ";
				}
			}
			std::cout << std::endl;
		}

	template <class vec>
		// Prints all information about vector
		void	printVecParams (vec &vec_cont, bool isItOrigVector){
			std::cout << "\033[33m";
			(isItOrigVector) ? (std::cout << "STD_") : (std::cout << "FT_");
			std::cout << "VECTOR_status" << "\033[0m" << std::endl;
			printVecContent(vec_cont, isItOrigVector);
			std::cout << "	count elem: " << vec_cont.size() << "\n"
						<< "	capaxity size: " << vec_cont.capacity() << "\n"
						<< "	emptyFlag: " << vec_cont.empty()
						<< std::endl << std::endl;
		}

	template <class ft_vec, class std_vec>
		void	printVectors(ft_vec &my, std_vec &orig){
			printVecParams(my, false);
			printVecParams(orig, true);
		}

	template <class ft_vec, class std_vec>
		bool	compareVectors(ft_vec &my_vec, std_vec &orig_vec){
			if (my_vec.capacity() != orig_vec.capacity()) { return false; }
			return compareContainers(my_vec, orig_vec);
		}

	//~~~~~~~~~~~ CHECKS_FOR_MEMBER_FUNCTIONS ~~~~~~~~~~~

	template <class ft_vec, class std_vec>
		void	constructorsCheckVec(ft_vec &my_tmp, std_vec &orig_tmp){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;
			{
				// /* <<<<<<<<<<<<<<< Tests for fill_constructor >>>>>>>>>>>>>>>*/
				timer.start();
				ft_vec	my_vec(factor, my_tmp[3]);
				ft_time = timer.stop();

				timer.start();
				std_vec	orig_vec(factor, orig_tmp[3]);
				std_time = timer.stop();

				result("construc(fill) ", my_vec, orig_vec, ft_time, std_time,
						compareVectors(my_vec, orig_vec), printVectors<ft_vec, std_vec>);
			}

			{
				/* <<<<<<<<<<<<<<< Tests for range_constructor >>>>>>>>>>>>>>>*/
				timer.start();
				ft_vec	my_vec(my_tmp.begin(),(my_tmp.end() - 1));
				ft_time = timer.stop();

				timer.start();
				std_vec	orig_vec(orig_tmp.begin(),(orig_tmp.end() - 1));
				std_time = timer.stop();

				result("construc(range)", my_vec, orig_vec, ft_time, std_time,
						compareVectors(my_vec, orig_vec), printVectors<ft_vec, std_vec>);
			}

			{
				/* <<<<<<<<<<<<<<< Tests for copy_constructor >>>>>>>>>>>>>>>*/
				timer.start();
				ft_vec	my_vec(my_tmp);
				ft_time = timer.stop();

				timer.start();
				std_vec	orig_vec = orig_tmp;
				std_time = timer.stop();
				result("construc(copy) ", my_vec, orig_vec, ft_time, std_time,
						compareVectors(my_vec, orig_vec), printVectors<ft_vec, std_vec>);
			}
		}

	template <class ft_vec, class std_vec>
		void	assignCheckVec(ft_vec &my_vec, std_vec &orig_vec,
								ft_vec &my_tmp, std_vec &orig_tmp){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			{
			// <<<<<<<<<<<<<<< Tests for assign(size_type, value_type) >>>>>>>>>>>>
				timer.start();
				my_vec.assign(my_tmp.begin(), my_tmp.end());
				ft_time = timer.stop();

				timer.start();
				orig_vec.assign(orig_tmp.begin(), orig_tmp.end());
				std_time = timer.stop();

				result("assign(range)  ", my_vec, orig_vec, ft_time, std_time,
						compareVectors(my_vec, orig_vec), printVectors<ft_vec, std_vec>);
			}
			{
				// <<<<<<<<<<<<<<< Tests for assign(size_type, value_type) >>>>>>>>>>>>
				for (size_t i = 2; i < 20; i *= i){
					timer.start();
					my_vec.assign(i, my_tmp[i]);
					ft_time += timer.stop();

					timer.start();
					orig_vec.assign(i, my_tmp[i]);
					std_time += timer.stop();
				}

				result("assign(fill)   ", my_vec, orig_vec, ft_time, std_time,
						compareVectors(my_vec, orig_vec), printVectors<ft_vec, std_vec>);
			}

		}

	template <class ft_vec, class std_vec>
		void	push_backCheckVec(ft_vec &my_vec, std_vec &orig_vec,
									ft_vec &my_tmp, std_vec &orig_tmp){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			my_vec.push_back(my_tmp[4]);
			my_vec.push_back(my_tmp[2]);
			my_vec.push_back(my_tmp[1]);
			ft_time = timer.stop();

			timer.start();
			orig_vec.push_back(orig_tmp[4]);
			orig_vec.push_back(orig_tmp[2]);
			orig_vec.push_back(orig_tmp[1]);
			std_time = timer.stop();

			result("push_back      ", my_vec, orig_vec, ft_time, std_time,
					compareVectors(my_vec, orig_vec), printVectors<ft_vec, std_vec>);
		}

	template <class ft_vec, class std_vec>
		void	pop_backCheckVec(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			my_vec.pop_back();
			my_vec.pop_back();
			my_vec.pop_back();
			ft_time = timer.stop();

			timer.start();
			orig_vec.pop_back();
			orig_vec.pop_back();
			orig_vec.pop_back();
			std_time = timer.stop();

			result("pop_back       ", my_vec, orig_vec, ft_time, std_time,
					compareVectors(my_vec, orig_vec), printVectors<ft_vec, std_vec>);
		}

	template <class ft_vec, class std_vec>
		void	insertCheckVec(ft_vec &my_vec, std_vec &orig_vec,
									ft_vec &my_tmp, std_vec &orig_tmp){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			{
			// <<<<<<<<<<<<<<< Tests for insert(range) >>>>>>>>>>>>>>>
				timer.start();
				my_vec.insert(my_vec.end(), my_tmp.begin(), my_tmp.end());
				ft_time = timer.stop();

				timer.start();
				orig_vec.insert(orig_vec.end(), orig_tmp.begin(), orig_tmp.end());
				std_time = timer.stop();

				result("insert(range)  ", my_vec, orig_vec, ft_time, std_time,
						compareVectors(my_vec, orig_vec), printVectors<ft_vec, std_vec>);
			}
			{
				typename ft_vec::iterator	myIter = my_vec.begin();
				typename std_vec::iterator	origIter = orig_vec.begin();

			// <<<<<<<<<<<<<<< Tests for insert(single elem) >>>>>>>>>>>>>>>
				timer.start();
				myIter = my_vec.insert((myIter + 2), my_tmp[2]);
				ft_time = timer.stop();

				timer.start();
				origIter = orig_vec.insert((origIter + 2), my_tmp[2]);
				std_time = timer.stop();

				result("insert(single) ", my_vec, orig_vec, ft_time, std_time,
						compareVectors(my_vec, orig_vec), printVectors<ft_vec, std_vec>);
			// <<<<<<<<<<<<<<< Tests for insert(fill) >>>>>>>>>>>>>>>

				timer.start();
				my_vec.insert(myIter, 2, my_tmp[0]);
				ft_time = timer.stop();

				timer.start();
				orig_vec.insert(origIter, 2, my_tmp[0]);
				std_time = timer.stop();

				result("insert(fill)   ", my_vec, orig_vec, ft_time, std_time,
						compareVectors(my_vec, orig_vec), printVectors<ft_vec, std_vec>);
			}
		}

	template <class ft_vec, class std_vec>
		void	eraseCheckVec(ft_vec &my_vec, std_vec &orig_vec){
			typedef typename ft_vec::iterator	myIter;
			typedef typename std_vec::iterator	origIter;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			myIter		my_tmp = my_vec.begin();
			origIter	orig_tmp = orig_vec.begin();
			{
			// <<<<<<<<<<<<<<< Tests for insert(position) >>>>>>>>>>>>>>>
				timer.start();
				// std::cout << my_vec.size() << std::endl;
				my_tmp = my_vec.erase(my_tmp+6);
				my_vec.erase(my_tmp + 3);
				my_vec.erase(my_vec.begin() + my_vec.size() - 1);
				ft_time = timer.stop();

				timer.start();
				orig_tmp = orig_vec.erase(orig_tmp+6);
				orig_vec.erase(orig_tmp + 3);
				orig_vec.erase(orig_vec.begin() + orig_vec.size() - 1);
				std_time = timer.stop();

				result("erase(position)", my_vec, orig_vec, ft_time, std_time,
						compareVectors(my_vec, orig_vec), printVectors<ft_vec, std_vec>);
			}
			{
			// <<<<<<<<<<<<<<< Tests for insert(range) >>>>>>>>>>>>>>>
				timer.start();

				my_vec.erase(my_vec.begin(), (my_vec.begin() + 3));
				ft_time = timer.stop();

				timer.start();
				orig_vec.erase(orig_vec.begin(), (orig_vec.begin() + 3));
				std_time = timer.stop();

				result("erase(range)   ", my_vec, orig_vec, ft_time, std_time,
						compareVectors(my_vec, orig_vec), printVectors<ft_vec, std_vec>);
			}
		}

	template <class ft_vec, class std_vec>
		void	swapCheckVec(ft_vec &my_vec, std_vec &orig_vec,
								ft_vec &my_tmp, std_vec &orig_tmp){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			my_vec.swap(my_tmp);
			ft_time = timer.stop();

			timer.start();
			orig_vec.swap(orig_tmp);
			std_time = timer.stop();

			result("swap           ", my_vec, orig_vec, ft_time, std_time,
					compareVectors(my_vec, orig_vec), printVectors<ft_vec, std_vec>);
		}

	template <class ft_vec, class std_vec>
		void	clearChechVec(ft_vec& my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			my_vec.clear();
			ft_time = timer.stop();

			timer.start();
			orig_vec.clear();
			std_time = timer.stop();

			result("clear          ", my_vec, orig_vec, ft_time, std_time,
					compareVectors(my_vec, orig_vec), printVectors<ft_vec, std_vec>);
		}

	template <class ft_vec, class std_vec>
		void	beginCheckVec(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			typename ft_vec::iterator myIter = my_vec.begin();
			ft_time = timer.stop();

			timer.start();
			typename std_vec::iterator origIter = orig_vec.begin();
			std_time = timer.stop();

			result("begin          ", my_vec, orig_vec, ft_time, std_time,
					((*myIter) == (*origIter)), printVectors<ft_vec, std_vec>);
		}

	template <class ft_vec, class std_vec>
		void	checkEndVec(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			typename ft_vec::iterator myIter = my_vec.end();
			ft_time = timer.stop();

			timer.start();
			typename std_vec::iterator origIter = orig_vec.end();
			std_time = timer.stop();

			result("end            ", my_vec, orig_vec, ft_time, std_time,
					(*(myIter - 1) == *(origIter - 1)), printVectors<ft_vec, std_vec>);
		}

	template <class ft_vec, class std_vec>
		void	rbeginCheckVec(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			typename ft_vec::reverse_iterator myIter = my_vec.rbegin();
			ft_time = timer.stop();

			timer.start();
			typename std_vec::reverse_iterator origIter = orig_vec.rbegin();
			std_time = timer.stop();

			result("rbegin         ", my_vec, orig_vec, ft_time, std_time,
					((*myIter) == (*origIter)), printVectors<ft_vec, std_vec>);
		}

	template <class ft_vec, class std_vec>
		void	rendCheckVec(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			typename ft_vec::reverse_iterator myIter = my_vec.rend();
			ft_time = timer.stop();

			timer.start();
			typename std_vec::reverse_iterator origIter = orig_vec.rend();
			std_time = timer.stop();

			result("rend           ", my_vec, orig_vec, ft_time, std_time,
					(*(myIter - 1) == *(origIter - 1)), printVectors<ft_vec, std_vec>);
		}

	template <class ft_vec, class std_vec>
		void	resizeCheckVec(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			my_vec.resize(5);
			ft_time = timer.stop();

			timer.start();
			orig_vec.resize(5);
			std_time = timer.stop();

			result("resize         ", my_vec, orig_vec, ft_time, std_time,
					compareVectors(my_vec, orig_vec), printVectors<ft_vec, std_vec>);
		}

	template <class ft_vec, class std_vec>
		void	reserveCheckVec(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			my_vec.reserve(500);
			ft_time = timer.stop();

			timer.start();
			orig_vec.reserve(500);
			std_time = timer.stop();

			result("reserve        ", my_vec, orig_vec, ft_time, std_time,
					compareVectors(my_vec, orig_vec), printVectors<ft_vec, std_vec>);
		}

	template <class ft_vec, class std_vec>
		void	atCheckVec(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			typename ft_vec::reference myIter = my_vec.at(3);
			ft_time = timer.stop();

			timer.start();
			typename std_vec::reference origIter = orig_vec.at(3);
			std_time = timer.stop();

			result("at             ", my_vec, orig_vec, ft_time, std_time,
					(myIter == origIter), printVectors<ft_vec, std_vec>);
		}

	template <class ft_vec, class std_vec>
		void	frontCheckVec(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			typename ft_vec::reference myIter = my_vec.front();
			ft_time = timer.stop();

			timer.start();
			typename std_vec::reference origIter = orig_vec.front();
			std_time = timer.stop();

			result("front          ", my_vec, orig_vec, ft_time, std_time,
					(myIter == origIter), printVectors<ft_vec, std_vec>);
		}

	template <class ft_vec, class std_vec>
		void	backCheckVec(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			typename ft_vec::reference myIter = my_vec.back();
			ft_time = timer.stop();

			timer.start();
			typename std_vec::reference origIter = orig_vec.back();
			std_time = timer.stop();

			result("back           ", my_vec, orig_vec, ft_time, std_time,
					(myIter == origIter), printVectors<ft_vec, std_vec>);
		}

	template <class ft_vec, class std_vec>
		void	checkCompareVecs(ft_vec& my_vec, std_vec& orig_vec,
										ft_vec &my_tmp, std_vec &orig_tmp){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			{
				timer.start();
				bool	myComp = (my_tmp == my_vec);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_tmp == orig_vec);
				std_time = timer.stop();

				result("vec==vec       ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp), printVectors<ft_vec, std_vec>);
			}

			{
				timer.start();
				bool	myComp = (my_tmp != my_vec);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_tmp != orig_vec);
				std_time = timer.stop();

				result("vec!=vec       ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp), printVectors<ft_vec, std_vec>);
			}

			{
				timer.start();
				bool	myComp = (my_tmp < my_vec);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_tmp < orig_vec);
				std_time = timer.stop();

				result("vec<vec        ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp), printVectors<ft_vec, std_vec>);
			}

			{
				timer.start();
				bool	myComp = (my_tmp > my_vec);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_tmp > orig_vec);
				std_time = timer.stop();

				result("vec>vec        ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp), printVectors<ft_vec, std_vec>);
			}

			{
				timer.start();
				bool	myComp = (my_tmp <= my_vec);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_tmp <= orig_vec);
				std_time = timer.stop();

				result("vec<=vec       ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp), printVectors<ft_vec, std_vec>);
			}

			{
				timer.start();
				bool	myComp = (my_tmp != my_vec);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_tmp != orig_vec);
				std_time = timer.stop();

				result("iter>=iter     ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp), printVectors<ft_vec, std_vec>);
			}
	}

	//~~~~~~~~~~~~~~~~~~~ CHECKS_FOR ITERATOR ~~~~~~~~~~~~~~~~~~~

	template <class ft_vec, class std_vec>
		void	checkIteratorsVecs(ft_vec& my_vec, std_vec& orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			typename ft_vec::iterator	myIterBegin = my_vec.begin();
			typename std_vec::iterator	origIterBegin = orig_vec.begin();
			{
				timer.start();
				(myIterBegin + 4)--;
				ft_time = timer.stop();

				timer.start();
				(origIterBegin + 4)--;
				std_time = timer.stop();

				result("orerator--     ", my_vec, orig_vec, ft_time, std_time,
						(*(myIterBegin.base()) == *(origIterBegin.base())),
						printVectors<ft_vec, std_vec>);
			}

			{
				timer.start();
				--(myIterBegin + 3);
				ft_time = timer.stop();

				timer.start();
				--(origIterBegin + 3);
				std_time = timer.stop();

				result("--orerator     ", my_vec, orig_vec, ft_time, std_time,
						(*(myIterBegin.base()) == *(origIterBegin.base())),
						printVectors<ft_vec, std_vec>);
			}

			{
				timer.start();
				++myIterBegin;
				ft_time = timer.stop();

				timer.start();
				++origIterBegin;
				std_time = timer.stop();

				result("++orerator     ", my_vec, orig_vec, ft_time, std_time,
						(*(myIterBegin.base()) == *(origIterBegin.base())),
						printVectors<ft_vec, std_vec>);
			}

			{
				timer.start();
				myIterBegin += 5;
				ft_time = timer.stop();

				timer.start();
				origIterBegin += 5;
				std_time = timer.stop();

				result("orerator+=     ", my_vec, orig_vec, ft_time, std_time,
						(*(myIterBegin.base()) == *(origIterBegin.base())),
						printVectors<ft_vec, std_vec>);
			}

			{
				timer.start();
				myIterBegin -= (-3);
				ft_time = timer.stop();

				timer.start();
				origIterBegin -= (-3);
				std_time = timer.stop();

				result("orerator-=     ", my_vec, orig_vec, ft_time, std_time,
						(*(myIterBegin.base()) == *(origIterBegin.base())),
						printVectors<ft_vec, std_vec>);
			}
	}

	template <class ft_vec, class std_vec>
		void	checkCompareItersVecs(ft_vec& my_vec, std_vec& orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			typename ft_vec::iterator	myIterBegin = my_vec.begin();
			typename std_vec::iterator	origIterBegin = orig_vec.begin();

			{
				timer.start();
				bool	myComp = (myIterBegin == my_vec.begin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (origIterBegin == orig_vec.begin());
				std_time = timer.stop();

				result("iter==iter     ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp), printVectors<ft_vec, std_vec>);
			}

			{
				timer.start();
				bool	myComp = ((myIterBegin + 3) != my_vec.begin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = ((origIterBegin + 3) != orig_vec.begin());
				std_time = timer.stop();

				result("iter!=iter     ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp), printVectors<ft_vec, std_vec>);
			}

			{
				timer.start();
				bool	myComp = ((myIterBegin + 3) < my_vec.begin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = ((origIterBegin + 3) < orig_vec.begin());
				std_time = timer.stop();

				result("iter<iter      ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp), printVectors<ft_vec, std_vec>);
			}

			{
				timer.start();
				bool	myComp = ((myIterBegin + 3) > my_vec.begin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = ((origIterBegin + 3) > orig_vec.begin());
				std_time = timer.stop();

				result("iter>iter      ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp), printVectors<ft_vec, std_vec>);
			}

			{
				timer.start();
				bool	myComp = ((myIterBegin + 4) <= my_vec.begin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = ((origIterBegin + 4) <= orig_vec.begin());
				std_time = timer.stop();

				result("iter<=iter     ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp), printVectors<ft_vec, std_vec>);
			}

			{
				timer.start();
				bool	myComp = ((myIterBegin + 4) != my_vec.begin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = ((origIterBegin + 4) != orig_vec.begin());
				std_time = timer.stop();

				result("iter>=iter     ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp), printVectors<ft_vec, std_vec>);
			}
	}

	template <class ft_vec, class std_vec>
		void	checkRevIteratorsVecs(ft_vec& my_vec, std_vec& orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			typename ft_vec::reverse_iterator	myIterBegin = my_vec.rend();
			typename std_vec::reverse_iterator	origIterBegin = orig_vec.rend();
			{
				timer.start();
				(myIterBegin + 5)--;
				ft_time = timer.stop();

				timer.start();
				(origIterBegin + 5)--;
				std_time = timer.stop();

				result("orerator--     ", my_vec, orig_vec, ft_time, std_time,
						(*(myIterBegin.base()) == *(origIterBegin.base())),
						printVectors<ft_vec, std_vec>);
			}

			{
				timer.start();
				--(myIterBegin + 3);
				ft_time = timer.stop();

				timer.start();
				--(origIterBegin + 3);
				std_time = timer.stop();

				result("--orerator     ", my_vec, orig_vec, ft_time, std_time,
						(*(myIterBegin.base()) == *(origIterBegin.base())),
						printVectors<ft_vec, std_vec>);
			}

			{
				timer.start();
				++(myIterBegin--);
				ft_time = timer.stop();

				timer.start();
				++(origIterBegin--);
				std_time = timer.stop();

				result("++orerator     ", my_vec, orig_vec, ft_time, std_time,
						(*(myIterBegin.base()) == *(origIterBegin.base())),
						printVectors<ft_vec, std_vec>);
			}

			{
				timer.start();
				myIterBegin += (-5);
				ft_time = timer.stop();

				timer.start();
				origIterBegin += (-5);
				std_time = timer.stop();

				result("orerator+=     ", my_vec, orig_vec, ft_time, std_time,
						(*(myIterBegin.base()) == *(origIterBegin.base())),
						printVectors<ft_vec, std_vec>);
			}

			{
				timer.start();
				myIterBegin -= 3;
				ft_time = timer.stop();

				timer.start();
				origIterBegin -= 3;
				std_time = timer.stop();

				result("orerator-=     ", my_vec, orig_vec, ft_time, std_time,
						(*(myIterBegin.base()) == *(origIterBegin.base())),
						printVectors<ft_vec, std_vec>);
			}
	}

	template <class ft_vec, class std_vec>
		void	checkCompareRevItersVecs(ft_vec& my_vec, std_vec& orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			typename ft_vec::reverse_iterator	myIterBegin = my_vec.rbegin();
			typename std_vec::reverse_iterator	origIterBegin = orig_vec.rbegin();

			{
				timer.start();
				bool	myComp = (myIterBegin == my_vec.rbegin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (origIterBegin == orig_vec.rbegin());
				std_time = timer.stop();

				result("iter==iter     ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp), printVectors<ft_vec, std_vec>);
			}

			{
				timer.start();
				bool	myComp = ((myIterBegin + 3) != my_vec.rbegin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = ((origIterBegin + 3) != orig_vec.rbegin());
				std_time = timer.stop();

				result("iter!=iter     ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp), printVectors<ft_vec, std_vec>);
			}

			{
				timer.start();
				bool	myComp = (myIterBegin < my_vec.rbegin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (origIterBegin < orig_vec.rbegin());
				std_time = timer.stop();

				result("iter<iter      ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp), printVectors<ft_vec, std_vec>);
			}

			{
				timer.start();
				bool	myComp = (myIterBegin > my_vec.rbegin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (origIterBegin > orig_vec.rbegin());
				std_time = timer.stop();

				result("iter>iter      ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp), printVectors<ft_vec, std_vec>);
			}

			{
				timer.start();
				bool	myComp = (myIterBegin <= my_vec.rbegin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (origIterBegin <= orig_vec.rbegin());
				std_time = timer.stop();

				result("iter<=iter     ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp), printVectors<ft_vec, std_vec>);
			}

			{
				timer.start();
				bool	myComp = ((myIterBegin + 4) != my_vec.rbegin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = ((origIterBegin + 4) != orig_vec.rbegin());
				std_time = timer.stop();

				result("iter>=iter     ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp), printVectors<ft_vec, std_vec>);
			}
	}

}

#endif
