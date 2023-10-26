/*
ID: tcarvel1
TASK: frac1
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>

int N;

struct fract {
    int numerator;
    int denominator;

    float value() {
        return (float)numerator / (float)denominator;
    }

    int sum() {
        return numerator + denominator;
    }

    std::string print() {
        return  std::to_string(numerator)+"/"+std::to_string(denominator);
    }
};

int main() {
    std::string _;
    std::ifstream fin("frac1.in");

    fin >> N;

    fin.close();

    fract fractions[160];

    for (int i = 0; i < N; i++) {
        fractions[i] = {1,i+1};
    }

    std::ofstream fout("frac1.out");
    fout << "0/1" << std::endl;

    float minValue;
    int minFraction;
    float lastValue = 0;

    while (lastValue < 1) {
        minValue = 1;
        minFraction = 0;
        for (int i = 0; i < N; i++) {
            if (fractions[i].value() == lastValue) {
                fractions[i].numerator += 1;
            }

            if (fractions[i].value() < minValue) {
                minValue = fractions[i].value();
                minFraction = i;
            }
        }

        fout << fractions[minFraction].numerator << "/" << fractions[minFraction].denominator << std::endl;
        lastValue = fractions[minFraction].value();
        fractions[minFraction].numerator += 1;
    }



    fout.close();

    return 0;
}

