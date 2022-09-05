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

#include "testsUtils.hpp"
#include "../map.hpp"
#include "../containers.hpp"


namespace ft{
	void	checkForMap(void);

	class	tmpMaps{
	private:
		ft::map<std::string, int>	myStringMap;
		ft::map<char, std::string>	myCharMap;
		ft::vector<int, char>		myIntMap;

		std::map<std::string, int>	origStringMap;
		std::map<char, std::string>	origCharMap;
		std::map<int, char>			origIntMap;
	public:
		tmpMaps(void) {
			setStringMaps();
			setCharMaps();
			setIntMaps();
		}

		~tmpMaps(void) { }

		void	setStringMaps(void){
			std::string	str = "ahora"
			for (size_t i = 0, char c = '~';
					i < factor;
					i++, c--){
				myStringMap[i] = str;
				origStringMap[i] = str;
				if (c == 'A') {
					c == '~';
					str.erase(str.begin()+8, str.begin()+40)
				}
				str += c;
			}
		}

		void	setCharVecs(void){
			for (char i = 0, c = 127;
					i < 64 && i < factor;
					i++, c--){
				myCharMap[i] = c;
				origCharMap[i] = c;
			}
		}

		void	setIntVecs(void){
			for (int i = 0;
					i < 1073741824 && i < factor;
					i++){
				my_vec_int[i] = i + 1073741823;
				orig_vec_int[i] = i + 1073741823;
			}
		}

		ft::map<std::string, int>	&getFtStringMap(void) { return myStringMap; }
		ft::map<char, std::string>	&getFtCharMap(void) { return myCharMap; }
		ft::map<int, char>			&getFtIntMap(void) { return myIntMap; }
		std::map<std::string, int>	&getStdStringMap(void) { return origStringMap; }
		std::map<char, std::string>	&getStdCharMap(void) { return origCharMap; }
		std::map<int, char>			&getStdIntMap(void) { return origIntMap; }
	} ;

	//~~~~~~~~~~~~~~~~~~ HELPFUL_UTILS ~~~~~~~~~~~~~~~~~~

	template <class map>
		// Prints value of map
		void	printMapContent(map &map_cont){
			std::cout << "	vector content: ";
			for (typename map::iterator it(map_cont.begin());
						it != map_cont.end();
						it++){
				std::cout << ((*it).first) << "  ";
			}
			std::cout << std::endl;
		}

	template <class map>
		// Prints all information about map
		void	printMapParams(map	&map_cont, bool isItOrigMap){
			std::cout << "\033[33m";
			(isItOrigMap) ? (std::cout << "STD_") : (std::cout << "FT_");
			std::cout << "MAP_status" << "\033[0m" << std::endl;
			printMapContent(map_cont);
			std::cout << "	count elem: " << map_cont.size() << "\n"
						<< "	emptyFlag: " << map_cont.empty()
						<< std::endl << std::endl;
		}

	template <class ft_map, class std_map>
		// Compare orig and my map
		bool	compareMaps(ft_map& myMap, std_map& origMap){
			if (myMap.size() != origMap.size()) { return false; }
			if (myMap.empty() != origMap.empty()) { return false; }
			if (myMap.empty() && origMap.empty()) { return true; }

			typename ft_map::iterator	myIter(myMap.begin());
			typename std_map::iterator	origIter = origMap.begin();

			while (myIter != myMap.end() || origIter != origMap.end()){
				if (*myIter != *origIter) { return false; }
				myIter++;
				origIter++;
			}
			return true;
		}

	template <class ft_vec, class std_vec>
		// Print result of compare to STDOUT
		void	result(const std::string& fieldName,
						ft_vec& my, std_vec& orig,
						long ft_time, long std_time,
						bool isItCompare){
			if (isItCompare){
				print_results(fieldName, ft_time, std_time);
			} else {
				print_mismatch(fieldName);
				printVecParams(my, false);
				printVecParams(orig, true);
			}
		}

}



#endif
