/*
ID: tcarvel1
TASK: barn1
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct board {
    int start;
    int length;
};

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int main() {
    std::string _;
    std::ifstream fin("barn1.in");

    int numBoards, numStalls, numCows;
    fin >> numBoards;
    fin >> numStalls;
    fin >> numCows;

    int cows[200];
    int temp;
    for (int i = 0; i < numCows; i++) {
        fin >> temp;
        cows[i] = temp;
    }
    fin.close();

    qsort(cows, numCows, sizeof(int), cmpfunc);

    std::vector<board> boards;

    for (int i = 0; i < numCows; i++) {
        boards.push_back({cows[i],1});
    }

    while (boards.size() > numBoards && numBoards > 0) {
        int minDist = 100000;
        int minBoard = -1;
        for (int i = 0; i < boards.size()-1; i++) {
            if (boards[i+1].start-boards[i].start-boards[i].length < minDist) {
                minDist = boards[i+1].start-boards[i].start-boards[i].length;
                minBoard = i;
            }
        }

        boards[minBoard].length = boards[minBoard+1].start+boards[minBoard+1].length-boards[minBoard].start;
        boards.erase(boards.begin()+minBoard+1);
    }

    int dist = 0;
    for (int i = 0; i < boards.size(); i++) {
        dist += boards[i].length;
    }

    std::ofstream fout("barn1.out");
    fout << dist << std::endl;
    fout.close();

    return 0;
}

