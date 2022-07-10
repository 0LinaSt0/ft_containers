/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsVec.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 11:38:01 by msalena           #+#    #+#             */
/*   Updated: 2022/07/10 18:13:21 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_VEC_HPP
#define TESTS_VEC_HPP
#include "vector.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <memory>

void	checkerForVector(void);

//~~~~~~~~~~~~~~~~~~ HELPFUL_UTILS ~~~~~~~~~~~~~~~~~~

template <class vecType>
	// Prints value of vector
	void	printVecContent(vecType &vec, bool isItOrigVector){
		std::cout << "	vector content: ";
		if (isItOrigVector){
			for (typename vecType::iterator orig = vec.begin();
			orig != vec.end(); orig++){
				std::cout << *orig << "  ";
			}
		} else {
			for (typename vecType::iterator my(vec.begin()); 
			my != vec.end(); my++){
				std::cout << *my << "  ";
			}
		}
		(void) isItOrigVector;
		std::cout << std::endl;
	}
template <class vecType>
	// Prints all information about vector
	void	printVecParams (vecType &vec, bool isItOrigVector){
		// (void)isItOrigVector;
		std::cout << "status" << std::endl;
		printVecContent(vec, isItOrigVector);
		std::cout << "	vecAddress: " << &vec << "\n"
				<< "	count elem: " << vec.size() << "\n"
				<< "	capaxity size: " << vec.capacity() << "\n"
				<< "	emptyFlag: " << vec.empty()
				<< std::endl << std::endl;
	}



//~~~~~~~~~~~ CHECKS_FOR_MEMBER_FUNCTIONS ~~~~~~~~~~~

template <class vecType>
	// Tests for RESIZE and RESERVE (reserve is called int resize)
	void	sizeNConstructor(vecType &vec, bool isItOrigVector){
		/*status*/printVecParams(vec, isItOrigVector);
		vec.resize(4);
		/*status*/printVecParams(vec,isItOrigVector);
		vec.resize(10);
		/*status*/printVecParams(vec, isItOrigVector);
		vec.resize(0);
		/*status*/printVecParams(vec, isItOrigVector);
	}

