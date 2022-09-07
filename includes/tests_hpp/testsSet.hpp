/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsSet.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 09:58:51 by marvin            #+#    #+#             */
/*   Updated: 2022/09/07 09:58:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_SET_HPP
#define TESTS_SET_HPP

#include "testsTmpClasses.hpp"
#include "../ft_set.hpp"
#include "../ft_containers.hpp"

namespace ft{
	void	setChecker(valueType key_type);

	//~~~~~~~~~~~~~~~~~~ HELPFUL_UTILS ~~~~~~~~~~~~~~~~~~

	template <class set>
		// Prints value of rb_container
		void	printSetContent(set &set_cont){
			std::cout << "	content: ";
			for (typename set::iterator it(set_cont.begin());
						it != set_cont.end();
						it++){
				std::cout << *it << "  ";
			}
			std::cout << std::endl;
		}

	template <class set>
		// Prints all information about rb_container
		void	printSetParams(set &set_cont, bool isItOrigRbCont){
			std::cout << "\033[33m";
			(isItOrigRbCont) ? (std::cout << "STD_") : (std::cout << "FT_");
			std::cout << "SET_status" << "\033[0m" << std::endl;
			printSetContent(set_cont);
			std::cout << "	count elem: " << set_cont.size() << "\n"
						<< "	emptyFlag: " << set_cont.empty()
						<< std::endl << std::endl;
		}

	template <class ft_set, class std_set>
		void	printSets(ft_set &my, std_set &orig){
			printSetParams(my, false);
			printSetParams(orig, true);
		}

	template <class ft_pair, class std_pair>
		bool	compareInsertReturnPairSet(ft_pair &my_pair, std_pair &orig_pair){
			if ((*(my_pair.first)) == (*(orig_pair.first))
				&& my_pair.second == orig_pair.second){
				return true;
			}
			return false;
		}

	template <class ft_pair, class std_pair>
		bool	compareEqualRangeReturnPairSet(ft_pair &my_pair, std_pair &orig_pair){
			if ((*(my_pair.first)) == (*(orig_pair.first))
				&& (*(my_pair.second)) == (*(orig_pair.second))){
				return true;
			}
			return false;
		}

	template <class ft_iter, class std_iter>
		bool	compareIteratorsSet(ft_iter &my_iter, std_iter &orig_iter){
			if (*my_iter == *orig_iter) { return true; }
			return false;
		}

	template <class ft_set, class std_set,
				class ft_content, class std_content,
				class plusFuncCompare>
		bool	compareSets(ft_set &my_set, std_set &orig_set,
							ft_content &my_cont, std_content &orig_cont,
							plusFuncCompare func){
			if (func(my_cont, orig_cont)
					&& compareContainers(my_set, orig_set)){
				return true;
			}
			return false;
		}

	//~~~~~~~~~~~ CHECKS_FOR_MEMBER_FUNCTIONS ~~~~~~~~~~~

	template <class ft_set, class std_set>
		void	constructorsCheckSet(ft_set &my_tmp, std_set &orig_tmp){
			typedef typename ft_set::iterator	ft_iter;
			typedef typename std_set::iterator	std_iter;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;
			{
				// /* <<<<<<<<<<<<<<< Tests for empty_constructor >>>>>>>>>>>>>>>*/
				timer.start();
				ft_set	my_set;
				ft_time = timer.stop();

				timer.start();
				std_set	orig_set;
				std_time = timer.stop();

				result("construc(empty) ", my_set, orig_set, ft_time, std_time,
						compareContainers(my_set, orig_set),
						printSets<ft_set, std_set>);
			}

			{
				/* <<<<<<<<<<<<<<< Tests for range_constructor >>>>>>>>>>>>>>>*/
				ft_iter		myIter(my_tmp.end());
				std_iter	origIter(orig_tmp.end());

				timer.start();
				ft_set	my_set(my_tmp.begin(),(--myIter));
				ft_time = timer.stop();

				timer.start();
				std_set	orig_set(orig_tmp.begin(),(--origIter));
				std_time = timer.stop();

				result("construc(range) ", my_set, orig_set, ft_time, std_time,
						compareContainers(my_set, orig_set),
						printSets<ft_set, std_set>);
			}

			{
				/* <<<<<<<<<<<<<<< Tests for copy_constructor >>>>>>>>>>>>>>>*/
				timer.start();
				ft_set	my_set(my_tmp);
				ft_time = timer.stop();

				timer.start();
				std_set	orig_set(orig_tmp);
				std_time = timer.stop();
				result("construc(copy)  ", my_set, orig_set, ft_time, std_time,
						compareContainers(my_set, orig_set),
						printSets<ft_set, std_set>);
			}
		}

	template <class ft_set, class std_set>
		void	insertCheckSet(ft_set &my_set, std_set &orig_set,
								ft_set &my_tmp, std_set &orig_tmp){
			typedef typename ft_set::iterator	ft_iter;
			typedef typename std_set::iterator	std_iter;

			ft_iter		myIterTmp(my_tmp.begin());
			std_iter	origIterTmp(orig_tmp.begin());

			ft::time	timer;
			long	ft_time = 0, std_time = 0;
			{
			// <<<<<<<<<<<<<<< Tests for insert(single) >>>>>>>>>>>>>>>
				typedef	ft::pair<ft_iter, bool>		ft_pair;
				typedef	std::pair<std_iter, bool>	std_pair;

				ft_pair		my_pair;
				std_pair	orig_pair;

				timer.start();
				my_pair = my_set.insert(*myIterTmp);
				ft_time = timer.stop();

				timer.start();
				orig_pair = orig_set.insert(*origIterTmp);
				ft_time = timer.stop();

				result("insert(single)  ", my_set, orig_set, ft_time, std_time,
						compareSets(my_set, orig_set, my_pair, orig_pair,
										compareInsertReturnPairSet<ft_pair, std_pair>),
						printSets<ft_set, std_set>);
			}

			{
			// <<<<<<<<<<<<<<< Tests for insert(hint) >>>>>>>>>>>>>>>
				ft_iter		myIter(my_set.end());
				std_iter	origIter(orig_set.end());

				myIterTmp++; origIterTmp++;
				myIter--; origIter--;

				timer.start();
				myIter = my_set.insert(myIter, (*myIterTmp));
				ft_time = timer.stop();

				timer.start();
				origIter = orig_set.insert(origIter, (*origIterTmp));
				ft_time = timer.stop();

				result("insert(hint)    ", my_set, orig_set, ft_time, std_time,
						compareSets(my_set, orig_set, myIter, origIter,
										compareIteratorsSet<ft_iter, std_iter>),
						printSets<ft_set, std_set>);
			}

			{
			// <<<<<<<<<<<<<<< Tests for insert(range) >>>>>>>>>>>>>>>
				ft_iter		myIterTmpEnd(my_tmp.end());
				std_iter	origIterTmpEnd(orig_tmp.end());

				myIterTmpEnd--; origIterTmpEnd--;
				myIterTmpEnd--; origIterTmpEnd--;
				myIterTmpEnd--; origIterTmpEnd--;

				timer.start();
				my_set.insert(myIterTmp, myIterTmpEnd);
				ft_time = timer.stop();

				timer.start();
				orig_set.insert(origIterTmp, origIterTmpEnd);
				ft_time = timer.stop();

				result("insert(range)   ", my_set, orig_set, ft_time, std_time,
						compareContainers(my_set, orig_set),
						printSets<ft_set, std_set>);
			}
		}

	template <class ft_set, class std_set>
		void	eraseCheckSet(ft_set &my_set, std_set &orig_set){
			typedef typename ft_set::iterator	ft_iter;
			typedef typename std_set::iterator	std_iter;

			ft_iter		myIter(my_set.begin());
			std_iter	origIter(orig_set.begin());

			ft::time	timer;
			long	ft_time = 0, std_time = 0;
			{
			// <<<<<<<<<<<<<<< Tests for erase(position) >>>>>>>>>>>>>>>
				timer.start();
				my_set.erase(++myIter);
				ft_time = timer.stop();

				timer.start();
				orig_set.erase(++origIter);
				ft_time = timer.stop();

				result("erase(position) ", my_set, orig_set, ft_time, std_time,
						compareContainers(my_set, orig_set),
						printSets<ft_set, std_set>);
			}

			{
			// <<<<<<<<<<<<<<< Tests for erase(value) >>>>>>>>>>>>>>>
				typedef typename ft_set::size_type	ft_size_type;
				typedef typename std_set::size_type	std_size_type;

				ft_size_type	my_size;
				std_size_type	orig_size;

				myIter = my_set.begin();
				origIter = orig_set.begin();

				timer.start();
				my_size = my_set.erase((*(myIter++)));
				ft_time = timer.stop();

				timer.start();
				orig_size = orig_set.erase((*(origIter++)));
				ft_time = timer.stop();

				result("erase(value)    ", my_set, orig_set, ft_time, std_time,
						(my_size == orig_size
							&& compareContainers(my_set, orig_set)),
						printSets<ft_set, std_set>);
			}

			{
			// <<<<<<<<<<<<<<< Tests for erase(range) >>>>>>>>>>>>>>>
				ft_iter		myIterEnd(my_set.end());
				std_iter	origIterEnd(orig_set.end());

				myIter = my_set.begin();
				origIter = orig_set.begin();

				myIterEnd--; origIterEnd--;
				myIterEnd--; origIterEnd--;
				myIterEnd--; origIterEnd--;
				myIterEnd--; origIterEnd--;
				myIterEnd--; origIterEnd--;
				myIterEnd--; origIterEnd--;
				myIterEnd--; origIterEnd--;
				myIterEnd--; origIterEnd--;
				myIterEnd--; origIterEnd--;

				timer.start();
				my_set.erase(myIter, myIterEnd);
				ft_time = timer.stop();

				timer.start();
				orig_set.erase(origIter, origIterEnd);
				ft_time = timer.stop();

				result("erase(range)    ", my_set, orig_set, ft_time, std_time,
						compareContainers(my_set, orig_set),
						printSets<ft_set, std_set>);
			}
		}

	template <class ft_set, class std_set>
		void	beginCheckSet(ft_set &my_set, std_set &orig_set){
			typedef typename ft_set::iterator	ft_iter;
			typedef typename std_set::iterator	std_iter;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			ft_iter	myIter = my_set.begin();
			ft_time = timer.stop();

			timer.start();
			std_iter	origIter = orig_set.begin();
			ft_time = timer.stop();

			result("begin()         ", my_set, orig_set, ft_time, std_time,
					compareSets(my_set, orig_set, myIter, origIter,
										compareIteratorsSet<ft_iter, std_iter>),
					printSets<ft_set, std_set>);
		}

	template <class ft_set, class std_set>
		void	endCheckSet(ft_set &my_set, std_set &orig_set){
			typedef typename ft_set::iterator	ft_iter;
			typedef typename std_set::iterator	std_iter;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			ft_iter	myIter = my_set.end();
			ft_time = timer.stop();

			timer.start();
			std_iter	origIter = orig_set.end();
			ft_time = timer.stop();

			result("end()           ", my_set, orig_set, ft_time, std_time,
					compareSets(my_set, orig_set, (--myIter), (--origIter),
									compareIteratorsSet<ft_iter, std_iter>),
					printSets<ft_set, std_set>);
		}

	template <class ft_set, class std_set>
		void	rbeginCheckSet(ft_set &my_set, std_set &orig_set){
			typedef typename ft_set::reverse_iterator	ft_rev_iter;
			typedef typename std_set::reverse_iterator	std_rev_iter;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			ft_rev_iter	ftRevIter = my_set.rbegin();
			ft_time = timer.stop();

			timer.start();
			std_rev_iter	stdRevIter = orig_set.rbegin();
			ft_time = timer.stop();

			result("rbegin()        ", my_set, orig_set, ft_time, std_time,
					compareSets(my_set, orig_set, (++ftRevIter), (++stdRevIter),
									compareIteratorsSet<ft_rev_iter, std_rev_iter>),
					printSets<ft_set, std_set>);
		}

	template <class ft_set, class std_set>
		void	rendCheckSet(ft_set &my_set, std_set &orig_set){
			typedef typename ft_set::reverse_iterator	ft_rev_iter;
			typedef typename std_set::reverse_iterator	std_rev_iter;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			ft_rev_iter	ftRevIter = my_set.rend();
			ft_time = timer.stop();

			timer.start();
			std_rev_iter	stdRevIter = orig_set.rend();
			ft_time = timer.stop();

			result("rend()          ", my_set, orig_set, ft_time, std_time,
					compareSets(my_set, orig_set, (--ftRevIter), (--stdRevIter),
								compareIteratorsSet<ft_rev_iter, std_rev_iter>),
					printSets<ft_set, std_set>);
		}

	template <class ft_set, class std_set>
		void	findCheckSet(ft_set &my_set, std_set &orig_set){
			typedef typename ft_set::iterator		ft_iter;
			typedef typename std_set::iterator		std_iter;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			ft_iter	myIter = my_set.find(*(my_set.begin()));
			ft_time = timer.stop();

			timer.start();
			std_iter	origIter = orig_set.find(*(orig_set.begin()));
			ft_time = timer.stop();

			result("find()          ", my_set, orig_set, ft_time, std_time,
					compareSets(my_set, orig_set, myIter, origIter,
								compareIteratorsSet<ft_iter, std_iter>),
					printSets<ft_set, std_set>);
		}

	template <class ft_set, class std_set>
		void	countCheckSet(ft_set &my_set, std_set &orig_set,
								ft_set &my_tmp, std_set &orig_tmp){
			typedef typename ft_set::iterator		ft_iter;
			typedef typename std_set::iterator		std_iter;
			typedef typename ft_set::size_type		ft_size_type;
			typedef typename std_set::size_type		std_size_type;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			ft_size_type	my_size;
			std_size_type	orig_size;

			ft_iter		myIterTmp = my_tmp.begin();
			std_iter	origIterTmp = orig_tmp.begin();

			myIterTmp++; origIterTmp++;
			myIterTmp++; origIterTmp++;

			timer.start();
			my_size = my_set.count(*myIterTmp);
			ft_time = timer.stop();

			timer.start();
			orig_size = orig_set.count(*origIterTmp);
			ft_time = timer.stop();

			result("count()         ", my_set, orig_set, ft_time, std_time,
					(my_size == orig_size
						&& compareContainers(my_set, orig_set)),
					printSets<ft_set, std_set>);
		}

	template <class ft_set, class std_set>
		void	lower_boundCheckSet(ft_set &my_set, std_set &orig_set){
			typedef typename ft_set::iterator		ft_iter;
			typedef typename std_set::iterator		std_iter;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			ft_iter		myIter = my_set.begin();
			std_iter	origIter = orig_set.begin();

			myIter++; origIter++;
			myIter++; origIter++;
			myIter++; origIter++;

			timer.start();
			myIter = my_set.lower_bound(*myIter);
			ft_time = timer.stop();

			timer.start();
			origIter = orig_set.lower_bound(*origIter);
			ft_time = timer.stop();

			result("lower_bound()   ", my_set, orig_set, ft_time, std_time,
					compareSets(my_set, orig_set, myIter, origIter,
								compareIteratorsSet<ft_iter, std_iter>),
					printSets<ft_set, std_set>);
		}

	template <class ft_set, class std_set>
		void	upper_boundCheckSet(ft_set &my_set, std_set &orig_set){
			typedef typename ft_set::iterator		ft_iter;
			typedef typename std_set::iterator		std_iter;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			ft_iter		myIter = my_set.begin();
			std_iter	origIter = orig_set.begin();

			myIter++; origIter++;

			timer.start();
			myIter = my_set.upper_bound(*myIter);
			ft_time = timer.stop();

			timer.start();
			origIter = orig_set.upper_bound(*origIter);
			ft_time = timer.stop();

			result("upper_bound()   ", my_set, orig_set, ft_time, std_time,
					compareSets(my_set, orig_set, myIter, origIter,
								compareIteratorsSet<ft_iter, std_iter>),
					printSets<ft_set, std_set>);
		}

	template <class ft_set, class std_set>
		void	equal_rangeCheckSet(ft_set &my_set, std_set &orig_set){
			typedef typename ft_set::iterator		ft_iter;
			typedef typename std_set::iterator		std_iter;
			typedef	ft::pair<ft_iter, ft_iter>		ft_pair;
			typedef	std::pair<std_iter, std_iter>	std_pair;

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			ft_pair		my_pair;
			std_pair	orig_pair;
			ft_iter		myIter = my_set.begin();
			std_iter	origIter = orig_set.begin();

			myIter++; origIter++;

			timer.start();
			my_pair = my_set.equal_range(*myIter);
			ft_time = timer.stop();

			timer.start();
			orig_pair = orig_set.equal_range(*origIter);
			ft_time = timer.stop();

			result("equal_range()   ", my_set, orig_set, ft_time, std_time,
					compareSets(my_set, orig_set, my_pair, orig_pair,
								compareEqualRangeReturnPairSet<ft_pair, std_pair>),
					printSets<ft_set, std_set>);
		}

	template <class ft_set, class std_set>
		void	clearCheckSet(ft_set &my_set, std_set &orig_set){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			my_set.clear();
			ft_time = timer.stop();

			timer.start();
			orig_set.clear();
			ft_time = timer.stop();

			result("clear()         ", my_set, orig_set, ft_time, std_time,
					compareContainers(my_set, orig_set),
					printSets<ft_set, std_set>);
		}

	template <class ft_set, class std_set>
		void	swapCheckSet(ft_set &my_set, std_set &orig_set,
								ft_set &my_tmp, std_set &orig_tmp){

			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			timer.start();
			my_set.swap(my_tmp);
			ft_time = timer.stop();

			timer.start();
			orig_set.swap(orig_tmp);
			ft_time = timer.stop();

			result("swap()          ", my_set, orig_set, ft_time, std_time,
					(compareContainers(my_set, orig_set)
						&& compareContainers(my_tmp, orig_tmp)),
					printSets<ft_set, std_set>);
		}

	template <class ft_set, class std_set>
		void	compareCheckSets(ft_set &my_set, std_set &orig_set,
									ft_set &my_tmp, std_set &orig_tmp){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			{
				timer.start();
				bool	myComp = (my_tmp == my_set);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_tmp == orig_set);
				std_time = timer.stop();

				result("set==set        ", my_set, orig_set, ft_time, std_time,
						(myComp == origComp), printSets<ft_set, std_set>);
			}

			{
				timer.start();
				bool	myComp = (my_tmp != my_set);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_tmp != orig_set);
				std_time = timer.stop();

				result("set!=set        ", my_set, orig_set, ft_time, std_time,
						(myComp == origComp), printSets<ft_set, std_set>);
			}

			{
				timer.start();
				bool	myComp = (my_tmp < my_set);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_tmp < orig_set);
				std_time = timer.stop();

				result("set<set         ", my_set, orig_set, ft_time, std_time,
						(myComp == origComp), printSets<ft_set, std_set>);
			}

			{
				timer.start();
				bool	myComp = (my_tmp > my_set);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_tmp > orig_set);
				std_time = timer.stop();

				result("set>set         ", my_set, orig_set, ft_time, std_time,
						(myComp == origComp), printSets<ft_set, std_set>);
			}

			{
				timer.start();
				bool	myComp = (my_tmp <= my_set);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_tmp <= orig_set);
				std_time = timer.stop();

				result("set<=set        ", my_set, orig_set, ft_time, std_time,
						(myComp == origComp), printSets<ft_set, std_set>);
			}

			{
				timer.start();
				bool	myComp = (my_tmp != my_set);
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (orig_tmp != orig_set);
				std_time = timer.stop();

				result("set>=set        ", my_set, orig_set, ft_time, std_time,
						(myComp == origComp), printSets<ft_set, std_set>);
			}
	}

	// ~~~~~~~~~~~~~~~~~~~ CHECKS_FOR ITERATOR ~~~~~~~~~~~~~~~~~~~;
	template <class ft_set, class std_set>
		void	iteratorsCheckSets(ft_set &my_set, std_set &orig_set){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			typename ft_set::iterator	myIterBegin = my_set.begin();
			typename std_set::iterator	origIterBegin = orig_set.begin();
			{
				myIterBegin++; myIterBegin++; myIterBegin++;
				timer.start();
				--myIterBegin;
				ft_time = timer.stop();

				origIterBegin++; origIterBegin++; origIterBegin++;
				timer.start();
				--origIterBegin;
				std_time = timer.stop();

				result("--orerator      ", my_set, orig_set, ft_time, std_time,
						compareIteratorsSet(myIterBegin, origIterBegin),
						printSets<ft_set, std_set>);
			}

			{
				timer.start();
				++myIterBegin;
				ft_time = timer.stop();

				timer.start();
				++origIterBegin;
				std_time = timer.stop();

				result("++orerator      ", my_set, orig_set, ft_time, std_time,
						compareIteratorsSet(myIterBegin, origIterBegin),
						printSets<ft_set, std_set>);
			}
		}

	template <class ft_set, class std_set>
		void	compareCheckItersSets(ft_set &my_set, std_set &orig_set){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			typename ft_set::iterator	myIterBegin = my_set.begin();
			typename std_set::iterator	origIterBegin = orig_set.begin();

			{
				timer.start();
				bool	myComp = (myIterBegin == my_set.begin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (origIterBegin == orig_set.begin());
				std_time = timer.stop();

				result("iter==iter      ", my_set, orig_set, ft_time, std_time,
						(myComp == origComp), printSets<ft_set, std_set>);
			}

			{
				myIterBegin++; myIterBegin++; myIterBegin++;
				timer.start();
				bool	myComp = (myIterBegin != my_set.begin());
				ft_time = timer.stop();

				origIterBegin++; origIterBegin++; origIterBegin++;
				timer.start();
				bool	origComp = (origIterBegin != orig_set.begin());
				std_time = timer.stop();

				result("iter!=iter      ", my_set, orig_set, ft_time, std_time,
						(myComp == origComp), printSets<ft_set, std_set>);
			}
		}

	template <class ft_set, class std_set>
		void	revIteratorsCheckSets(ft_set &my_set, std_set &orig_set){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			typename ft_set::reverse_iterator	myIterBegin = my_set.rbegin();
			typename std_set::reverse_iterator	origIterBegin = orig_set.rbegin();
			{
				myIterBegin++; myIterBegin++; myIterBegin++;
				timer.start();
				myIterBegin--;
				ft_time = timer.stop();

				origIterBegin++; origIterBegin++; origIterBegin++;
				timer.start();
				origIterBegin--;
				std_time = timer.stop();

				result("orerator--      ", my_set, orig_set, ft_time, std_time,
						compareIteratorsSet(myIterBegin, origIterBegin),
						printSets<ft_set, std_set>);
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

				result("--orerator      ", my_set, orig_set, ft_time, std_time,
						compareIteratorsSet(myIterBegin, origIterBegin),
						printSets<ft_set, std_set>);
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

				result("++orerator      ", my_set, orig_set, ft_time, std_time,
						compareIteratorsSet(myIterBegin, origIterBegin),
						printSets<ft_set, std_set>);
			}
		}

	template <class ft_set, class std_set>
		void	compareCheckRevItersSets(ft_set &my_set, std_set &orig_set){
			ft::time	timer;
			long	ft_time = 0, std_time = 0;

			typename ft_set::reverse_iterator	myIterBegin = my_set.rbegin();
			typename std_set::reverse_iterator	origIterBegin = orig_set.rbegin();

			{
				timer.start();
				bool	myComp = (myIterBegin == my_set.rbegin());
				ft_time = timer.stop();

				timer.start();
				bool	origComp = (origIterBegin == orig_set.rbegin());
				std_time = timer.stop();

				result("iter==iter      ", my_set, orig_set, ft_time, std_time,
						(myComp == origComp), printSets<ft_set, std_set>);
			}

			{
				myIterBegin++; myIterBegin++; myIterBegin++;
				timer.start();
				bool	myComp = (myIterBegin != my_set.rbegin());
				ft_time = timer.stop();

				origIterBegin++; origIterBegin++; origIterBegin++;
				timer.start();
				bool	origComp = (origIterBegin != orig_set.rbegin());
				std_time = timer.stop();

				result("iter!=iter      ", my_set, orig_set, ft_time, std_time,
						(myComp == origComp), printSets<ft_set, std_set>);
			}
		}
}

#endif
