#include "brainfuck_interpreter.hpp"
#include <iostream>
#include <list>
#include <string>
using namespace std;


brainfuck_interpreter::brainfuck_interpreter(string code) {
    this->code=code;
    this->code_position=0;
    this->memory.push_back(brainfuck_interpreter::default_value);
    this->memory_pointer=this->memory.begin();
}
brainfuck_interpreter::~brainfuck_interpreter() {}

void brainfuck_interpreter::increment_pointer() {
    if(this->memory_pointer==this->memory.end()) {
        this->memory.push_back(brainfuck_interpreter::default_value);
    }
    this->memory_pointer++;
}
void brainfuck_interpreter::decrement_pointer() {
    this->memory_pointer--;
}
void brainfuck_interpreter::increment() {
    char val=this->get_memory_value();
    this->set_memory_value(val++);
}
void brainfuck_interpreter::decrement() {
    char val=this->get_memory_value();
    this->set_memory_value(val--);
}
void brainfuck_interpreter::output() {
    cout<<this->get_memory_value();
}
void brainfuck_interpreter::input() {
    char value;
    cin.get(value);
    this->set_memory_value(value);
}
void brainfuck_interpreter::goto_forward() {
}
void brainfuck_interpreter::goto_backward() {
}

// Private

char brainfuck_interpreter::get_memory_value() {
    return *(this->memory_pointer);
}

void brainfuck_interpreter::set_memory_value(char value) {
    *(this->memory_pointer)=value;
}
