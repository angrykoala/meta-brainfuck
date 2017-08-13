#include <fstream>
#include "bf_file_parser.hpp"
using namespace std;



bf_file_parser::bf_file_parser(const string &filename) {
    this->filename=filename;
}

// PUBLIC

brainfuck_interpreter bf_file_parser::load_file() const{
    ifstream ifs(this->filename);
    string content((istreambuf_iterator<char>(ifs)),
                   (istreambuf_iterator<char>()));
    return brainfuck_interpreter(content);
}

// PRIVATE

string bf_file_parser::get_content() const{
    return "";
}
brainfuck_interpreter bf_file_parser::parse_content(const string &content) const{
    return brainfuck_interpreter("");
}
