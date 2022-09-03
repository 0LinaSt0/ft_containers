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

	/*~~~~~~~~~~~~~~~~~~Header for utilities~~~~~~~~~~~~~~~~~~*/

#ifndef CONTAINERS_HPP
#define CONTAINERS_HPP

#include "vectorIterator.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <deque>
#include <stack>
#include <map>


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

	/* Util-functions for realization red-black tree */

	template <class Type>
		struct rebind {
			typedef std::allocator<Type> other;
		};

	enum	nodeColor{
		RED = 'r',
		BLACK = 'b',
		DOUBLE_BLACK = 'd'
	} ;

	enum	olderYangerBro{
		OLDER,
		YANGER,
		NONE
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

			// _tree_node&	operator=(const _tree_node& comingTree){
			// 	value = comingTree.value;
			// 	color = comingTree.color;
			// 	previous = comingTree.previous;
			// 	nextRight = comingTree.nextRight;
			// 	nextLeft = comingTree.nextLeft;

			// 	return *this;
			// }

			// pointer_node&	operator=(const pointer_node& comingTree){
			// 	value = comingTree->value;
			// 	color = comingTree->color;
			// 	previous = comingTree->previous;
			// 	nextRight = comingTree->nextRight;
			// 	nextLeft = comingTree->nextLeft;

			// 	return *this;
			// }
		} ;

	template < class value_type >
		class _rb_tree_iter{
		public:
			// typedef value_type											val;
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
				// std::cout <<
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
			_rb_tree_iter(void) : node (NULL) { }
			_rb_tree_iter(const _rb_tree_iter& tree) { node = tree.node; }
			_rb_tree_iter(const pointer_node tree) : node(tree) { }
			~_rb_tree_iter(void) { }

			reference		operator* (void) const { return (*node).value; }
			pointer			operator->(void) const { return &node->value; }
			_rb_tree_iter&	operator=(const _rb_tree_iter& other) { node = other.node; return *this; }
			_rb_tree_iter&	operator++(void) { node = _findNextNode(node); return *this; }
			_rb_tree_iter	operator++(int) { _rb_tree_iter _new = *this; node = _findNextNode(node); return _new; }
			_rb_tree_iter&	operator--(void) { node = _findPrevNode(node); return *this; }
			_rb_tree_iter	operator--(int) { _rb_tree_iter _new = *this; node = _findPrevNode(node); return _new; }

			pointer_node	base(void) const { return node; }
		} ;

	template < class rbIter>
		class	_rb_tree_rev_iter : public _rb_tree_iter <rbIter>{
		protected:
			rbIter	iterTree;
		public:
			typedef typename rbIter::difference_type	difference_type;
			typedef typename rbIter::pointer			pointer;
			typedef typename rbIter::reference			reference;
			typedef typename rbIter::iterator_category	iterator_category;
			typedef _rb_tree_rev_iter					rbRevIter;

			_rb_tree_rev_iter(void) : iterTree (NULL) { }
			template < class Type >
				_rb_tree_rev_iter (const _rb_tree_rev_iter<Type>& revIter) { *this = revIter; }
			_rb_tree_rev_iter(const rbIter revIter) : iterTree(revIter) { }
			~_rb_tree_rev_iter(void) { }

			reference	operator* (void) const { rbIter t = iterTree; return (--t).base()->value; }
			pointer		operator->(void) const { return &(operator*()); }
			/*???*/rbRevIter&	operator=(const rbRevIter& other) { iterTree = other.iterTree; return *this; }
			rbRevIter&	operator++(void) { --iterTree; return *this; }
			rbRevIter	operator++(int) { rbRevIter _new(*this); --iterTree; return _new; }
			rbRevIter&	operator--(void) { ++iterTree; return *this; }
			rbRevIter	operator--(int) { rbRevIter _new(*this); ++iterTree; return _new; }

			rbIter		base(void) const { return iterTree; }

		} ;

		template <class Iter1, class Iter2>
			bool	operator==(const _rb_tree_iter<Iter1>& a, const _rb_tree_iter<Iter2>& b)
				{ return a.base() == b.base(); }
		template <class Iter1, class Iter2>
			bool	operator!=(const _rb_tree_iter<Iter1>& a, const _rb_tree_iter<Iter2>& b)
				{ return a.base() != b.base(); }

		template <class Iter1, class Iter2>
			bool	operator==(const _rb_tree_rev_iter<Iter1>& a, const _rb_tree_rev_iter<Iter2>& b)
				{ return a.base() == b.base(); }
		template <class Iter1, class Iter2>
			bool	operator!=(const _rb_tree_rev_iter<Iter1>& a, const _rb_tree_rev_iter<Iter2>& b)
				{ return a.base() != b.base(); }

	template <class _T, class _Compare, class _Allocator>
		class	_rb_tree {
		public:
			typedef _T															value_type;
			typedef _Compare													compare_class;
			typedef _tree_node<value_type>										tree_node;
			typedef _Allocator													allocator_type;
			typedef typename allocator_type::pointer							pointer_type;
			typedef typename allocator_type::reference							reference_type;
			typedef typename allocator_type::template rebind<tree_node>::other	allocator_node;
			typedef typename tree_node::pointer_node							pointer_node;
			typedef typename allocator_node::reference							reference_node;

			typedef ft::_rb_tree_iter<value_type>								iterator;
			typedef ft::_rb_tree_iter<value_type>								const_iterator;
			typedef ft::_rb_tree_rev_iter<iterator>								reverse_iterator;
			typedef ft::_rb_tree_rev_iter<const_iterator>						const_reverse_iterator;
			typedef ptrdiff_t													difference_type;
			typedef size_t														size_type;

		private:
			pointer_node	node;
			compare_class	compare;
			// class value_compare;
			// /*FOR TESTING MAP*/ value_compare	compare;
			size_type		countElems;
			allocator_node	nodeAlloc;

		private:
			// /*FORE CHECKING*/
			// class value_compare
			// {
			// 	friend class _rb_tree;

			// 	protected:
			// 		_Compare comp;
			// 		value_compare () {}
			// 	public:
			// 		bool operator() (const value_type& x, const value_type& y) const
			// 		{
			// 			return comp(x.first, y.first);
			// 		}
			// } ;
			/* ~~~~~~~~~~~~ USEFUL FUNCTIONS FOR ADD NODE ~~~~~~~~~~*/

			pointer_node	__findUncle(pointer_node newNode);

			void	___updateNodesPointers(pointer_node oldNode,
											pointer_node newNode);

			void	___nodeMoreGranddad(pointer_node uncle, pointer_node addedNode);
			void	___nodeLessGranddad(pointer_node uncle, pointer_node addedNode);

			void	__blackUncle(pointer_node uncle, pointer_node addedNode);
			void	__redUncle(pointer_node uncle, pointer_node addedNode);



			/* ~~~~~~~~~~~ USEFUL FUNCTIONS FOR DELETE NODE ~~~~~~~~~*/

			void	__deleteNode(pointer_node deletedNode);

			void	___pointersSwap(pointer_node& to, pointer_node& from);
			void	____childrenParentSwap(pointer_node finded, pointer_node deleted,
										bool isNodeNeigbours);
			void	____childrenSwap(pointer_node finded, pointer_node deleted,
										bool isNodeNeigbours);
			void	____parentChildrenSwap(pointer_node finded, pointer_node deleted,
										bool isNodeNeigbours);
			void	____parentsSwap(pointer_node finded, pointer_node deleted,
										bool isNodeNeigbours);
			void	____optionsSwap(pointer_node finded, pointer_node deleted,
										bool isNodeNeigbours);
			bool	____isNodeNeigboursSwap(pointer_node finded,
												pointer_node deleted);
			void	___nodesSwap(pointer_node finded, pointer_node deleted);


			void	___brotherParentChange(pointer_node doubleBlackNode,
										pair<olderYangerBro, pointer_node> bro);
			pair<olderYangerBro, pointer_node>	___olderYangerBrother(pointer_node doubleBlackNode);
			pointer_node	___findLeastRightChild(pointer_node currentNode);


			void	___yangerBrotherBalancing(pointer_node doubleBlackNode,
										pair<olderYangerBro, pointer_node> bro);
			void	___blackChildrenBalancing(pointer_node doubleBlackNode,
											pair<olderYangerBro, pointer_node> bro);
			void	___redLeftChildBalancing(pointer_node doubleBlackNode,
												pair<olderYangerBro, pointer_node> bro);
			void	___redRightChildBalancing(pointer_node doubleBlackNode,
												pair<olderYangerBro, pointer_node> bro);
			void	___redBrotherBalancing(pointer_node doubleBlackNode,
										pair<olderYangerBro,pointer_node> bro);
			void	___blackBrotherBalancing(pointer_node doubleBlackNode,
										pair<olderYangerBro,pointer_node> bro);
			void	__blackBalancing(pointer_node doubleBlackNode);

			void	__deletedWithTwoGhildren(pointer_node deletedNode);
			void	__deletedWithOneChild(pointer_node deletedNode);
			void	__deletedWithoutChildren(pointer_node deletedNode);

		private:
			void	_printChildren(pointer_node child) const{
				if (child){
					std::cout << "		isitNil - " << std::boolalpha
													<< child->isItNil << "\n";
					if (!(child->isItNil))
						{ std::cout << "		key - " << child->value.first << "\n"; } /*for map*/
						// { std::cout << "		key - " << child->value << "\n"; }/*for set*/
				}
			}

			void	_print_node(pointer_node treeNode) const{
				std::cout << "NODE_status" << std::endl;
				std::cout << "	nodeAddress: " << &(*treeNode) << "\n";
				if (!treeNode->isItNil)
					std::cout << "	nodeKey: " << treeNode->value.first << "\n";/*FOR MAP*/
				// std::cout << "	nodeKey: " << treeNode->value << "\n";/*FOR SET*/
				std::cout << "	isItNil: " << std::boolalpha << treeNode->isItNil << "\n";
				std::cout << "	color: " << (char)(treeNode->color) << "\n";

				std::cout << "	parent: " << "\n"
								<< "		adress - " << treeNode->previous << "\n";
				if (treeNode->previous){
					std::cout << "		key - " << treeNode->previous->value.first << "\n"/*FOR MAP*/
					// std::cout << "		key - " << treeNode->previous->value << "\n"/*FOR SET*/
					<< "		color - " << (char)(treeNode->previous->color) << "\n";
				}

				std::cout << "	rightChild: " << "\n"
							<< "		adress - " << treeNode->nextRight << "\n";
				_printChildren(treeNode->nextRight);

				std::cout << "	leftChild: " << "\n"
							<< "		adress - " << treeNode->nextLeft << "\n";
				_printChildren(treeNode->nextLeft);
				std::cout<< std::endl << std::endl;
			}

			void	_print_tree(pointer_node currentNode) const{
				if (!currentNode || currentNode->isItNil) { return ; }

				_print_tree(currentNode->nextLeft);
				_print_node(currentNode);
				_print_tree(currentNode->nextRight);

			}

			pointer_node	_createNode(const value_type& val){

					pointer_node	newNode = nodeAlloc.allocate(1);
					nodeAlloc.construct(newNode, tree_node(val));

					newNode->color = RED;
					newNode->isItNil = false;
					newNode->previous = NULL;
					newNode->nextRight = NULL;
					newNode->nextLeft = NULL;

					return newNode;
				}

			pointer_node	_createdNilNode(pointer_node parent){
				pointer_node	nilNode;


				nilNode = nodeAlloc.allocate(1);
				nodeAlloc.construct(nilNode, tree_node(value_type()));

				nilNode->color = BLACK;
				nilNode->isItNil = true;
				nilNode->previous = parent;
				nilNode->nextRight = NULL;
				nilNode->nextLeft = NULL;

				return nilNode;
			}

			void	_freeNode(pointer_node destroiedNode){
				if (!destroiedNode) { return; }
				nodeAlloc.destroy(destroiedNode);
				nodeAlloc.deallocate(destroiedNode, 1);
			}

			void	_freeTree(pointer_node node){
				(void)node;
				// if (node->isItNil) { if (!node->previous) { _freeNode(node); } return ; }

				// _freeTree(node->nextLeft);
				// pointer_node	tmp = node->nextRight;
				// _print_node(node);
				// _freeTree(node->nextRight);
				// _freeNode(node);
			}

			pointer_node	_findNode(const value_type& finding) const{
				if (!node || node->isItNil){ return NULL; }

				pointer_node	lookedNode = node;

				// _print_node(lookedNode);
				while(1){
					if (!compare(lookedNode->value, finding)
							&& !compare(finding, lookedNode->value)) {
						break;
					} else if (compare(lookedNode->value, finding)) {
						lookedNode = lookedNode->nextRight;
					} else { lookedNode = lookedNode->nextLeft; }
					if (lookedNode->isItNil) { return NULL; }
				}
				return lookedNode;
			}

			pointer_node	_findsInsertPlace(pointer_node comingNode,
												pointer_node currentNode){
				if (!currentNode || currentNode->isItNil){
					return currentNode;
				} else if (compare(currentNode->value, comingNode->value)){
					return _findsInsertPlace(comingNode, currentNode->nextRight);
				} else if (compare(comingNode->value, currentNode->value)){
					return _findsInsertPlace(comingNode, currentNode->nextLeft);
				} else {
					return comingNode;
				}
			}

			void	_leftTurn(pointer_node oldParent, pointer_node newParent){
				oldParent->nextRight = newParent->nextLeft;
				newParent->nextLeft->previous = oldParent;
				newParent->nextLeft = oldParent;
				___updateNodesPointers(oldParent, newParent);
			}

			void	_rightTurn(pointer_node oldParent, pointer_node newParent){
				oldParent->nextLeft = newParent->nextRight;
				newParent->nextRight->previous = oldParent;
				newParent->nextRight = oldParent;
				___updateNodesPointers(oldParent, newParent);
			}


			void	_addsNodeToFindedPlace(pointer_node addedNode,
											pointer_node insertPlace){
				pointer_node	nilRight = _createdNilNode(addedNode);
				pointer_node	nilLeft = _createdNilNode(addedNode);

				addedNode->nextRight = nilRight;
				addedNode->nextLeft = nilLeft;
				if (!countElems){
					_freeNode(node);
					node = addedNode;
					node->color = BLACK;
					// node->previous = NULL;
				} else {
					addedNode->previous = insertPlace->previous;
					if (compare(insertPlace->previous->value, addedNode->value)){
						insertPlace->previous->nextRight = addedNode;
					} else {
						insertPlace->previous->nextLeft = addedNode;
					}
					_freeNode(insertPlace);
				}
				countElems++;
			}

			void	_redDad(pointer_node& addedNode){
				pointer_node	uncle = __findUncle(addedNode);

				if (!uncle){ }
				else if (!(uncle->previous)) { addedNode->previous->color = BLACK; }
				else if (uncle->color == RED) { __redUncle(uncle, addedNode); }
				else if (uncle->color == BLACK) { __blackUncle(uncle, addedNode); }
				else { return ;}
				if (!node) { node = addedNode; }
			}

			void	_deleteOptions(pointer_node& deletedNode){
				if (!deletedNode->nextRight->isItNil
						&& !deletedNode->nextLeft->isItNil){
					__deletedWithTwoGhildren(deletedNode);
				} else if (deletedNode->color == BLACK
					&& (!deletedNode->nextRight->isItNil
							|| !deletedNode->nextLeft->isItNil)) {
					__deletedWithOneChild(deletedNode);
				} else {
					__deletedWithoutChildren(deletedNode);
				}
			}

			pointer_node	_theLeastNode(pointer_node current) const{
				if (current->nextLeft->isItNil)
					{ return current; }
				return _theLeastNode(current->nextLeft);
			}

			pointer_node	_theLargestNode(pointer_node current) const{
				if (!current || current->isItNil
						|| current->nextRight->isItNil)
					{ return current; }
				return _theLargestNode(current->nextRight);
			}

			pair<iterator,bool> _insertNode (pointer_node added_node,
												pointer_node insertPlace){
				_addsNodeToFindedPlace(added_node, insertPlace);
				if (added_node->previous
						&& added_node->previous->color == RED)
					{ _redDad(added_node); }
				return pair<iterator, bool>(iterator(added_node), true);
			}

			iterator	_greaterElem(value_type comingVal) const {
				iterator	current = begin();

				while (!current.base()->isItNil
						&& (compare(*current, comingVal)
						|| (!compare(*current, comingVal)
						&& !compare(comingVal, *current)))){
					current++;
				}
				return current;
			}

		public:
			_rb_tree(const compare_class& comp,
						const allocator_type& a = allocator_type())
			: compare(comp), countElems(0), nodeAlloc(a) { node = _createdNilNode(NULL); }
			// _rb_tree(const _rb_tree& other) : compare(other.compare), countElems(0) {
			// 	node = _createdNilNode(NULL);
			// 	insert(other.begin(), other.end());
			// 	countElems = other.countElems;
			// 	nodeAlloc = other.nodeAlloc;
			// }
			~_rb_tree(void) { _freeTree(node); }

			// _rb_tree& operator= (const _rb_tree& x){
			// 	insert(x.begin(), x.end());
			// 	compare(x.compare);
			// 	countElems = x.countElems;
			// 	nodeAlloc = x.nodeAlloc;
			// 	return *this;
			// }

			/*Iterators: begin, end, rbegin, rend*/

			iterator begin(void) {
				return countElems ? iterator(_theLeastNode(node)) : end();
			}

			const_iterator begin(void) const {
				return countElems ? const_iterator(_theLeastNode(node)) : end();
			}

			iterator end(void) {
				return countElems ? iterator((_theLargestNode(node))->nextRight)
									: iterator(node);
			}

			const_iterator end(void) const {
				return countElems ? const_iterator((_theLargestNode(node))->nextRight)
									: iterator(node);
			}

			reverse_iterator rbegin(void) { return reverse_iterator(end()); }

			const_reverse_iterator rbegin(void) const { return const_reverse_iterator(end()); }

			reverse_iterator rend(void) { return reverse_iterator(begin()); }

			const_reverse_iterator rend(void) const { return const_reverse_iterator(begin()); }

			/*Capacity: empty, size, max_size*/

			bool	empty(void) const { return countElems ? false : true; }

			size_type	size(void) const { return countElems; }

			size_type	max_size(void) const { return nodeAlloc.max_size(); }


			/* ~~~~~~~~~~~~ MODIFIERS ~~~~~~~~~~
				insert			|	Add added_node to the right place
				erase			|	Delete deleded_node to the right place
				clear			|	Free all nodes in tree
			*/

			pair<iterator,bool> insert (const value_type& val){
				pointer_node	insertPlace = node;
				pointer_node	added_node = _createNode(val);

				insertPlace = _findsInsertPlace(added_node, insertPlace);
				if (insertPlace == added_node)
					{ return pair<iterator, bool>
									(iterator(added_node), false); }
				return _insertNode(added_node, insertPlace);
			}

			iterator insert (iterator position, const value_type& val){
				pointer_node	pos1 = position.base();
				if(pos1->isItNil) { return insert(val).first; }

				pointer_node	pos2 = (++position).base();

				if (compare(pos1->value, val)
						&& compare(val, pos2->value)){
					return _insertNode(_createNode(val), pos1).first;
				} else if (!compare(pos1->value, val)
							&& !compare(val, pos1->value)){
					return (iterator(pos1));
				} else if (!compare(pos2->value, val)
							&& !compare(val, pos2->value)){
					return (iterator(pos2));
				} else { return insert(val).first; }
			}

			template <class InputIterator>
				void insert (InputIterator first, InputIterator last){
					if (first.base()->isItNil) {
						insert(*first);
					} else {
						for (iterator it(first); it != last; it++){
							insert(*it);
						}
					}
				}

			size_type	erase(const value_type& val){
				pointer_node	deletedNode = _findNode(val);

				if (!deletedNode) { return 0; }

				 _deleteOptions(deletedNode);

				if (node->isItNil){
					_freeNode(node);
					node = NULL;
				}
				countElems--;
				return 1;
			}

			void erase (iterator position){	erase(*position); }

			void erase (iterator first, iterator last){
				if (first.base()->isItNil) { return ; }
				iterator	tmp = first;
				for (iterator it(first); it != last; ){
					++it;
					erase(*tmp);
					tmp = it;
				}
			}

			void clear(void) { /*_freeTree(node);*/ countElems = 0; node = _createdNilNode(NULL); }

			/* ~~~~~~~~~~~~ OPERATIONS ~~~~~~~~~~
				at			|	Returns a pointer to the node with key 'n' or NULL
				root		|	Returns a pointer to the first root node in tree or NULL
				find		|	Returns an iter to the node with key 'n' or end()
				count		|	Return 1 if key 'val' was found or 0
				lower_bound	|	Return an iter to the node with key 'val' or end()
				upper_bound	|	Return an iter to the node with greater then node with key 'val' or end()
				equal_range	|	Return a pair<iter, iter> with an iter to node with key 'val and n iter to next node
							|		or pair<iter, iter> with to iters to node which greater then node with key 'val' or end()
			*/

			pointer_node	at(const value_type& n) const
				{	return (empty()) ? NULL : _findNode(n); }

			iterator	find(const value_type& n) const{
				pointer_node	finding = _findNode(n);
				// _print_node(finding);
				return (empty() || !finding) ? end() : iterator(finding);
			}

			size_type	count(const value_type& val) const
				{ return at(val) ? 1 : 0; }

			pointer_node	root(void) const
				{ return (empty()) ? NULL : node; }

			iterator	lower_bound(const value_type& val) const{
				iterator	comingElem = find(val);

				return (comingElem == end()) ? _greaterElem(val)
												: comingElem;
			}

			iterator	upper_bound(const value_type& val) const{
				return _greaterElem(val);
			}

			pair<iterator,iterator>	equal_range(const value_type& val) const{
				iterator	comingElem = find(val);

				if (comingElem == end()){
					iterator	returnedElem = _greaterElem(val);
					if (returnedElem.base()->isItNil) { returnedElem--; }
					return (pair<iterator, iterator>(returnedElem, returnedElem));
				} else {
					iterator	coming = comingElem;
					return (pair<iterator, iterator>(coming, (++comingElem)));
				}
			}

			/* ~~~~~~~~~~~~ ALLOCATOR ~~~~~~~~~~*/

			allocator_type	get_allocator(void) const { return allocator_type(); }


			compare_class	key_comp(void) const { return compare; }
			/* ~~~~~~~~~~~~ PRINTING_FUNCTIONS ~~~~~~~~~~
				_print_node	|	print coming node
				_print_tree	|	print tree, taking root node
			*/


			void	printTree(void){
				_print_tree(node);
			}
	} ;
}

#include "tpp_format/tree.tpp"

#endif
