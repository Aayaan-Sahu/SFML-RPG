#include "../include/Parser.hpp"

namespace parserUtilities {
	std::string convertUnderscoresToWhitespaces(std::string s) {
		std::string n;
		for (char c : s) { n += (c == '_') ? ' ' : c; }
		return n;
	}
}

bool Splitter::present(char c) {
	return (std::find(this->delimiters.begin(), this->delimiters.end(), c) != this->delimiters.end());
}

Splitter::Splitter(std::string buffer) {
	this->parts.push_back( "" );
	this->delimiters.push_back( '\n' );
	this->delimiters.push_back( '\t' );
	this->delimiters.push_back( ' ' );
	this->delimiters.push_back( '=' );
	this->buffer = buffer;
}

void Splitter::split() {
	/* Read */
	std::ifstream fin(this->buffer);
	char c;
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
		this->links[this->parts[0]] = this->parts[1];
		this->parts.erase(this->parts.begin());
		this->parts.erase(this->parts.begin());
	}
}

std::string Lexer::operator[](std::string key) {
	return this->links[key];
}

Parser::Parser(std::string buffer) {
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
