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

	template <class ft_pair, class std_pair>
		bool	compareEqualRangeReturnPair(ft_pair &my_pair, std_pair &orig_pair){
			if (my_pair.first->first == orig_pair.first->first
				&& my_pair.second->first == orig_pair.second->first){
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
				my_pair = my_map.insert(*ftIterTmp);
				ft_time = timer.stop();

				timer.start();
				orig_pair = orig_map.insert(*stdIterTmp);
				ft_time = timer.stop();

				result("insert(single)  ", my_map, orig_map, ft_time, std_time,
						compareMaps(my_map, orig_map, my_pair, orig_pair,
										compareInsertReturnPair<ft_pair, std_pair>),
						printMaps<ft_map, std_map>);
			}

			{
			// <<<<<<<<<<<<<<< Tests for insert(hint) >>>>>>>>>>>>>>>
				ft_iter		ftIter(my_map.end());
				std_iter	stdIter(orig_map.end());

				ftIterTmp++; stdIterTmp++;
				ftIter--; stdIter--;

				timer.start();
				ftIter = my_map.insert(ftIter, (*ftIterTmp));
				ft_time = timer.stop();

				timer.start();
				stdIter = orig_map.insert(stdIter, (*stdIterTmp));
				ft_time = timer.stop();

				result("insert(hint)    ", my_map, orig_map, ft_time, std_time,
						compareMaps(my_map, orig_map, ftIter, stdIter,
										compareKeysInPair<ft_iter, std_iter>),
						printMaps<ft_map, std_map>);
			}

			{
			// <<<<<<<<<<<<<<< Tests for insert(range) >>>>>>>>>>>>>>>
				ft_iter		ftIterTmpEnd(my_tmp.end());
				std_iter	stdIterTmpEnd(orig_tmp.end());

				ftIterTmpEnd--; stdIterTmpEnd--;
				ftIterTmpEnd--; stdIterTmpEnd--;
				ftIterTmpEnd--; stdIterTmpEnd--;

				timer.start();
				my_map.insert(ftIterTmp, ftIterTmpEnd);
				ft_time = timer.stop();

				timer.start();
				orig_map.insert(stdIterTmp, stdIterTmpEnd);
				ft_time = timer.stop();

				result("insert(range)   ", my_map, orig_map, ft_time, std_time,
						compareContainers(my_map, orig_map,
											compareKeysInPair<ft_iter, std_iter>),
						printMaps<ft_map, std_map>);
			}
		}

	template <class ft_map, class std_map>
		void	eraseCheckMap(ft_map &my_map, std_map &orig_map){
			typedef typename ft_map::iterator	ft_iter;
			typedef typename std_map::iterator	std_iter;

			ft_iter		ftIter(my_map.begin());
			std_iter	stdIter(orig_map.begin());

			ft::time	timer;
			long	ft_time = 0, std_time = 0;
			{
			// <<<<<<<<<<<<<<< Tests for erase(position) >>>>>>>>>>>>>>>
				timer.start();
				my_map.erase(++ftIter);
				ft_time = timer.stop();

				timer.start();
				orig_map.erase(++stdIter);
				ft_time = timer.stop();

				result("erase(position) ", my_map, orig_map, ft_time, std_time,
						compareContainers(my_map, orig_map,
											compareKeysInPair<ft_iter, std_iter>),
						printMaps<ft_map, std_map>);
			}

			{
			// <<<<<<<<<<<<<<< Tests for erase(value) >>>>>>>>>>>>>>>
				typedef typename ft_map::size_type	ft_size_type;
				typedef typename std_map::size_type	std_size_type;

				ft_size_type	my_size;
				std_size_type	orig_size;

				ftIter = my_map.begin();
				stdIter = orig_map.begin();

				timer.start();
				my_size = my_map.erase((*(ftIter++)).first);
				ft_time = timer.stop();

				timer.start();
				orig_size = orig_map.erase((*(stdIter++)).first);
				ft_time = timer.stop();

				result("erase(value)    ", my_map, orig_map, ft_time, std_time,
						(my_size == orig_size
							&& compareContainers(my_map, orig_map,
													compareKeysInPair<ft_iter,
																		std_iter>)),
						printMaps<ft_map, std_map>);
			}

			{
			// <<<<<<<<<<<<<<< Tests for erase(range) >>>>>>>>>>>>>>>
				ft_iter		ftIterEnd(my_map.end());
				std_iter	stdIterEnd(orig_map.end());

				ftIter = my_map.begin();
				stdIter = orig_map.begin();

				ftIterEnd--; stdIterEnd--;
				ftIterEnd--; stdIterEnd--;
				ftIterEnd--; stdIterEnd--;
				ftIterEnd--; stdIterEnd--;
				ftIterEnd--; stdIterEnd--;
				ftIterEnd--; stdIterEnd--;
				ftIterEnd--; stdIterEnd--;
				ftIterEnd--; stdIterEnd--;
				ftIterEnd--; stdIterEnd--;

				timer.start();
				my_map.erase(ftIter, ftIterEnd);
				ft_time = timer.stop();

				timer.start();
				orig_map.erase(stdIter, stdIterEnd);
				ft_time = timer.stop();

				result("erase(range)    ", my_map, orig_map, ft_time, std_time,
						compareContainers(my_map, orig_map,
											compareKeysInPair<ft_iter, std_iter>),
						printMaps<ft_map, std_map>);
			}
		}

	template <class ft_map, class std_map>
		void	beginCheckMap(ft_map &my_map, std_map &orig_map){
			typedef typename ft_map::iterator	ft_iter;
			typedef typename std_map::iterator	std_iter;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			ft_iter	ftIter = my_map.begin();
			ft_time = timer.stop();

			timer.start();
			std_iter	stdIter = orig_map.begin();
			ft_time = timer.stop();

			result("begin()         ", my_map, orig_map, ft_time, std_time,
					compareMaps(my_map, orig_map, ftIter, stdIter,
									compareKeysInPair<ft_iter, std_iter>),
					printMaps<ft_map, std_map>);
		}

	template <class ft_map, class std_map>
		void	endCheckMap(ft_map &my_map, std_map &orig_map){
			typedef typename ft_map::iterator	ft_iter;
			typedef typename std_map::iterator	std_iter;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			ft_iter	ftIter = my_map.end();
			ft_time = timer.stop();

			timer.start();
			std_iter	stdIter = orig_map.end();
			ft_time = timer.stop();

			result("end()           ", my_map, orig_map, ft_time, std_time,
					compareMaps(my_map, orig_map, (--ftIter), (--stdIter),
									compareKeysInPair<ft_iter, std_iter>),
					printMaps<ft_map, std_map>);
		}

	template <class ft_map, class std_map>
		void	rbeginCheckMap(ft_map &my_map, std_map &orig_map){
			typedef typename ft_map::reverse_iterator	ft_rev_iter;
			typedef typename std_map::reverse_iterator	std_rev_iter;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			ft_rev_iter	ftRevIter = my_map.rbegin();
			ft_time = timer.stop();

			timer.start();
			std_rev_iter	stdRevIter = orig_map.rbegin();
			ft_time = timer.stop();

			result("rbegin()        ", my_map, orig_map, ft_time, std_time,
					compareMaps(my_map, orig_map, (++ftRevIter), (++stdRevIter),
									compareKeysInPair<ft_rev_iter, std_rev_iter>),
					printMaps<ft_map, std_map>);
		}

	template <class ft_map, class std_map>
		void	rendCheckMap(ft_map &my_map, std_map &orig_map){
			typedef typename ft_map::reverse_iterator	ft_rev_iter;
			typedef typename std_map::reverse_iterator	std_rev_iter;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			ft_rev_iter	ftRevIter = my_map.rend();
			ft_time = timer.stop();

			timer.start();
			std_rev_iter	stdRevIter = orig_map.rend();
			ft_time = timer.stop();

			result("rend()          ", my_map, orig_map, ft_time, std_time,
					compareMaps(my_map, orig_map, (--ftRevIter), (--stdRevIter),
									compareKeysInPair<ft_rev_iter, std_rev_iter>),
					printMaps<ft_map, std_map>);
		}

	template <class ft_map, class std_map>
		void	atCheckMap(ft_map &my_map, std_map &orig_map){
			typedef typename ft_map::iterator		ft_iter;
			typedef typename std_map::iterator		std_iter;
			typedef typename ft_map::mapped_type	ft_value;
			typedef typename std_map::mapped_type	std_value;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			ft_value	myValue = my_map.at(my_map.begin()->first);
			ft_time = timer.stop();

			timer.start();
			std_value	origValue = orig_map.at(orig_map.begin()->first);
			ft_time = timer.stop();

			result("at()            ", my_map, orig_map, ft_time, std_time,
					(myValue == origValue
							&& compareContainers(my_map, orig_map,
													compareKeysInPair<ft_iter,
																		std_iter>)),
					printMaps<ft_map, std_map>);
		}

	template <class ft_map, class std_map>
		void	findCheckMap(ft_map &my_map, std_map &orig_map){
			typedef typename ft_map::iterator		ft_iter;
			typedef typename std_map::iterator		std_iter;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			ft_iter	myIter = my_map.find(my_map.begin()->first);
			ft_time = timer.stop();

			timer.start();
			std_iter	origIter = orig_map.find(orig_map.begin()->first);
			ft_time = timer.stop();

			result("find()          ", my_map, orig_map, ft_time, std_time,
					compareMaps(my_map, orig_map, myIter, origIter,
									compareKeysInPair<ft_iter, std_iter>),
					printMaps<ft_map, std_map>);
		}

	template <class ft_map, class std_map>
		void	countCheckMap(ft_map &my_map, std_map &orig_map,
								ft_map &my_tmp, std_map &orig_tmp){
			typedef typename ft_map::iterator		ft_iter;
			typedef typename std_map::iterator		std_iter;
			typedef typename ft_map::size_type		ft_size_type;
			typedef typename std_map::size_type		std_size_type;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			ft_size_type	my_size;
			std_size_type	orig_size;

			ft_iter		myIterTmp = my_tmp.begin();
			std_iter	origIterTmp = orig_tmp.begin();

			myIterTmp++; origIterTmp++;
			myIterTmp++; origIterTmp++;

			timer.start();
			my_size = my_map.count(myIterTmp->first);
			ft_time = timer.stop();

			timer.start();
			orig_size = orig_map.count(origIterTmp->first);
			ft_time = timer.stop();

			result("count()         ", my_map, orig_map, ft_time, std_time,
					(my_size == orig_size
						&& compareContainers(my_map, orig_map,
												compareKeysInPair<ft_iter,
																	std_iter>)),
					printMaps<ft_map, std_map>);
		}

	template <class ft_map, class std_map>
		void	lower_boundCheckMap(ft_map &my_map, std_map &orig_map){
			typedef typename ft_map::iterator		ft_iter;
			typedef typename std_map::iterator		std_iter;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			ft_iter		myIter = my_map.begin();
			std_iter	origIter = orig_map.begin();

			myIter++; origIter++;
			myIter++; origIter++;
			myIter++; origIter++;

			timer.start();
			myIter = my_map.lower_bound(myIter->first);
			ft_time = timer.stop();

			timer.start();
			origIter = orig_map.lower_bound(origIter->first);
			ft_time = timer.stop();

			result("lower_bound()   ", my_map, orig_map, ft_time, std_time,
					compareMaps(my_map, orig_map, myIter, origIter,
									compareKeysInPair<ft_iter, std_iter>),
					printMaps<ft_map, std_map>);
		}

	template <class ft_map, class std_map>
		void	upper_boundCheckMap(ft_map &my_map, std_map &orig_map){
			typedef typename ft_map::iterator		ft_iter;
			typedef typename std_map::iterator		std_iter;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			ft_iter		myIter = my_map.begin();
			std_iter	origIter = orig_map.begin();

			myIter++; origIter++;

			timer.start();
			myIter = my_map.upper_bound(myIter->first);
			ft_time = timer.stop();

			timer.start();
			origIter = orig_map.upper_bound(origIter->first);
			ft_time = timer.stop();

			result("upper_bound()   ", my_map, orig_map, ft_time, std_time,
					compareMaps(my_map, orig_map, myIter, origIter,
									compareKeysInPair<ft_iter, std_iter>),
					printMaps<ft_map, std_map>);
		}

	template <class ft_map, class std_map>
		void	equal_rangeCheckMap(ft_map &my_map, std_map &orig_map){
			typedef typename ft_map::iterator		ft_iter;
			typedef typename std_map::iterator		std_iter;
			typedef	ft::pair<ft_iter, ft_iter>		ft_pair;
			typedef	std::pair<std_iter, std_iter>	std_pair;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			ft_pair		my_pair;
			std_pair	orig_pair;
			ft_iter		myIter = my_map.begin();
			std_iter	origIter = orig_map.begin();

			myIter++; origIter++;

			timer.start();
			my_pair = my_map.equal_range(myIter->first);
			ft_time = timer.stop();

			timer.start();
			orig_pair = orig_map.equal_range(origIter->first);
			ft_time = timer.stop();

			result("equal_range()   ", my_map, orig_map, ft_time, std_time,
					compareMaps(my_map, orig_map, my_pair, orig_pair,
									compareEqualRangeReturnPair<ft_pair, std_pair>),
					printMaps<ft_map, std_map>);
		}

	template <class ft_map, class std_map>
		void	clearCheckMap(ft_map &my_map, std_map &orig_map){
			typedef typename ft_map::iterator		ft_iter;
			typedef typename std_map::iterator		std_iter;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			my_map.clear();
			ft_time = timer.stop();

			timer.start();
			orig_map.clear();
			ft_time = timer.stop();

			result("clear()         ", my_map, orig_map, ft_time, std_time,
					compareContainers(my_map, orig_map,
											compareKeysInPair<ft_iter, std_iter>),
					printMaps<ft_map, std_map>);
		}

	template <class ft_map, class std_map>
		void	swapCheckMap(ft_map &my_map, std_map &orig_map,
								ft_map &my_tmp, std_map &orig_tmp){
			typedef typename ft_map::iterator		ft_iter;
			typedef typename std_map::iterator		std_iter;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			my_map.swap(my_tmp);
			ft_time = timer.stop();

			timer.start();
			orig_map.swap(orig_tmp);
			ft_time = timer.stop();

			result("swap()          ", my_map, orig_map, ft_time, std_time,
					(compareContainers(my_map, orig_map,
											compareKeysInPair<ft_iter, std_iter>)
					&& compareContainers(my_tmp, orig_tmp,
											compareKeysInPair<ft_iter, std_iter>)),
					printMaps<ft_map, std_map>);
		}

	template <class ft_map, class std_map>
		void	compareCheckMaps(ft_map &my_map, std_map &orig_map,
									ft_map &my_tmp, std_map &orig_tmp){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			{
				timer.start();
				bool	myComp = (my_tmp == my_map);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_tmp == orig_map);
				std_time = timer.stop();

				result("map==map       ", my_map, orig_map, ft_time, std_time,
						(myComp == origComp), printMaps<ft_map, std_map>);
			}

			{
				timer.start();
				bool	myComp = (my_tmp != my_map);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_tmp != orig_map);
				std_time = timer.stop();

				result("map!=map       ", my_map, orig_map, ft_time, std_time,
						(myComp == origComp), printMaps<ft_map, std_map>);
			}

			{
				timer.start();
				bool	myComp = (my_tmp < my_map);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_tmp < orig_map);
				std_time = timer.stop();

				result("map<map        ", my_map, orig_map, ft_time, std_time,
						(myComp == origComp), printMaps<ft_map, std_map>);
			}

			{
				timer.start();
				bool	myComp = (my_tmp > my_map);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_tmp > orig_map);
				std_time = timer.stop();

				result("map>map        ", my_map, orig_map, ft_time, std_time,
						(myComp == origComp), printMaps<ft_map, std_map>);
			}

			{
				timer.start();
				bool	myComp = (my_tmp <= my_map);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_tmp <= orig_map);
				std_time = timer.stop();

				result("map<=map       ", my_map, orig_map, ft_time, std_time,
						(myComp == origComp), printMaps<ft_map, std_map>);
			}

			{
				timer.start();
				bool	myComp = (my_tmp != my_map);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_tmp != orig_map);
				std_time = timer.stop();

				result("map>=map        ", my_map, orig_map, ft_time, std_time,
						(myComp == origComp), printMaps<ft_map, std_map>);
			}
	}

	// ~~~~~~~~~~~~~~~~~~~ CHECKS_FOR ITERATOR ~~~~~~~~~~~~~~~~~~~;
	template <class ft_map, class std_map>
		void	iteratorsCheckMaps(ft_map &my_map, std_map &orig_map){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			typename ft_map::iterator	myIterBegin = my_map.begin();
			typename std_map::iterator	origIterBegin = orig_map.begin();
			{
				myIterBegin++; myIterBegin++; myIterBegin++;
				timer.start();
				--myIterBegin;
				ft_time = timer.stop();

				origIterBegin++; origIterBegin++; origIterBegin++;
				timer.start();
				--origIterBegin;
				std_time = timer.stop();

				result("--orerator     ", my_map, orig_map, ft_time, std_time,
						(myIterBegin->first == origIterBegin->first),
						printMaps<ft_map, std_map>);
			}

			{
				timer.start();
				++myIterBegin;
				ft_time = timer.stop();

				timer.start();
				++origIterBegin;
				std_time = timer.stop();

				result("++orerator     ", my_map, orig_map, ft_time, std_time,
						(myIterBegin->first == origIterBegin->first),
						printMaps<ft_map, std_map>);
			}
		}

	template <class ft_map, class std_map>
		void	compareCheckItersMaps(ft_map &my_map, std_map &orig_map){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			typename ft_map::iterator	myIterBegin = my_map.begin();
			typename std_map::iterator	origIterBegin = orig_map.begin();

			{
				timer.start();
				bool	myComp = (myIterBegin == my_map.begin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (origIterBegin == orig_map.begin());
				std_time = timer.stop();

				result("iter==iter     ", my_map, orig_map, ft_time, std_time,
						(myComp == origComp), printMaps<ft_map, std_map>);
			}

			{
				myIterBegin++; myIterBegin++; myIterBegin++;
				timer.start();
				bool	myComp = (myIterBegin != my_map.begin());
				ft_time = timer.stop();

				origIterBegin++; origIterBegin++; origIterBegin++;
				timer.start();
				bool	origComp = (origIterBegin != orig_map.begin());
				std_time = timer.stop();

				result("iter!=iter     ", my_map, orig_map, ft_time, std_time,
						(myComp == origComp), printMaps<ft_map, std_map>);
			}
		}

	template <class ft_map, class std_map>
		void	revIteratorsCheckMaps(ft_map &my_map, std_map &orig_map){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			typename ft_map::reverse_iterator	myIterBegin = my_map.rend();
			typename std_map::reverse_iterator	origIterBegin = orig_map.rend();
			{
				myIterBegin++; myIterBegin++; myIterBegin++;
				timer.start();
				myIterBegin--;
				ft_time = timer.stop();

				origIterBegin++; origIterBegin++; origIterBegin++;
				timer.start();
				origIterBegin--;
				std_time = timer.stop();

				result("orerator--     ", my_map, orig_map, ft_time, std_time,
						(myIterBegin->first == origIterBegin->first),
						printMaps<ft_map, std_map>);
			}

			{
				myIterBegin++; myIterBegin++; myIterBegin++;
				timer.start();
				--myIterBegin;
				ft_time = timer.stop();

				origIterBegin++; origIterBegin++; origIterBegin++;
				timer.start();
				--origIterBegin;
				std_time = timer.stop();

				result("--orerator     ", my_map, orig_map, ft_time, std_time,
						(myIterBegin->first == origIterBegin->first),
						printMaps<ft_map, std_map>);
			}

			{
				myIterBegin--;
				timer.start();
				++myIterBegin;
				ft_time = timer.stop();

				origIterBegin--;
				timer.start();
				++origIterBegin;
				std_time = timer.stop();

				result("++orerator     ", my_map, orig_map, ft_time, std_time,
						(myIterBegin->first == origIterBegin->first),
						printMaps<ft_map, std_map>);
			}
		}

	template <class ft_map, class std_map>
		void	compareCheckRevItersMaps(ft_map &my_map, std_map &orig_map){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			typename ft_map::reverse_iterator	myIterBegin = my_map.rbegin();
			typename std_map::reverse_iterator	origIterBegin = orig_map.rbegin();

			{
				timer.start();
				bool	myComp = (myIterBegin == my_map.rbegin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (origIterBegin == orig_map.rbegin());
				std_time = timer.stop();

				result("iter==iter     ", my_map, orig_map, ft_time, std_time,
						(myComp == origComp), printMaps<ft_map, std_map>);
			}

			{
				myIterBegin++; myIterBegin++; myIterBegin++;
				timer.start();
				bool	myComp = (myIterBegin != my_map.rbegin());
				ft_time = timer.stop();

				origIterBegin++; origIterBegin++; origIterBegin++;
				timer.start();
				bool	origComp = (origIterBegin != orig_map.rbegin());
				std_time = timer.stop();

				result("iter!=iter     ", my_map, orig_map, ft_time, std_time,
						(myComp == origComp), printMaps<ft_map, std_map>);
			}
		}
}



#endif
