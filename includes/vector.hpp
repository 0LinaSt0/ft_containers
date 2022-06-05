/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:06:03 by msalena           #+#    #+#             */
/*   Updated: 2022/06/05 20:11:57 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "vectorIterator.hpp"

/*
	Чтобы сделать функцию resize (не готова - дорабработь), нужно сделать функцию reserve.
	Сейчас проблема последней заключается в том, что у нее необходимо выделить память для vec.
	Vec был зафришин уже.

	В то же время я разработала функцию freeMemory, которая ставит дефолтные значения на места,
	которые я не передаю, но так нельзя. Разобраться надо!
*/
namespace ft{
	template < class T >
		struct is_integral { static const bool	value = false; };
	template < >
		struct is_integral < bool > { static const bool	value = true; };
	template < >
		struct is_integral < char > { static const bool	value = true; };
	template < >
		struct is_integral < unsigned char > { static const bool	value = true; };
	template < >
		struct is_integral < signed char > { static const bool	value = true; };
	template < >
		struct is_integral < wchar_t > { static const bool	value = true; };
	template < >
		struct is_integral < short > { static const bool	value = true; };
	template < >
		struct is_integral < unsigned short > { static const bool	value = true; };
	template < >
		struct is_integral < int > { static const bool	value = true; };
	template < >
		struct is_integral < unsigned int > { static const bool	value = true; };
	template < >
		struct is_integral < long > { static const bool	value = true; };
	template < >
		struct is_integral < unsigned long > { static const bool	value = true; };
	template < >
		struct is_integral < long long > { static const bool	value = true; };
	template < >
		struct is_integral < unsigned long long > { static const bool	value = true; };
	
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
		size_type											capacitySize;

		void	capacityUpdate(size_type amountCapacity){
			if (capacitySize == 0){
				capacitySize = amountCapacity;
			}
			while (capacitySize < amountCapacity) {
				capacitySize *= 2;
			}
		}
		
		void	freeMemory(bool justDestructFlag = 0, size_type freeElems = capacitySize){
			if (justDestructFlag){
				for (size_type i = 0; i < countElem; i++){
					vecAlloc.destruct(vec + i);
				}
			}
			vecAlloc.deallocate(vec, freeElems);
		}
		// void	reallocationMemory(size_type amountElems, size_type amountCapacity,
		// 					size_type sizeCapacity = capacitySize){
		// 	if (sizeCapacity < amountElems){
		// 		freeMemory(0, sizeCapacity);
		// 		capacityUpdate(amountCapacity);
		// 		vec = vecAlloc.allocate(sizeCapacity);
		// 	} else {
		// 		freeMemory(1, sizeCapacity);
		// 	}
		// }
	public:
		/* ~~~~~~~~~~ Constructors ~~~~~~~~~~ 
			1. explicit vector (const allocator_type&)			|	Empty vector
			2. explicit vector (size_type, const value_type&,	|	Creat vector on 'n' elems with value 'val'
						const allocator_type&)					|
			3. vector (InputIterator, InputIterator,			|	Vector with elems from first to last
						const allocator_type&)					|
			4. vector (const vector&)							|	Copy constructor
		*/
		explicit vector (const allocator_type& alloc = allocator_type()) : 
						vec (NULL), countElem (0), capacitySize (0) { vecAlloc = alloc; } 
		explicit vector (size_type n, const value_type& val = value_type(),
						const allocator_type& alloc = allocator_type()) : 
						countElem (n), capacitySize (n){
							vecAlloc = alloc;
							vec = vecAlloc.allocate(n);
							
							for (iterator iter(this->begin()); iter < this->end(); iter++){
								(*iter) = val;
							}
						}
		 // !!!!!!!!!!!ADD THE EXCEPTION WHEN first OR/AND last is NULL!!!!!!!!!!!
		 // TYPE OF EXCEPTION: "libc++abi.dylib: terminating with uncaught exception of type std::length_error: vector"
		template < class InputIterator >
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type(), 
					typename enable_if<!is_integral<InputIterator>::value, 
												InputIterator>::type tmp = InputIterator()){ 
						(void) tmp;
						for (size_type i=0; first != last; first++){
							countElem = i++;
						}
						capacitySize = countElem;
						vecAlloc = alloc;
						vec = vecAlloc.allocate(countElem);
						
						iterator	iter(vec);
						
						for (size_type i=0; first != last; first++){
							iter[i++] = (*first);
						}
					}
		vector (const vector& x){	
			countElem = x.countElem;
			capacitySize = countElem;
			vec = vecAlloc.allocate(countElem);
			operator=(x);
		}
		~vector (void) {}

		// ~~~~~~~~~~ Operators ~~~~~~~~~~
		vector&			operator= (const vector& x){
			if (capacitySize < x.size()){
				freeMemory();
				capacityUpdate(x.capacity());
				vec = vecAlloc.allocate(capacitySize);
			} else {
				freeMemory(1);
			}
			
			iterator	thisIter(vec);
			size_type	i = 0;

			for (iterator	xIter(x.begin()); xIter != x.end(); xIter++){
				thisIter[i] = (*xIter);
				i++;
			}
			countElem = x.size();
			return *this;
		}
		reference		operator[] (size_type n) 
			{ iterator	referBrackets(vec); return referBrackets[n]; }
		const_reference	operator[] (size_type n) const 
			{ iterator	constReferBrackets; return constReferBrackets[n]; }
		
		
		/* ~~~~~~~~~~ Iterators ~~~~~~~~~~ 
			begin	|	Return iterator to beginning
			end		|	Return iterator to end
			rbegin	|	Return reverse iterator to reverse beginning
			rend	|	Return reverse iterator to reverse end
		*/
		iterator			begin() const { iterator iter(vec); return countElem ? iter : end(); }
		iterator			end() const { iterator iter(vec); return iter + countElem; }
		reverse_iterator	rbegin();
		reverse_iterator	rend();

		/* ~~~~~~~~~~ Capacity ~~~~~~~~~~
			size		|	Return size
			max_size	|	Return maximum possible size
			resize		|	Change size on 'n' size
			capacity	|	Return size of allocated storage capacity
			empty		|	Test whether vector is empty
			reserve		|	Request a change in capacity
		*/
		size_type	size() const { return countElem; }
		size_type	max_size() const { return vecAlloc.max_size(); }
		void		resize (size_type n, value_type val = value_type()){ 
			if (n == countElem)
				return ;
			vector<value_type>	copy(n);
			size_type	i = 0;
			
			for (iterator iter(this->begin()); iter != this->end(); iter++){
				copy[i] = iter;
				i++;
			}
			vecAlloc.deallocate(vec, countElem);
			if (n > countElem){
				for (size_type it = i; it < n; it++){
					copy[it] = val;
				}
			}

			// vecAlloc.constuct(vec + 2, val);
			// vecAlloc.destruct(vec + 2);

			vec = vecAlloc.allocate(n);
			vec = copy;
			countElem = n;
			copy.vecAlloc.deallocate(copy, n);
		}
		size_type	capacity() const { return capacitySize; }
		bool		empty() const{ return countElem ? false : true; }
		void		reserve (size_type n){
			if (capacitySize < n){
				size_type			oldCapacity = capacitySize;
				capacityUpdate(n);
				vector<size_type>	tmp(capacitySize);
				
				tmp = vec;
				freeMemory(0, oldCapacity);
				/* тут нужно нормально выделить память для vec на новый capacitySize 
				последого, как я зафришила это самый vec */
				vec = tmp;
				
			}
		}
		
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
