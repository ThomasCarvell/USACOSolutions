/*
ID: tcarvel1
TASK: sprime
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

int N;

bool isPrime (int n) {

    if (n == 2) return true;
    if (n%2 < 1 || n < 2) return false;

    for (int i = 3; i*i <= n; i+=2) {
        if (n%i < 1) {return false;}
    }
    return true;
}

int getDigit(int n, int d) {return (n / (int)std::pow(10,d))%10;}


int main() {
    std::string _;
    std::ifstream fin("sprime.in");

    fin >> N;

    fin.close();

    int i = 0;

    for (int j = 0; j <= N-2; j++) {
        i += std::pow(10,j);
    }
    i += std::pow(10,N-1)*2;

    int digit;
    int n;
    bool notValid = false;
    bool isValid = false;

    std::ofstream fout("sprime.out");

    while (i < (int)std::pow(10,N)-1) {
        isValid = true;

        n = 0;
        for (int dig = N-1; dig >= 0; dig--) {
            n *= 10;
            n += getDigit(i,dig);

            if (!isPrime(n)) {isValid = false; i += (int)std::pow(10,dig); break;}
        }
        if (isValid) {fout << i << std::endl; i += 2;}

    }

    fout.close();

    return 0;
}

