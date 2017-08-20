#include "bf_file_parser.hpp"
#include "brainfuck_interpreter.hpp"
#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    bool finished;
    bf_file_parser parser("ncp/test.mbf");
    do {
        brainfuck_interpreter interpreter = parser.load();
        interpreter.execute_step();
        // interpreter.execute();
        parser.save(interpreter);
        finished=interpreter.finished();
    } while(!finished);
}
