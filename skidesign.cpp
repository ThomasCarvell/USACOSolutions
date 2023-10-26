/*
ID: tcarvel1
TASK: skidesign
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int N;
int hills[1000];
int costs[1000];

int cmp (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main() {
    std::string _;
    std::ifstream fin("skidesign.in");

    fin >> N;
    for (int i = 0; i < N; i++) {
        fin >> hills[i];
        costs[i] = 1;
    }

    fin.close();

    int cost = 0;

    qsort(hills, N, sizeof(int), cmp);

    int topVal = hills[N-1];
    int bottomVal = hills[0];

    int range = topVal - bottomVal;

    int costForTop;
    int costForBottom;
    int n;

    while (range > 17) {
        costForTop = 0;
        n = 1;
        while (hills[N-n] > topVal-1) {
            costForTop += costs[N-n];
            n++;
        }

        costForBottom = 0;
        n = 0;
        while (hills[n] < bottomVal+1) {
            costForBottom += costs[n];
            n++;
        }

        if (costForTop > costForBottom) {
            n = 0;
            while (hills[n] < bottomVal+1) {
                hills[n] += 1;
                cost += costs[n];
                costs[n] += 2;
                n++;
            }
            bottomVal += 1;
        } else {
            n = 1;
            while (hills[N-n] > topVal-1) {
                hills[N-n] -= 1;
                cost += costs[N-n];
                costs[N-n] += 2;
                n++;
            }
            topVal -= 1;
        }
        range = topVal - bottomVal;
    }

    
    std::ofstream fout("skidesign.out");
    fout << cost << std::endl;
    fout.close();

    return 0;
}

