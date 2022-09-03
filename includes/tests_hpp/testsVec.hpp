/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsVec.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:38:01 by msalena           #+#    #+#             */
/*   Updated: 2022/09/03 14:08:31 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_VEC_HPP
#define TESTS_VEC_HPP

#include "testsUtils.hpp"
#include "../vector.hpp"
#include "../containers.hpp"

namespace ft{
	void	vectorChecker(valueType type);

	class	tmpVectors{
	private:
		ft::vector<std::string>		myStringVec;
		ft::vector<char>			myCharVec;
		ft::vector<int>				myIntVec;

		std::vector<std::string>	origStringVec;
		std::vector<char>			origCharVec;
		std::vector<int>			origIntVec;
	public:
		tmpVectors(void) {
			setStringVecs();
			setCharVecs();
			setIntVecs();
		}

		~tmpVectors(void) { }

		void	setStringVecs(void){
			for (size_t i = 0; i < factor; i++){
				myStringVec.push_back("hola");
				origStringVec.push_back("hola");
			}
		}

		void	setCharVecs(void){
			for (size_t i = 0; i < factor; i++){
				myCharVec.push_back('s');
				origCharVec.push_back('s');
			}
		}

		void	setIntVecs(void){
			for (size_t i = 0; i < factor; i++){
				myIntVec.push_back(i*2);
				origIntVec.push_back(i*2);
			}
		}

		ft::vector<std::string>		&getFtStringVec(void) { return myStringVec; }
		ft::vector<char>			&getFtCharVec(void) { return myCharVec; }
		ft::vector<int>				&getFtIntVec(void) { return myIntVec; }
		std::vector<std::string>	&getStdStringVec(void) { return origStringVec; }
		std::vector<char>			&getStdCharVec(void) { return origCharVec; }
		std::vector<int>			&getStdIntVec(void) { return origIntVec; }
	} ;

	//~~~~~~~~~~~~~~~~~~ HELPFUL_UTILS ~~~~~~~~~~~~~~~~~~
	template <class ft_vec>
		// Prints value of vector
		void	printVecContent(ft_vec &vec, bool isItOrigVector){
			std::cout << "	vector content: ";
			if (isItOrigVector){
				for (typename ft_vec::iterator orig = vec.begin();
				orig != (vec.end()); orig++){
					std::cout << *orig << "  ";
				}
			} else {
				for (typename ft_vec::iterator my(vec.begin());
				my != vec.end(); my++){
					std::cout << *my << "  ";
				}
			}
			(void) isItOrigVector;
			std::cout << std::endl;
		}
	template <class ft_vec>
		// Prints all information about vector
		void	printVecParams (ft_vec &vec, bool isItOrigVector){
			// (void)isItOrigVector;
			std::cout << "\033[33m";
			(isItOrigVector) ? (std::cout << "STD_") : (std::cout << "FT_");
			std::cout << "VECTOR_status" << "\033[0m" << std::endl;
			printVecContent(vec, isItOrigVector);
			std::cout << "	count elem: " << vec.size() << "\n"
						<< "	capaxity size: " << vec.capacity() << "\n"
						<< "	emptyFlag: " << vec.empty()
						<< std::endl << std::endl;
		}

	template <class ft_vec, class std_vec>
		// Compare orig and my vectors
		bool	compareVectors(ft_vec& myVec, std_vec& origVec){
			if (myVec.capacity() != origVec.capacity()) { return false; }
			if (myVec.size() != origVec.size()) { return false; }
			if (myVec.empty() != origVec.empty()) { return false; }
			if (myVec.empty() && origVec.empty()) { return true; }

			typename ft_vec::iterator	myIter(myVec.begin());
			typename std_vec::iterator	origIter = origVec.begin();

			while (myIter != myVec.end() || origIter != origVec.end()){
				if (*myIter != *origIter) { return false; }
				myIter++;
				origIter++;
			}
			return true;
		}

	template <class ft_vec, class std_vec>
		// Print result of compare to STDOUT
		void	result(const std::string& fieldName,
						ft_vec& my, std_vec& orig,
						long ft_time, long std_time,
						bool isItCompare){
			if (isItCompare){
				print_results(fieldName, ft_time, std_time);
			} else {
				print_mismatch(fieldName);
				printVecParams(my, false);
				printVecParams(orig, true);
			}
		}


	//~~~~~~~~~~~ CHECKS_FOR_MEMBER_FUNCTIONS ~~~~~~~~~~~

	template <class ft_vec, class std_vec>
		void	checkVecConstructors(ft_vec &my_tmp, std_vec &orig_tmp){
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

				result("construc(fill)  ", my_vec, orig_vec, ft_time, std_time,
						compareVectors(my_vec, orig_vec));
			}

			{
				/* <<<<<<<<<<<<<<< Tests for range_constructor >>>>>>>>>>>>>>>*/
				timer.start();
				ft_vec	my_vec(my_tmp.begin(),(my_tmp.end() - 1));
				ft_time = timer.stop();

				timer.start();
				std_vec	orig_vec(orig_tmp.begin(),(orig_tmp.end() - 1));
				std_time = timer.stop();

				result("construc(range) ", my_vec, orig_vec, ft_time, std_time,
						compareVectors(my_vec, orig_vec));
			}

			{
				/* <<<<<<<<<<<<<<< Tests for copy_constructor >>>>>>>>>>>>>>>*/
				timer.start();
				ft_vec	my_vec(my_tmp);
				ft_time = timer.stop();

				timer.start();
				std_vec	orig_vec = orig_tmp;
				std_time = timer.stop();
				result("construc(copy)  ", my_vec, orig_vec, ft_time, std_time,
						compareVectors(my_vec, orig_vec));
			}
		}

	template <class ft_vec, class std_vec>
		void	assignCheck(ft_vec &my_vec, std_vec &orig_vec,
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

				result("assign(range)   ", my_vec, orig_vec, ft_time, std_time,
						compareVectors(my_vec, orig_vec));
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

				result("assign(fill)    ", my_vec, orig_vec, ft_time, std_time,
						compareVectors(my_vec, orig_vec));
			}

		}

	template <class ft_vec, class std_vec>
		void	push_backCheck(ft_vec &my_vec, std_vec &orig_vec,
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

			result("push_back       ", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
		}

	template <class ft_vec, class std_vec>
		void	pop_backCheck(ft_vec &my_vec, std_vec &orig_vec){
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

			result("pop_back       ", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
		}

	template <class ft_vec, class std_vec>
		void	insertCheck(ft_vec &my_vec, std_vec &orig_vec,
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

				result("insert(range)   ", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
			}
			{
				typename ft_vec::iterator	ftIter = my_vec.begin();
				typename std_vec::iterator	stdIter = orig_vec.begin();

			// <<<<<<<<<<<<<<< Tests for insert(single elem) >>>>>>>>>>>>>>>
				timer.start();
				ftIter = my_vec.insert((ftIter + 2), my_tmp[2]);
				ft_time = timer.stop();

				timer.start();
				stdIter = orig_vec.insert((stdIter + 2), my_tmp[2]);
				std_time = timer.stop();

				result("insert(single)  ", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
			// <<<<<<<<<<<<<<< Tests for insert(fill) >>>>>>>>>>>>>>>

				timer.start();
				my_vec.insert(ftIter, 2, my_tmp[0]);
				ft_time = timer.stop();

				timer.start();
				orig_vec.insert(stdIter, 2, my_tmp[0]);
				std_time = timer.stop();

				result("insert(fill)    ", my_vec, orig_vec, ft_time, std_time, 
						compareVectors(my_vec, orig_vec));
			}
		}

	template <class ft_vec, class std_vec>
		void	eraseCheck(ft_vec &my_vec, std_vec &orig_vec){
			typedef typename ft_vec::iterator	myIter;
			typedef typename std_vec::iterator	origIter;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			myIter		my_tmp = my_vec.begin();
			origIter	orig_tmp = orig_vec.begin();
			{
			// <<<<<<<<<<<<<<< Tests for insert(position) >>>>>>>>>>>>>>>
				timer.start();
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
						compareVectors(my_vec, orig_vec));
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
						compareVectors(my_vec, orig_vec));
			}
		}

	template <class ft_vec, class std_vec>
		void	swapCheck(ft_vec &my_vec, std_vec &orig_vec,
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
					compareVectors(my_vec, orig_vec));
		}

	template <class ft_vec, class std_vec>
		void	clearChech(ft_vec& my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			my_vec.clear();
			ft_time = timer.stop();

			timer.start();
			orig_vec.clear();
			std_time = timer.stop();

			result("clear          ", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
		}

	template <class ft_vec, class std_vec>
		void	checkBegin(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			typename ft_vec::iterator myIter = my_vec.begin();
			ft_time = timer.stop();

			timer.start();
			typename std_vec::iterator origIter = orig_vec.begin();
			std_time = timer.stop();

			result("begin          ", my_vec, orig_vec, ft_time, std_time,
					((*myIter) == (*origIter)));
		}

	template <class ft_vec, class std_vec>
		void	checkEnd(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			typename ft_vec::iterator myIter = my_vec.end();
			ft_time = timer.stop();

			timer.start();
			typename std_vec::iterator origIter = orig_vec.end();
			std_time = timer.stop();

			result("end            ", my_vec, orig_vec, ft_time, std_time,
					(*(myIter - 1) == *(origIter - 1)));
		}

	template <class ft_vec, class std_vec>
		void	checkRbegin(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			typename ft_vec::reverse_iterator myIter = my_vec.rbegin();
			ft_time = timer.stop();

			timer.start();
			typename std_vec::reverse_iterator origIter = orig_vec.rbegin();
			std_time = timer.stop();

			result("rbegin         ", my_vec, orig_vec, ft_time, std_time,
					((*myIter) == (*origIter)));
		}

	template <class ft_vec, class std_vec>
		void	checkRend(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			typename ft_vec::reverse_iterator myIter = my_vec.rend();
			ft_time = timer.stop();

			timer.start();
			typename std_vec::reverse_iterator origIter = orig_vec.rend();
			std_time = timer.stop();

			result("rend           ", my_vec, orig_vec, ft_time, std_time,
					(*(myIter - 1) == *(origIter - 1)));
		}

	template <class ft_vec, class std_vec>
		void	checkResize(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			my_vec.resize(5);
			ft_time = timer.stop();

			timer.start();
			orig_vec.resize(5);
			std_time = timer.stop();

			result("resize         ", my_vec, orig_vec, ft_time, std_time,
					compareVectors(my_vec, orig_vec));
		}

	template <class ft_vec, class std_vec>
		void	checkReserve(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			my_vec.reserve(500);
			ft_time = timer.stop();

			timer.start();
			orig_vec.reserve(500);
			std_time = timer.stop();

			result("reserve        ", my_vec, orig_vec, ft_time, std_time,
					compareVectors(my_vec, orig_vec));
		}

	template <class ft_vec, class std_vec>
		void	checkAt(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			typename ft_vec::reference myIter = my_vec.at(3);
			ft_time = timer.stop();

			timer.start();
			typename std_vec::reference origIter = orig_vec.at(3);
			std_time = timer.stop();

			result("at             ", my_vec, orig_vec, ft_time, std_time,
					(myIter == origIter));
		}

	template <class ft_vec, class std_vec>
		void	checkFront(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			typename ft_vec::reference myIter = my_vec.front();
			ft_time = timer.stop();

			timer.start();
			typename std_vec::reference origIter = orig_vec.front();
			std_time = timer.stop();

			result("front          ", my_vec, orig_vec, ft_time, std_time,
					(myIter == origIter));
		}

	template <class ft_vec, class std_vec>
		void	checkBack(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			typename ft_vec::reference myIter = my_vec.back();
			ft_time = timer.stop();

			timer.start();
			typename std_vec::reference origIter = orig_vec.back();
			std_time = timer.stop();

			result("back           ", my_vec, orig_vec, ft_time, std_time,
					(myIter == origIter));
		}

	template <class ft_vec, class std_vec>
		void	checkCompareVectors(ft_vec& my_vec, std_vec& orig_vec,
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
						(myComp == origComp));
			}

			{
				timer.start();
				bool	myComp = (my_tmp != my_vec);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_tmp != orig_vec);
				std_time = timer.stop();

				result("vec!=vec       ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp));
			}

			{
				timer.start();
				bool	myComp = (my_tmp < my_vec);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_tmp < orig_vec);
				std_time = timer.stop();

				result("vec<vec        ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp));
			}

			{
				timer.start();
				bool	myComp = (my_tmp > my_vec);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_tmp > orig_vec);
				std_time = timer.stop();

				result("vec>vec        ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp));
			}

			{
				timer.start();
				bool	myComp = (my_tmp <= my_vec);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_tmp <= orig_vec);
				std_time = timer.stop();

				result("vec<=vec       ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp));
			}

			{
				timer.start();
				bool	myComp = (my_tmp != my_vec);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_tmp != orig_vec);
				std_time = timer.stop();

				result("iter>=iter     ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp));
			}
	}

	//~~~~~~~~~~~~~~~~~~~ CHECKS_FOR ITERATOR ~~~~~~~~~~~~~~~~~~~

	template <class ft_vec, class std_vec>
		void	checkIterators(ft_vec& my_vec, std_vec& orig_vec){
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
						(*(myIterBegin.base()) == *(origIterBegin.base())));
			}

			{
				timer.start();
				--(myIterBegin + 3);
				ft_time = timer.stop();

				timer.start();
				--(origIterBegin + 3);
				std_time = timer.stop();

				result("--orerator     ", my_vec, orig_vec, ft_time, std_time,
						(*(myIterBegin.base()) == *(origIterBegin.base())));
			}

			{
				timer.start();
				++myIterBegin;
				ft_time = timer.stop();

				timer.start();
				++origIterBegin;
				std_time = timer.stop();

				result("++orerator     ", my_vec, orig_vec, ft_time, std_time,
						(*(myIterBegin.base()) == *(origIterBegin.base())));
			}

			{
				timer.start();
				myIterBegin += 5;
				ft_time = timer.stop();

				timer.start();
				origIterBegin += 5;
				std_time = timer.stop();

				result("orerator+=     ", my_vec, orig_vec, ft_time, std_time,
						(*(myIterBegin.base()) == *(origIterBegin.base())));
			}

			{
				timer.start();
				myIterBegin -= (-3);
				ft_time = timer.stop();

				timer.start();
				origIterBegin -= (-3);
				std_time = timer.stop();

				result("orerator-=     ", my_vec, orig_vec, ft_time, std_time,
						(*(myIterBegin.base()) == *(origIterBegin.base())));
			}
	}

	template <class ft_vec, class std_vec>
		void	checkCompareIters(ft_vec& my_vec, std_vec& orig_vec){
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
						(myComp == origComp));
			}

			{
				timer.start();
				bool	myComp = ((myIterBegin + 3) != my_vec.begin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = ((origIterBegin + 3) != orig_vec.begin());
				std_time = timer.stop();

				result("iter!=iter     ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp));
			}

			{
				timer.start();
				bool	myComp = ((myIterBegin + 3) < my_vec.begin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = ((origIterBegin + 3) < orig_vec.begin());
				std_time = timer.stop();

				result("iter<iter      ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp));
			}

			{
				timer.start();
				bool	myComp = ((myIterBegin + 3) > my_vec.begin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = ((origIterBegin + 3) > orig_vec.begin());
				std_time = timer.stop();

				result("iter>iter      ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp));
			}

			{
				timer.start();
				bool	myComp = ((myIterBegin + 4) <= my_vec.begin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = ((origIterBegin + 4) <= orig_vec.begin());
				std_time = timer.stop();

				result("iter<=iter     ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp));
			}

			{
				timer.start();
				bool	myComp = ((myIterBegin + 4) != my_vec.begin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = ((origIterBegin + 4) != orig_vec.begin());
				std_time = timer.stop();

				result("iter>=iter     ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp));
			}
	}

	template <class ft_vec, class std_vec>
		void	checkRevIterators(ft_vec& my_vec, std_vec& orig_vec){
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
						(*(myIterBegin.base()) == *(origIterBegin.base())));
			}

			{
				timer.start();
				--(myIterBegin + 3);
				ft_time = timer.stop();

				timer.start();
				--(origIterBegin + 3);
				std_time = timer.stop();

				result("--orerator     ", my_vec, orig_vec, ft_time, std_time,
						(*(myIterBegin.base()) == *(origIterBegin.base())));
			}

			{
				timer.start();
				++(myIterBegin--);
				ft_time = timer.stop();

				timer.start();
				++(origIterBegin--);
				std_time = timer.stop();

				result("++orerator     ", my_vec, orig_vec, ft_time, std_time,
						(*(myIterBegin.base()) == *(origIterBegin.base())));
			}

			{
				timer.start();
				myIterBegin += (-5);
				ft_time = timer.stop();

				timer.start();
				origIterBegin += (-5);
				std_time = timer.stop();

				result("orerator+=     ", my_vec, orig_vec, ft_time, std_time,
						(*(myIterBegin.base()) == *(origIterBegin.base())));
			}

			{
				timer.start();
				myIterBegin -= 3;
				ft_time = timer.stop();

				timer.start();
				origIterBegin -= 3;
				std_time = timer.stop();

				result("orerator-=     ", my_vec, orig_vec, ft_time, std_time,
						(*(myIterBegin.base()) == *(origIterBegin.base())));
			}
	}

	template <class ft_vec, class std_vec>
		void	checkCompareRevIters(ft_vec& my_vec, std_vec& orig_vec){
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
						(myComp == origComp));
			}

			{
				timer.start();
				bool	myComp = ((myIterBegin + 3) != my_vec.rbegin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = ((origIterBegin + 3) != orig_vec.rbegin());
				std_time = timer.stop();

				result("iter!=iter     ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp));
			}

			{
				timer.start();
				bool	myComp = (myIterBegin < my_vec.rbegin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (origIterBegin < orig_vec.rbegin());
				std_time = timer.stop();

				result("iter<iter      ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp));
			}

			{
				timer.start();
				bool	myComp = (myIterBegin > my_vec.rbegin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (origIterBegin > orig_vec.rbegin());
				std_time = timer.stop();

				result("iter>iter      ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp));
			}

			{
				timer.start();
				bool	myComp = (myIterBegin <= my_vec.rbegin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (origIterBegin <= orig_vec.rbegin());
				std_time = timer.stop();

				result("iter<=iter     ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp));
			}

			{
				timer.start();
				bool	myComp = ((myIterBegin + 4) != my_vec.rbegin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = ((origIterBegin + 4) != orig_vec.rbegin());
				std_time = timer.stop();

				result("iter>=iter     ", my_vec, orig_vec, ft_time, std_time,
						(myComp == origComp));
			}
	}

}

#endif
