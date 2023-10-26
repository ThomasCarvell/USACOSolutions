/*
ID: tcarvel1
TASK: transform
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct pattern {
    int data[10][10] = {};
    int n = 0;
};

pattern rotate90(pattern operand) {
    pattern result;
    result.n = operand.n;

    int n = result.n-1;

    for (int x = 0; x < operand.n; x++)  {
        for (int y = 0; y < operand.n; y++) {
            result.data[n-y][x] = operand.data[x][y];
        }
    }

    return result;
};

pattern reflect(pattern operand) {
    pattern result;
    result.n = operand.n;

    int n = result.n-1;

    for (int x = 0; x < operand.n; x++)  {
        for (int y = 0; y < operand.n; y++) {
            result.data[n-x][y] = operand.data[x][y];
        }
    }

    return result;
};

void printPattern(pattern operand) {
    for (int y = 0; y < operand.n; y++) {
        for (int x = 0; x < operand.n; x++) {
            if (operand.data[x][y] == 2) {
                std::cout << "-" << " ";
            } else {
                std::cout << "@" << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
};

bool equal(pattern op1, pattern op2) {
    for (int y = 0; y < op1.n; y++) {
        for (int x = 0; x < op1.n; x++) {
            if (op1.data[x][y] != op2.data[x][y]) {
                return false;
            }
        }
    }
    return true;
};

int main() {
    std::string _;
    std::ifstream fin("transform.in");

    pattern input;
    pattern target;

    fin >> input.n;
    target.n = input.n;
    std::getline(fin, _);

    std::string line;

    for (int i = 0; i < input.n; i++) {
        std::getline(fin, line);
        for (int j = 0; j < input.n; j++) {
            input.data[j][i] = (int)(line[j]=='-') + 1;
        }
    }

    for (int i = 0; i < target.n; i++) {
        std::getline(fin, line);
        for (int j = 0; j < target.n; j++) {
            target.data[j][i] = (int)(line[j]=='-') + 1;
        }
    }

    int num = 7;

    pattern rot90 = rotate90(input);
    pattern rot180;
    pattern rot270;

    pattern reflection;
    pattern refrot90;
    pattern refrot180;
    pattern refrot270;

    if (equal(rot90, target)) {
        num = 1;
    } 
    if (num == 7) {
        rot180 = rotate90(rot90);
        if (equal(rot180, target)) {
            num = 2;
        }
    }
    if (num == 7) {
        rot270 = rotate90(rot180);
        if (equal(rot270, target)) {
            num = 3;
        }
    }
    if (num == 7) {
        reflection = reflect(input);
        if (equal(reflection, target)) {
            num = 4;
        }
    }
    if (num == 7) {
        refrot90 = rotate90(reflection);
        refrot180 = rotate90(refrot90);
        refrot270 = rotate90(refrot180);

        if (equal(target, refrot90) || equal(target, refrot180) || equal(target, refrot270)) {
            num = 5;
        }
    }
    if (num == 7 && equal(target,input)) {
        num = 6;
    }

    std::ofstream fout("transform.out");

    fout << num << std::endl;

    fout.close();

    return 0;
}