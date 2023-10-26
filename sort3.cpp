/*
ID: tcarvel1
TASK: sort3
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

int N;
int seq[1000];

int min(int x, int y) {
    if (x < y) return x;
    return y;
}

int main() {
    std::string _;
    std::ifstream fin("sort3.in");

    fin >> N;

    for (int i = 0; i < N; i++) {
        fin >> seq[i];
    }

    fin.close();

    int num1 = 0;
    int num2 = 0;
    int num3 = 0;

    for (int i = 0; i < N; i++) {
        if (seq[i] == 1) {
            num1++;
        } else if (seq[i] == 2) {
            num2++;
        } else {
            num3++;
        }
    }

    int s1 = 0;
    int s2 = num1;
    int s3 = num1+num2;

    int oneSeq[3] = {0};
    int twoSeq[3] = {0};
    int threeSeq[3] = {0};

    for (int i = s1; i < s2; i++) oneSeq[seq[i]-1]++;
    for (int i = s2; i < s3; i++) twoSeq[seq[i]-1]++;
    for (int i = s3; i < N; i++) threeSeq[seq[i]-1]++;

    int moves =   min(oneSeq[1], twoSeq[0])
                + min(oneSeq[2], threeSeq[0])
                + min(twoSeq[2], threeSeq[1]);

    oneSeq[1] -= min(oneSeq[1], twoSeq[0]);
    twoSeq[0] -= min(oneSeq[1], twoSeq[0]);

    oneSeq[2] -= min(oneSeq[2], threeSeq[0]);
    threeSeq[0] -= min(oneSeq[2], threeSeq[0]);

    twoSeq[2] -= min(twoSeq[2], threeSeq[1]);
    threeSeq[1] -= min(twoSeq[2], threeSeq[1]);

    moves += 2 * (oneSeq[1] + oneSeq[2]);

    std::ofstream fout("sort3.out");

    fout << moves << std::endl;

    fout.close();

    return 0;
}
