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
		YANGER
	} ;

	template <class _T, class _Compare>
		struct _tree_node{
			typedef _T								value_type;
			typedef _Compare						key_type;
			typedef ft::pair<key_type, value_type>	pair_type;
			typedef _tree_node*						pointer_node;

			pair_type		value;
			nodeColor		color;
			bool			isItNil;
			pointer_node	previous;
			pointer_node	nextRight;
			pointer_node	nextLeft;

			_tree_node&	operator=(const _tree_node& comingTree){
				value = comingTree.value;
				color = comingTree.color;
				previous = comingTree.previous;
				nextRight = comingTree.nextRight;
				nextLeft = comingTree.nextLeft;

				return *this;
			}
		} ;

	template <class _T, class _Compare, class _Allocator>
		class	_tree {
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
			size_t			countElems;
			allocator_node	nodeAlloc;

		private:
			/* ~~~~~~~~~~~~ USEFUL FUNCTIONS FOR ADD NODE ~~~~~~~~~~*/

			void	___updateNodesPointers(pointer_node oldNode,
											pointer_node newNode);

			void	___nodeMoreGranddad(pointer_node uncle, pointer_node addedNode);

			void	___nodeLessGranddad(pointer_node uncle, pointer_node addedNode);

			void	__blackUncle(pointer_node uncle, pointer_node addedNode);

			void	__redUncle(pointer_node uncle, pointer_node addedNode);

			pointer_node	__findUncle(pointer_node newNode);


			/* ~~~~~~~~~~~ USEFUL FUNCTIONS FOR DELETE NODE ~~~~~~~~~*/

			void	__deleteNode(pointer_node deletedNode);

			void	___nodesValueChange(pointer_node whichNode,
											pointer_node inNode);

			void	___brotherParentChange(pointer_node doubleBlackNode,
										pair<olderYangerBro, pointer_node> bro);

			pair<olderYangerBro, pointer_node>	___olderYangerBrother(pointer_node doubleBlackNode);

			pointer_node	___findLeastRightChild(pointer_node currentNode);

			void	___blackChildrenBalancing(pointer_node doubleBlackNode,
											pair<olderYangerBro, pointer_node> bro);

			void	___redLeftChildBalancing(pointer_node doubleBlackNode,
												pair<olderYangerBro, pointer_node> bro);

			void	___blackLeftChildBalancing(pointer_node doubleBlackNode,
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
			void	_freeNode(pointer_node destroiedNode){
				// nodeAlloc.destroy(destroiedNode->value);
				// nodeAlloc.destroy(destroiedNode->color);
				// nodeAlloc.destroy(destroiedNode->isItNil);

				nodeAlloc.deallocate(destroiedNode, 1);
			}

			void	_printChildren(pointer_node child){
				if (child){
					std::cout << "		isitNil - " << std::boolalpha
													<< child->isItNil << "\n";
					if (!(child->isItNil))
						{ std::cout << "		key - " << child->value.first << "\n"; }
				}
			}

			pointer_node	_findNode(const value_compare& key) const{
				pointer_node	lookedNode = node;
				size_t			i = 0;
				for (value_compare nodeKey = node->value.first;
						nodeKey != key && i < countElems;
						i++){
					if (key > nodeKey) { lookedNode = lookedNode->nextRight; }
					else { lookedNode = lookedNode->nextLeft; }
					nodeKey = lookedNode->value.first;
				}
				return (i == countElems) ? NULL : lookedNode;
			}

			pointer_node	_findsInsertPlace(pointer_node comingNode,
												pointer_node currentNode){
				if (!currentNode || currentNode->isItNil){
					return currentNode;
				} else if (comingNode->value.first > currentNode->value.first){
					return _findsInsertPlace(comingNode, currentNode->nextRight);
				} else if (comingNode->value.first < currentNode->value.first){
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
					if (inceptionPlace->previous->value.first < addedNode->value.first){
						inceptionPlace->previous->nextRight = addedNode;
					} else {
						inceptionPlace->previous->nextLeft = addedNode;
					}
					_freeNode(inceptionPlace);
				}
				countElems++;
			}

			void	_redDad(pointer_node addedNode){
				pointer_node	uncle = __findUncle(addedNode);

				if (!uncle){ }
				else if (!(uncle->previous)) { addedNode->previous->color = BLACK; }
				else if (uncle->color == RED) { __redUncle(uncle, addedNode); }
				else if (uncle->color == BLACK) { __blackUncle(uncle, addedNode); }
				else { return ;}
				if (!node) { node = addedNode; }
			}

			void	_deleteOptions(pointer_node deletedNode){
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
			_tree(void) : node (NULL), countElems(0) {}
			~_tree(void) {/*delete*/}

			bool	empty(void) const { return countElems ? false : true; }

			size_t	size(void) const { return countElems; }

			/* ~~~~~~~~~~~~ FIND ELEMS FUNCTIONS ~~~~~~~~~~
				at		|	Returns a reference to the node with key 'n' in tree or NULL
						|		(if the tree is empty; if coming key was't find)
				root	|	Returns a reference to the first root node in tree
						|		or NULL if the tree is empty
			*/

			pointer_node		at(const value_compare& key) const
				{ return (empty()) ? NULL : _findNode(key); }

			pointer_node		root(void) const
				{ return (empty()) ? NULL : node; }

			void	print_node(pointer_node treeNode){
				std::cout << "NODE_status" << std::endl;
				std::cout << "	nodeAddress: " << &treeNode << "\n";
				std::cout << "	nodeKey: " << treeNode->value.first << "\n";
				std::cout << "	nodeValue: " << treeNode->value.second << "\n";
				std::cout << "	isItNil: " << std::boolalpha << treeNode->isItNil << "\n";
				std::cout << "	color: " << (char)(treeNode->color) << "\n";

				std::cout << "	parent: " << "\n"
								<< "		adress - " << treeNode->previous << "\n";
				if (treeNode->previous){
					std::cout << "		key - " << treeNode->previous->value.first << "\n"
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

			void	print_tree(pointer_node currentNode){
				if (!currentNode) { std::cout << "Oopss... Tree doesn't have nodes" << std::endl; return ; }

				if (currentNode->isItNil) { return ; }

				print_tree(currentNode->nextLeft);
				print_node(currentNode);
				print_tree(currentNode->nextRight);
			}

			/* ~~~~~~~~~~~~ MODIFIERS FUNCTIONS ~~~~~~~~~~
				createNode	|	Create new node and return pointer to it
				insert		|	Add added_node to the right place and return pointer to it
				erase		|	Delete deleded_node to the right place
			*/

			pointer_node	createNode(const value_compare& node_key,
											const value_type& node_value){
				pointer_node	newNode;

				newNode = nodeAlloc.allocate(1);
				newNode->value = make_pair(node_key, node_value);
				newNode->color = RED;
				newNode->isItNil = false;
				newNode->previous = NULL;
				newNode->nextRight = NULL;
				newNode->nextLeft = NULL;

				return newNode;
			}

			pointer_node	insert(pointer_node added_node){
				pointer_node	inceptionPlace = node;

				inceptionPlace = _findsInsertPlace(added_node, inceptionPlace);
				if (inceptionPlace == added_node)
					return NULL;
				_addsNodeToFindedPlace(added_node, inceptionPlace);
				if (added_node->previous
						&& added_node->previous->color == RED)
					{ _redDad(added_node); }
				return added_node;
			}

			void	erase(_Compare deleted_key){
				pointer_node	deletedNode = _findNode(deleted_key);

				if (!deleted_key) { return ; }

				_deleteOptions(deletedNode);
			}

			void	erase(pointer_node deleted_node)
				{ erase(deleted_node->value.first); }

		} ;
}

#include "tpp_format/tree.tpp"

#endif
