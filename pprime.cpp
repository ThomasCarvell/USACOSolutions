/*
ID: tcarvel1
TASK: pprime
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

int min;
int max;

int palindromeeven(int n, int digits) {
    int nDigits =  digits;

    int number = 0;
    int digit = 0;
    for (int i = 0; i < nDigits; i++) {
        digit = (n / (int)std::pow(10,i))%10;
        number += (int)std::pow(10, nDigits+i) * digit;
        number += (int)std::pow(10, nDigits-i-1) * digit;
    }
    return number;
}

int palindromeodd(int n, int digits) {
    int nDigits =  digits;

    int number = 0;
    int digit = 0;
    number += (int)std::pow(10, nDigits-1) * (n%10);
    for (int i = 1; i < nDigits; i++) {
        digit = (n / (int)std::pow(10,i))%10;
        number += (int)std::pow(10, nDigits+i-1) * digit;
        number += (int)std::pow(10, nDigits-i-1) * digit;
    }
    return number;
}

bool isPrime (int n) {
    if (n%2 < 1) return false;

    for (int i = 3; i*i <= n; i+=2) {
        if (n%i < 1) {return false;}
    }
    return true;
}

int main() {
    std::string _;
    std::ifstream fin("pprime.in");

    fin >> min;
    fin >> max;

    fin.close();


    bool done = false;
    int lastDig;
    int num;

    std::ofstream fout("pprime.out");

    for (int dig = 1; dig <= 4; dig++) {
        for (int i = int(std::pow(10,dig-1)); i < int(std::pow(10,dig)); i++) {

            lastDig = (i / (int)std::pow(10,dig-1))%10;
            if (dig > 1 && !(lastDig == 3 || lastDig == 7 || lastDig == 1 || lastDig == 9)) {
                continue;
            }

            num = palindromeodd(i,dig);
            if (num > max) {done = true; break;}
            if (num < min) {continue;}
            if (isPrime(num))
                fout << num << std::endl;
        }

        if (dig == 1 && 11 > min && 11 < max) {
            fout << 11 << std::endl;
        }

        /*for (int i = int(std::pow(10,dig-1)); i < int(std::pow(10,dig)); i++) {
            num = palindromeeven(i,dig);
            if (num > max) {done = true; break;}
            if (num < min) {continue;}
            if (isPrime(num))
                fout << num << std::endl;
        }*/

        if (done) break;
    }

    fout.close();

    return 0;
}