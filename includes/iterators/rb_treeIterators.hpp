/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_treeIterators.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:22:09 by marvin            #+#    #+#             */
/*   Updated: 2022/09/18 13:39:22 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE_ITERATORS_HPP
#define RB_TREE_ITERATORS_HPP

#include "../ft_containers.hpp"

namespace ft{
	template < class value_type >
		class rb_tree_iter{
		public:
			typedef ptrdiff_t											difference_type;
			typedef value_type*											pointer;
			typedef value_type&											reference;
			typedef std::bidirectional_iterator_tag						iterator_category;

			typedef typename _tree_node<value_type>::pointer_node		pointer_node;
		protected:
			pointer_node	node;

			pointer_node	_findNextNode(pointer_node elem){
				pointer_node	returned = elem;
				if (returned->nextRight->isItNil){
					pointer_node parent = returned->previous;
					while(parent && (returned == parent->nextRight)){
						returned = parent;
						parent = parent->previous;
					}
					if (!parent) { returned = elem->nextRight; }
					if (returned->nextRight != parent) { returned = parent; }
				} else {
					returned = returned->nextRight;
					while (!returned->nextLeft->isItNil) {
						returned = returned->nextLeft;
					}
				}
				return returned;
			}

			pointer_node	_findPrevNode(pointer_node elem){
				pointer_node	returned = elem;

				if (returned->isItNil) { return returned->previous; }

				if (returned->nextLeft->isItNil){
					pointer_node parent = returned->previous;
					while(parent && returned == parent->nextLeft){
						returned = parent;
						parent = parent->previous;
					}
					if (!parent) { returned = elem->nextLeft; }
					if (returned->nextLeft != parent) { returned = parent; }
				} else {
					returned = returned->nextLeft;
					while (!returned->nextRight->isItNil) {
						returned = returned->nextRight;
					}
				}
				return returned;
			}
		public:
			rb_tree_iter(void) : node (NULL) { }
			rb_tree_iter(const rb_tree_iter& tree) { node = tree.node; }
			rb_tree_iter(const pointer_node tree) : node(tree) { }
			~rb_tree_iter(void) { }

			reference		operator* (void) const { return (*node).value; }
			pointer			operator->(void) const { return &node->value; }
			rb_tree_iter&	operator=(const rb_tree_iter& other) { node = other.node; return *this; }
			rb_tree_iter&	operator++(void) { node = _findNextNode(node); return *this; }
			rb_tree_iter	operator++(int) { rb_tree_iter _new = *this; node = _findNextNode(node); return _new; }
			rb_tree_iter&	operator--(void) { node = _findPrevNode(node); return *this; }
			rb_tree_iter	operator--(int) { rb_tree_iter _new = *this; node = _findPrevNode(node); return _new; }

			pointer_node	base(void) const { return node; }
		} ;

	template < class rbIter>
		class	rb_tree_rev_iter : public rb_tree_iter <rbIter>{
		protected:
			rbIter	iterTree;
		public:
			typedef typename rbIter::difference_type	difference_type;
			typedef typename rbIter::pointer			pointer;
			typedef typename rbIter::reference			reference;
			typedef typename rbIter::iterator_category	iterator_category;
			typedef rb_tree_rev_iter					rbRevIter;

			rb_tree_rev_iter(void) : iterTree (NULL) { }
			template < class Type >
				rb_tree_rev_iter (const rb_tree_rev_iter<Type>& revIter) { *this = revIter; }
			rb_tree_rev_iter(const rbIter revIter) : iterTree(revIter) { }
			~rb_tree_rev_iter(void) { }

			reference	operator* (void) const { rbIter t = iterTree; return (--t).base()->value; }
			pointer		operator->(void) const { return &(operator*()); }
			rbRevIter&	operator=(const rbRevIter& other) { iterTree = other.iterTree; return *this; }
			rbRevIter&	operator++(void) { --iterTree; return *this; }
			rbRevIter	operator++(int) { rbRevIter _new(*this); --iterTree; return _new; }
			rbRevIter&	operator--(void) { ++iterTree; return *this; }
			rbRevIter	operator--(int) { rbRevIter _new(*this); ++iterTree; return _new; }

			rbIter		base(void) const { return iterTree; }

		} ;

		template <class Iter1, class Iter2>
			bool	operator==(const rb_tree_iter<Iter1>& a, const rb_tree_iter<Iter2>& b)
				{ return a.base() == b.base(); }
		template <class Iter1, class Iter2>
			bool	operator!=(const rb_tree_iter<Iter1>& a, const rb_tree_iter<Iter2>& b)
				{ return a.base() != b.base(); }

		template <class Iter1, class Iter2>
			bool	operator==(const rb_tree_rev_iter<Iter1>& a, const rb_tree_rev_iter<Iter2>& b)
				{ return a.base() == b.base(); }
		template <class Iter1, class Iter2>
			bool	operator!=(const rb_tree_rev_iter<Iter1>& a, const rb_tree_rev_iter<Iter2>& b)
				{ return a.base() != b.base(); }

}

#endif
