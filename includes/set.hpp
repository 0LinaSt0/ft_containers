/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:25:39 by marvin            #+#    #+#             */
/*   Updated: 2022/08/23 13:25:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include "containers.hpp"

namespace ft{
	template < class _T,
		class _Compare = std::less<_T>,
		class _Alloc = std::allocator<_T>
		> class set {
		public:
			typedef _T											key_type;
			typedef _T											value_type;
			typedef _Compare									key_compare;
			typedef _Compare									value_compare;
			typedef _Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
		private:
			typedef _rb_tree<value_type, value_compare, allocator_type>	set_tree;
			typedef	typename set_tree::pointer_node						ptr_node;

			set_tree		tree;
			allocator_type	setAlloc;
			key_compare		setCompare;
		public:
			typedef typename set_tree::size_type				size_type;
			typedef typename set_tree::difference_type			difference_type;
			typedef typename set_tree::iterator					iterator;
			typedef typename set_tree::const_iterator			const_iterator;
			typedef typename set_tree::reverse_iterator			reverse_iterator;
			typedef typename set_tree::const_reverse_iterator	const_reverse_iterator;

			explicit set(const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type())
				: tree(comp, alloc), setAlloc(alloc), setCompare(comp) { }

			template <class InputIterator>
				set(InputIterator first, InputIterator last,
						const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type())
				: tree(comp, alloc), setAlloc(alloc), setCompare(comp) {
					tree.insert(first, last);
				}

			set(const set& x) : tree(x.tree) {
				ыetAlloc = x.setAlloc;
				setCompare =x.setCompare;
			}
			
			~set(void) { }

			set& operator= (const set& x){
				tree = x.tree;
				setAlloc = x.setAlloc;
				setCompare =x.setCompare;
				return *this;
			}

			/*Iterators: begin, end, rbegin, rend*/

			iterator begin(void) { return tree.begin(); }

			const_iterator begin(void) const { return tree.begin(); }

			iterator end(void) { return tree.end(); }

			const_iterator end(void) const { return tree.end(); }

			reverse_iterator rbegin(void) { return tree.rbegin(); }

			const_reverse_iterator rbegin(void) const { return tree.rbegin(); }

			reverse_iterator rend(void) { return tree.rend(); }

			const_reverse_iterator rend(void) const { return tree.rend(); }

			/*Capacity: empty, size, max_size*/

			bool empty(void) const { return tree.empty(); }

			size_type size(void) const { return tree.size(); }

			size_type max_size(void) const { return tree.max_size(); }

			/* Modifiers: insert, erase, swap, clear */

			ft::pair<iterator,bool> insert(const value_type& val){
				tree.insert(val);
			}

			iterator insert(iterator position, const value_type& val){
				tree.insert(position, val);
			}

			template <class InputIterator>
				void insert(InputIterator first, InputIterator last){
					tree.insert(fisrt, last);
				}

			void erase(iterator position){
				tree.erase(position);
			}

			size_type erase(const value_type& val){
				tree.erase(val);
			}

			void erase(iterator first, iterator last){
				tree.erase(fisrt, last);
			}

			void swap(set& x) {
				set	tmp = *this;

				this = x;
				x = tmp;
			}

			void clear(void) { tree.clear(); }

			// Observers: key_comp, value_comp

			key_compare key_comp(void) const { return setCompare; }

			value_compare value_comp(void) const { return setCompare; }

			// Operators: find, count, lower_bound, upper_bound, equal_range

			iterator find(const value_type& val) const {
				return tree.find(val);
			}

			size_type count(const value_type& val) const{
				return tree.cout(val);
			}

			iterator lower_bound(const value_type& val) const{
				return tree.lower_bound(val);
			}

			iterator upper_bound(const value_type& val) const{
				return tree.upper_bound(val);
			}

			pair<iterator,iterator> equal_range
								(const value_type& val) const{
				return tree.equal_range(val);
			}

			// Allocator

			allocator_type get_allocator(void) const { return setAlloc; }
		} ;

	template <class T, class Compare, class Alloc>
		bool operator== (const set<T, Compare, Alloc>& lhs,
							const set<T, Compare, Alloc>& rhs){
			if (lhs.empty() && rhs.empty()) return true;
			else if (lhs.empty() || rhs.empty()) return false;
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}

	template <class T, class Compare, class Alloc>
		bool operator!=(const set<T, Compare, Alloc>& lhs,
							const set<T, Compare, Alloc>& rhs){
			if (lhs.empty() && rhs.empty()) return false;
			else if (lhs.empty() || rhs.empty()) return true;
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin()) ? 0 : 1;
		}

	template <class T, class Compare, class Alloc>
		bool operator< (const set<T, Compare, Alloc>& lhs,
							const set<T, Compare, Alloc>& rhs){
			if (lhs.empty() && rhs.empty()) return false;
			else if (lhs.empty() && !rhs.empty()) return true;
			else if (!lhs.empty() && rhs.empty()) return false;
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin(),
								ft::_lessCheck<set, set>);
		}

	template <class T, class Compare, class Alloc>
		bool operator<=(const set<T, Compare, Alloc>& lhs,
							const set<T, Compare, Alloc>& rhs){
			if (lhs.empty() && rhs.empty()) return true;
			else if (lhs.empty() && !rhs.empty()) return true;
			else if (!lhs.empty() && rhs.empty()) return false;
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin(),
								ft::_equalLessCheck<set, set>);
		}

	template <class T, class Compare, class Alloc>
		bool operator>(const set<T, Compare, Alloc>& lhs,
							const set<T, Compare, Alloc>& rhs){
			if (lhs.empty() && rhs.empty()) return false;
			else if (lhs.empty() && !rhs.empty()) return false;
			else if (!lhs.empty() && rhs.empty()) return true;
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin(),
								ft::_moreCheck<set, set>);
		}

	template <class T, class Compare, class Alloc>
		bool operator>=(const set<T, Compare, Alloc>& lhs,
							const set<T, Compare, Alloc>& rhs){
			if (lhs.empty() && rhs.empty()) return true;
			else if (lhs.empty() && !rhs.empty()) return false;
			else if (!lhs.empty() && rhs.empty()) return true;
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin(),
								ft::_equalMoreCheck<set, set>);
		}

	template <class T, class Compare, class Alloc>
		void swap(set<T,Compare,Alloc>& lhs,
					set<T,Compare,Alloc>& rhs ){
			lhs.swap(rhs);
		}
}

#endif
