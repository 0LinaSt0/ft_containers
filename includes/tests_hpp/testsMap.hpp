/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsMap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 15:43:23 by msalena           #+#    #+#             */
/*   Updated: 2022/08/31 22:07:45 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_MAP_HPP
#define TESTS_MAP_HPP

#include "testsClasses.hpp"
#include "../map.hpp"
#include "../containers.hpp"


namespace ft{
	void	mapChecker(valueType key_type);

	//~~~~~~~~~~~~~~~~~~ HELPFUL_UTILS ~~~~~~~~~~~~~~~~~~

	template <class map>
		// Prints value of rb_container
		void	printMapContent(map &map_cont){
			std::cout << "	content: ";
			for (typename map::iterator it(map_cont.begin());
						it != map_cont.end();
						it++){
				std::cout << ((*it).first) << "  ";
			}
			std::cout << std::endl;
		}

	template <class map>
		// Prints all information about rb_container
		void	printMapParams(map &map_cont, bool isItOrigRbCont){
			std::cout << "\033[33m";
			(isItOrigRbCont) ? (std::cout << "STD_") : (std::cout << "FT_");
			std::cout << "MAP_status" << "\033[0m" << std::endl;
			printMapContent(map_cont);
			std::cout << "	count elem: " << map_cont.size() << "\n"
						<< "	emptyFlag: " << map_cont.empty()
						<< std::endl << std::endl;
		}

	template <class ft_map, class std_map>
		void	printMaps(ft_map &my, std_map &orig){
			printMapParams(my, false);
			printMapParams(orig, true);
		}

	template <class ft_iter, class std_iter>
		bool	compareKeysInPair(ft_iter &my_iter, std_iter &orig_iter){
			if ((*my_iter).first != (*orig_iter).first){
				return false;
			}
			return true;
		}

	template <class ft_pair, class std_pair>
		bool	compareInsertReturnPair(ft_pair &my_pair, std_pair &orig_pair){
			if ((*(my_pair.first)).first == (*(orig_pair.first)).first
				&& my_pair.second == orig_pair.second){
				return true;
			}
			return false;
		}

	template <class ft_map, class std_map,
				class ft_content, class std_content,
				class plusFuncCompare>
		bool	compareMaps(ft_map &my_map, std_map &orig_map,
							ft_content &my_cont, std_content &orig_cont,
							plusFuncCompare func){
			typedef typename ft_map::iterator	ft_iter;
			typedef typename std_map::iterator	std_iter;

			if (func(my_cont, orig_cont) && compareContainers(my_map, orig_map,
						compareKeysInPair<ft_iter, std_iter>)){
				return true;
			}
			return false;
		}

	//~~~~~~~~~~~ CHECKS_FOR_MEMBER_FUNCTIONS ~~~~~~~~~~~

	template <class ft_map, class std_map>
		void	constructorsCheckMap(ft_map &my_tmp, std_map &orig_tmp){
			typedef typename ft_map::iterator	ft_iter;
			typedef typename std_map::iterator	std_iter;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;
			{
				// /* <<<<<<<<<<<<<<< Tests for empty_constructor >>>>>>>>>>>>>>>*/
				timer.start();
				ft_map	my_map;
				ft_time = timer.stop();

				timer.start();
				std_map	orig_map;
				std_time = timer.stop();

				result("construc(empty) ", my_map, orig_map, ft_time, std_time,
						compareContainers(my_map, orig_map,
						compareKeysInPair<ft_iter, std_iter>),
						printMaps<ft_map, std_map>);
			}

			{
				/* <<<<<<<<<<<<<<< Tests for range_constructor >>>>>>>>>>>>>>>*/
				ft_iter		myIter(my_tmp.end());
				std_iter	origIter(orig_tmp.end());

				timer.start();
				ft_map	my_map(my_tmp.begin(),(--myIter));
				ft_time = timer.stop();

				timer.start();
				std_map	orig_map(orig_tmp.begin(),(--origIter));
				std_time = timer.stop();

				result("construc(range) ", my_map, orig_map, ft_time, std_time,
						compareContainers(my_map, orig_map,
						compareKeysInPair<ft_iter, std_iter>),
						printMaps<ft_map, std_map>);
			}

			{
				/* <<<<<<<<<<<<<<< Tests for copy_constructor >>>>>>>>>>>>>>>*/
				timer.start();
				ft_map	my_map(my_tmp);
				ft_time = timer.stop();

				timer.start();
				std_map	orig_map(orig_tmp);
				std_time = timer.stop();
				result("construc(copy)  ", my_map, orig_map, ft_time, std_time,
						compareContainers(my_map, orig_map,
						compareKeysInPair<ft_iter, std_iter>),
						printMaps<ft_map, std_map>);
			}
		}


	template <class ft_map, class std_map>
		void	insertCheckMap(ft_map &my_map, std_map &orig_map,
								ft_map &my_tmp, std_map &orig_tmp){
			typedef typename ft_map::iterator	ft_iter;
			typedef typename std_map::iterator	std_iter;

			ft_iter		ftIterTmp(my_tmp.begin());
			std_iter	stdIterTmp(orig_tmp.begin());

			ft::time	timer;
			long	ft_time = 0, std_time = 0;
			{
			// <<<<<<<<<<<<<<< Tests for insert(single) >>>>>>>>>>>>>>>
				typedef	ft::pair<ft_iter, bool>		ft_pair;
				typedef	std::pair<std_iter, bool>	std_pair;

				ft_pair		my_pair;
				std_pair	orig_pair;

				timer.start();
				my_pair = my_map.insert(*(++ftIterTmp));
				ft_time = timer.stop();

				timer.start();
				orig_pair = orig_map.insert(*(++stdIterTmp));
				ft_time = timer.stop();

				result("insert(single)  ", my_map, orig_map, ft_time, std_time,
						compareMaps(my_map, orig_map, my_pair, orig_pair,
										compareInsertReturnPair<ft_pair, std_pair>),
						printMaps<ft_map, std_map>);
			}
		}


	// insertCheck(my_vec, orig_vec, my_tmp, orig_tmp);
	// eraseCheck(my_vec, orig_vec);
	// beginCheckMap(my_vec, orig_vec);
	// checkEndMap(my_vec, orig_vec);
	// rbeginCheckMap(my_vec, orig_vec);
	// rendCheckMap(my_vec, orig_vec);
	// atCheckMap(my_vec, orig_vec);
	// findCheckMap(my_vec, orig_vec);
	// countCheckMap(my_vec, orig_vec);
	// lower_boundCheckMap();
	// upper_boundCheckMap();
	// equal_boundCheckMap();
	// clearChechMap(my_vec, orig_vec);
	// swapCheckMap(my_vec, orig_vec, my_tmp, orig_tmp);

}



#endif
