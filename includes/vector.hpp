/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:06:03 by msalena           #+#    #+#             */
/*   Updated: 2022/05/02 15:59:52 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "vectorIterator.hpp"
#include <iostream>
#include <string>
#include <memory>

namespace ft{
	template < class T, class Alloc = std::allocator<T> >
	class	vector{
	public:
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef ft::Iter<pointer>							iterator;
		typedef ft::Iter<const_pointer>						const_iterator;
		typedef ft::reverseIter<iterator>					reverse_iterator;
		typedef ft::reverseIter<const_iterator>				const_reverse_iterator;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;
	private:
		value_type*											vector;
	public:
		//ENABLE_IF!!!!!!
		explicit vector (const allocator_type& alloc = allocator_type()); //empty_vector
		explicit vector (size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type()); // creat n vector elems with value val
		template < class InputIterator >
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type()); // vector with elems from first to last
		vector (const vector& x); // copy constructor
		~vector (void);

		//Iterators
		iterator			begin();
		iterator			end();
		reverse_iterator	rbegin();
		reverse_iterator	rend();

		//Capacity
		size_type 			size() const;
		size_type 			max_size() const;
		void 				resize (size_type n, value_type val = value_type());v
		size_type 			capacity() const;
		bool 				empty() const;
		void 				reserve (size_type n);
		
		//Element access
		reference			at (size_type n);
		const_reference		at (size_type n) const;
		reference			front();
		const_reference		front() const;
		reference			back();
		const_reference		back() const;

		//Modifiers
		template <class InputIterator>
			void		assign (InputIterator first, InputIterator last);	
		void			assign (size_type n, const value_type& val);
		
		void			push_back (const value_type& val);
		
		void			pop_back();
		
		iterator		insert (iterator position, const value_type& val);
		void			insert (iterator position, size_type n, const value_type& val);
		template <class InputIterator>
			void		insert (iterator position, InputIterator first, InputIterator last);
		
		iterator		erase (iterator position);
		iterator		erase (iterator first, iterator last);

		void			swap (vector& x);

		void			clear();

		//Allocator
		allocator_type	get_allocator() const;

		//Operators
		vector&			operator= (const vector& x);
		reference		operator[] (size_type n);
		const_reference	operator[] (size_type n) const;
	};

	template <class T, class Alloc>
  		bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
		bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
		bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
		bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);

	template <class T, class Alloc>
		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
	
	
	template <class T, class Alloc>
  		void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
}


#endif
