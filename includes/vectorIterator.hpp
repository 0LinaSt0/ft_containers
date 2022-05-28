/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:44:46 by msalena           #+#    #+#             */
/*   Updated: 2022/05/28 20:12:53 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP

#include <iostream>
#include <string>
#include <stddef.h>
#include <memory>

namespace ft{
	template<typename T>
		struct remove_pointer
		{
			typedef T type;
		};

	template<typename T>
		struct remove_pointer<T*>
		{
			typedef typename remove_pointer<T>::type type;
		};
	
	template < class Tp >
		struct iterator_traits {
			typedef ptrdiff_t 							difference_type; // result of subtracting (-) one iterator from another
			typedef typename remove_pointer<Tp>::type	value_type; // the type of the element
			typedef value_type&							reference; // the type of a reference to an element
			typedef Tp									pointer; // the type of a pointer to an element
			typedef std::random_access_iterator_tag		iterator_category; // the iterator category
		} ;

	template < class Type >
		class	Iter{
		protected:
			typedef Type	iterator_type;
			iterator_type	vectorElem;
		public:
			typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
			typedef typename iterator_traits<iterator_type>::value_type			value_type;
			typedef typename iterator_traits<iterator_type>::pointer			pointer;
			typedef typename iterator_traits<iterator_type>::reference			reference;
			typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
			
			Iter (void) : vectorElem (NULL){} //default
			Iter (const iterator_type vecElem) : vectorElem (vecElem){ } // assign 
			Iter (const Iter& other){ *this = other; } // copy
			~Iter (void){} // destructor

			//Operator
			reference	operator* (void) const { return *vectorElem; }
			reference	operator[](difference_type distan) const { return vectorElem[distan]; }
			pointer		operator->(void) const { return vectorElem; }
			Iter&		operator=(const Iter& other) { vectorElem = other.vectorElem; return *this; }
			Iter&		operator++(void) { ++vectorElem; return *this; }
			Iter		operator++(int) { Iter _new = *this; ++vectorElem; return _new; }
			Iter&		operator--(void) { --vectorElem; return *vectorElem; }
			Iter		operator--(int) { Iter _new = *this; --vectorElem; return _new; }
			Iter&		operator+(difference_type distan) { vectorElem += distan; return *this; }
			Iter&		operator-(difference_type distan) { vectorElem -= distan; return *this; }
			Iter&		operator+=(difference_type distan) { vectorElem += distan; return *this; }
			Iter&		operator-=(difference_type distan) { vectorElem -= distan; return *this; }

			pointer		base(void) const { return vectorElem; }
		} ;

	template < class Type >
		class	reversIter : public Iter < Type > {
			
		} ;
	template <class Iter1, class Iter2>
		bool		operator==(const Iter<Iter1>& a, const Iter<Iter2>& b){ return a.base() == b.base(); }
	template <class Iter1, class Iter2>
		bool		operator<(const Iter<Iter1>& a, const Iter<Iter2>& b) { return a.base() < b.base(); }
	template <class Iter1, class Iter2>
		bool		operator!=(const Iter<Iter1>& a, const Iter<Iter2>& b) { return a.base() != b.base(); }
	template <class Iter1, class Iter2>
		bool		operator>(const Iter<Iter1>& a, const Iter<Iter2>& b) { return a.base() > b.base(); }
	template <class Iter1, class Iter2>
		bool		operator>=(const Iter<Iter1>& a, const Iter<Iter2>& b) { return a.base() >= b.base(); }
	template <class Iter1, class Iter2>
		bool		operator<=(const Iter<Iter1>& a, const Iter<Iter2>& b) { return a.base() <= b.base(); }
}

#endif