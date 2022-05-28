/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:06:03 by msalena           #+#    #+#             */
/*   Updated: 2022/05/28 23:23:49 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "vectorIterator.hpp"

namespace ft{
	// template < class T >
	// 	struct is_integral { static const bool	value = false; };
	template < bool T >
		struct is_integral { static const bool	value = true; };
	template < char T >
		struct is_integral { static const bool	value = true; };
	template < unsigned char T >
		struct is_integral { static const bool	value = true; };
	template < signed char T >
		struct is_integral { static const bool	value = true; };
	template < wchar_t T >
		struct is_integral { static const bool	value = true; };
	template < short T >
		struct is_integral { static const bool	value = true; };
	template < unsigned short T >
		struct is_integral { static const bool	value = true; };
	template < int T >
		struct is_integral { static const bool	value = true; };
	template < unsigned int T >
		struct is_integral { static const bool	value = true; };
	template < long T >
		struct is_integral { static const bool	value = true; };
	template < unsigned long T >
		struct is_integral { static const bool	value = true; };
	template < long long T >
		struct is_integral { static const bool	value = true; };
	template < unsigned long long T >
		struct is_integral { static const bool	value = true; };
	template < long long T >
		struct is_integral { static const bool	value = true; };
	template < class T >
		struct is_integral { static const bool	value = false; }; 
	
	template < bool Cond, class T = void > 
		struct enable_if {};
	template < class T > 
		struct enable_if < true, T > { typedef T type; };

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
		typedef ft::reversIter<iterator>					reverse_iterator;
		typedef ft::reversIter<const_iterator>				const_reverse_iterator;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;
	private:
		value_type*											vec;
		allocator_type										vecAlloc;
		size_type											countElem;
	public:
		
			
		explicit vector (const allocator_type& alloc = allocator_type()) : 
									vec (NULL), countElem (0) { vecAlloc = alloc; } //empty_vector
		explicit vector (size_type n, const value_type& val = value_type(),
							const allocator_type& alloc = allocator_type()) : 
							countElem (n){  // creat n vector elems with value val
								vecAlloc = alloc;
								vec = vecAlloc.allocate(n);
								
								iterator iter(vec);
								
								for (size_type i=0; i < n; i++){
									iter[i] = val;
								}
							}
		
		
		template < class InputIterator >
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type(),
					typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type tmp = void){ // vector with elems from first to last
						for (size_type i=0; first != last; first++){
							countElem = i++;
						}
						vecAlloc = alloc;
						vec = vecAlloc.allocate(countElem);
						
						iterator	iter(vec);
						iterator	copy = first;
						
						for (size_type i=0; copy != last; copy++){
							iter[i++] = (*copy);
						}
					}
		vector (const vector& x){ // copy constructor
			allocator_type	all;
			
			countElem = x.countElem;
			vec = all.allocate(countElem);
			operator=(x);
		}
		~vector (void) {}

		//Iterators
		iterator			begin() { iterator iter(vec); return countElem ? iter : end(); }
		iterator			end() { iterator iter(vec); return iter + countElem; }
		reverse_iterator	rbegin();
		reverse_iterator	rend();

		//Capacity
		size_type 			size() const;
		size_type 			max_size() const;
		void 				resize (size_type n, value_type val = value_type());
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
		vector&			operator= (const vector& x){
			iterator	thisIter(vec);
			iterator	xIter(x.beging());
			size_type	i = 0;

			for (; xIter != x.end(); xIter++){
				thisIter[i++] = xIter;
			}
			countElem = i;
			return *this;
		}
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
