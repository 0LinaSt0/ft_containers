/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:48:35 by marvin            #+#    #+#             */
/*   Updated: 2022/08/11 16:48:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPITERATOR_HPP
#define MAPITERATOR_HPP

#include "map.hpp"

namespace ft{

	template < class Tp >
		struct iterator_traits {
			typedef ptrdiff_t 							difference_type; // result of subtracting (-) one iterator from another
			typedef Tp									value_type; // the type of the element
			typedef value_type&							reference; // the type of a reference to an element
			typedef Tp*									pointer; // the type of a pointer to an element
			typedef std::bidirectional_iterator_tag		iterator_category; // the iterator category
		} ;

	template < class Iter >
		class iterMap{
		public:
			typedef Iter														iterator_type;
			typedef typename iterator_traits<iterator_type>::difference_type	difference_type;
			typedef typename iterator_traits<iterator_type>::value_type			value_type;
			typedef typename iterator_traits<iterator_type>::pointer			pointer;
			typedef typename iterator_traits<iterator_type>::reference			reference;
			typedef typename iterator_traits<iterator_type>::iterator_category	iterator_category;
		protected:
			pointer	tree;
		public:
			iterMap	(void) : tree (NULL) { }
			iterMap (const pointer tree) : tree(tree) { }
			iterMap (const iterMap& otherTree) : tree(otherTree.base()) { }
			~IterMap (void) { }

			reference	operator* (void) const { return *vectorElem; }
			pointer		operator->(void) const { return vectorElem; }
			iterVec&	operator=(const iterVec& other) { vectorElem = other.vectorElem; return *this; }
			iterVec&	operator++(void) { ++vectorElem; return *this; }
			iterVec		operator++(int) { iterVec _new(*this); ++(*this); return _new; }
			iterVec&	operator--(void) { --vectorElem; return *this; }
			iterVec		operator--(int) { iterVec _new(*this); --(*this); return _new; }

			pointer		base(void) const { return vectorElem; }
		}
}

#endif
