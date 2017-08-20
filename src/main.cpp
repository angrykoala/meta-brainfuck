#include "brainfuck_interpreter.hpp"
#include "bf_file_parser.hpp"
#include "utils.hpp"
#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    bf_file_parser parser("ncp/test.mbf");
    brainfuck_interpreter interpreter=parser.load_file();
    interpreter.execute();
    interpreter.print_memory();
}
