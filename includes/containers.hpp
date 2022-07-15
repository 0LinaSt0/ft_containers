/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   containers.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:07:27 by msalena           #+#    #+#             */
/*   Updated: 2022/07/13 21:10:10 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	/*~~~~~~~~~~~~~~~~~~Header for utilities~~~~~~~~~~~~~~~~~~*/

#ifndef CONTAINERS_HPP
#define CONTAINERS_HPP

#include <iostream>
#include <string>


namespace ft{
	/*Equal functions and helpfully functions for their*/
	template <class InputIterator1, class InputIterator2>
		bool equal (InputIterator1 first1, InputIterator1 last1,
				InputIterator2 first2){
			while (first1 != last1){
				if (*(first1) != *(first2)){
					return false;
				}
				first1++; first2++;
			}
			return true;
		}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
		bool equal (InputIterator1 first1, InputIterator1 last1,
				InputIterator2 first2, BinaryPredicate pred){
			while (first1 != last1){
				if (pred(*(first1), *(first2)) == false)
					return false;
				first1++; first2++;
			}
			return true;
		}

	template <class T1, class T2>
		bool _lessCheck(T1 a, T2 b){ return (a < b) ? true : false; }

	template <class T1, class T2>
		bool _equalLessCheck(T1 a, T2 b){ return (a <= b) ? true : false; }

	template <class T1, class T2>
		bool _moreCheck(T1 a, T2 b){ return _lessCheck(a, b) ? false : true; }

	template <class T1, class T2>
		bool _equalMoreCheck(T1 a, T2 b){ return _equalLessCheck(a, b) ? false : true; }


	/*Pair class for constructing two type of elements to ine class objects*/
	template < class T1, class T2 >
		class pair {
		public:
			typedef T1	first_type;
			typedef T2	second_type;

			first_type	first;
			second_type	second;

			pair () : first (0), second (0) {}
			template < class U, class V >
				pair (const pair < U, V > &pr) : first (pr.first), second (pr.second) {}
			pair (const first_type &a, const second_type &b) : first (a), second (b) {}
			~pair ();

			pair& operator= (const pair& pr) { first = pr.first; second = pr.second; return *this; }
		} ;

	template <class T1, class T2>
		pair<T1,T2> make_pair(T1 x, T2 y){
			return pair<T1, T2>(x, y);
		}

	template <class T1, class T2>
		bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
			return lhs.first == rhs.first && lhs.second == rhs.second;
		}

	template <class T1, class T2>
		bool operator!=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
			return !(lhs == rhs);
		}
	template <class T1, class T2>
		bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
			return lhs.first<rhs.first
						|| (!(rhs.first < lhs.first) && lhs.second < rhs.second);
		}

	template <class T1, class T2>
		bool operator<=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
			return !(rhs < lhs);
		}

	template <class T1, class T2>
		bool operator>(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
			return rhs < lhs;;
		}

	template <class T1, class T2>
		bool operator>=(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
			return !(lhs < rhs);
		}
}


#endif
