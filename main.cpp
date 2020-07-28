//
// Created by gethakt on 16.07.2020.
//

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <unistd.h>
#include <climits>

struct tr_str {
    std::string comment;
    std::string declaration;
    std::string body;
};

struct strings_struct {
    std::vector<std::string> includes_list;
    std::vector<tr_str> struct_list;
    std::vector<tr_str> classes_list;
};

void read_as_lines(std::vector<std::string> &in_lines, std::string filename)
{
    std::string line;
    int i = 0;
    std::ifstream in (filename);
    if(in.is_open())
    {
        while(getline(in, line))
        {
            in_lines.push_back(line);
            std::cout << i << ' ' << in_lines[i] << std::endl;
            i++;
        }
    }
    in.close();
}

void Parse(const std::vector<std::string> &lines, strings_struct &res)
{
    for(int i = 0; i < lines.size(); i++){
        while(getchar())
    }
}

int main()
{
    std::vector<std::string> input_lines;
    read_as_lines(input_lines, "test/sample.h");

    strings_struct res;
    Parse(input_lines, res);

    return 0;
}
