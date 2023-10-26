/*
ID: tcarvel1
TASK: ride
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    std::ifstream fin ("ride.in");
    std::string line1;
    std::string line2;
    std::getline(fin, line1);
    std::getline(fin, line2);

    unsigned int cometNumber = 1;
    for (int i = 0; i < line1.length(); i++) {
        cometNumber *= (uint8_t) line1[i] - (uint8_t) 'A' + 1;
    }
    cometNumber %= 47;

    unsigned int groupNumber = 1;
    for (int i = 0; i < line2.length(); i++) {
        groupNumber *= (uint8_t) line2[i] - (uint8_t) 'A' + 1;
    }
    groupNumber %= 47;

    std::ofstream fout("ride.out");

    if (groupNumber == cometNumber) {
        fout << "GO" << std::endl;
    } else {
        fout << "STAY" << std::endl;
    }

    fout.close();


    return 0;
}