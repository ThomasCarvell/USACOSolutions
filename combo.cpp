/*
ID: tcarvel1
TASK: combo
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int mod(int x, int y) {
    if (x >= 0) {
        return x % y;
    } else {
        while (x<0) {x+=y;}
        return x;
    }
}

int main() {
    std::string _;
    std::ifstream fin("combo.in");

    int n;
    fin >> n;

    int mCombo[3] = {0};
    int jCombo[3] = {0};

    fin >> jCombo[0];
    fin >> jCombo[1];
    fin >> jCombo[2];

    fin >> mCombo[0];
    fin >> mCombo[1];
    fin >> mCombo[2];
    
    fin.close();

    int numJohns[3] = {0};
    int numMaster[3] = {0};
    int numBoth[3] = {0};

    bool john;
    bool master;

    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < n; i++) {
            john =   (mod(i+2,n) + 1 == jCombo[j] || mod(i+1,n) + 1 == jCombo[j] || mod(i,n) + 1 == jCombo[j] || mod(i-1,n) + 1 == jCombo[j] || mod(i-2,n) + 1 == jCombo[j]);
            master = (mod(i+2,n) + 1 == mCombo[j] || mod(i+1,n) + 1 == mCombo[j] || mod(i,n) + 1 == mCombo[j] || mod(i-1,n) + 1 == mCombo[j] || mod(i-2,n) + 1 == mCombo[j]);

            if (john && master) {
                numBoth[j]++;
            } else if (john) {
                numJohns[j]++;
            } else if (master) {
                numMaster[j]++;
            }
        }
    }

    std::ofstream fout("combo.out");
    fout <<   numJohns[0] * numJohns[1] * numJohns[2]
            + numMaster[0] * numMaster[1] * numMaster[2] 
            + numBoth[0] * numBoth[1] * numBoth[2]

            + numJohns[0] * numBoth[1]  * numBoth[2]
            + numBoth[0]  * numJohns[1] * numBoth[2]
            + numJohns[0] * numJohns[1] * numBoth[2]
            + numBoth[0]  * numBoth[1]  * numJohns[2]
            + numJohns[0] * numBoth[1]  * numJohns[2]
            + numBoth[0]  * numJohns[1] * numJohns[2]

            + numMaster[0] * numBoth[1]   * numBoth[2]
            + numBoth[0]   * numMaster[1] * numBoth[2]
            + numMaster[0] * numMaster[1] * numBoth[2]
            + numBoth[0]   * numBoth[1]   * numMaster[2]
            + numMaster[0] * numBoth[1]   * numMaster[2]
            + numBoth[0]   * numMaster[1] * numMaster[2] << std::endl;

    
    fout.close();

    return 0;
}

