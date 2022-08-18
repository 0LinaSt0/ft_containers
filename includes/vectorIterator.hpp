/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:44:46 by msalena           #+#    #+#             */
/*   Updated: 2022/07/16 20:52:06 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTORITERATOR_HPP
#define VECTORITERATOR_HPP

#include <iostream>
#include <string>
#include <stddef.h>
#include <memory>

namespace ft{
	// template<typename stackType>
	// 	struct remove_pointer
	// 	{
	// 		typedef stackType type;
	// 	};

	// template<typename stackType>
	// 	struct remove_pointer<stackType*>
	// 	{
	// 		typedef typename remove_pointer<stackType>::type type;
	// 	};

	template < class Tp >
		struct iterator_traits {
			typedef ptrdiff_t 							difference_type; // result of subtracting (-) one iterator from another
			typedef Tp									value_type; // the type of the element
			typedef value_type&							reference; // the type of a reference to an element
			typedef Tp*									pointer; // the type of a pointer to an element
			typedef std::random_access_iterator_tag		iterator_category; // the iterator category
		} ;
	// template < class Tp >
	// 	struct iterator_traits<Tp*> {
	// 		typedef ptrdiff_t 							difference_type; // result of subtracting (-) one iterator from another
	// 		typedef typename remove_pointer<Tp>::type	value_type; // the type of the element
	// 		typedef value_type&							reference; // the type of a reference to an element
	// 		typedef Tp									pointer; // the type of a pointer to an element
	// 		typedef std::random_access_iterator_tag		iterator_category; // the iterator category
	// 	} ;


	template < class Iter >
		class	iterVec{
		public:
			typedef Iter														iterator_type;
			typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
			typedef typename iterator_traits<iterator_type>::value_type			value_type;
			typedef typename iterator_traits<iterator_type>::pointer			pointer;
			typedef typename iterator_traits<iterator_type>::reference			reference;
			typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
		protected:
			pointer														vectorElem;
		public:
			iterVec (void) : vectorElem (NULL){ } //default
			iterVec (const pointer vecElem) : vectorElem (vecElem){ } // assign
			iterVec (const iterVec& other) : vectorElem (other.base()){ } // copy
			~iterVec (void){} // destructor

			//Operator
			reference	operator* (void) const { return *vectorElem; }
			reference	operator[](difference_type distan) const { return vectorElem[distan]; }
			pointer		operator->(void) const { return vectorElem; }
			iterVec&	operator=(const iterVec& other) { vectorElem = other.vectorElem; return *this; }
			iterVec&	operator++(void) { ++vectorElem; return *this; }
			iterVec		operator++(int) { iterVec _new(*this); ++(*this); return _new; }
			iterVec&	operator--(void) { --vectorElem; return *this; }
			iterVec		operator--(int) { iterVec _new(*this); --(*this); return _new; }
			iterVec		operator+(difference_type distan) const {iterVec it(*this); it += distan; return it; }
			iterVec		operator-(difference_type distan) const { iterVec it(*this); it -= distan; return it;; } //{ vectorElem -= distan; return *this; }
			iterVec&	operator+=(difference_type distan) { vectorElem += distan; return *this; }
			iterVec&	operator-=(difference_type distan) { vectorElem -= distan; return *this; }

			pointer		base(void) const { return vectorElem; }
		} ;

	template < class Iter >
		class	revIterVec : public iterVec < Iter > {
		protected:
			Iter	current;
		public:
			typedef typename Iter::difference_type		difference_type;
			typedef typename Iter::value_type			value_type;
			typedef typename Iter::pointer				pointer;
			typedef typename Iter::reference			reference;
			typedef typename Iter::iterator_category	iterator_category;

			revIterVec (void) : current() { }
			explicit revIterVec (Iter it) : current (it){ }
			template < class Type >
				revIterVec (const revIterVec<Type> &rev_it) { *this = rev_it; }
			~revIterVec (void) { }

			//Operator
			reference	operator*(void) const { Iter ret = current; return (*--ret); }
			reference	operator[] (difference_type n) const { return *(current + n); }
			pointer		operator->(void) const { return &(operator*()); }
			revIterVec&	operator++(void) { --current; return *this; }
			revIterVec	operator++(int) { revIterVec it(*this); --current; return it; }
			revIterVec&	operator--(void) { ++current; return *this; }
			revIterVec	operator--(int) { revIterVec it(*this); ++current; return it; }
			revIterVec	operator+(difference_type n) const { revIterVec it (current - n); return it; }
			revIterVec	operator-(difference_type n) const { return revIterVec(current + n); }
			revIterVec&	operator+=(difference_type n) { current-= n; return *this; }
			revIterVec&	operator-=(difference_type n) { current += n; return *this; }

			Iter base() const { return current; }
		} ;
	template <class Iter1, class Iter2>
		bool		operator==(const iterVec<Iter1>& a, const iterVec<Iter2>& b){ return a.base() == b.base(); }
	template <class Iter1, class Iter2>
		bool		operator<(const iterVec<Iter1>& a, const iterVec<Iter2>& b) { return a.base() < b.base(); }
	template <class Iter1, class Iter2>
		bool		operator!=(const iterVec<Iter1>& a, const iterVec<Iter2>& b) { return a.base() != b.base(); }
	template <class Iter1, class Iter2>
		bool		operator>(const iterVec<Iter1>& a, const iterVec<Iter2>& b) { return a.base() > b.base(); }
	template <class Iter1, class Iter2>
		bool		operator>=(const iterVec<Iter1>& a, const iterVec<Iter2>& b) { return a.base() >= b.base(); }
	template <class Iter1, class Iter2>
		bool		operator<=(const iterVec<Iter1>& a, const iterVec<Iter2>& b) { return a.base() <= b.base(); }

		template <class Iter1, class Iter2>
		bool		operator==(const revIterVec<Iter1>& a, const revIterVec<Iter2>& b){ return a.base() == b.base(); }
	template <class Iter1, class Iter2>
		bool		operator<(const revIterVec<Iter1>& a, const revIterVec<Iter2>& b) { return a.base() < b.base(); }
	template <class Iter1, class Iter2>
		bool		operator!=(const revIterVec<Iter1>& a, const revIterVec<Iter2>& b) { return a.base() != b.base(); }
	template <class Iter1, class Iter2>
		bool		operator>(const revIterVec<Iter1>& a, const revIterVec<Iter2>& b) { return a.base() > b.base(); }
	template <class Iter1, class Iter2>
		bool		operator>=(const revIterVec<Iter1>& a, const revIterVec<Iter2>& b) { return a.base() >= b.base(); }
	template <class Iter1, class Iter2>
		bool		operator<=(const revIterVec<Iter1>& a, const revIterVec<Iter2>& b) { return a.base() <= b.base(); }
}

#endif
