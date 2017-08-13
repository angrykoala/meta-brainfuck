#include <fstream>
#include "file_parser.hpp"
using namespace std;


file_parser::file_parser(string filename) {
    this->filename=filename;
}
brainfuck_interpreter file_parser::read_brainfuck() {
    ifstream ifs(this->filename);
    string content((istreambuf_iterator<char>(ifs)),
                   (istreambuf_iterator<char>()));
    return brainfuck_interpreter(content);
}
