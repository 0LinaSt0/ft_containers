/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:44:46 by msalena           #+#    #+#             */
/*   Updated: 2022/07/09 14:46:19 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP

#include <iostream>
#include <string>
#include <stddef.h>
#include <memory>

namespace ft{
	template<typename vecType>
		struct remove_pointer
		{
			typedef vecType type;
		};

	template<typename vecType>
		struct remove_pointer<vecType*>
		{
			typedef typename remove_pointer<vecType>::type type;
		};
	
	template < class Tp >
		struct iterator_traits {
			typedef ptrdiff_t 							difference_type; // result of subtracting (-) one iterator from another
			typedef typename remove_pointer<Tp>::type	value_type; // the type of the element
			typedef value_type&							reference; // the type of a reference to an element
			typedef Tp									pointer; // the type of a pointer to an element
			typedef std::random_access_iterator_tag		iterator_category; // the iterator category
		} ;

	template < class Iter >
		class	iterator{
		protected:
			typedef Iter	iterator_type;
			iterator_type	vectorElem;
		public:
			typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
			typedef typename iterator_traits<iterator_type>::value_type			value_type;
			typedef typename iterator_traits<iterator_type>::pointer			pointer;
			typedef typename iterator_traits<iterator_type>::reference			reference;
			typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;

			iterator (void) : vectorElem (NULL){ } //default
			iterator (const iterator_type vecElem) : vectorElem (vecElem){ } // assign 
			iterator (const iterator& other) : vectorElem (other.base()){ } // copy
			~iterator (void){} // destructor

			//Operator
			reference	operator* (void) const { return *vectorElem; }
			reference	operator[](difference_type distan) const { return vectorElem[distan]; }
			pointer		operator->(void) const { return vectorElem; }
			iterator&	operator=(const iterator& other) { vectorElem = other.vectorElem; return *this; }
			iterator&	operator++(void) { ++vectorElem; return *this; }
			iterator	operator++(int) { iterator _new(*this); ++(*this); return _new; }
			iterator&	operator--(void) { --vectorElem; return *this; }
			iterator	operator--(int) { iterator _new(*this); --(*this); return _new; }
			iterator	operator+(difference_type distan) const {iterator it(*this); it += distan; return it; }
			iterator	operator-(difference_type distan) const { iterator it(*this); it -= distan; return it;; } //{ vectorElem -= distan; return *this; }
			iterator&	operator+=(difference_type distan) { vectorElem += distan; return *this; }
			iterator&	operator-=(difference_type distan) { vectorElem -= distan; return *this; }

			pointer		base(void) const { return vectorElem; }
		} ;

	template < class Iter >
		class	reverse_iterator : public iterator < Iter > {
		protected:
			Iter	current;
		public:
			typedef typename Iter::difference_type		difference_type;
			typedef typename Iter::value_type			value_type;
			typedef typename Iter::pointer				pointer;
			typedef typename Iter::reference			reference;
			typedef typename Iter::iterator_category	iterator_category;

			reverse_iterator (void) : current() { }
			explicit reverse_iterator (Iter it) : current (it){ }
			template < class Type >
				reverse_iterator (const reverse_iterator<Type> &rev_it) { *this = rev_it; }
			~reverse_iterator (void) { }

			//Operator
			reference			operator*(void) const { Iter ret = current; return (*--ret); }
			reverse_iterator	operator+(difference_type n) const { reverse_iterator it (current - n); return it; }
			reverse_iterator	operator-(difference_type n) const { return reverse_iterator(current + n); }
			reverse_iterator&	operator++(void) { --current; return *this; }
			reverse_iterator	operator++(int) { reverse_iterator it(*this); --current; return it; }
			reverse_iterator&	operator--(void) { ++current; return *this; }
			reverse_iterator	operator--(int) { reverse_iterator it(*this); ++current; return it; }
			reverse_iterator&	operator+=(difference_type n) { current-= n; return *this; }
			reverse_iterator&	operator-=(difference_type n) { current += n; return *this; }
			pointer				operator->(void) const { return &(operator*()); }
			reference			operator[] (difference_type n) const { return *(current + n); }

			Iter base() const { return current; }
		} ;
	template <class Iter1, class Iter2>
		bool		operator==(const iterator<Iter1>& a, const iterator<Iter2>& b){ return a.base() == b.base(); }
	template <class Iter1, class Iter2>
		bool		operator<(const iterator<Iter1>& a, const iterator<Iter2>& b) { return a.base() < b.base(); }
	template <class Iter1, class Iter2>
		bool		operator!=(const iterator<Iter1>& a, const iterator<Iter2>& b) { return a.base() != b.base(); }
	template <class Iter1, class Iter2>
		bool		operator>(const iterator<Iter1>& a, const iterator<Iter2>& b) { return a.base() > b.base(); }
	template <class Iter1, class Iter2>
		bool		operator>=(const iterator<Iter1>& a, const iterator<Iter2>& b) { return a.base() >= b.base(); }
	template <class Iter1, class Iter2>
		bool		operator<=(const iterator<Iter1>& a, const iterator<Iter2>& b) { return a.base() <= b.base(); }

		template <class Iter1, class Iter2>
		bool		operator==(const reverse_iterator<Iter1>& a, const reverse_iterator<Iter2>& b){ return a.base() == b.base(); }
	template <class Iter1, class Iter2>
		bool		operator<(const reverse_iterator<Iter1>& a, const reverse_iterator<Iter2>& b) { return a.base() < b.base(); }
	template <class Iter1, class Iter2>
		bool		operator!=(const reverse_iterator<Iter1>& a, const reverse_iterator<Iter2>& b) { return a.base() != b.base(); }
	template <class Iter1, class Iter2>
		bool		operator>(const reverse_iterator<Iter1>& a, const reverse_iterator<Iter2>& b) { return a.base() > b.base(); }
	template <class Iter1, class Iter2>
		bool		operator>=(const reverse_iterator<Iter1>& a, const reverse_iterator<Iter2>& b) { return a.base() >= b.base(); }
	template <class Iter1, class Iter2>
		bool		operator<=(const reverse_iterator<Iter1>& a, const reverse_iterator<Iter2>& b) { return a.base() <= b.base(); }
}

#endif