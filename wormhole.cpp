/*
ID: tcarvel1
TASK: wormhole
LANG: C++                 
*/
// WHAT THE FUCK EVEN IS THIS PIECE OF SHIT
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define MAXHOLES 12

int X[12];
int Y[12];
int partner[12];
int right[12];
int N;

int isCyclic() {
    int tmp;
    for (int w = 0; w < N; w++) {
        tmp = w;
        while (tmp != -1) {
            tmp = right[partner[tmp]];
            if (tmp == w) {return 1;}
        }
    }

    return 0;
}

int solve() {
    
    int w1 = 0;
    bool partnered = true;
    for (int n = 0; n < N; n++) {
        if (partner[n] == -1) {partnered = false; w1 = n; break;}
    } 

    if (partnered) {return isCyclic();}

    int total = 0;
    for (int w2 = w1+1; w2 < N; w2++) {
        if (partner[w2] != -1) {continue;}

        partner[w1] = w2;
        partner[w2] = w1;

        total += solve();
        partner[w1] = -1;
        partner[w2] = -1;
    }

    return total;
}

int main() {
    std::string _;
    std::ifstream fin("wormhole.in");

    fin >> N;

    for (int i = 0; i < N; i++) {
        fin >> X[i];
        fin >> Y[i];
        partner[i] = -1;
        right[i] = -1;
    }
    fin.close();

    for (int w = 0; w < N; w++) {
        for (int w2 = 0; w2 < N; w2++) {
            if (Y[w] != Y[w2]) {continue;}

            if (right[w] == -1 && X[w] < X[w2]) {
                right[w] = w2;
            } else if (X[right[w]] > X[w2] && X[w2] > X[w]) {
                right[w] = w2;
            }
        }
    }

    std::ofstream fout("wormhole.out");
    fout << solve() << std::endl;
    fout.close();

    return 0;
}

