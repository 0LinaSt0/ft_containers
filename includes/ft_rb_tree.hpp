/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_tree.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:08:49 by marvin            #+#    #+#             */
/*   Updated: 2022/09/14 20:19:45 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RB_TREE_HPP
#define FT_RB_TREE_HPP

#include "ft_containers.hpp"
#include "iterators/rb_treeIterators.hpp"

namespace ft{
	template <class Type>
		struct rebind {
			typedef std::allocator<Type> other;
		};

	enum	olderYangerBro{
		OLDER,
		YANGER,
		NONE
	} ;


	template <class _T, class _Compare, class _Allocator>
		class	rb_tree {
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

			typedef ft::rb_tree_iter<value_type>								iterator;
			typedef ft::rb_tree_iter<value_type>								const_iterator;
			typedef ft::rb_tree_rev_iter<iterator>								reverse_iterator;
			typedef ft::rb_tree_rev_iter<const_iterator>						const_reverse_iterator;
			typedef ptrdiff_t													difference_type;
			typedef size_t														size_type;
		private:
			pointer_node	node;
			compare_class	compare;
			size_type		countElems;
			allocator_node	nodeAlloc;
		public:
			rb_tree(const compare_class& comp,
						const allocator_type& a = allocator_type())
			: compare(comp), countElems(0), nodeAlloc(a) { node = _createNilNode(NULL); }
			rb_tree(const rb_tree& other) : node (NULL), compare(other.compare),
											countElems(0), nodeAlloc(other.nodeAlloc){
				insert(other.begin(), other.end());
			}
			~rb_tree(void) { _freeTree(node); }

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

			void clear(void) { /*_freeTree(node);*/ countElems = 0; node = _createNilNode(NULL); }

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


			/* ~~~~~~~~~~~~ PRINTING_FUNCTIONS ~~~~~~~~~~*/

			void	printTree(void){
				_print_tree(node);
			}

			void	printNode(pointer_node treeNode){
				_print_node(treeNode);
			}
		private:
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

			/* ~~~~~~~~~~~ USEFUL FUNCTIONS FOR METHODS ~~~~~~~~~*/

			void	_printChildren(pointer_node child) const;
			void	_print_node(pointer_node treeNode) const;
			void	_print_tree(pointer_node currentNode) const;

			pointer_node	_createNode(const value_type& val);
			pointer_node	_createNilNode(pointer_node parent);

			void	_freeNode(pointer_node destroiedNode);
			void	_freeTree(pointer_node node);

			pointer_node	_findNode(const value_type& finding) const;
			pointer_node	_findsInsertPlace(pointer_node comingNode,
												pointer_node currentNode);

			void	_leftTurn(pointer_node oldParent, pointer_node newParent);
			void	_rightTurn(pointer_node oldParent, pointer_node newParent);


			void	_addsNodeToFindedPlace(pointer_node addedNode,
											pointer_node insertPlace);

			void	_redDad(pointer_node& addedNode);

			void	_deleteOptions(pointer_node& deletedNode);

			pointer_node	_theLeastNode(pointer_node current) const;
			pointer_node	_theLargestNode(pointer_node current) const;

			pair<iterator,bool> _insertNode (pointer_node added_node,
												pointer_node insertPlace);

			iterator	_greaterElem(value_type comingVal) const ;
	} ;

	template <class T, class Compare, class Allocator>
		typename rb_tree<T, Compare, Allocator>::pointer_node
			rb_tree<T, Compare, Allocator>::
			___findLeastRightChild(pointer_node currentNode){
				return ((currentNode->nextLeft->isItNil)
							? currentNode
							: ___findLeastRightChild(currentNode->nextLeft));
		}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
			__deleteNode(pointer_node deletedNode){
				_freeNode(deletedNode->nextRight);
				_freeNode(deletedNode->nextLeft);
				deletedNode->nextRight = NULL;
				deletedNode->nextLeft = NULL;
				deletedNode->color = BLACK;
				deletedNode->isItNil = true;
		}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
			___pointersSwap(pointer_node& to,
								pointer_node& from){
			pointer_node	tmp = to;

			to = from; from = tmp;
		}
	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
				____childrenParentSwap(pointer_node finded,
											pointer_node deleted,
											bool isNodeNeigbours){
			bool	deletedLessFinded
				= compare(deleted->value, finded->value);

			/*left children parents swap*/
			finded->nextLeft->previous = deleted;
			if (deletedLessFinded || !isNodeNeigbours){
				deleted->nextLeft->previous = finded;
			}
			/*right children parents swap*/
			finded->nextRight->previous = deleted;
			if (!deletedLessFinded || !isNodeNeigbours){
				deleted->nextRight->previous = finded;
			}
		}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
				____childrenSwap(pointer_node finded,
									pointer_node deleted,
									bool isNodeNeigbours){
			bool	deletedLessFinded
						= compare(deleted->value, finded->value);

			/*left children swap*/
			if (deletedLessFinded || !isNodeNeigbours){
				___pointersSwap(deleted->nextLeft, finded->nextLeft);
			} else {
				deleted->nextLeft = finded->nextLeft;
				finded->nextLeft = deleted;
			}
			/*right children swap*/
			if (!deletedLessFinded || !isNodeNeigbours){
				___pointersSwap(deleted->nextRight, finded->nextRight);
			} else {
				deleted->nextRight = finded->nextRight;
				finded->nextRight = deleted;
			}
		}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
				____parentChildrenSwap(pointer_node finded,
										pointer_node deleted,
										bool isNodeNeigbours){
			/*parents children swap*/
			if (deleted->previous){
				if (deleted != deleted->previous->nextRight)
						deleted->previous->nextLeft = finded;
				else { deleted->previous->nextRight = finded;}
			}
			if (!isNodeNeigbours){
				(finded != finded->previous->nextRight)
					? finded->previous->nextLeft = deleted
					: finded->previous->nextRight = deleted;
			}
		}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
				____parentsSwap(pointer_node finded,
									pointer_node deleted,
									bool isNodeNeigbours){
			/*parents swap*/
			if (isNodeNeigbours){
				finded->previous = deleted->previous;
				deleted->previous = finded;
			} else {
				___pointersSwap(deleted->previous, finded->previous); }
		}

	template <class T, class Compare, class Allocator>
			void	rb_tree<T, Compare, Allocator>::
				____optionsSwap(pointer_node finded,
									pointer_node deleted,
									bool isNodeNeigbours){
		____childrenParentSwap(finded, deleted, isNodeNeigbours);
		____childrenSwap(finded, deleted, isNodeNeigbours);
		____parentChildrenSwap(finded, deleted, isNodeNeigbours);
		____parentsSwap(finded, deleted, isNodeNeigbours);
		if (!finded->previous) { node = &(*finded); }
	}

	template <class T, class Compare, class Allocator>
		bool	rb_tree<T, Compare, Allocator>::
			____isNodeNeigboursSwap(pointer_node finded,
									pointer_node deleted){
			if ((!compare(deleted->nextRight->value, finded->value)
					&& !compare(finded->value, deleted->nextRight->value))
					|| (!compare(deleted->nextLeft->value, finded->value)
					&& !compare(finded->value, deleted->nextLeft->value)))
				return true;
			else { return false; }
		}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
			___nodesSwap(pointer_node finded,
							pointer_node deleted){
			nodeColor	tmpColor = deleted->color;

			deleted->color = finded->color;
			finded->color = tmpColor;

			____optionsSwap(finded, deleted,
								____isNodeNeigboursSwap(finded, deleted));
		}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
			___brotherParentChange(pointer_node doubleBlackNode,
										ft::pair<olderYangerBro,
										typename rb_tree<T, Compare, Allocator>
										::pointer_node> bro){
				if (bro.first == OLDER){
					_leftTurn(doubleBlackNode->previous, bro.second);
				} else {
					_rightTurn(doubleBlackNode->previous, bro.second);
				}
			}

	template <class T, class Compare, class Allocator>
		ft::pair<olderYangerBro, typename rb_tree<T, Compare, Allocator>::pointer_node>
			rb_tree<T, Compare, Allocator>::
			___olderYangerBrother(pointer_node doubleBlackNode){
				typedef ft::pair<olderYangerBro,
								typename rb_tree<T, Compare, Allocator>
								::pointer_node>	__pair;

				if (doubleBlackNode->previous){
					if (doubleBlackNode->previous->nextRight != doubleBlackNode)
						{ return __pair(OLDER, doubleBlackNode->previous->nextRight); }
					return __pair(YANGER, doubleBlackNode->previous->nextLeft);
				}
				return __pair(NONE, NULL);
			}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
			___yangerBrotherBalancing(pointer_node doubleBlackNode,
										ft::pair<olderYangerBro,
										typename rb_tree<T, Compare, Allocator>
										::pointer_node> bro){
				doubleBlackNode->color = BLACK;
				bro.second->color = BLACK;
				if (bro.second->previous->color == RED){
					bro.second->nextLeft->color = RED;
				} else {
					bro.second->previous->color = BLACK;
					bro.second->nextLeft->color = BLACK;
				}
				_rightTurn(bro.second->previous, bro.second);
			}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
			___blackChildrenBalancing(pointer_node doubleBlackNode,
										ft::pair<olderYangerBro,
										typename rb_tree<T, Compare, Allocator>
										::pointer_node> bro){
				doubleBlackNode->color = BLACK;
				bro.second->color = RED;

				if (doubleBlackNode->previous->color == RED){
					doubleBlackNode->previous->color = BLACK;
				} else {
					doubleBlackNode->previous->color = DOUBLE_BLACK;
					__blackBalancing(doubleBlackNode->previous);
				}
			}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
			___redLeftChildBalancing(pointer_node doubleBlackNode,
										ft::pair<olderYangerBro,
										typename rb_tree<T, Compare, Allocator>
										::pointer_node> bro){
				if (bro.first == YANGER){
					___yangerBrotherBalancing(doubleBlackNode, bro);
				} else {
					bro.second->color = RED;
					bro.second->nextLeft->color = BLACK;

					_rightTurn(bro.second, bro.second->nextLeft);
					___redRightChildBalancing(doubleBlackNode,
										___olderYangerBrother(doubleBlackNode));
				}
			}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
			___redRightChildBalancing(pointer_node doubleBlackNode,
										ft::pair<olderYangerBro,
										typename rb_tree<T, Compare, Allocator>
										::pointer_node> bro){
				if (bro.first == YANGER) {
					_leftTurn(bro.second, bro.second->nextRight);
					___yangerBrotherBalancing(doubleBlackNode,
										___olderYangerBrother(doubleBlackNode));
				} else {
						doubleBlackNode->color = BLACK;
						bro.second->color = doubleBlackNode->previous->color;
						bro.second->nextRight->color = BLACK;
						doubleBlackNode->previous->color = BLACK;
					___brotherParentChange(doubleBlackNode, bro);
				}
			}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
			___redBrotherBalancing(pointer_node doubleBlackNode,
									ft::pair<olderYangerBro,
									typename rb_tree<T, Compare, Allocator>
									::pointer_node> bro){
				___brotherParentChange(doubleBlackNode, bro);
				bro.second->color = BLACK;
				doubleBlackNode->previous->color = RED;
				__blackBalancing(doubleBlackNode);
			}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
			___blackBrotherBalancing(pointer_node doubleBlackNode,
										ft::pair<olderYangerBro,
										typename rb_tree<T, Compare, Allocator>
										::pointer_node> bro){
				if (bro.second->nextLeft->color == BLACK
						&& bro.second->nextRight->color == BLACK){
					___blackChildrenBalancing(doubleBlackNode, bro);
				} else if (bro.second->nextLeft->color == RED) {
					___redLeftChildBalancing(doubleBlackNode, bro);
				} else {
					___redRightChildBalancing(doubleBlackNode, bro);
				}
			}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
			__blackBalancing(pointer_node doubleBlackNode){
				typedef ft::pair<olderYangerBro,
								typename rb_tree<T, Compare, Allocator>
								::pointer_node>	__pair;

				__pair	bro(___olderYangerBrother(doubleBlackNode));

				if (!doubleBlackNode->previous){
					doubleBlackNode->color = BLACK;
				} else if (bro.second->color == RED){
					___redBrotherBalancing(doubleBlackNode, bro);
				} else if (bro.second->color == BLACK){
					___blackBrotherBalancing(doubleBlackNode, bro);
				} else { return ; }

		}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
			__deletedWithTwoGhildren(pointer_node deletedNode){
				pointer_node	leastRightChild;

				leastRightChild = ___findLeastRightChild(deletedNode->nextRight);

				___nodesSwap(leastRightChild, deletedNode);
				_deleteOptions(deletedNode);
		}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
			__deletedWithOneChild(pointer_node deletedNode){

				if (deletedNode->nextRight->isItNil){
					deletedNode->nextLeft->color = deletedNode->color;
					_rightTurn(deletedNode, deletedNode->nextLeft);
					__deleteNode(deletedNode);
				} else {
					deletedNode->nextRight->color = deletedNode->color;
					_leftTurn(deletedNode, deletedNode->nextRight);
					__deleteNode(deletedNode);
				}
		}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
			__deletedWithoutChildren(pointer_node deletedNode){
				if (deletedNode->color == RED){
					__deleteNode(deletedNode);
				} else {
					deletedNode->color = DOUBLE_BLACK;
					__deleteNode(deletedNode);
					__blackBalancing(deletedNode);
				}
		}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
				_printChildren(typename rb_tree<T, Compare, Allocator>::
								pointer_node child) const{
					if (child){
						std::cout << "		isitNil - " << std::boolalpha
														<< child->isItNil << "\n";
						if (!(child->isItNil))
							{ std::cout << "		key - " << child->value.first << "\n"; } /*for map*/
							// { std::cout << "		key - " << child->value << "\n"; }/*for set*/
					}
				}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
				_print_node(typename rb_tree<T, Compare, Allocator>::
							pointer_node treeNode) const{
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

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
				_print_tree(typename rb_tree<T, Compare, Allocator>::
							pointer_node currentNode) const{
			if (!currentNode || currentNode->isItNil) { return ; }

			_print_tree(currentNode->nextLeft);
			_print_node(currentNode);
			_print_tree(currentNode->nextRight);

		}

	template <class T, class Compare, class Allocator>
		typename rb_tree<T, Compare, Allocator>::pointer_node
			rb_tree<T, Compare, Allocator>::
			_createNode(const typename rb_tree<T, Compare, Allocator>::
						value_type& val){

				typename rb_tree<T, Compare, Allocator>::
				pointer_node	newNode = nodeAlloc.allocate(1);

				nodeAlloc.construct(newNode, tree_node(val));

				newNode->color = RED;
				newNode->isItNil = false;
				newNode->previous = NULL;
				newNode->nextRight = NULL;
				newNode->nextLeft = NULL;

				return newNode;
			}

	template <class T, class Compare, class Allocator>
		typename rb_tree<T, Compare, Allocator>::pointer_node
			rb_tree<T, Compare, Allocator>::
			_createNilNode(typename rb_tree<T, Compare, Allocator>::
							pointer_node parent){

			typename rb_tree<T, Compare, Allocator>::
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

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
				_freeNode(typename rb_tree<T, Compare, Allocator>::
							pointer_node destroiedNode){
			if (!destroiedNode) { return; }
			nodeAlloc.destroy(destroiedNode);
			nodeAlloc.deallocate(destroiedNode, 1);
		}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
				_freeTree(typename rb_tree<T, Compare, Allocator>::
							pointer_node node){
			if (node->isItNil) {
				_freeNode(node);
				return ;
			}

			_freeTree(node->nextLeft);
			// typename rb_tree<T, Compare, Allocator>::pointer_node	tmp = node->nextRight;
			// _print_node(node);
			_freeTree(node->nextRight);
			_freeNode(node);
		}

	template <class T, class Compare, class Allocator>
		typename rb_tree<T, Compare, Allocator>::pointer_node
			rb_tree<T, Compare, Allocator>::
			_findNode(const rb_tree<T, Compare, Allocator>::
						value_type& finding) const{
			if (!node || node->isItNil){ return NULL; }

			typename rb_tree<T, Compare, Allocator>::
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

	template <class T, class Compare, class Allocator>
		typename rb_tree<T, Compare, Allocator>::pointer_node
			rb_tree<T, Compare, Allocator>::
			_findsInsertPlace(typename rb_tree<T, Compare, Allocator>::
								pointer_node comingNode,
								typename rb_tree<T, Compare, Allocator>::
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

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
				_leftTurn(typename rb_tree<T, Compare, Allocator>::
							pointer_node oldParent,
							typename rb_tree<T, Compare, Allocator>::
							pointer_node newParent){
			oldParent->nextRight = newParent->nextLeft;
			newParent->nextLeft->previous = oldParent;
			newParent->nextLeft = oldParent;
			___updateNodesPointers(oldParent, newParent);
		}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
				_rightTurn(typename rb_tree<T, Compare, Allocator>::
							pointer_node oldParent,
							typename rb_tree<T, Compare, Allocator>::
							pointer_node newParent){
			oldParent->nextLeft = newParent->nextRight;
			newParent->nextRight->previous = oldParent;
			newParent->nextRight = oldParent;
			___updateNodesPointers(oldParent, newParent);
		}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
				_addsNodeToFindedPlace(typename rb_tree<T, Compare, Allocator>::
										pointer_node addedNode,
										typename rb_tree<T, Compare, Allocator>::
										pointer_node insertPlace){
			typedef typename rb_tree<T, Compare, Allocator>::pointer_node	ptr_node;

			ptr_node	nilRight = _createNilNode(addedNode);
			ptr_node	nilLeft = _createNilNode(addedNode);

			addedNode->nextRight = nilRight;
			addedNode->nextLeft = nilLeft;
			if (!countElems){
				_freeNode(node);
				node = addedNode;
				node->color = BLACK;
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

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
				_redDad(typename rb_tree<T, Compare, Allocator>::
						pointer_node& addedNode){
			typename rb_tree<T, Compare, Allocator>::
			pointer_node	uncle = __findUncle(addedNode);

			if (!uncle){ }
			else if (!(uncle->previous)) { addedNode->previous->color = BLACK; }
			else if (uncle->color == RED) { __redUncle(uncle, addedNode); }
			else if (uncle->color == BLACK) { __blackUncle(uncle, addedNode); }
			else { return ;}
			if (!node) { node = addedNode; }
		}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
				_deleteOptions(typename rb_tree<T, Compare, Allocator>::
								pointer_node& deletedNode){
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

	template <class T, class Compare, class Allocator>
		typename rb_tree<T, Compare, Allocator>::pointer_node
			rb_tree<T, Compare, Allocator>::
			_theLeastNode(typename rb_tree<T, Compare, Allocator>::
							pointer_node current) const{
			if (current->nextLeft->isItNil)
				{ return current; }
			return _theLeastNode(current->nextLeft);
		}

	template <class T, class Compare, class Allocator>
		typename rb_tree<T, Compare, Allocator>::pointer_node
			rb_tree<T, Compare, Allocator>::
			_theLargestNode(typename rb_tree<T, Compare, Allocator>::
								pointer_node current) const{
			if (!current || current->isItNil
					|| current->nextRight->isItNil)
				{ return current; }
			return _theLargestNode(current->nextRight);
		}

	template <class T, class Compare, class Allocator>
		pair<typename rb_tree<T, Compare, Allocator>::iterator,bool>
			rb_tree<T, Compare, Allocator>::
			_insertNode (typename rb_tree<T, Compare, Allocator>::
							pointer_node added_node,
							typename rb_tree<T, Compare, Allocator>::
							pointer_node insertPlace){
			_addsNodeToFindedPlace(added_node, insertPlace);
			if (added_node->previous
					&& added_node->previous->color == RED)
				{ _redDad(added_node); }
			return pair<iterator, bool>(iterator(added_node), true);
		}

	template <class T, class Compare, class Allocator>
		typename rb_tree<T, Compare, Allocator>::iterator
			rb_tree<T, Compare, Allocator>::
			_greaterElem(typename rb_tree<T, Compare, Allocator>::
							value_type comingVal) const {
			iterator	current = begin();

			while (!current.base()->isItNil
					&& (compare(*current, comingVal)
					|| (!compare(*current, comingVal)
					&& !compare(comingVal, *current)))){
				current++;
			}
			return current;
		}

	template <class T, class Compare, class Allocator>
		typename rb_tree<T, Compare, Allocator>::pointer_node
			rb_tree<T, Compare, Allocator>::
			__findUncle(pointer_node newNode){
				if (newNode->previous){
					if (newNode->previous->previous){
						if (newNode->previous->previous->nextLeft != newNode->previous){
							return (newNode->previous->previous->nextLeft);
						} else {
							return (newNode->previous->previous->nextRight);
						}
					} else { return newNode; }
				} else { return NULL; }
			}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
				___updateNodesPointers(pointer_node oldNode,
										pointer_node newNode){
			if (oldNode->previous) {
				if (oldNode->previous->nextLeft != oldNode) {
				oldNode->previous->nextRight = newNode;
				} else {
					oldNode->previous->nextLeft = newNode;
				}
			}

			newNode->previous = oldNode->previous;
			oldNode->previous = newNode;
			if (!newNode->previous)
				node = newNode;
		}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
				___nodeMoreGranddad(pointer_node uncle,
										pointer_node errorNode){
			if (errorNode != errorNode->previous->nextRight){
				_rightTurn(errorNode->previous, errorNode);
				_leftTurn(uncle->previous, errorNode);
				errorNode->color = BLACK;
			} else {
				_leftTurn(uncle->previous, errorNode->previous);
				errorNode->previous->color = BLACK;
			}
		}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
				___nodeLessGranddad(pointer_node uncle,
										pointer_node errorNode){
			if (errorNode != errorNode->previous->nextLeft){
				_leftTurn(errorNode->previous, errorNode);
				_rightTurn(uncle->previous, errorNode);
				errorNode->color = BLACK;
			} else {
				_rightTurn(uncle->previous, errorNode->previous);
				errorNode->previous->color = BLACK;
			}
		}

	template <class T, class Compare, class Allocator>
		void	rb_tree<T, Compare, Allocator>::
				__blackUncle(pointer_node uncle,
								pointer_node addedNode){

			if (uncle->previous->nextLeft != addedNode->previous){
				___nodeMoreGranddad(uncle, addedNode);
			} else {
				___nodeLessGranddad(uncle, addedNode);
			}
			uncle->previous->color = RED;


		}

	template <class T, class Compare, class Allocator>
			void	rb_tree<T, Compare, Allocator>::
					__redUncle(pointer_node uncle,
									pointer_node addedNode){
				/*dad*/addedNode->previous->color = BLACK;
				/*uncle*/uncle->color = BLACK;
				if (uncle->previous->previous){
					/*grandded*/uncle->previous->color = RED;
					if (uncle->previous->previous->color == RED){
						_redDad(uncle->previous);
					}
				}
			}
}

// #include "../useful_tpp/ft_rb_tree_insert.tpp"
// #include "../useful_tpp/ft_rb_tree_erase.tpp"
// #include "../useful_tpp/ft_rb_tree_helpful.tpp"

#endif
