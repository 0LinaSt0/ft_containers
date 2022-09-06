/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsClasses.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:24:46 by marvin            #+#    #+#             */
/*   Updated: 2022/09/05 15:24:46 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_CLASSES
#define TESTS_CLASSES

#include "testsUtils.hpp"
#include "../vector.hpp"
#include "../set.hpp"
#include "../stack.hpp"
#include "../map.hpp"

namespace	ft{
	class	tmpVectors{
	private:
		// ft::vector<std::string>		myStringVec;
		ft::vector<char>			myCharVec;
		ft::vector<int>				myIntVec;

		// std::vector<std::string>	origStringVec;
		std::vector<char>			origCharVec;
		std::vector<int>			origIntVec;
	public:
		tmpVectors(void) {
			// setStringVecs();
			setCharVecs();
			setIntVecs();
		}

		~tmpVectors(void) { }

		// void	setStringVecs(void){
		// 	for (int i = 0; i < factor; i++){
		// 		myStringVec.push_back("hola");
		// 		origStringVec.push_back("hola");
		// 	}
		// }

		void	setCharVecs(void){
			for (int i = 0; i < factor; i++){
				myCharVec.push_back('s');
				origCharVec.push_back('s');
			}
		}

		void	setIntVecs(void){
			for (int i = 0; i < factor; i++){
				myIntVec.push_back(i*2);
				origIntVec.push_back(i*2);
			}
		}

		// ft::vector<std::string>		&getFtStringVec(void) { return myStringVec; }
		ft::vector<char>			&getFtCharVec(void) { return myCharVec; }
		ft::vector<int>				&getFtIntVec(void) { return myIntVec; }
		// std::vector<std::string>	&getStdStringVec(void) { return origStringVec; }
		std::vector<char>			&getStdCharVec(void) { return origCharVec; }
		std::vector<int>			&getStdIntVec(void) { return origIntVec; }
	} ;

	class	tmpMaps{
	private:
		// ft::map<std::string, int>	myStringMap;
		ft::map<char, std::string>	myCharMap;
		ft::map<int, char>			myIntMap;

		// std::map<std::string, int>	origStringMap;
		std::map<char, std::string>	origCharMap;
		std::map<int, char>			origIntMap;
	public:
		tmpMaps(void) {
			// setStringMaps();
			setCharMaps();
			setIntMaps();
		}

		~tmpMaps(void) { }

		// void	setStringMaps(void){
		// 	std::string	str = "ahora";
		// 	char c = '~';

		// 	for (int i = 0;
		// 			i < factor;
		// 			i++){
		// 		myStringMap[str] = int();
		// 		origStringMap[str] = int();
		// 		if (c == 'A'){
		// 			c = '~';
		// 			str.erase(str.begin()+1, str.begin()+3);
		// 		}
		// 		str += c;
		// 		c--;
		// 	}
		// }

		void	setCharMaps(void){
			for (char i = 64, q = 0;
					i < 127 && q < factor;
					i++, q++){
				myCharMap[i] = std::string();
				origCharMap[i] = std::string();
			}
		}

		void	setIntMaps(void){
			for (int i = 1073741824, q = 0;
					i < 2147483647 && q < factor;
					i++, q++){
				myIntMap[i] = char();
				origIntMap[i] = char();
			}
		}

		// ft::map<std::string, int>	&getFtStringMap(void) { return myStringMap; }
		ft::map<char, std::string>	&getFtCharMap(void) { return myCharMap; }
		ft::map<int, char>			&getFtIntMap(void) { return myIntMap; }
		// std::map<std::string, int>	&getStdStringMap(void) { return origStringMap; }
		std::map<char, std::string>	&getStdCharMap(void) { return origCharMap; }
		std::map<int, char>			&getStdIntMap(void) { return origIntMap; }

	} ;


}


#endif
