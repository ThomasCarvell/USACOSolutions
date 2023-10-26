/*
ID: tcarvel1
TASK: preface
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

int N;

int totals[7] = {0,0,0,0,0,0,0};

char key[7] = {'I','V','X','L','C','D','M'};

int units[13][8] = {
    {1,0,0,0,0,0,0,1}, // I
    {1,1,0,0,0,0,0,4}, // IV
    {0,1,0,0,0,0,0,5}, // V
    {1,0,1,0,0,0,0,9}, // IX
    {0,0,1,0,0,0,0,10}, // X
    {0,0,1,1,0,0,0,40}, // XL
    {0,0,0,1,0,0,0,50}, // L
    {0,0,1,0,1,0,0,90}, // XC
    {0,0,0,0,1,0,0,100}, // C
    {0,0,0,0,1,1,0,400}, // CD
    {0,0,0,0,0,1,0,500}, // D
    {0,0,0,0,1,0,1,900}, // CM
    {0,0,0,0,0,0,1,1000} // M
};

void addToTotal(int n) {
    for (int i = 0; i < 7; i++) {
        totals[i] += units[n][i];
    }
}

void addNum(int n) {
    int i = 12;
    while (n > 0) {
        while (n < units[i][7]) {
            i -= 1;
        }
        n -= units[i][7];
        addToTotal(i);
    }
}


int main() {
    std::string _;
    std::ifstream fin("preface.in");
    fin >> N;
    fin.close();

    for (int i = 0; i <= N; i++) {
        addNum(i);
    }
    
    std::ofstream fout("preface.out");
    for (int i = 0; i < 7; i++) {
        if (totals[i] > 0) {
            fout << key[i] << " " << totals[i] << std::endl;
        }
    }
    fout.close();

    return 0;
}

