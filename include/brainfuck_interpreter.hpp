# ifndef BF_INTERPRETER
# define BF_INTERPRETER

#include <list>
#include <string>
using namespace std;



class brainfuck_interpreter {
public:
    static const char default_value=0;
private:
    list<unsigned char>::iterator memory_pointer;
    list<unsigned char> memory;
    unsigned int secondary_memory_pointer;
    string code;
    unsigned int code_position;

public:
    brainfuck_interpreter(const string &code);
    brainfuck_interpreter(const string &code, unsigned int code_position,const list<unsigned char> &memory,unsigned int memory_pointer);
    ~brainfuck_interpreter();

    bool finished() const;
    void execute();
    void execute_step();
    void increment_pointer();
    void decrement_pointer();
    void increment();
    void decrement();
    void output() const;
    void input();
    void goto_forward();
    void goto_backward();
    list<unsigned char> get_memory() const;
    unsigned int get_code_positon() const;
    string get_code() const;
    unsigned int get_memory_pointer() const;


    void print_memory() const;

private:
    char get_memory_value() const;
    void set_memory_value(unsigned char value);
    void execute(char commands);
    void increment_step();
    void decrement_step();
    char get_current_command() const;
};

# endif
