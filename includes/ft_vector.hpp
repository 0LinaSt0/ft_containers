/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:06:03 by msalena           #+#    #+#             */
/*   Updated: 2022/09/17 23:14:41 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "iterators/vectorIterator.hpp"
#include "ft_containers.hpp"

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

	template < class _T, class _Alloc = std::allocator<_T> >
		class	vector{
		public:
			typedef _T											value_type;
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

			void	_capacityUpdate(size_type amountCapacity);

			void	_freeMemory(bool DoIDeallocate, size_type freeElems);

			pointer	_allocateMemory(pointer &allocateTo, size_type capacSize,
										size_type constructSize);

			template <class InputIterator>
				size_type	_sizeItersDistance(InputIterator first, InputIterator last);

			template <class InputIterator>
				void	_writeValue(InputIterator &container, InputIterator position,
										char whichPartFl);
										
			void	_assignMemoryUpdate(void);
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
								vec = _allocateMemory(vec, capacitySize, countElem);

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
							vec = _allocateMemory(vec, capacitySize, countElem);

							iterator	iter(vec);

							for (size_type i=0; first != last; first++){
								iter[i++] = (*first);
							}
						}

			vector (const vector& x) : countElem(0), capacitySize(0) { operator=(x); }

			~vector (void) { if (capacitySize) { _freeMemory(true, capacitySize); } }


			// ~~~~~~~~~~ Operators ~~~~~~~~~~
			vector&			operator= (const vector& x){
				if (x.countElem){
					if (capacitySize){ _freeMemory(true, capacitySize); }
					capacitySize = 0;
					countElem = x.countElem;
					_capacityUpdate(countElem);
					vec = _allocateMemory(vec, capacitySize, countElem);

						iterator	thisIter(vec);

						for (iterator	xIter(x.begin());
								xIter != x.end();
								xIter++, thisIter++){
							(*thisIter) = (*xIter);
						}
				}
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
						vecAlloc.construct((vec + countElem), val);
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

					tmp = _allocateMemory(tmp, capacitySize, countElem);

					for (size_type iter = 0; iter < countElem; iter++){
						tmp[iter] = vec[iter];
					}
					if(oldCapacity) { _freeMemory(true, oldCapacity); }
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
					if (countElem) { _freeMemory(false, countElem); }
					countElem = 0;
					for (InputIterator myFirst(first); myFirst != last; myFirst++){
						countElem++;
					}
					if (countElem){
						_assignMemoryUpdate();
						for (size_type i = 0; first != last; first++, i++){
							vecAlloc.construct((vec + i), *first);
						}
					}
				}

			void		assign (size_type n, const value_type& val){
				if (countElem) { _freeMemory(false, countElem); }
				countElem = n;
				if (countElem){
					_assignMemoryUpdate();
					for (size_type i = 0; i < n; i++){
						vecAlloc.construct((vec + i), val);
					}
				}
			}

			void		push_back (const value_type& val){
				if ((capacitySize - countElem) <= 0){
					reserve(capacitySize+1);
				}
				vecAlloc.construct((vec + countElem), val);
				++countElem;
			}

			void		pop_back(void){
				vecAlloc.destroy(vec + countElem - 1);
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

					_capacityUpdate(countElem + distanceSize);
					t = _allocateMemory(t, capacitySize, countElem + distanceSize);

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
					if (oldCapacity) { _freeMemory(true, oldCapacity); }
					countElem += distanceSize;
					vec = t;
				}

			iterator	insert (iterator position, const value_type& val){
				size_type	oldCapacity = capacitySize;
				pointer	tmp;

				_capacityUpdate(countElem+1);
				tmp = _allocateMemory(tmp, capacitySize, countElem + 1);

				iterator	tmpIter(tmp);

				_writeValue(tmpIter, position, 'b');

				(*tmpIter) = val;
				iterator	returnPosition(tmpIter);
				tmpIter++;

				_writeValue(tmpIter, position, 'e');
				if (oldCapacity) { _freeMemory(true, oldCapacity); }
				countElem++;
				vec = tmp;
				return(returnPosition);
			}

			void		insert (iterator position, size_type n,
									const value_type& val){
				size_type	oldCapacity = capacitySize;
				pointer	tmp;

				_capacityUpdate(countElem+n);
				tmp = _allocateMemory(tmp, capacitySize, countElem + n);

				iterator	tmpIter(tmp);
				_writeValue(tmpIter, position, 'b');

				for (size_type i=0; i < n; i++){
					(*tmpIter) = val;
					tmpIter++;
				}

				_writeValue(tmpIter, position, 'e');
				if (oldCapacity) { _freeMemory(true, oldCapacity); }
				countElem += n;
				vec = tmp;
			}

			iterator	erase (iterator position){
				size_type	distance = _sizeItersDistance((position+1), end());
				size_type	deletePos = countElem - distance - 1;
				pointer	tmp;

				tmp = _allocateMemory(tmp, capacitySize, countElem - 1);

				iterator	tmpIter(tmp);

				_writeValue(tmpIter, position, 'b');
				_writeValue(tmpIter, (position+1), 'e');
				
				if (capacitySize) { _freeMemory(true, capacitySize); }
				countElem--;
				vec = tmp;
				return (iterator(vec+deletePos));
			}

			iterator	erase (iterator first, iterator last){
				pointer	tmp;
				size_type	toLastDistance = _sizeItersDistance(begin(), last);
				size_type	comingDistance = _sizeItersDistance(first, last);

				tmp = _allocateMemory(tmp, capacitySize, countElem - comingDistance);

				iterator	tmpIter(tmp);

				_writeValue(tmpIter, first, 'b');
				_writeValue(tmpIter, last, 'e');
				if (capacitySize) { _freeMemory(true, capacitySize); }
				countElem -= comingDistance;
				vec = tmp;
				return (iterator(vec+(toLastDistance - comingDistance)));
			}

			void		swap (vector& x){
				pointer			tmpVec = vec;
				allocator_type	tmpAlloc = vecAlloc;
				size_type		tmpCount = countElem;
				size_type		tmpCapacity = capacitySize;

				vec = x.vec;
				vecAlloc = x.vecAlloc;
				countElem = x.countElem;
				capacitySize = x.capacitySize;

				x.vec = tmpVec;
				x.vecAlloc = tmpAlloc;
				x.countElem = tmpCount;
				x.capacitySize = tmpCapacity;
			}

			void		clear(){ _freeMemory(false, countElem); countElem = 0; }

			//Allocator
			allocator_type	get_allocator() const{ return (vecAlloc); }
		};

		template <class _T, class _Alloc>
			bool operator== (const vector<_T,_Alloc>& lhs,
								const vector<_T,_Alloc>& rhs){
				if (lhs.empty() && rhs.empty()) return true;
				else if (lhs.empty() || rhs.empty()) return false;
				return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
			}

		template <class _T, class _Alloc>
			bool operator!=(const vector<_T,_Alloc>& lhs,
								const vector<_T,_Alloc>& rhs){
				if (lhs.empty() && rhs.empty()) return false;
				else if (lhs.empty() || rhs.empty()) return true;
				return (lhs == rhs) ? false : true;
			}

		template <class _T, class _Alloc>
			bool operator< (const vector<_T,_Alloc>& lhs,
								const vector<_T,_Alloc>& rhs){
				if (lhs.empty() && rhs.empty()) return false;
				else if (lhs.empty() && !rhs.empty()) return true;
				else if (!lhs.empty() && rhs.empty()) return false;
				return ft::lexicographical_compare(lhs.begin(), lhs.end(),
													rhs.begin(), rhs.end());
			}

		template <class _T, class _Alloc>
			bool operator<=(const vector<_T,_Alloc>& lhs,
								const vector<_T,_Alloc>& rhs){
				if (lhs.empty() && rhs.empty()) return true;
				else if (lhs.empty() && !rhs.empty()) return true;
				else if (!lhs.empty() && rhs.empty()) return false;
				return (lhs < rhs || lhs == rhs) ? true : false;
			}

		template <class _T, class _Alloc>
			bool operator>(const vector<_T,_Alloc>& lhs,
								const vector<_T,_Alloc>& rhs){
				if (lhs.empty() && rhs.empty()) return false;
				else if (lhs.empty() && !rhs.empty()) return false;
				else if (!lhs.empty() && rhs.empty()) return true;
				return (!(lhs <= rhs)) ? true : false;
			}

		template <class _T, class _Alloc>
			bool operator>=(const vector<_T,_Alloc>& lhs,
								const vector<_T,_Alloc>& rhs){
				if (lhs.empty() && rhs.empty()) return true;
				else if (lhs.empty() && !rhs.empty()) return false;
				else if (!lhs.empty() && rhs.empty()) return true;
				return (!(lhs < rhs)) ? true : false;
			}

		template <class _T, class _Alloc>
			void swap(vector<_T,_Alloc>& x,
						vector<_T,_Alloc>& y) {
				x.swap(y);
			}
};

#include "../useful_tpp/ft_vector.tpp"

#endif
