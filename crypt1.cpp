/*
ID: tcarvel1
TASK: crypt1
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

bool isDigit(int target, int n, int* digits) {
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (digits[i] == target) {found = true; break;}
    }
    return found;
}

int getDigit(int num, int digit) {
    return (num / (int)std::pow(10,digit)) % 10;
}

int main() {
    std::string _;
    std::ifstream fin("crypt1.in");

    int n;
    fin >> n;

    int digits[10];

    for (int i = 0; i < n; i++) {
        fin >> digits[i];
    }

    fin.close();

    int result;
    int subResult1;
    int subResult2;

    int solutions = 0;

    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            for (int c = 0; c < n; c++) {
                for (int d = 0; d < n; d++) {
                    for (int e = 0; e < n; e++) {
                        subResult1 = digits[e] * (digits[a]*100 + digits[b]*10 + digits[c]);

                        if (subResult1 > 999 || !isDigit(getDigit(subResult1,0), n, digits) || !isDigit(getDigit(subResult1,1), n, digits) || !isDigit(getDigit(subResult1,2), n, digits)) {continue;}

                        subResult2 = digits[d] * (digits[a]*100 + digits[b]*10 + digits[c]);

                        if (subResult2 > 999 || !isDigit(getDigit(subResult2,0), n, digits) || !isDigit(getDigit(subResult2,1), n, digits) || !isDigit(getDigit(subResult2,2), n, digits)) {continue;}

                        result = subResult1 + subResult2*10;

                        if (result > 9999 || !isDigit(getDigit(result,0), n, digits) || !isDigit(getDigit(result,1), n, digits) || !isDigit(getDigit(result,2), n, digits) || !isDigit(getDigit(result,3), n, digits)) {continue;}
                        
                        solutions++;
                    }
                }
            }
        }
    }

    std::ofstream fout("crypt1.out");
    fout << solutions << std::endl;
    fout.close();

    return 0;
}

