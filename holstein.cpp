/*
ID: tcarvel1
TASK: holstein
LANG: C++                 
*/
#include <iostream>
#include <fstream>

#include <string>
#include <cmath>

int V;
int vitReq[25];
int G;
int feeds[15][25];

bool isSolution(bool sol[15]) {
    int vits[25] = {0};
    for (int i = 0; i < G; i++) {
        if (!sol[i]) continue;

        for (int j = 0; j < V; j++) {
            vits[j] += feeds[i][j];
        }
    }

    for (int i = 0; i < V; i++) {
        if (vits[i] < vitReq[i]) return false;
    }
    return true;
}

bool foundSolution = false;
bool solution[15] = {false};

void search(bool start[15], int depth) {
    if (depth < 1) {
        if (isSolution(start)) {
            foundSolution = true;
            for (int i = 0; i < G; i++) {
                solution[i] = start[i];
            }
            return;
        }
    } else {
        int lowest = 14;
        while (start[lowest] == false && lowest > 0) lowest--;
        for (int i = lowest; i < G; i++) {
            if (!start[i]) {
                start[i] = true;
                search(start, depth-1);
                start[i] = false;

                if (foundSolution) {
                    return;
                }
            }
        }
    }
}

int main() {
    std::string _;
    std::ifstream fin("holstein.in");

    fin >> V;

    for (int i = 0; i < V; i++) {
        fin >> vitReq[i];
    }

    fin >> G;

    for (int i = 0; i < G; i++) {
        for (int j = 0; j < V; j++) {
            fin >> feeds[i][j];
        }
    }

    fin.close();

    int depth = 0;
    bool start[15] = {0};
    while (!foundSolution) {
        search(start, depth);
        depth++;
    }

    std::ofstream fout("holstein.out");

    int total = 0;
    for (int i = 0; i < G; i++) {
        if (solution[i]) total++;
    }

    fout << total;

    for (int i = 0; i < G; i++) {
        if (solution[i]) fout << " " << i+1;
    }
    fout << std::endl;

    fout.close();

    return 0;
}

