#ifndef _PARSER_HPP
#define _PARSER_HPP

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

namespace parserUtilities {
	/* For the game's use case: to get a title that contains spaces */
	std::string convertUnderscoresToWhitespaces(std::string s);
}

class Splitter {

	private:
		bool present(char c);

	public:
		std::vector<std::string> parts;

	public:
		/* Constructor / Destructor */
		Splitter(std::string buffer);

		/* Functions */
		void split();
	
	private:
		std::vector<char> delimiters;
		std::string buffer;

};

class Lexer {

	public:
		std::map<std::string, std::string> links;

	public:
		/* Constructor / Destructor */
		Lexer(std::vector<std::string> parts);

		/* Functions */
		void lex();

		/* Overloads */
		std::string operator[](std::string key);

	private:
		std::vector<std::string> parts;

};

class Parser {

	public:
		Parser(std::string buffer);
		~Parser();

		/* Overloads */
		std::string operator[](std::string key);

	private:
		Splitter* s;
		Lexer* l;

};

#endif