template <class vecType>
	// Tests for ASSIGN  (two overloads)
	void	assignCheck(vecType &vec, bool isItOrigVector){
			std::cout << "<<<<< ASSIGN CHECK" << std::endl << std::endl;
			
		/* <<<<<<<<<<<<<<< Tests for assign(iterator, iterator) >>>>>>>>>>>>>>>*/
			/* ~~~~~~~~~~Example 1~~~~~~~~~~ */
			// T	vec1(0);
			// typename T::iterator	wrong1Vec1(vec1.begin());
			// typename T::iterator	wrong2Vec1(vec1.end());

			// std::cout << "example # 1 assign(iterator, iterator)" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			// vec.assign(wrong1Vec1, wrong2Vec1);
			// std::cout << "example # 1 assign(iterator, iterator)" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			
			// /* ~~~~~~~~~~Example 2~~~~~~~~~~ */
			// T	vec2(12, 'd');
			// typename T::iterator	wrong1Vec2(vec2.begin());
			// typename T::iterator	wrong2Vec2(vec2.end());

			// std::cout << "example # 2 assign(iterator, iterator)" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			// vec.assign(wrong1Vec2, wrong2Vec2);
			// std::cout << "example # 2 assign(iterator, iterator)" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			
			// /* ~~~~~~~~~~Example 3~~~~~~~~~~ */
			// T	vec3(3, 'd');
			// typename T::iterator	wrong1Vec3(vec3.begin());
			// typename T::iterator	wrong2Vec3(vec3.end());

			// std::cout << "example # 3 assign(iterator, iterator)" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			// vec.assign(wrong1Vec3, wrong2Vec3);
			// std::cout << "example # 3 assign(iterator, iterator)" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);

							/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */

		/* <<<<<<<<<<<<<<< Tests for assign(size_type, value_type) >>>>>>>>>>>>>>>*/
							// FOR STD::STRING
			// /* ~~~~~~~~~~ Example 1 for std::string ~~~~~~~~~~ */
			// typedef typename T::size_type	size_type;
			// typedef typename T::value_type	value_type;

			// size_type	countElems1 = 0;
			// value_type	value1 = "hola";
			
			// std::cout << "example # 1 assign(size_type, value_type) for std::string" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			// vec.assign(countElems1, value1);
			// std::cout << "example # 1 assign(size_type, value_type) for std::string" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			
			// /* ~~~~~~~~~~Example 2 for std::string ~~~~~~~~~~ */
			// size_type	countElems2 = 10;
			// value_type	value2 = "hola";

			// std::cout << "example # 2 assign(size_type, value_type) std::string" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			// vec.assign(countElems2, value2);
			// std::cout << "example # 2 assign(size_type, value_type) std::string" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			
			// /* ~~~~~~~~~~Example 3 for std::string ~~~~~~~~~~ */
			// size_type	countElems3 = 5;
			// value_type	value3 = "gracias";

			// std::cout << "example # 3 assign(size_type, value_type) std::string" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
			// vec.assign(countElems3, value3);
			// std::cout << "example # 3 assign(size_type, value_type) std::string" << std::endl;
			// /*status*/printVecParams(vec, isItOrigVector);
								// FOR INT
			/* ~~~~~~~~~~ Example 1 for int ~~~~~~~~~~ */
			typedef typename vecType::size_type	size_type;
			typedef typename vecType::value_type	value_type;

			size_type	countElems1 = 0;
			value_type	value1 = 3;
			
			std::cout << "example # 1 assign(size_type, value_type) for int*" << std::endl;
			/*status*/printVecParams(vec, isItOrigVector);
			vec.assign(countElems1, value1);
			std::cout << "example # 1 assign(size_type, value_type) for int*" << std::endl;
			/*status*/printVecParams(vec, isItOrigVector);
			
			/* ~~~~~~~~~~Example 2 for int* ~~~~~~~~~~ */
			size_type	countElems2 = 10;
			value_type	value2 = 1;

			std::cout << "example # 2 assign(size_type, value_type) for int*" << std::endl;
			/*status*/printVecParams(vec, isItOrigVector);
			vec.assign(countElems2, value2);
			std::cout << "example # 2 assign(size_type, value_type) for int*" << std::endl;
			/*status*/printVecParams(vec, isItOrigVector);
			
			/* ~~~~~~~~~~Example 3 for int* ~~~~~~~~~~ */
			size_type	countElems3 = 5;
			value_type	value3 = 156;

			std::cout << "example # 3 assign(size_type, value_type) for int*" << std::endl;
			/*status*/printVecParams(vec, isItOrigVector);
			vec.assign(countElems3, value3);
			std::cout << "example # 3 assign(size_type, value_type) for int*" << std::endl;
			/*status*/printVecParams(vec, isItOrigVector);

							/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */

			std::cout << "-----" << std::endl;
		}

template <class vecType>
	// Tests for PUSH_BACK 
	void	push_backCheck(vecType &vec, bool isItOrigVector){
		/* <<<<<<<<<<<<<<< Tests for std::string type >>>>>>>>>>>>>>>*/
			// vec.push_back("156");
			// printVecParams(vec, isItOrigVector);
			// vec.push_back("157");
			// printVecParams(vec, isItOrigVector);
			// vec.push_back("158");
			// printVecParams(vec, isItOrigVector);
			// vec.push_back("159");
			// printVecParams(vec, isItOrigVector);
				/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */
				
		/* <<<<<<<<<<<<<<< Tests for int type >>>>>>>>>>>>>>>*/
			vec.push_back(156);
			printVecParams(vec, isItOrigVector);
			vec.push_back(157);
			printVecParams(vec, isItOrigVector);
			vec.push_back(158);
			printVecParams(vec, isItOrigVector);
			vec.push_back(159);
			printVecParams(vec, isItOrigVector);
				/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */
		}

template <class vecType>
	// Tests for POP_BACK 
	void	pop_backCheck(vecType &vec, bool isItOrigVector){
		vec.pop_back();
		printVecParams(vec, isItOrigVector);
	}

