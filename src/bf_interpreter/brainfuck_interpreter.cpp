#include "brainfuck_interpreter.hpp"
#include <iostream>
#include <list>
#include <string>
using namespace std;

brainfuck_interpreter::brainfuck_interpreter(const string &code) {
    this->code = code;
    this->code_position = 0;
    this->memory.push_back(brainfuck_interpreter::default_value);
    this->memory_pointer = this->memory.begin();
    this->secondary_memory_pointer=0;
}

brainfuck_interpreter::brainfuck_interpreter(const string &code, unsigned int code_position,const list<char> &memory,unsigned int memory_pointer) {
    this->code=code;
    this->code_position=code_position;
    this->memory=memory;
    this->memory_pointer = this->memory.begin();
    this->secondary_memory_pointer=0;
    for(unsigned int i=0; i<memory_pointer; i++) {
        this->increment_pointer();
    }
}

brainfuck_interpreter::~brainfuck_interpreter() {}

// PUBLIC

bool brainfuck_interpreter::finished() const {
    return this->code_position >= this->code.size();
}

void brainfuck_interpreter::execute() {
    while(!this->finished()) {
        this->execute_step();
    }
}
void brainfuck_interpreter::execute_step() {
    char command = this->get_current_command();
    this->execute(command);
    this->increment_step();
}

void brainfuck_interpreter::increment_pointer() {
    auto iter=this->memory_pointer;
    iter++;
    if(iter == this->memory.end()) {
        this->memory.push_back(brainfuck_interpreter::default_value);
    }
    this->memory_pointer++;
    this->secondary_memory_pointer++;
}

void brainfuck_interpreter::decrement_pointer() {
    this->memory_pointer--;
    this->secondary_memory_pointer--;
}

void brainfuck_interpreter::increment() {
    char val = this->get_memory_value();
    this->set_memory_value(val + 1);
}

void brainfuck_interpreter::decrement() {
    char val = this->get_memory_value();
    this->set_memory_value(val - 1);
}

void brainfuck_interpreter::output() const {
    cout << this->get_memory_value();
}

void brainfuck_interpreter::input() {
    char value;
    cin.get(value);
    this->set_memory_value(value);
}

void brainfuck_interpreter::goto_forward() {
    char value = this->get_memory_value();
    if(value == 0) {
        while(this->get_current_command() != ']') {
            this->increment_step();
        }
    }
}

void brainfuck_interpreter::goto_backward() {
    char value = this->get_memory_value();
    if(value != 0) {
        while(this->get_current_command() != '[') {
            this->decrement_step();
        }
    }
}

list<char> brainfuck_interpreter::get_memory() const {
    return this->memory;
}

unsigned int brainfuck_interpreter::get_code_positon() const {
    return this->code_position;
}

string brainfuck_interpreter::get_code() const {
    return this->code;
}

unsigned int brainfuck_interpreter::get_memory_pointer() const {
    return this->secondary_memory_pointer;
}

void brainfuck_interpreter::print_memory() const {
    cout<<"{ ";
    for(auto it=this->memory.begin(); it != this->memory.end(); it++) {
        cout<<(int)*it<<" ";
    }
    cout<<"}"<<endl;
}

// Private

char brainfuck_interpreter::get_memory_value() const {
    return *(this->memory_pointer);
}

void brainfuck_interpreter::set_memory_value(char value) {
    *(this->memory_pointer) = value;
}

void brainfuck_interpreter::execute(char command) {
    switch(command) {
    case '+':
        this->increment();
        break;
    case '-':
        this->decrement();
        break;
    case '.':
        this->output();
        break;
    case ',':
        this->input();
        break;
    case '>':
        this->increment_pointer();
        break;
    case '<':
        this->decrement_pointer();
        break;
    case '[':
        this->goto_forward();
        break;
    case ']':
        this->goto_backward();
        break;
    }
}

void brainfuck_interpreter::increment_step() {
    this->code_position++;
}

void brainfuck_interpreter::decrement_step() {
    this->code_position--;
}

char brainfuck_interpreter::get_current_command() const {
    return this->code[this->code_position];
}
