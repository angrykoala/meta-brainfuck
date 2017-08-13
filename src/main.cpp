#include "brainfuck_interpreter.hpp"
#include <iostream>

using namespace std;

int main() {
    brainfuck_interpreter interpreter(",>,>,..<..<..");
    while(!interpreter.finished()) {
        interpreter.execute_step();
    }
    cout<<endl<<"[";
    interpreter.print_memory();
    cout<<"]";
}
