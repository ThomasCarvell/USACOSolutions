/*
ID: tcarvel1
TASK: ariprog
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

int length;
int ub;


unsigned char bisquares[15625];

void setIndex(int i, bool val) {
    if (val) {
        bisquares[i/8] |= (int)std::pow(2, i%8);
    } else {
        bisquares[i/8] &= (int)std::pow(2, i%8);
    }
}

bool getIndex(int i) {
    return 1 == ((bisquares[i/8] >> (i%8)) & 1);
}

void generatebisquares() {
    int limit = 2*ub*ub;
    for (int p = 0; p <= ub; p++) {
        for (int q = 0; q <= ub; q++) {
            setIndex(p*p+q*q, true);
        }
    }
}

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    std::string _;
    std::ifstream fin("ariprog.in");
    fin >> length;
    fin >> ub;
    fin.close();

    generatebisquares();

    int ind;
    int next;
    bool failed;
    int maxD;


    bool any = false;

    std::ofstream fout("ariprog.out");

    for (int d = 1; d <= (2*ub*ub) / (length-1); d++) {
        for (int a = 0; a < 2*ub*ub; a++) {
            if (!getIndex(a)) {continue;}

            if (a + (length-1)*d > 2*ub*ub) {break;}

            ind = a;
            failed = false;
            for (int i = 1; i < length; i++) {
                ind += d;
                if (!getIndex(ind)) {failed = true; break;}
            }

            if (!failed) {fout << a << " " << d << std::endl; any = true;}
        }
    }

    if (!any) {fout << "NONE" << std::endl;}

    fout.close();

    return 0;
}

