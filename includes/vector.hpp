/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:06:03 by msalena           #+#    #+#             */
/*   Updated: 2022/08/31 19:37:53 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

// #include "vectorIterator.hpp"
#include "containers.hpp"

/*
	! - means things which i still don't implement
*/
namespace ft{
	template < class D >
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

	template < bool Cond, class D = void >
		struct enable_if {};
	template < class D >
		struct enable_if < true, D > { typedef D type; };

	template < class ft_vec, class _Alloc = std::allocator<ft_vec> >
	class	vector{
	public:
		typedef ft_vec									value_type;
		typedef _Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef ft::iterVec<value_type>						iterator;
		typedef ft::iterVec<value_type>						const_iterator;
		typedef ft::revIterVec<iterator>					reverse_iterator;
		typedef ft::revIterVec<const_iterator>				const_reverse_iterator;
		typedef typename allocator_type::size_type			size_type;
		typedef typename allocator_type::difference_type	difference_type;
	private:
		pointer												vec;
		allocator_type										vecAlloc;
		size_type											countElem;
		size_type											capacitySize;
		// Just change size of "capacitySize" variable
		void	_capacityUpdate(size_type amountCapacity){
			if (capacitySize == 0){
				capacitySize = amountCapacity;
			} else if (capacitySize < amountCapacity) {
				if ((capacitySize * 2) < amountCapacity){
					capacitySize = amountCapacity;
				} else {
					capacitySize *= 2;
				}
			}
		}

		/* 	1) destruct needing element (DoIDeallocate - false)
			2) destruct and deallocate vec
				(DoIDeallocate - true, freeElems - how much deallocate)*/
		void	_freeMemory(bool DoIDeallocate, size_type freeElems){
			for (size_type i = 0; i < countElem; i++){
					vecAlloc.destroy(vec + i);
			}
			if (DoIDeallocate){
					vecAlloc.deallocate(vec, freeElems);
				}
		}

		/* Counts distance between two iterators and returns size of the distance */
		template < class InputIterator >
			size_type	_sizeItersDistance(InputIterator first, InputIterator last){
				size_type	distance = 0;

				while (first != last){
						distance++;
						first++;
					}
				return (distance);
			}

		/* Writes in 'container' value from begin_vector to 'posititon' iterators
			or from 'position' to end_vector. It depends on whichPartFl.
			'whichPartFl' flag could be:
				- 'b' if needs put first part of vector to containter
				- 'e' if needs put last part of vector to containter */
		template < class InputIterator >
			void	_writeValue(InputIterator &container, InputIterator position, char whichPartFl){
				if (whichPartFl == 'b') {
					for (InputIterator vecBeging(begin());
							vecBeging != position;
							vecBeging++){
						(*container) = (*vecBeging);
						container++;
					}
				} else if (whichPartFl == 'e') {
					for (InputIterator vecEnd(end());
							position != vecEnd;
							position++){
						(*container) = (*position);
						container++;
					}
				} else { }
			}

		// template < class vec1 >
			void	_exchangesContant(vector& putIn, vector& takeFrom){
				putIn.vecAlloc = takeFrom.vecAlloc;
				putIn.countElem = takeFrom.countElem;
				putIn.capacitySize = takeFrom.capacitySize;
				putIn.vec = vecAlloc.allocate(putIn.capacitySize);
				vecAlloc.construct(putIn.vec, value_type());

				if (!takeFrom.countElem){
					vec = NULL;
				} else {
					iterator	putInIter(putIn.vec);
					size_t i = 0;

					for (iterator takeFromIter(takeFrom.begin());
							takeFromIter != takeFrom.end();
							takeFromIter++, i++){
						putInIter[i] = *takeFromIter;
					}
				}
			}

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
							vecAlloc.construct(vec, value_type());

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
						countElem = _sizeItersDistance(first, last);
						capacitySize = countElem;
						vecAlloc = alloc;
						vec = vecAlloc.allocate(countElem);
						vecAlloc.construct(vec, value_type());

						iterator	iter(vec);

