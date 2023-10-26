/*
ID: tcarvel1
TASK: namenum
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

char mapping[10][3] = {{0,0,0},{0,0,0},{'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','R','S'},{'T','U','V'},{'W','X','Y'}};

int chrToNum(char chr) {
    return (int)chr - (int)'1' + 1;
}

int main() {
    std::string _;
    std::ifstream fin("namenum.in");

    std::string number;
    std::getline(fin, number);

    std::ifstream names("dict.txt");

    std::vector<std::string> dict;
    std::string name;
    while (std::getline(names, name)) {
        if (name.size() == number.size())
            dict.push_back(name);
    }

    for (int let = 0; let < number.size(); let++) {
        for (int nme = dict.size()-1; nme >= 0; nme--) {
            if (!(dict[nme][let] == mapping[chrToNum(number[let])][0] || dict[nme][let] == mapping[chrToNum(number[let])][1] || dict[nme][let] == mapping[chrToNum(number[let])][2]))
                dict.erase(dict.begin()+nme);
        }
    }

    std::ofstream fout("namenum.out");

    for (int nme = 0; nme < dict.size(); nme++) {
        fout << dict[nme] << std::endl;
    }

    if (dict.size() == 0) {
        fout << "NONE" << std::endl;
    }

    fout.close(); 

    return 0;
}

