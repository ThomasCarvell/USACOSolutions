/*
ID: tcarvel1
TASK: numtri
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

typedef uint8_t uint8;

int nums[1001*500];

int N;

int max(int x, int y) {
    if (x > y) {return x;}
    return y;
}

int numToInd(int layer, int ind) {
    int index = ind;
    for (int i = 1; i < layer; i++) {
        index += i;
    }
    return index;
}

int get(int layer, int ind) {
    return nums[numToInd(layer, ind)];
}

int main() {
    std::string _;
    std::ifstream fin("numtri.in");

    fin >> N;

    int n;

    for (int i = 0; i < (int)( (float) (N+1) * ((float) N / 2.0f) ); i++) {
        fin >> nums[i];
    }

    fin.close();

    for (int layer = N-1; layer >= 1; layer--) {
        for (int i = 0; i < layer; i++) {
            nums[numToInd(layer,i)] += max(nums[numToInd(layer+1,i)],nums[numToInd(layer+1,i+1)]);
        }
    }

    std::ofstream fout("numtri.out");

    fout << nums[0] << std::endl;

    fout.close();

    return 0;
}

