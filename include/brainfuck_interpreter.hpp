# ifndef BF_INTERPRETER
# define BF_INTERPRETER

#include <list>
#include <string>
using namespace std;



class brainfuck_interpreter {
public:
    static const char default_value=0;
private:
    list<char>::iterator memory_pointer;
    list<char> memory;

    string code;
    unsigned int code_position;

public:
    brainfuck_interpreter(string code);
    ~brainfuck_interpreter();

    void increment_pointer();
    void decrement_pointer();
    void increment();
    void decrement();
    void output();
    void input();
    void goto_forward();
    void goto_backward();

private:
    char get_memory_value();
    void set_memory_value(char value);
};

# endif
