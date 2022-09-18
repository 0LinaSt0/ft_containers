/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_tree.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:08:49 by marvin            #+#    #+#             */
/*   Updated: 2022/09/18 12:12:08 by msalena          ###   ########.fr       */
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
			: node(NULL), compare(comp), countElems(0), nodeAlloc(a) { }
			rb_tree(const rb_tree& other) : node(NULL), compare(other.compare) { 
				operator=(other);
			}
			~rb_tree(void) { _freeTree(node); }

			rb_tree&	operator=(const rb_tree& other){
				if (node){
					_freeTree(node);
					node = NULL;
					compare = other.compare;
				}
				countElems = 0;
				nodeAlloc = other.nodeAlloc;
				if (other.begin().base()){
					insert(other.begin(), other.end());
				}
				return *this;
			}

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
				if (insertPlace == added_node){ 
					_freeNode(added_node);
					return pair<iterator, bool>
								(iterator(insertPlace), false); 
				}
				return _insertNode(added_node, insertPlace);
			}

			iterator insert (iterator position, const value_type& val){
				pointer_node	pos1 = position.base();
				if (pos1) { 
					pointer_node	pos2 = (++position).base();

					if (compare(pos1->value, val)
							&& compare(val, pos2->value)){
						return _insertNode(_createNode(val), pos1).first;
					}
				}
				return insert(val).first;
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
				iterator	tmp = first;
				for (iterator it(first); it != last; ){
					++it;
					erase(*tmp);
					tmp = it;
				}
			}

			void clear(void) { _freeTree(node); countElems = 0; node = NULL; }

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
}

#include "../useful_tpp/ft_rb_tree_insert.tpp"
#include "../useful_tpp/ft_rb_tree_erase.tpp"
#include "../useful_tpp/ft_rb_tree_helpful.tpp"

#endif
