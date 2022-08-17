/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   containers.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:07:27 by msalena           #+#    #+#             */
/*   Updated: 2022/07/24 20:57:49 by msalena          ###   ########.fr       */
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

void	treeChecks(void);
template <class node>
	void	printAllAboutNode(node& treeNode);

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
			~pair () {}

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
			typedef _tree_node*						pointre_node;

			value_type		value;
			nodeColor		color;
			bool			isItNil;
			pointre_node	previous;
			pointre_node	nextRight;
			pointre_node	nextLeft;

			_tree_node&	operator=(const _tree_node& comingTree){
				value = comingTree.value;
				color = comingTree.color;
				previous = comingTree.previous;
				nextRight = comingTree.nextRight;
				nextLeft = comingTree.nextLeft;

				return *this;
			}
		} ;

	template < class value_type >
		class _rb_tree_iter{
		public:
			typedef ptrdiff_t											difference_type;
			typedef value_type&											pointer;
			typedef value_type*											reference;
			typedef std::bidirectional_iterator_tag						iterator_category;

			typedef typename _tree_node<value_type>::pointre_node		pointer_node;
		protected:
			pointer_node	node;
		public:
			_rb_tree_iter(void) : node (NULL) { }
			_rb_tree_iter(const pointer_node tree) : node(tree) { }
			// _rb_tree_iter(const _rb_tree_iter& otherTree) : node(otherTree.base()) { }
			~_rb_tree_iter(void) { }

			reference		operator* (void) const { return *node->value; }
			pointer			operator->(void) const { return node->value; }
			_rb_tree_iter&	operator=(const _rb_tree_iter& other) { node = other.node; return *this; }
			_rb_tree_iter&	operator++(void) { node = node->nextRight; return *this; }
			_rb_tree_iter	operator++(int) { pointer_node _new = *node; node = node->nextRight; return _new; }
			_rb_tree_iter&	operator--(void) { node = node->previous; return *this; }
			_rb_tree_iter	operator--(int) { pointer_node _new = *node; node = node->previous; return _new; }

			pointer		base(void) const { return *node; }
		} ;

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
			typedef typename allocator_node::pointer							pointer_node;
			typedef typename allocator_node::reference							reference_node;

			typedef ft::_rb_tree_iter<value_type>								iterator;
			typedef ft::_rb_tree_iter<value_type>								const_iterator;
			// typedef ft::_rb_tree_rev_iter<iterator>								reverse_iterator;
			// typedef ft::_rb_tree_rev_iter<const_iterator>						const_reverse_iterator;
			typedef ptrdiff_t													difference_type;
			typedef size_t														size_type;

		private:
			pointer_node	node;
			// compare_class	compare;
			class value_compare;
			/*FOR TESTING MAP*/ value_compare	compare;
			size_type		countElems;
			allocator_node	nodeAlloc;

		private:
			/*FORE CHECKING*/
			class value_compare
			{
				friend class _rb_tree;

				protected:
					_Compare comp;
					value_compare () {}  // constructed with map's comparison object
					public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			} ;
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
			pointer_node	_createNode(const value_type& val){
					pointer_node	newNode = nodeAlloc.allocate(1);
					newNode->value = val;
					newNode->color = RED;
					newNode->isItNil = false;
					newNode->previous = NULL;
					newNode->nextRight = NULL;
					newNode->nextLeft = NULL;

					return newNode;
				}


			void	_freeNode(pointer_node destroiedNode)
				{ nodeAlloc.deallocate(destroiedNode, 1); }

			void	_freeTree(pointer_node node){
				if (!node || node->isItNil) { return ; }

				_freeTree(node->nextLeft);
				_freeNode(node->nextLeft);
				_freeTree(node->nextRight);
				_freeNode(node->nextRight);
			}

			pointer_node	_endElem() const {
				pointer_node	last_node = node;

				while (node && !last_node->isItNil)
					{ last_node = last_node->nextRight; }
				return last_node;
			}

			pointer_node	_findNode(const value_type& finding) const{
				if (!node){ return NULL; }

				pointer_node	lookedNode = node;

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

			pointer_node	_createdNilNode(pointer_node parent){
				pointer_node	nilNode;

				nilNode = nodeAlloc.allocate(1);
				nilNode->color = BLACK;
				nilNode->isItNil = true;
				nilNode->previous = parent;
				nilNode->nextRight = NULL;
				nilNode->nextLeft = NULL;

				return nilNode;
			}

			void	_addsNodeToFindedPlace(pointer_node addedNode,
											pointer_node inceptionPlace){
				pointer_node	nilRight = _createdNilNode(addedNode);
				pointer_node	nilLeft = _createdNilNode(addedNode);

				addedNode->nextRight = nilRight;
				addedNode->nextLeft = nilLeft;

				if (!countElems){
					node = addedNode;
					node->color = BLACK;
					node->previous = NULL;
				} else {
					addedNode->previous = inceptionPlace->previous;
					if (compare(inceptionPlace->previous->value, addedNode->value)){
						inceptionPlace->previous->nextRight = addedNode;
					} else {
						inceptionPlace->previous->nextLeft = addedNode;
					}
					_freeNode(inceptionPlace);
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

		public:
			explicit _rb_tree(void) : node (NULL), countElems(0) {}
			template <class InputIterator>
				_rb_tree(InputIterator first, InputIterator last);
			_rb_tree(const _rb_tree& other);
			~_rb_tree(void) { _freeTree(node); _freeNode(node); }

			_rb_tree& operator= (const _rb_tree& x);

			/*Iterators: begin, end, rbegin, rend*/
			iterator begin() { return countElems ? iterator(node) : end(); }
			const_iterator begin() const { return countElems ? const_iterator(node) : end(); }
			iterator end() { return _endElem(); }
			const_iterator end() const { return _endElem(); }
			// reverse_iterator rbegin();
			// const_reverse_iterator rbegin() const;
			// reverse_iterator rend();
			// const_reverse_iterator rend() const;

			/*Capacity: empty, size, max_size*/
			bool	empty(void) const { return countElems ? false : true; }

			size_t	size(void) const { return countElems; }

			size_type max_size() const { return nodeAlloc.max_size(); }


			/* ~~~~~~~~~~~~ MODIFIERS ~~~~~~~~~~
				insert			|	Add added_node to the right place
				erase			|	Delete deleded_node to the right place
				swap, clear*/

			pair<iterator,bool> insert (const value_type& val){
				pointer_node	insertPlace = node;
				pointer_node	added_node = _createNode(val);

				insertPlace = _findsInsertPlace(added_node, insertPlace);
				if (insertPlace == added_node)
					{ return pair<iterator, bool>
									(iterator(added_node), false); }
				_addsNodeToFindedPlace(added_node, insertPlace);
				if (added_node->previous
						&& added_node->previous->color == RED)
					{ _redDad(added_node); }
				return pair<iterator, bool>(iterator(added_node), true);
			}

			iterator insert (iterator position, const value_type& val){
				if (!compare(position->value.first, val)
						&& !compare(val, position->value.first)){
					return position;
				} else (compare(position->value.first, val))
			}

			template <class InputIterator>
				void insert (InputIterator first, InputIterator last){
					for (iterator it(first); it != last; it++){
						insert(*it);
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
				for (iterator it(first); it != last; it++){
					erase(*it);
				}
			}

			void clear() { _freeTree(node); node == NULL; }

			/* ~~~~~~~~~~~~ OPERATIONS ~~~~~~~~~~
				at		|	Returns a pointer to the node with value_type 'n' in tree or NULL
						|		(if the tree is empty; if coming key was't find)
				root	|	Returns a pointer to the first root node in tree
						|		or NULL if the tree is empty

				find, count, lower_bound, upper_bound, equal_range
			*/

			pointer_node	at(const value_type& n) const
				{ return (empty()) ? NULL : _findNode(n); }

			pointer_node	root(void) const
				{ return (empty()) ? NULL : node; }

			/* ~~~~~~~~~~~~ PRINTING_FUNCTIONS ~~~~~~~~~~
				print_node	|	print coming node
				print_tree	|	print tree, taking root node
			*/

			void	printChildren(pointer_node child){
				if (child){
					std::cout << "		isitNil - " << std::boolalpha
													<< child->isItNil << "\n";
					if (!(child->isItNil))
						{ std::cout << "		key - " << child->value.first << "\n"; } /*for map*/
						// { std::cout << "		key - " << child->value << "\n"; }/*for set*/
				}
			}

			void	print_node(pointer_node treeNode){
				std::cout << "NODE_status" << std::endl;
				std::cout << "	nodeAddress: " << &(*treeNode) << "\n";
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
				printChildren(treeNode->nextRight);

				std::cout << "	leftChild: " << "\n"
							<< "		adress - " << treeNode->nextLeft << "\n";
				printChildren(treeNode->nextLeft);
				std::cout<< std::endl << std::endl;
			}

			void	print_tree(pointer_node currentNode){
				if (!currentNode) { std::cout << "Oopss... Tree doesn't have nodes" << std::endl; return ; }

				if (currentNode->isItNil) { return ; }

				print_tree(currentNode->nextLeft);
				print_node(currentNode);
				print_tree(currentNode->nextRight);

			}
		} ;
} ;

#include "tpp_format/tree.tpp"

#endif
