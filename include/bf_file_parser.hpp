#ifndef FILE_PARSER
#define FILE_PARSER

#include "brainfuck_interpreter.hpp"
#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include "bf_file_parser.hpp"
using namespace std;

class bf_file_parser {
private:
    string filename;
    static const regex tag_regex;

public:
    bf_file_parser(const string &filename);
    brainfuck_interpreter load_file() const;

private:
    string get_content() const;
    brainfuck_interpreter parse_content(const string &content) const;
    list<char> parse_memory(const string &raw_memory) const;
};

# endif
