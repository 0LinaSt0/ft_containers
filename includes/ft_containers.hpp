/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   containers.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:07:27 by msalena           #+#    #+#             */
/*   Updated: 2022/09/03 14:36:07 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTAINERS_HPP
#define CONTAINERS_HPP

#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <deque>
#include <stack>
#include <map>
#include <set>


void	treeChecks(void);
template <class node>
	void	printAllAboutNode(node& treeNode);

namespace ft{

	/*Equal functions and helpfully functions for their*/
	template <class InputIterator1, class InputIterator2>
		bool	equal(InputIterator1 first1, InputIterator1 last1,
				InputIterator2 first2){
			if (!first1.base() || !first2.base()) return false;
			while (first1 != last1){
				if (*(first1) != *(first2)){
					return false;
				}
				first1++; first2++;
			}
			return true;
		}

	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
		bool	equal(InputIterator1 first1, InputIterator1 last1,
				InputIterator2 first2, BinaryPredicate pred){
			while (first1 != last1){
				if (pred(*(first1), *(first2)) == false)
					return false;
				first1++; first2++;
			}
			return true;
		}

	template< class InputIt1, class InputIt2 >
		bool	lexicographical_compare( InputIt1 first1, InputIt1 last1,
											InputIt2 first2, InputIt2 last2){
			while ((first1 != last1) && (first2 != last2)) {
				if (*first1 < *first2) { return true; }
				if (*first2 < *first1) { return false; }
				first1++;
				first2++;
			}
			return (first1 == last1) && (first2 != last2);
		}

	template<class InputIt1, class InputIt2, class Compare>
		bool lexicographical_compare(InputIt1 first1, InputIt1 last1,
										InputIt2 first2, InputIt2 last2,
										Compare comp){
			if (!first1.base() || !first2.base()) return false;
			while ((first1 != last1) && (first2 != last2)) {
				if (comp(*first1, *first2)) { return true; }
				if (comp(*first2, *first1)) { return false; }
				first1++;
				first2++;
			}
			return (first1 == last1) && (first2 != last2);
		}

	/*Pair class for constructing two type of elements to ine class objects*/
	template < class T1, class T2 >
		class pair {
		public:
			typedef T1	first_type;
			typedef T2	second_type;

			first_type	first;
			second_type	second;

			pair () : first (first_type()), second (second_type()) {}
			template < class U, class V >
				pair (const pair < U, V > &pr) : first (pr.first), second (pr.second) {}
			pair (const first_type &a, const second_type &b) : first (a), second (b) {}
			~pair () {}

			pair& operator= (const pair& pr) {
				first = pr.first;
				second = pr.second;
				return *this;
			}
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

	enum	nodeColor{
		RED = 'r',
		BLACK = 'b',
		DOUBLE_BLACK = 'd'
	} ;

	template <class value_type>
		struct _tree_node{
			typedef _tree_node*						pointer_node;

			value_type		value;
			nodeColor		color;
			bool			isItNil;
			pointer_node	previous;
			pointer_node	nextRight;
			pointer_node	nextLeft;

			_tree_node(const value_type& other) : value(other) {}
		} ;
}

#endif
