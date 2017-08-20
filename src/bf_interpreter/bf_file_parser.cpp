#include "bf_file_parser.hpp"

using namespace std;


const regex bf_file_parser::tag_regex("^\\s*\\{(\\d*)\\}\\s*\\{(\\d*)\\}\\s*\\{([\\s\\d]*)\\}\\s*([+-.><,\\[\\]]*)\\s*$");


bf_file_parser::bf_file_parser(const string &filename) {
    this->filename=filename;
}

// PUBLIC

brainfuck_interpreter bf_file_parser::load_file() const {
    string content=this->get_content();
    return this->parse_content(content);
}

// PRIVATE

string bf_file_parser::get_content() const {
    ifstream ifs(this->filename);
    string content((istreambuf_iterator<char>(ifs)),
                   (istreambuf_iterator<char>()));
    return content;
}

brainfuck_interpreter bf_file_parser::parse_content(const string &content) const {
    smatch m;
    regex_search(content,m,this->tag_regex);
    unsigned int code_position=stoi(m[1]);
    unsigned int memory_pointer=stoi(m[2]);
    list<char> memory=this->parse_memory(m[3]);
    // cout<<m[1]<<endl<<m[2]<<endl<<m[3]<<endl;
    return brainfuck_interpreter(m[4],code_position,memory,memory_pointer);
}

list<char> bf_file_parser::parse_memory(const string &raw_memory) const{
    list<char> memory;
    regex r(R"(\d+)");
    sregex_iterator iter(raw_memory.begin(),raw_memory.end(),r);
    sregex_iterator end;

    while(iter!=end){
        char value=stoi((*iter)[0]);
        memory.push_back(value);
        iter++;
    }
    return memory;
}
