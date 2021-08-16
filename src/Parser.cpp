#include "../include/Parser.hpp"

namespace parserUtilities {
	std::string convertUnderscoresToWhitespaces(std::string s) {
		std::string n;
		for (char c : s) { n += (c == '_') ? ' ' : c; }
		return n;
	}
}

bool Splitter::present(char c) {
	// Using std::find defined in <algorithm> to find if an element `c` is present within a container
	return (std::find(this->delimiters.begin(), this->delimiters.end(), c) != this->delimiters.end());
}

Splitter::Splitter(std::string buffer) {
	// Initialize this->parts to make the algorithm used work
	this->parts.push_back( "" );

	// Set of pre-defined delimiters to make the parsing work
	this->delimiters.push_back( '\n' );
	this->delimiters.push_back( '\t' );
	this->delimiters.push_back( ' ' );
	this->delimiters.push_back( '=' );

	// Set the buffer to read from to buffer
	this->buffer = buffer;
}

void Splitter::split() {
	/* Read */
	std::ifstream fin(this->buffer);
	char c;

	// Read every character
	// If the character is a delimiter, add a new part
	// Else, add the character to the string at the back of this->parts
	while (fin >> std::noskipws >> c) {
		if (this->present(c)) {
			if (this->parts.back() != "") {
				this->parts.push_back("");
			} else {
				continue;
			}
		} else {
			this->parts.back() += c;
		}
	}
	fin.close();

	/* Clean */
	for (int i = 0; i < this->parts.size(); i++) {
		if (this->parts[i] == " " || this->parts[i] == "" || this->parts[i] == "\n" || this->parts[i] == "=") {
			this->parts.erase(this->parts.begin() + i);
		}
	}
}

Lexer::Lexer(std::vector<std::string> parts) {
	this->parts = parts;
}

void Lexer::lex() {
	while (this->parts.empty() == false) {
		// Put every pair of elements in this->links
		this->links[this->parts[0]] = this->parts[1];
		this->parts.erase(this->parts.begin());
		this->parts.erase(this->parts.begin());
	}
}

std::string Lexer::operator[](std::string key) {
	return this->links[key];
}

Parser::Parser(std::string buffer) {
	// Simple API to put everything together
	this->s = new Splitter(buffer);
	this->s->split();

	this->l = new Lexer(this->s->parts);
	this->l->lex();
}

Parser::~Parser() {
	delete this->s;
	delete this->l;
}

std::string Parser::operator[](std::string key) {
	return this->l->links[key];
}