						for (size_type i=0; first != last; first++){
							iter[i++] = (*first);
						}
					}
		vector (const vector& x){
			countElem = x.countElem;
			capacitySize = x.capacitySize;
			if (!x.vec){
				vec = NULL;
			} else {
				vec = vecAlloc.allocate(capacitySize);
				vecAlloc.construct(vec, value_type());
			}

			operator=(x);
		}
		~vector (void) { _freeMemory(true, capacitySize); }


		// ~~~~~~~~~~ Operators ~~~~~~~~~~
		vector&			operator= (const vector& x){
			_freeMemory(true, capacitySize);
			capacitySize = x.capacitySize;
			vec = vecAlloc.allocate(capacitySize);
			vecAlloc.construct(vec, value_type());

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
			{ const_iterator	constReferBrackets(vec); return constReferBrackets[n]; }


		/* ~~~~~~~~~~ Iterators ~~~~~~~~~~
			begin	|	Return iterator to beginning
			end		|	Return iterator to end
			rbegin	|	Return reverse iterator to reverse beginning
			rend	|	Return reverse iterator to reverse end
		*/
		iterator			begin() const { iterator iter(vec); return countElem ? iter : end(); }
		iterator			end() const { iterator iter(vec); return iter + countElem; }
		reverse_iterator	rbegin() { return reverse_iterator(end()); }
		reverse_iterator	rend() { return reverse_iterator (begin()); }

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
			if (n < countElem){
				for (; countElem > n; countElem--){
					vecAlloc.destroy(vec + countElem);
				}
			} else {
				reserve(n);
				for (; countElem <= n; countElem++){
					vec[countElem] = val;
				}
				countElem--;
			}
		}
		size_type	capacity() const { return capacitySize; }
		bool		empty() const{ return countElem ? false : true; }
		void		reserve (size_type n){
			if (n > capacitySize){
				size_type			oldCapacity = capacitySize;
				_capacityUpdate(n);
				pointer	tmp;

				tmp = vecAlloc.allocate(capacitySize);
				vecAlloc.construct(tmp, value_type());

				for (size_type iter = 0; iter < countElem; iter++){
					tmp[iter] = vec[iter];
				}
				_freeMemory(true, oldCapacity);
				vec = tmp;

			}
		}

		/* ~~~~~~~~~~ Element access ~~~~~~~~~~
			at		|	Returns a reference to the element at position 'n' in the vector
			front	|	Returns a reference to the first element in the vector
			back	|	Returns a reference to the last element in the vector
		*/
		reference			at (size_type n) {
			if (n > countElem || !countElem){
				throw std::invalid_argument("libc++abi.dylib: terminating with uncaught exception of type std::out_of_range: vector");
			}
			return (vec[n]);
		}
		const_reference		at (size_type n) const { at(n); }
		reference			front() { return at(0); }
		const_reference		front() const { return front(); }
		reference			back(){
			if(countElem){
				return vec[countElem - 1];
			}
			return at(countElem);
		}
		const_reference		back() const { return back(); }

		/* ~~~~~~~~~~ Modifiers ~~~~~~~~~~
			assign		|	Assigns new contents to the vector and modifying its size
			push_back	|	Adds a new element at the end of the vector
			pop_back	|	Removes the last element in the vector
			intsert		|	Inserting new elements before the concret element
			earse		|	Removes from the vector one element (position) or a range of elements ([first,last))
			swap		|	Exchanges the vector content by the other
			clear		|	Removes all elements from the vector (which are destroyed)
		*/
		template <class InputIterator>
			void	assign (InputIterator first, InputIterator last,
								typename enable_if<!is_integral<InputIterator>::value,
												InputIterator>::type tmp = InputIterator()){
				(void)tmp;
				_freeMemory(false, countElem);
				countElem = 0;
				for (InputIterator myFirst(first); myFirst != last; myFirst++){
					countElem++;
				}
				if (countElem){
					if (countElem > capacitySize){
						vecAlloc.deallocate(vec, capacitySize);
						vec = vecAlloc.allocate(countElem);
						vecAlloc.construct(vec, value_type());
						capacitySize = countElem;
					}
					for (iterator iterVec(vec); first != last; first++){
						*iterVec = *first;
						iterVec++;
					}
				}
			}

