/*
ID: tcarvel1
TASK: palsquare
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

char digits[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'};

std::string reverse(std::string operand) {
    std::string result = "";
    int n = operand.size()-1;

    for (int i = 0; i <= n; i++) {
        result.push_back(operand[n-i]);
    }

    return result;
}

std::string convertToStr(int n, int base) {
    std::string result = "";
    int copy = n;

    int i = 0;
    while ((float)n / std::pow(base,i) >= base) {
        i += 1;
    }
    
    for (int j = i; j >= 0; j--) {
        result.push_back(digits[copy/(int)std::pow(base,j)]);
        copy %= (int)std::pow(base,j);
    }

    return result;
}

int main() {
    std::string _;
    std::ifstream fin("palsquare.in");
    int base;
    fin >> base;
    fin.close();

    std::ofstream fout("palsquare.out");

    for (int i = 1; i <= 300; i++) {
        std::string sqr = convertToStr(i*i, base);
        if (reverse(sqr) == sqr) {
            fout << convertToStr(i,base) << " " << sqr << std::endl;
        }
    }



    fout.close();

    return 0;
}

