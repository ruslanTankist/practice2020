//
// Created by gethakt on 16.07.2020.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

#include <vector>
#include <set>

#include <unistd.h>
#include <climits>

struct tr_str {
    std::string comment;
    std::string declaration;
    std::vector<std::string> body;
};

struct strings_struct {
    std::vector<std::string> includes_list;
    std::vector<tr_str> struct_list;
    std::vector<tr_str> classes_list;
};

// std::set<std::string> variable_type = {"void", "int", "char", "bool", "float", "double"};

void readAsLines(std::vector<std::string> &in_lines, const std::string filename)
{
    std::string line;
    int i = 0;
    std::ifstream in (filename);
    if(in.is_open())
    {
        while(getline(in, line))
        {
            in_lines.push_back(line);
            i++;
        }
    }
    in.close();
}

//erasing tabs and spaces
void eraseSpaces(std::vector<std::string> &lines){
    for(int i = 0; i < lines.size(); i++){
        while (lines[i][0] == ' ' || lines[i][0] == '/r')
            lines[i].erase(0, 1);
    }
}

//figuring out the line range of the body
void parseBrackets(const std::vector<std::string> &lines, int pos, std::vector<std::string> &body)
{
    int countOpen = 0, countClose = 0;
    do{
        if (pos == lines.size()) {
            std::cout << "error: more opening brackets than closing\n";
            break;
        }
        body.push_back("");
        for(int i = 0; i < lines[pos].size(); i++){
            if(lines[pos][i] == '{')
                countOpen++;
            if(lines[pos][i] == '}')
                countClose++;
            if(countOpen > 0)
                body[body.size() - 1] += lines[pos][i];
        }
        pos++;
    } while(countOpen > countClose);
}

void Parse(std::vector<std::string> &lines, strings_struct &res)
{
    for(int i = 0; i < lines.size(); i++){
        //filling the structure
        if (lines[i].substr(0, 8) == "#include"){
            res.includes_list.push_back(lines[i]);
        } else if (lines[i].substr(0, 6) == "struct"){
            tr_str struct_strings;
            if (lines[i-1].substr(0, 2) == "//")
                struct_strings.comment = lines[i-1];
            struct_strings.declaration = lines[i];
            parseBrackets(lines, i, struct_strings.body);
            res.struct_list.push_back(struct_strings);
        } else if (lines[i].substr(0, 5) == "class"){
            tr_str struct_strings;
            if (lines[i-1].substr(0, 2) == "//")
                struct_strings.comment = lines[i-1];
            struct_strings.declaration = lines[i];
            parseBrackets(lines, i, struct_strings.body);
            res.classes_list.push_back(struct_strings);
        }
    }
}

void printStruct(strings_struct &str){
    std::cout << "  includes_list:\n";
    for(int i = 0; i < str.includes_list.size(); i++){
        std::cout << " include [" << i << "]\n"
            << str.includes_list[i] << std::endl;
    }

    std::cout << "\n  struct_list:\n";
    for(int i = 0; i < str.struct_list.size(); i++){
        std::cout << " structure [" << i << "]\n"
            << str.struct_list[i].comment << std::endl
            << str.struct_list[i].declaration << std::endl;
        for(int j = 0; j < str.struct_list[i].body.size(); j++) {
            std::cout << str.struct_list[i].body[j] << std::endl;
        }
    }

    std::cout << "\n  classes_list:\n";
    for(int i = 0; i < str.classes_list.size(); i++){
        std::cout << " class [" << i << "]\n"
                  << str.classes_list[i].comment << std::endl
                  << str.classes_list[i].declaration << std::endl;
        for(int j = 0; j < str.classes_list[i].body.size(); j++) {
            std::cout << str.classes_list[i].body[j] << std::endl;
        }
    }
}

int main()
{
    std::vector<std::string> input_lines;
    std::string input_filename;
    std::cout << "Введите имя .h-файла в директории проекта или введите букву t (test), чтобы использовать test/sample.h" << std::endl;
    std::cin >> input_filename;
    if (input_filename == "t")
        input_filename = "test/sample.h";
    readAsLines(input_lines, input_filename);

    eraseSpaces(input_lines);

    strings_struct res;
    Parse(input_lines, res);

    printStruct(res);

    return 0;
}