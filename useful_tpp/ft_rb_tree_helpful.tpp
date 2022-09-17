/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb_tree_helpful.tpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:01:43 by marvin            #+#    #+#             */
/*   Updated: 2022/09/16 22:07:46 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft{

	template <class _T, class _Compare, class _Allocator>
		void	rb_tree<_T, _Compare, _Allocator>::
				_printChildren(typename rb_tree<_T, _Compare, _Allocator>::
								pointer_node child) const{
					if (child){
						std::cout << "		isitNil - " << std::boolalpha
														<< child->isItNil << "\n";
						if (!(child->isItNil))
							// { std::cout << "		key - " << child->value.first << "\n"; } /*for map*/
							{ std::cout << "		key - " << child->value << "\n"; }/*for set*/
					}
				}

	template <class _T, class _Compare, class _Allocator>
		void	rb_tree<_T, _Compare, _Allocator>::
				_print_node(typename rb_tree<_T, _Compare, _Allocator>::
							pointer_node treeNode) const{
			std::cout << "NODE_status" << std::endl;
			std::cout << "	nodeAddress: " << &(*treeNode) << "\n";
			if (!treeNode->isItNil)
				std::cout << "	nodeKey: " << treeNode->value.first << "\n";/*FOR MAP*/
				std::cout << "	nodeVal: " << treeNode->value.second << "\n";/*FOR MAP*/
			// std::cout << "	nodeKey: " << treeNode->value << "\n";/*FOR SET*/
			std::cout << "	isItNil: " << std::boolalpha << treeNode->isItNil << "\n";
			std::cout << "	color: " << (char)(treeNode->color) << "\n";

			std::cout << "	parent: " << "\n"
							<< "		adress - " << treeNode->previous << "\n";
			if (treeNode->previous){
				// std::cout << "		key - " << treeNode->previous->value.first << "\n"/*FOR MAP*/
				std::cout << "		key - " << treeNode->previous->value << "\n"/*FOR SET*/
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

	template <class _T, class _Compare, class _Allocator>
		void	rb_tree<_T, _Compare, _Allocator>::
				_print_tree(typename rb_tree<_T, _Compare, _Allocator>::
							pointer_node currentNode) const{
			if (!currentNode || currentNode->isItNil) { return ; }

			_print_tree(currentNode->nextLeft);
			_print_node(currentNode);
			_print_tree(currentNode->nextRight);

		}

	template <class _T, class _Compare, class _Allocator>
		typename rb_tree<_T, _Compare, _Allocator>::pointer_node
			rb_tree<_T, _Compare, _Allocator>::
			_createNode(const typename rb_tree<_T, _Compare, _Allocator>::
						value_type& val){

				typename rb_tree<_T, _Compare, _Allocator>::
				pointer_node	newNode = nodeAlloc.allocate(1);

				nodeAlloc.construct(newNode, tree_node(val));

				newNode->color = RED;
				newNode->isItNil = false;
				newNode->previous = NULL;
				newNode->nextRight = NULL;
				newNode->nextLeft = NULL;

				return newNode;
			}

	template <class _T, class _Compare, class _Allocator>
		typename rb_tree<_T, _Compare, _Allocator>::pointer_node
			rb_tree<_T, _Compare, _Allocator>::
			_createNilNode(typename rb_tree<_T, _Compare, _Allocator>::
							pointer_node parent){

			typename rb_tree<_T, _Compare, _Allocator>::
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

	template <class _T, class _Compare, class _Allocator>
		void	rb_tree<_T, _Compare, _Allocator>::
				_freeNode(typename rb_tree<_T, _Compare, _Allocator>::
							pointer_node destroiedNode){
			if (!destroiedNode) { return; }
			nodeAlloc.destroy(destroiedNode);
			nodeAlloc.deallocate(destroiedNode, 1);
		}

	template <class _T, class _Compare, class _Allocator>
		void	rb_tree<_T, _Compare, _Allocator>::
				_freeTree(typename rb_tree<_T, _Compare, _Allocator>::
							pointer_node node){
			if (node->isItNil) { 
				_freeNode(node); 
				return ; 
			}

			_freeTree(node->nextLeft);
			_freeTree(node->nextRight);
			_freeNode(node);
		}

	template <class _T, class _Compare, class _Allocator>
		typename rb_tree<_T, _Compare, _Allocator>::pointer_node
			rb_tree<_T, _Compare, _Allocator>::
			_findNode(const rb_tree<_T, _Compare, _Allocator>::
						value_type& finding) const{
			if (node->isItNil){ return NULL; }

			typename rb_tree<_T, _Compare, _Allocator>::
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

	template <class _T, class _Compare, class _Allocator>
		typename rb_tree<_T, _Compare, _Allocator>::pointer_node
			rb_tree<_T, _Compare, _Allocator>::
			_findsInsertPlace(typename rb_tree<_T, _Compare, _Allocator>::
								pointer_node comingNode,
								typename rb_tree<_T, _Compare, _Allocator>::
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

	template <class _T, class _Compare, class _Allocator>
		void	rb_tree<_T, _Compare, _Allocator>::
				_leftTurn(typename rb_tree<_T, _Compare, _Allocator>::
							pointer_node oldParent,
							typename rb_tree<_T, _Compare, _Allocator>::
							pointer_node newParent){
			oldParent->nextRight = newParent->nextLeft;
			newParent->nextLeft->previous = oldParent;
			newParent->nextLeft = oldParent;
			___updateNodesPointers(oldParent, newParent);
		}

	template <class _T, class _Compare, class _Allocator>
		void	rb_tree<_T, _Compare, _Allocator>::
				_rightTurn(typename rb_tree<_T, _Compare, _Allocator>::
							pointer_node oldParent,
							typename rb_tree<_T, _Compare, _Allocator>::
							pointer_node newParent){
			oldParent->nextLeft = newParent->nextRight;
			newParent->nextRight->previous = oldParent;
			newParent->nextRight = oldParent;
			___updateNodesPointers(oldParent, newParent);
		}

	template <class _T, class _Compare, class _Allocator>
		void	rb_tree<_T, _Compare, _Allocator>::
				_addsNodeToFindedPlace(typename rb_tree<_T, _Compare, _Allocator>::
										pointer_node addedNode,
										typename rb_tree<_T, _Compare, _Allocator>::
										pointer_node insertPlace){
			typedef typename rb_tree<_T, _Compare, _Allocator>::pointer_node	ptr_node;

			ptr_node	nilRight = _createNilNode(addedNode);
			ptr_node	nilLeft = _createNilNode(addedNode);

			addedNode->nextRight = nilRight;
			addedNode->nextLeft = nilLeft;
			if (node->isItNil){
				_freeNode(node);
				node = addedNode;
				node->color = BLACK;
			} else {
				addedNode->previous = insertPlace->previous;
				if (insertPlace != insertPlace->previous->nextLeft){
					insertPlace->previous->nextRight = addedNode;
				} else {
					insertPlace->previous->nextLeft = addedNode;
				}
				_freeNode(insertPlace);
			}
			countElems++;
		}

	template <class _T, class _Compare, class _Allocator>
		void	rb_tree<_T, _Compare, _Allocator>::
				_redDad(typename rb_tree<_T, _Compare, _Allocator>::
						pointer_node& addedNode){
			typename rb_tree<_T, _Compare, _Allocator>::
			pointer_node	uncle = __findUncle(addedNode);

			if (uncle->isItNil){ }
			else if (!(uncle->previous)) { addedNode->previous->color = BLACK; }
			else if (uncle->color == RED) { __redUncle(uncle, addedNode); }
			else if (uncle->color == BLACK) { __blackUncle(uncle, addedNode); }
			else { return ;}
			if (node->isItNil) { _freeNode(node); node = addedNode; }
		}

	template <class _T, class _Compare, class _Allocator>
		void	rb_tree<_T, _Compare, _Allocator>::
				_deleteOptions(typename rb_tree<_T, _Compare, _Allocator>::
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

	template <class _T, class _Compare, class _Allocator>
		typename rb_tree<_T, _Compare, _Allocator>::pointer_node
			rb_tree<_T, _Compare, _Allocator>::
			_theLeastNode(typename rb_tree<_T, _Compare, _Allocator>::
							pointer_node current) const{
			if (current->isItNil || current->nextLeft->isItNil)
				{ return current; }
			return _theLeastNode(current->nextLeft);
		}

	template <class _T, class _Compare, class _Allocator>
		typename rb_tree<_T, _Compare, _Allocator>::pointer_node
			rb_tree<_T, _Compare, _Allocator>::
			_theLargestNode(typename rb_tree<_T, _Compare, _Allocator>::
								pointer_node current) const{
			if (current->isItNil || current->nextRight->isItNil)
				{ return current; }
			return _theLargestNode(current->nextRight);
		}

	template <class _T, class _Compare, class _Allocator>
		pair<typename rb_tree<_T, _Compare, _Allocator>::iterator,bool>
			rb_tree<_T, _Compare, _Allocator>::
			_insertNode (typename rb_tree<_T, _Compare, _Allocator>::
							pointer_node added_node,
							typename rb_tree<_T, _Compare, _Allocator>::
							pointer_node insertPlace){
			_addsNodeToFindedPlace(added_node, insertPlace);
			if (added_node->previous
					&& added_node->previous->color == RED)
				{ _redDad(added_node); }
			return pair<iterator, bool>(iterator(added_node), true);
		}

	template <class _T, class _Compare, class _Allocator>
		typename rb_tree<_T, _Compare, _Allocator>::iterator
			rb_tree<_T, _Compare, _Allocator>::
			_greaterElem(typename rb_tree<_T, _Compare, _Allocator>::
							value_type comingVal) const {
			iterator	current = begin();

			while (current != end() && !current.base()->isItNil
					&& (compare(*current, comingVal)
					|| (!compare(*current, comingVal)
					&& !compare(comingVal, *current)))){
				current++;
			}
			return current;
		}
}