		void		assign (size_type n, const value_type& val){
			_freeMemory(false, countElem);
			countElem = n;
			if (countElem){
				if (countElem > capacitySize){
					vecAlloc.deallocate(vec, capacitySize);
						vec = vecAlloc.allocate(countElem);
						vecAlloc.construct(vec, value_type());
						capacitySize = countElem;
				}
				for (size_type i = 0; i < n; i++){
					vec[i] = val;
				}
			}
		}

		void		push_back (const value_type& val){
			if ((capacitySize - countElem) <= 0){
				reserve(capacitySize+1);
			}
			vec[countElem] = val;
			++countElem;
		}

		void		pop_back(void){
			vecAlloc.destroy(vec + countElem-1);
			--countElem;
		}

		template <class InputIterator>
			void	insert (iterator position, InputIterator first, InputIterator last,
								typename enable_if<!is_integral<InputIterator>::value,
												InputIterator>::type tmp = InputIterator()){
				(void)tmp;
					size_type	distanceSize;
				try {
					distanceSize = _sizeItersDistance(first, last);
				} catch (...) {
					throw std::invalid_argument( "libc++abi.dylib: terminating with uncaught exception of type char const*" );
				}
				size_type	oldCapacity = capacitySize;
				pointer	t;

				_capacityUpdate(countElem+distanceSize);
				t = vecAlloc.allocate(capacitySize);
				vecAlloc.construct(t, value_type());

				iterator	tmpIter(t);
				_writeValue(tmpIter, position, 'b');
				try {
					for (InputIterator i(first); i != last; i++){
						(*tmpIter) = (*i);
						tmpIter++;
					}
				} catch (...) {
					vecAlloc.deallocate(t, 0);
					capacitySize = oldCapacity;
					// throw std::invalid_argument(ex);
					throw std::invalid_argument( "libc++abi.dylib: terminating with uncaught exception of type char const*" );
				}
				// } catch (std::exception& ex) {
				// 	vecAlloc.deallocate(t, 0);
				// 	capacitySize = oldCapacity;
				// 	throw std::invalid_argument(ex);
				// 	// throw std::invalid_argument( "libc++abi.dylib: terminating with uncaught exception of type char const*" );
				// }

				_writeValue(tmpIter, position, 'e');
				countElem += distanceSize;
				_freeMemory(true, oldCapacity);
				vec = t;
			}
		iterator	insert (iterator position, const value_type& val){
			size_type	oldCapacity = capacitySize;
			pointer	tmp;

			_capacityUpdate(countElem+1);
			tmp = vecAlloc.allocate(capacitySize);
			vecAlloc.construct(tmp, value_type());

			iterator	tmpIter(tmp);
			_writeValue(tmpIter, position, 'b');

			(*tmpIter) = val;
			iterator	returnPosition(tmpIter);
			tmpIter++;

			_writeValue(tmpIter, position, 'e');
			countElem++;
			_freeMemory(true, oldCapacity);
			vec = tmp;
			return(returnPosition);
		}
		void		insert (iterator position, size_type n, const value_type& val){
			size_type	oldCapacity = capacitySize;
			pointer	tmp;

			_capacityUpdate(countElem+n);
			tmp = vecAlloc.allocate(capacitySize);
			vecAlloc.construct(tmp, value_type());

			iterator	tmpIter(tmp);
			_writeValue(tmpIter, position, 'b');

			for (size_type i=0; i < n; i++){
				(*tmpIter) = val;
				tmpIter++;
			}

			_writeValue(tmpIter, position, 'e');
			countElem += n;
			_freeMemory(true, oldCapacity);
			vec = tmp;
		}