template <class vecType>
	// Tests for INSERT (three overloads) 
	void	insertCheck(vecType &vec, bool isItOrigVector){
		std::cout << "<<<<< INSERT CHECK" << std::endl << std::endl;
		typedef typename vecType::iterator	iterator;
		iterator	iterVec = vec.begin();
		/* <<<<<<<<<<<<<<< Tests for char type >>>>>>>>>>>>>>>*/
		iterVec = vec.insert(iterVec+2, 'h');
		std::cout << "example # 1 insert: add char " << std::endl;
		/*status*/printVecParams(vec, isItOrigVector);
	
		vec.insert(iterVec, 4, '~');
		std::cout << "example # 2 insert: add chars " << std::endl;
		/*status*/printVecParams(vec, isItOrigVector);
		
		vecType	newVec(8, '+');
		iterVec = vec.end();
		vec.insert(iterVec, newVec.begin(), newVec.end());
		std::cout << "example # 3 insert: add distance " << std::endl;
		/*status*/printVecParams(vec, isItOrigVector);
				/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */

		/* <<<<<<<<<<<<<<< Tests for std::string type >>>>>>>>>>>>>>>*/
		// iterVec = vec.insert(iterVec+2, "aaa");
		// std::cout << "example # 1 insert: add char " << std::endl;
		// /*status*/printVecParams(vec, isItOrigVector);
	
		// vec.insert(iterVec, 2, "bbb");
		// std::cout << "example # 2 insert: add some chars " << std::endl;
		// /*status*/printVecParams(vec, isItOrigVector);
		
		// T	newVec(8, "new");
		// iterVec = vec.end();
		// vec.insert(iterVec, newVec.begin(), newVec.end());
		// std::cout << "example # 3 insert: add distance " << std::endl;
		// /*status*/printVecParams(vec, isItOrigVector);
				/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */
				
		std::cout << ">>>>>" << std::endl;
	}

template <class vecType>
	// Tests for ERASE (two overloads) 
	void	eraseCheck(vecType &vec, bool isItOrigVector){
		std::cout << "<<<<< ERASE CHECK" << std::endl << std::endl;
		typedef typename vecType::iterator	iterator;
		iterator	iterVecBegin = vec.begin();
		iterator	returnIter;
		/* <<<<<<<<<<<<<<< Tests for int type >>>>>>>>>>>>>>>*/
		returnIter = vec.erase(iterVecBegin+2);
		std::cout << "example # 1 erase: remove elem " << std::endl;
		/*status*/printVecParams(vec, isItOrigVector);
		/*print_return*/std::cout << "	earse_return: "
								<< (*returnIter) 
								<< std::endl << std::endl;
	
		// std::cout << *iterVecBegin << std::endl;
		iterVecBegin = vec.begin();
		returnIter = vec.erase(iterVecBegin, iterVecBegin+5);
		std::cout << "example # 2 erase: remove elems " << std::endl;
		/*status*/printVecParams(vec, isItOrigVector);
		/*print_return*/std::cout << "	earse_return: "
								<< (*returnIter) 
								<< std::endl << std::endl;
				/* <<<<<<<<<<<<<<<>>>>>>>>>>>>>>> */
				
		std::cout << ">>>>>" << std::endl;
	}

template <class vecType>
	// Testd for RBEGIN and REND
	void	reverseBeginEndCheck(vecType &vec){
		std::cout << "<<<<< RBEGIN & REND CHECK" << std::endl << std::endl;
		std::cout << "rbegin: " << *(vec.rbegin()) << std::endl;
		std::cout << "rend: " << *(vec.rend()-1) << std::endl;
		std::cout << ">>>>>" << std::endl << std::endl;
	}



//~~~~~~~~~~~~~~~~~~~ CHECKS_FOR ITERATOR ~~~~~~~~~~~~~~~~~~~

template <class vecType, class revIterType>
	void	checkIterators(vecType& vec, revIterType& rev){

	typedef typename vecType::iterator iter_type;

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

#endif