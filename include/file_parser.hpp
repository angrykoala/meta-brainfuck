#ifndef FILE_PARSER
#define FILE_PARSER

#include "brainfuck_interpreter.hpp"
#include <iostream>
using namespace std;

class file_parser {
private:
    string filename;

public:
    file_parser(string filename);
    brainfuck_interpreter read_brainfuck();
};

# endif
