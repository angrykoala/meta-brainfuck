#include "brainfuck_interpreter.hpp"
#include <iostream>

using namespace std;

int main() {
    brainfuck_interpreter interpreter(",++.");
    interpreter.execute_step();
    interpreter.execute_step();
    interpreter.execute_step();
    interpreter.execute_step();
}
