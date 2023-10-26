/*
ID: tcarvel1
TASK: beads
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::string _;
    std::ifstream fin("beads.in");

    int numOfBeads;
    fin >> numOfBeads;
    std::getline(fin, _);

    std::string beads;
    std::getline(fin, beads);

    fin.close();

    int size = beads.length();
    int max = 0;
    int numLeft;
    int numRight;
    char bead;

    for (int i = 0; i < size; i++) {
        numLeft = 0;
        numRight = 0;

        bead = 'w';
        while ((bead == 'w' || beads[(i+numRight+1) % size] == bead || beads[(i+numRight+1) % size] == 'w') && numRight < size) {
            if (bead == 'w' && beads[(i+numRight+1) % size] != 'w') {
                bead = beads[(i+numRight+1) % size];
            }
            numRight++;
        }

        if (numRight == size) {
            max = size;
            break;
        }

        bead = 'w';
        while ((bead == 'w' || beads[(i-numLeft) % size] == bead || beads[(i-numLeft) % size] == 'w') && numLeft + numRight < size) {
            if (bead == 'w' && beads[(i-numLeft) % size] != 'w') {
                bead = beads[(i-numLeft) % size];
            }
            numLeft++;
        }

        if (numLeft + numRight > max) {max = numLeft + numRight;}
    }

    std::ofstream fout("beads.out");

    fout << max << std::endl;

    fout.close();

    return 0;
}



