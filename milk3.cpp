/*
ID: tcarvel1
TASK: milk3
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int limits[3];

struct state {
    int containers[3];
};

int min(int x, int y) {
    if (x < y) {return x;}
    return y;
}

state modify(state origin, int from, int to) {
    state result = {0,0,0};
    int delta = min(origin.containers[from], limits[to]-origin.containers[to]);

    for (int i = 0; i < 3; i++) {
        if (i == from) {result.containers[i] = origin.containers[i]-delta;}
        else if (i == to) {result.containers[i] = origin.containers[i]+delta;}
        else {result.containers[i] = origin.containers[i];}
    }

    return result;
}

bool milkNumbers[25] = {false};

state searched[100];
int numSearched = 0;

void solve(state start) {
    for (int i = 0; i < numSearched; i++) {
        if (searched[i].containers[0] == start.containers[0] && searched[i].containers[1] == start.containers[1] && searched[i].containers[2] == start.containers[2]) {
            return;
        }
    }

    searched[numSearched] = start;
    numSearched++;

    if (start.containers[0] == 0) {
        milkNumbers[start.containers[2]] = true;
    }

    solve(modify(start, 0, 1));
    solve(modify(start, 1, 0));
    solve(modify(start, 0, 2));
    solve(modify(start, 2, 0));
    solve(modify(start, 1, 2));
    solve(modify(start, 2, 1));
}

int main() {
    std::string _;
    std::ifstream fin("milk3.in"); 
    fin >> limits[0];
    fin >> limits[1];
    fin >> limits[2];
    fin.close();

    solve({0,0,limits[2]});

    std::ofstream fout("milk3.out");
    int started = false;
    for (int i = 0; i < 21; i++) {
        if (milkNumbers[i]) {if (started) {fout << " ";} fout << i; started = true;}
    }
    fout << std::endl;
    fout.close();

    return 0;
}

