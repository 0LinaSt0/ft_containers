/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 17:43:22 by msalena           #+#    #+#             */
/*   Updated: 2022/05/01 07:15:18 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/containers.hpp"
#include <vector>
#include <list>

template<class BidirIt>
void my_reverse(BidirIt first, BidirIt last)
{
    typename ft::iterator_traits<BidirIt>::difference_type n = std::distance(first, last);
    for (--n; n > 0; n -= 2) {
        typename ft::iterator_traits<BidirIt>::value_type tmp = *first;
        *first++ = *--last;
        *last = tmp;
    }
}
 
int main()
{
    std::vector<int, std::allocator<char> > v;
	
	for(int i=1; i<6; i++){
		v.push_back(i);
	}
    my_reverse(v.begin(), v.end());
    std::cout << '\n';
}
// template<class BidirIt>
// void my_reverse(BidirIt first, BidirIt last)
// {
//     typename std::iterator_traits<BidirIt>::difference_type n = std::distance(first, last);
//     for (--n; n > 0; n -= 2) {
//         typename std::iterator_traits<BidirIt>::value_type tmp = *first;
//         *first++ = *--last;
//         *last = tmp;
//     }
// 	if (typeid(typename std::iterator_traits<BidirIt>::iterator_category)==typeid(std::random_access_iterator_tag))
//     	std::cout << "int* is a random-access iterator"<< std::endl ;
// }

// int main()
// {
//     std::vector<int, std::allocator<char> > v{1, 2, 3, 4, 5};
//     my_reverse(v.begin(), v.end());
//     for (int n : v) {
//         std::cout << n << ' ';
//     }
//     std::cout << '\n';
 
//     std::list<int> l{1, 2, 3, 4, 5};
//     my_reverse(l.begin(), l.end());
//     for (int n : l) {
//         std::cout << n << ' ';
//     }
//     std::cout << '\n';
 
//     int a[] = {1, 2, 3, 4, 5};
//     my_reverse(a, a + std::size(a));
//     for (int n : a) {
//         std::cout << n << ' ';
//     }
//     std::cout << '\n';
 
// //    std::istreambuf_iterator<char> i1(std::cin), i2;
// //    my_reverse(i1, i2); // compilation error
 
// }
