#include "brainfuck_interpreter.hpp"
#include "bf_file_parser.hpp"
#include <iostream>

using namespace std;

int main() {
    // brainfuck_interpreter interpreter(",>,>,..<..<..");
    // while(!interpreter.finished()) {
    //     interpreter.execute_step();
    // }
    // cout<<endl<<"[";
    // interpreter.print_memory();
    // cout<<"]";
    bf_file_parser parser("ncp/test.bf");
    brainfuck_interpreter interpreter=parser.load_file();
    interpreter.execute();
}
