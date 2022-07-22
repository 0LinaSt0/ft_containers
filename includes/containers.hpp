/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   containers.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:07:27 by msalena           #+#    #+#             */
/*   Updated: 2022/07/22 21:54:06 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

	/*~~~~~~~~~~~~~~~~~~Header for utilities~~~~~~~~~~~~~~~~~~*/

#ifndef CONTAINERS_HPP
#define CONTAINERS_HPP

#include "vectorIterator.hpp"
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <deque>
#include <stack>
#include <map>


namespace ft{
	/*Equal functions and helpfully functions for their*/
	template <class InputIterator1, class InputIterator2>
		bool equal (InputIterator1 first1, InputIterator1 last1,
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
		bool equal (InputIterator1 first1, InputIterator1 last1,
				InputIterator2 first2, BinaryPredicate pred){
			if (!first1.base() || !first2.base()) return false;
			while (first1 != last1){
				if (pred(*(first1), *(first2)) == false)
					return false;
				// std::cout << "IIIIII" << std::endl;
				first1++; first2++;
			}
			return true;
		}

	template <class T1, class T2>
		bool _lessCheck(T1 a, T2 b){ return (a < b) ? true : false; }

	template <class T1, class T2>
		bool _equalLessCheck(T1 a, T2 b){ return (a <= b) ? true : false; }

	template <class T1, class T2>
		bool _moreCheck(T1 a, T2 b){ return(a > b) ? true : false; }

	template <class T1, class T2>
		bool _equalMoreCheck(T1 a, T2 b){ return (_equalLessCheck(a, b) && a != b) ? false : true; }


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


	/* Util-functions for realization red-black tree */

	template <class Type> 
		struct rebind {
			typedef std::allocator<Type> other;
		};

	template <class _T, class _Compare>
		struct _tree_node{
			typedef _T								value_type;
			typedef _Compare						key_type;
			typedef ft::pair<key_type, value_type>	pair_type;
			typedef _tree_node*						pointer_node;
			
			pair_type		value;
			char			color;
			pointer_node	previous;
			pointer_node	next;
		} ;
	


	template <class _T, class _Compare, class _Allocator>
		class	_tree{
		public:
			typedef _T														value_type;
			typedef _Compare												value_compare;
			typedef _tree_node<_T, _Compare>								tree_node;
			typedef _Allocator												allocator_pair;
			typedef typename allocator_pair::pointer						pointer_pair;
			typedef typename allocator_pair::reference						reference_pair;
			typedef typename _Allocator::template rebind<tree_node>::other	allocator_node;
			typedef typename allocator_node::pointer						pointer_node;
			typedef typename allocator_node::reference						reference_node;
		private:
			pointer_node	node;
			bool			countElems;
			allocator_pair	pairAlloc;
			allocator_node	nodeAlloc;
		private:
			/* ~~~~~~~~~~ USEFUL FUNCTIONS FOR FINDING NODE ~~~~~~~~ 
				
			*/
		
		
			/* ~~~~~~~~~~~~ USEFUL FUNCTIONS FOR ADD NODE ~~~~~~~~~~ 
				
			*/


			/* ~~~~~~~~~~ USEFUL FUNCTIONS FOR DELETE NODE ~~~~~~~~~
				
			*/
		
		public:
			_tree(void) : node (NULL), countElems(1), 
							allocator_pair(NULL), allocator_node(NULL) {}
			~_tree(void) {/*delete*/}

			bool	empty() const { return countElems ? false : true; } 

			/* ~~~~~~~~~~~~ FIND ELEMS FUNCTIONS ~~~~~~~~~~
				at		|	Returns a reference to the node with key 'n' in tree
				root	|	Returns a reference to the first root node in tree
			*/
			
			reference_node		at(const value_compare& key) const;
			reference_node		root(void) const;


			/* ~~~~~~~~~~~~MODIFIERS FUNCTIONS ~~~~~~~~~~
				createNode	|	Create new node and return pointer to it
				addNode		|	Add coming_node to the right place and return pointer to it
				deleteNode	|	Delete deleded_node to the right place and return pointer to root
			*/
		
			pointer_node	createNode(const value_compare& nodeKey,
											const value_type& nodeValue){
				pointer_node	new_node;

				new_node = nodeAlloc.allocate(1); // dont know how much memory i need
				new_node->value = pairAlloc.allocate(1); // dont know how much memory i need
				new_node->value = make_pair(nodeKey, nodeValue);
				new_node->color = 'r';
				new_node->previous = NULL;
				new_node->next = NULL;
				
				return new_node;
			}

			pointer_node	addNode(const pointer_node& coming_node);
			pointer_node	deleteNode(const pointer_node& deleted_node);
		} ;
}


#endif
