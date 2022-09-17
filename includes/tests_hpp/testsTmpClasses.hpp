/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsTmpClasses.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msalena <msalena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:23:41 by marvin            #+#    #+#             */
/*   Updated: 2022/09/10 20:03:58 by msalena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_CLASSES
#define TESTS_CLASSES

#include "testsUtils.hpp"
#include "../ft_vector.hpp"
#include "../ft_set.hpp"
#include "../ft_stack.hpp"
#include "../ft_map.hpp"

namespace	ft{
	class	tmpVectors{
	private:
		ft::vector<std::string>		myStringVec;
		ft::vector<char>			myCharVec;
		ft::vector<int>				myIntVec;

		std::vector<std::string>	origStringVec;
		std::vector<char>			origCharVec;
		std::vector<int>			origIntVec;
	public:
		tmpVectors(void) {
			setStringVecs();
			setCharVecs();
			setIntVecs();
		}

		~tmpVectors(void) { }

		void	setStringVecs(void){
			for (int i = 0; i < factor; i++){
				myStringVec.push_back("hola");
				origStringVec.push_back("hola");
			}
		}

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

		ft::vector<std::string>		&getFtStringVec(void) { return myStringVec; }
		ft::vector<char>			&getFtCharVec(void) { return myCharVec; }
		ft::vector<int>				&getFtIntVec(void) { return myIntVec; }
		std::vector<std::string>	&getStdStringVec(void) { return origStringVec; }
		std::vector<char>			&getStdCharVec(void) { return origCharVec; }
		std::vector<int>			&getStdIntVec(void) { return origIntVec; }
	} ;

	class	tmpMaps{
	private:
		ft::map<std::string, int>	myStringMap;
		ft::map<char, std::string>	myCharMap;
		ft::map<int, char>			myIntMap;

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
			std::string	str = "ahora";
			char c = '~';

			for (int i = 0;
					i < factor;
					i++){
				myStringMap[str] = int();
				origStringMap[str] = int();
				if (c == 'A'){
					c = '~';
					str.erase(str.begin()+1, str.begin()+3);
				}
				str += c;
				c--;
			}
		}

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

		ft::map<std::string, int>	&getFtStringMap(void) { return myStringMap; }
		ft::map<char, std::string>	&getFtCharMap(void) { return myCharMap; }
		ft::map<int, char>			&getFtIntMap(void) { return myIntMap; }
		std::map<std::string, int>	&getStdStringMap(void) { return origStringMap; }
		std::map<char, std::string>	&getStdCharMap(void) { return origCharMap; }
		std::map<int, char>			&getStdIntMap(void) { return origIntMap; }

	} ;

	class	tmpSets{
	private:
		ft::set<std::string>	myStringSet;
		ft::set<char>			myCharSet;
		ft::set<int>			myIntSet;

		std::set<std::string>	origStringSet;
		std::set<char>			origCharSet;
		std::set<int>			origIntSet;
	public:
		tmpSets(void) {
			setStringSets();
			setCharSets();
			setIntSets();
		}

		~tmpSets(void) { }

		void	setStringSets(void){
			std::string	str = "ahora";
			char c = '~';

			for (int i = 0;
					i < factor;
					i++){
				myStringSet.insert(str);
				origStringSet.insert(str);
				if (c == 'A'){
					c = '~';
					str.erase(str.begin()+1, str.begin()+3);
				}
				str += c;
				c--;
			}
		}

		void	setCharSets(void){
			for (char i = 64, q = 0;
					i < 127 && q < factor;
					i++, q++){
				myCharSet.insert(i);
				origCharSet.insert(i);
			}
		}

		void	setIntSets(void){
			for (int i = 1073741824, q = 0;
					i < 2147483647 && q < factor;
					i++, q++){
				myIntSet.insert(i);
				origIntSet.insert(i);
			}
		}

		ft::set<std::string>	&getFtStringSet(void) { return myStringSet; }
		ft::set<char>			&getFtCharSet(void) { return myCharSet; }
		ft::set<int>			&getFtIntSet(void) { return myIntSet; }
		std::set<std::string>	&getStdStringSet(void) { return origStringSet; }
		std::set<char>			&getStdCharSet(void) { return origCharSet; }
		std::set<int>			&getStdIntSet(void) { return origIntSet; }

	} ;

	template <class ft_stack_class, class std_stack_class>
		class	tmpStackString{
		public:
			typedef ft::stack<std::string, ft_stack_class>		ft_stack_string;

			typedef std::stack<std::string, std_stack_class>	std_stack_string;
		private:

			ft_stack_string		myStringStack;

			std_stack_string	origStringStack;
		public:
			tmpStackString(tmpVectors &tmp_vec)
					: myStringStack(tmp_vec.getFtStringVec()),
						origStringStack(tmp_vec.getStdStringVec()) { }

			~tmpStackString(void) { }

			ft_stack_string		&getFtStringStack(void) { return myStringStack; }
			std_stack_string	&getStdStringStack(void) { return origStringStack; }
		} ;
		
	template <class ft_stack_class, class std_stack_class>
		class	tmpStackChar{
		public:
			typedef ft::stack<char, ft_stack_class>		ft_stack_char;

			typedef std::stack<char, std_stack_class>	std_stack_char;
		private:
			ft_stack_char		myCharStack;

			std_stack_char		origCharStack;
		public:
			tmpStackChar(tmpVectors &tmp_vec)
					: myCharStack(tmp_vec.getFtCharVec()),
						origCharStack(tmp_vec.getStdCharVec()) { }

			~tmpStackChar(void) { }

			ft_stack_char		&getFtCharStack(void) { return myCharStack; }
			std_stack_char		&getStdCharStack(void) { return origCharStack; }
		} ;

	template <class ft_stack_class, class std_stack_class>
		class	tmpStackInt{
		public:
			typedef ft::stack<int, ft_stack_class>		ft_stack_int;

			typedef std::stack<int, std_stack_class>	std_stack_int;
		private:
			ft_stack_int		myIntStack;

			std_stack_int		origIntStack;
		public:
			tmpStackInt(tmpVectors &tmp_vec)
					: myIntStack(tmp_vec.getFtIntVec()),
						origIntStack(tmp_vec.getStdIntVec()) { }

			~tmpStackInt(void) { }

			ft_stack_int		&getFtIntStack(void) { return myIntStack; }
			std_stack_int		&getStdIntStack(void) { return origIntStack; }
		} ;
}


#endif
