/*
ID: tcarvel1
TASK: dualpal
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
    std::ifstream fin("dualpal.in");

    int start;
    int num;

    fin >> num;
    fin >> start;

    fin.close();

    std::ofstream fout("dualpal.out");

    int n = start+1;
    int nums = 0;
    int bases;
    std::string strNum;

    while (nums < num) {
        bases = 0;
        for (int i = 2; i <= 10; i++ ) {
            strNum = convertToStr(n, i);
            if (strNum == reverse(strNum)) {
                bases += 1;
                if (bases >= 2){
                    fout << n << std::endl;
                    nums += 1;
                    break;
                }
            }
        }
        n++;
    }


    fout.close();

    return 0;
}

