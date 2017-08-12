#include "brainfuck_interpreter.hpp"
#include <iostream>

using namespace std;

int main() {
    brainfuck_interpreter interpreter("");
    interpreter.increment();
    interpreter.output();
    cout << endl;
}
