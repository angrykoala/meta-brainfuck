#ifndef FILE_PARSER
#define FILE_PARSER

#include "brainfuck_interpreter.hpp"
#include <iostream>
using namespace std;

class bf_file_parser {
private:
    string filename;

public:
    bf_file_parser(const string &filename);
    brainfuck_interpreter load_file() const;

private:
    string get_content() const;
    brainfuck_interpreter parse_content(const string &content) const;
};

# endif
