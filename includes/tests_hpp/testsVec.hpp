/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsVec.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:38:01 by msalena           #+#    #+#             */
/*   Updated: 2022/08/31 19:46:16 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_VEC_HPP
#define TESTS_VEC_HPP

#include "testsUtils.hpp"
#include "../vector.hpp"
#include "../containers.hpp"

namespace ft{
	void	vectorChecker(valueType type);

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
		void	assignCheckString(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			{
			// <<<<<<<<<<<<<<< Tests for assign(size_type, value_type) >>>>>>>>>>>>
				ft_vec	myTmp;
				std_vec	origTmp;

				for (size_t i = 0; i < factor; i++){
					myTmp.push_back("hola");
					origTmp.push_back("hola");
				}

				timer.start();
				my_vec.assign(myTmp.begin(), myTmp.end());
				ft_time = timer.stop();

				timer.start();
				orig_vec.assign(origTmp.begin(), origTmp.end());
				std_time = timer.stop();

				result("assign(range)", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
			}
			{
				// <<<<<<<<<<<<<<< Tests for assign(size_type, value_type) >>>>>>>>>>>>
				for (size_t i = 1; i < 20; i *= i){
					timer.start();
					my_vec.assign(i, "hola");
					ft_time += timer.stop();

					timer.start();
					orig_vec.assign(i, "hola");
					std_time += timer.stop();
				}

				result("assign(fill)", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
			}

		}

	template <class ft_vec, class std_vec>
		void	assignCheckChar(ft_vec &my_vec, std_vec &orig_vec){
		ft::time	timer;
		long	ft_time = 0, std_time = 0;

		{
			// <<<<<<<<<<<<<<< Tests for assign(iterator, iterator) >>>>>>>>>>>>>>>

			ft_vec	myTmp;
			std_vec	origTmp;

			for (size_t i = 0; i < factor; i++){
				myTmp.push_back('s');
				origTmp.push_back('s');
			}

			timer.start();
			my_vec.assign(myTmp.begin(), myTmp.end());
			ft_time = timer.stop();

			timer.start();
			orig_vec.assign(origTmp.begin(), origTmp.end());
			std_time = timer.stop();

			result("assign(range)", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
		}
		{
			// <<<<<<<<<<<<<<< Tests for assign(size_type, value_type) >>>>>>>>>>>>
			for (size_t i = 2; i < 20; i *= i){
				timer.start();
				my_vec.assign(i, 's');
				ft_time += timer.stop();

				timer.start();
				orig_vec.assign(i, 's');
				std_time += timer.stop();
			}

			result("assign(fill)", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
		}
	}

	template <class ft_vec, class std_vec>
		void	assignCheckInt(ft_vec &my_vec, std_vec &orig_vec){
		ft::time	timer;
		long	ft_time = 0, std_time = 0;

		{
			// <<<<<<<<<<<<<<< Tests for assign(iterator, iterator) >>>>>>>>>>>>>>>
			ft_vec	myTmp;
			std_vec	origTmp;

			for (size_t i = 0; i < factor; i++){
				myTmp.push_back(i);
				origTmp.push_back(i);
			}

			timer.start();
			my_vec.assign(myTmp.begin(), myTmp.end());
			ft_time = timer.stop();

			timer.start();
			orig_vec.assign(origTmp.begin(), origTmp.end());
			std_time = timer.stop();

			result("assign(range)", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
		}
		{
			// <<<<<<<<<<<<<<< Tests for assign(size_type, value_type) >>>>>>>>>>>>
				for (size_t i = 2; i < 20; i *= i){
					timer.start();
					my_vec.assign(i, i);
					ft_time += timer.stop();

					timer.start();
					orig_vec.assign(i, i);
					std_time += timer.stop();
				}

				result("assign(fill)", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
		}
	}


	template <class ft_vec, class std_vec>
		void	push_backCheckString(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			my_vec.push_back("156");
			my_vec.push_back("1fdfd");
			my_vec.push_back("100");
			ft_time = timer.stop();

			timer.start();
			orig_vec.push_back("156");
			orig_vec.push_back("1fdfd");
			orig_vec.push_back("100");
			std_time = timer.stop();

			result("push_back   ", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
		}

	template <class ft_vec, class std_vec>
		void	push_backCheckChar(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			my_vec.push_back('y');
			my_vec.push_back('i');
			my_vec.push_back('6');
			ft_time = timer.stop();

			timer.start();
			orig_vec.push_back('y');
			orig_vec.push_back('i');
			orig_vec.push_back('6');
			std_time = timer.stop();

			result("push_back   ", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
		}

	template <class ft_vec, class std_vec>
		void	push_backCheckInt(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			my_vec.push_back(16);
			my_vec.push_back(4545);
			my_vec.push_back(3);
			ft_time = timer.stop();

			timer.start();
			orig_vec.push_back(16);
			orig_vec.push_back(4545);
			orig_vec.push_back(3);
			std_time = timer.stop();

			result("push_back   ", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
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

			result("pop_back    ", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
		}


	template <class ft_vec, class std_vec>
		void	insertCheckString(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			{
			// <<<<<<<<<<<<<<< Tests for insert(range) >>>>>>>>>>>>>>>
				ft_vec	myTmp;
				std_vec	origTmp;

				for (size_t i = 0; i < factor; i++){
					myTmp.push_back("hola");
					origTmp.push_back("hola");
				}

				timer.start();
				my_vec.insert(my_vec.end(), myTmp.begin(), myTmp.end());
				ft_time = timer.stop();

				timer.start();
				orig_vec.insert(orig_vec.end(), origTmp.begin(), origTmp.end());
				std_time = timer.stop();

				result("insert(range)", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
			}
			{
			// <<<<<<<<<<<<<<< Tests for insert(single elem) >>>>>>>>>>>>>>>

			typename ft_vec::iterator	ftIter = my_vec.begin();
			typename std_vec::iterator	stdIter = orig_vec.begin();
				timer.start();
				ftIter = my_vec.insert(ftIter + 2, "hola");
				ft_time = timer.stop();

				timer.start();
				stdIter = orig_vec.insert(stdIter + 2, "hola");
				std_time = timer.stop();

				result("insert(single)", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));

			// <<<<<<<<<<<<<<< Tests for insert(fill) >>>>>>>>>>>>>>>
				timer.start();
				my_vec.insert(ftIter, 2, "bbb");
				ft_time = timer.stop();

				timer.start();
				orig_vec.insert(stdIter, 2, "bbb");
				std_time = timer.stop();

				result("insert(fill)", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
			}
		}

	template <class ft_vec, class std_vec>
		void	insertCheckChar(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;
			{
			// <<<<<<<<<<<<<<< Tests for insert(range) >>>>>>>>>>>>>>>
				ft_vec	myTmp;
				std_vec	origTmp;

				for (size_t i = 0; i < factor; i++){
					myTmp.push_back('t');
					origTmp.push_back('t');
				}

				timer.start();
				my_vec.insert(my_vec.end(), myTmp.begin(), myTmp.end());
				ft_time = timer.stop();

				timer.start();
				orig_vec.insert(orig_vec.end(), origTmp.begin(), origTmp.end());
				std_time = timer.stop();

				result("insert(range)", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
			}
			{
				typename ft_vec::iterator	ftIter = my_vec.begin();
				typename std_vec::iterator	stdIter = orig_vec.begin();
			// <<<<<<<<<<<<<<< Tests for insert(single elem) >>>>>>>>>>>>>>>
				timer.start();
				ftIter = my_vec.insert(ftIter + 2, 't');
				ft_time = timer.stop();

				timer.start();
				stdIter = orig_vec.insert(stdIter + 2, 't');
				std_time = timer.stop();

				result("insert(single)", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));

			// <<<<<<<<<<<<<<< Tests for insert(fill) >>>>>>>>>>>>>>>

				timer.start();
				my_vec.insert(ftIter, 2, 't');
				ft_time = timer.stop();

				timer.start();
				orig_vec.insert(stdIter, 2, 't');
				std_time = timer.stop();

				result("insert(fill)", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
			}
		}

	template <class ft_vec, class std_vec>
		void	insertCheckInt(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			{
			// <<<<<<<<<<<<<<< Tests for insert(range) >>>>>>>>>>>>>>>
				ft_vec	myTmp;
				std_vec	origTmp;

				for (size_t i = 0; i < factor; i++){
					myTmp.push_back(i);
					origTmp.push_back(i);
				}

				timer.start();
				my_vec.insert(my_vec.end(), myTmp.begin(), myTmp.end());
				ft_time = timer.stop();

				timer.start();
				orig_vec.insert(orig_vec.end(), origTmp.begin(), origTmp.end());
				std_time = timer.stop();

				result("insert(range)", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
			}
			{
				typename ft_vec::iterator	ftIter = my_vec.begin();
				typename std_vec::iterator	stdIter = orig_vec.begin();

			// <<<<<<<<<<<<<<< Tests for insert(single elem) >>>>>>>>>>>>>>>
				timer.start();
				ftIter = my_vec.insert((ftIter + 2), 6);
				ft_time = timer.stop();

				timer.start();
				stdIter = orig_vec.insert((stdIter + 2), 6);
				std_time = timer.stop();

				result("insert(single)", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
			// <<<<<<<<<<<<<<< Tests for insert(fill) >>>>>>>>>>>>>>>

				timer.start();
				my_vec.insert(ftIter, 2, 5);
				ft_time = timer.stop();

				timer.start();
				orig_vec.insert(stdIter, 2, 5);
				std_time = timer.stop();

				result("insert(fill)", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
			}
		}


	template <class ft_vec, class std_vec>
		void	eraseCheck(ft_vec &my_vec, std_vec &orig_vec){
			typedef typename ft_vec::iterator	myIter;
			typedef typename std_vec::iterator	origIter;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			myIter		myTmp = my_vec.begin();
			origIter	origTmp = orig_vec.begin();
			{
			// <<<<<<<<<<<<<<< Tests for insert(position) >>>>>>>>>>>>>>>
				timer.start();
				myTmp = my_vec.erase(myTmp+6);
				my_vec.erase(myTmp + 3);
				my_vec.erase(my_vec.begin() + my_vec.size() - 1);
				ft_time = timer.stop();

				timer.start();
				origTmp = orig_vec.erase(origTmp+6);
				orig_vec.erase(origTmp + 3);
				orig_vec.erase(orig_vec.begin() + orig_vec.size() - 1);
				std_time = timer.stop();

				result("erase(position)", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
			}
			{
			// <<<<<<<<<<<<<<< Tests for insert(range) >>>>>>>>>>>>>>>
				timer.start();
				my_vec.erase(my_vec.begin(), (my_vec.begin() + 3));
				ft_time = timer.stop();

				timer.start();
				orig_vec.erase(orig_vec.begin(), (orig_vec.begin() + 3));
				std_time = timer.stop();

				result("erase(range)", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
			}
		}


	template <class ft_vec, class std_vec>
		void	swapCheckString(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			ft_vec	myTmp;
			std_vec origTmp;

			for (size_t i = 0; i < factor; i++){
				myTmp.push_back("Cumpleanios");
				origTmp.push_back("Cumpleanios");
			}
			timer.start();
			my_vec.swap(myTmp);
			ft_time = timer.stop();

			timer.start();
			orig_vec.swap(origTmp);
			std_time = timer.stop();

			result("swap        ", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
		}

	template <class ft_vec, class std_vec>
		void	swapCheckChar(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			ft_vec	myTmp;
			std_vec origTmp;

			for (size_t i = 0; i < factor; i++){
				myTmp.push_back('r');
				origTmp.push_back('r');
			}
			timer.start();
			my_vec.swap(myTmp);
			ft_time = timer.stop();

			timer.start();
			orig_vec.swap(origTmp);
			std_time = timer.stop();

			result("swap        ", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
		}

	template <class ft_vec, class std_vec>
		void	swapCheckInt(ft_vec &my_vec, std_vec &orig_vec){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			ft_vec	myTmp;
			std_vec origTmp;

			for (size_t i = 0; i < factor; i++){
				myTmp.push_back(i*2);
				origTmp.push_back(i*2);
			}
			timer.start();
			my_vec.swap(myTmp);
			ft_time = timer.stop();

			timer.start();
			orig_vec.swap(origTmp);
			std_time = timer.stop();

			result("swap        ", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
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

			result("clear        ", my_vec, orig_vec, ft_time, std_time, compareVectors(my_vec, orig_vec));
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

			result("begin        ", my_vec, orig_vec, ft_time, std_time,
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

			result("end          ", my_vec, orig_vec, ft_time, std_time,
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

			result("rbegin        ", my_vec, orig_vec, ft_time, std_time,
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

			result("rend          ", my_vec, orig_vec, ft_time, std_time,
					((*myIter) == (*origIter)));
		}



	//~~~~~~~~~~~~~~~~~~~ CHECKS_FOR ITERATOR ~~~~~~~~~~~~~~~~~~~

	template <class ft_vec, class revIterType>
		void	checkIterators(ft_vec& vec, revIterType& rev){

		typedef typename ft_vec::iterator iter_type;

		iter_type from (vec.begin());
		std::cout << "_______________" << std::endl;
		std::cout << "|BEGIN_ITER: "
					<< *(from.base())
					<< std::endl;
		iter_type until (vec.end());
		std::cout << "|END_ITER: "
					<< *(until.base() - 1)
					<< std::endl;
		/*usual_operations*/std::cout << "{" << std::endl;
		std::cout << "	OPERATOR+ (begin+3):	"
					<< *(from+3)
					<< std::endl;
		std::cout << "	OPERATOR- (end-2):	"
					<< *(until-2)
					<< std::endl << std::endl;
		std::cout << "	++OPERATOR (++begin):	"
					<< *(++from)
					<< std::endl;
		std::cout << "	--OPERATOR (--end):	"
					<< *(--until)
					<< std::endl << std::endl;
		std::cout << "	OPERATOR++ (begin++):	"
					<< *(from++)
					<< "   *after post-icrement* "
					<< *(from)
					<< std::endl;
		std::cout << "	OPERATOR-- (end--):	"
					<< *(until--)
					<< "   *after post-decrement* "
					<< *(until)
					<< std::endl << std::endl;
		std::cout << "	OPERATOR+= (begin += 1):"
					<< *(from += 1)
					<< std::endl;
		std::cout << "	OPERATOR-= (end -= 1):	"
					<< *(until -= 1)
					<< std::endl << std::endl;
		std::cout << "	OPERATOR[] (from[1]):	"
					<< from[1]
					<< std::endl << std::endl;


		std::cout << "}" << std::endl << std::endl;


		iter_type			forRevFrom(vec.begin());
		iter_type			forRevUntil(vec.end());
		revIterType rev_from (forRevUntil);
		std::cout << "_______________________" << std::endl;
		std::cout << "|BEGIN_REVERSE_ITER: "
					<< *(rev_from.base() - 1)
					<< std::endl;
		revIterType rev_until (forRevFrom);
		std::cout << "|END_REVERSE_ITER: "
					<< *(rev_until.base())
					<< std::endl;
		/*reverse_operations*/std::cout << "{" << std::endl;
		std::cout << "	REV_OPERATOR+ (begin+3):	"
					<< *(rev_from+3)
					<< std::endl;
		std::cout << "	REV_OPERATOR- (end-2):		"
					<< *(rev_until-2)
					<< std::endl << std::endl;
		std::cout << "	REV_++OPERATOR (++begin):	"
					<< *(++rev_from)
					<< std::endl;
		std::cout << "	REV_--OPERATOR (--end):		"
					<< *(--rev_until)
					<< std::endl << std::endl;
		std::cout << "	REV_OPERATOR++ (begin++):	"
					<< *(rev_from++)
					<< "   *after post-icrement* "
					<< *(rev_from)
					<< std::endl;
		std::cout << "	REV_OPERATOR-- (end--):		"
					<< *(rev_until--)
					<< "   *after post-decrement* "
					<< *(rev_until)
					<< std::endl << std::endl;
		std::cout << "	REV_OPERATOR+= (begin += 1):	"
					<< *(from += 1)
					<< std::endl;
		std::cout << "	REV_OPERATOR-= (end -= 1):	"
					<< *(until -= 1)
					<< std::endl << std::endl;
		std::cout << "	REV_OPERATOR[] (from[1]):	"
					<< from[1]
					<< std::endl << std::endl;
		std::cout << "}" << std::endl << std::endl;

		///////////////////
		(void)rev;
	}

}

#endif