		//MAYBE TAKE OTHER REALIZATION FROM LAST COMMIT
		iterator	erase (iterator position){
			pointer	tmp;

			tmp = vecAlloc.allocate(capacitySize);
			vecAlloc.construct(tmp, value_type());
			iterator	tmpIter(tmp);
			size_type	distance = _sizeItersDistance((position+1), end());
			size_type	deletePos = countElem - distance - 1;

			_writeValue(tmpIter, (position+1), 'e');
			vecAlloc.destroy(vec+deletePos);
			countElem--;

			for (size_type i = deletePos, y = 0;
					i < distance;
					i++, y++){
				vec[i] = tmp[y];
			}
			return (iterator(vec+deletePos));
		}
		iterator	erase (iterator first, iterator last){
			pointer	tmp;

			tmp = vecAlloc.allocate(capacitySize);
			vecAlloc.construct(tmp, value_type());

			iterator	tmpIter(tmp);
			size_type	toLastDistance = _sizeItersDistance(begin(), last);
			size_type	comingDistance = _sizeItersDistance(first, last);

			_writeValue(tmpIter, first, 'b');
			_writeValue(tmpIter, last, 'e');
			countElem -= comingDistance;
			_freeMemory(true, capacitySize);
			vec = tmp;
			return (iterator(vec+(toLastDistance - comingDistance)));
		}

		void		swap (vector& x){
			vector	tmp(*this);

			_freeMemory(true, countElem);
			_exchangesContant(*this, x);

			x.~vector();
			_exchangesContant(x, tmp);
		}

		void		clear(){ _freeMemory(false, countElem); countElem = 0; }

		//Allocator
		allocator_type	get_allocator() const{ return (vecAlloc); }
	};

	template <class ft_vec, class _Alloc>
		bool operator== (const vector<ft_vec,_Alloc>& lhs,
							const vector<ft_vec,_Alloc>& rhs){
			if (lhs.empty() && rhs.empty()) return true;
			else if (lhs.empty() || rhs.empty()) return false;
			return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}

	template <class ft_vec, class _Alloc>
		bool operator!=(const vector<ft_vec,_Alloc>& lhs,
							const vector<ft_vec,_Alloc>& rhs){
			if (lhs.empty() && rhs.empty()) return false;
			else if (lhs.empty() || rhs.empty()) return true;
			return (lhs == rhs) ? false : true;
		}

	template <class ft_vec, class _Alloc>
		bool operator< (const vector<ft_vec,_Alloc>& lhs,
							const vector<ft_vec,_Alloc>& rhs){
			if (lhs.empty() && rhs.empty()) return false;
			else if (lhs.empty() && !rhs.empty()) return true;
			else if (!lhs.empty() && rhs.empty()) return false;
			return ft::lexicographical_compare(lhs.begin(), lhs.end(),
												rhs.begin(), rhs.end());
		}

	template <class ft_vec, class _Alloc>
		bool operator<=(const vector<ft_vec,_Alloc>& lhs,
							const vector<ft_vec,_Alloc>& rhs){
			if (lhs.empty() && rhs.empty()) return true;
			else if (lhs.empty() && !rhs.empty()) return true;
			else if (!lhs.empty() && rhs.empty()) return false;
			return (lhs < rhs || lhs == rhs) ? true : false;
		}

	template <class ft_vec, class _Alloc>
		bool operator>(const vector<ft_vec,_Alloc>& lhs,
							const vector<ft_vec,_Alloc>& rhs){
			if (lhs.empty() && rhs.empty()) return false;
			else if (lhs.empty() && !rhs.empty()) return false;
			else if (!lhs.empty() && rhs.empty()) return true;
			return (!(lhs <= rhs)) ? true : false;
		}

	template <class ft_vec, class _Alloc>
		bool operator>=(const vector<ft_vec,_Alloc>& lhs,
							const vector<ft_vec,_Alloc>& rhs){
			if (lhs.empty() && rhs.empty()) return true;
			else if (lhs.empty() && !rhs.empty()) return false;
			else if (!lhs.empty() && rhs.empty()) return true;
			return (!(lhs < rhs)) ? true : false;
		}

	template <class ft_vec, class _Alloc>
		void swap(vector<ft_vec,_Alloc>& x,
					vector<ft_vec,_Alloc>& y) {
			x.swap(y);
		}
};


#endif
