#include "brainfuck_interpreter.hpp"
#include "bf_file_parser.hpp"
#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    bf_file_parser loader("ncp/test.mbf");
    brainfuck_interpreter interpreter=loader.load();
    interpreter.execute_step();
    //interpreter.execute();
    interpreter.print_memory();
    bf_file_parser writer("ncp/test2.mbf");
    writer.save(interpreter);
}
