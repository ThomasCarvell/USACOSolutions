/*
ID: tcarvel1
TASK: gift1
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::ifstream fin("gift1.in");

    int NP;
    fin >> NP;
    std::string _;
    std::getline(fin, _);

    std::vector<std::string> names;
    std::vector<int> money;
    std::string line;
    for (int i = 0; i < NP; i++) {
        std::getline(fin, line);
        names.push_back(line);
        money.push_back(0);
    }

    int giftMoney, friends;
    std::string person;
    std::string giftRecv;

    for (int i = 0; i < NP; i++) {
        std::getline(fin,person);
        fin >> giftMoney >> friends;
        std::getline(fin,_);

        //std::cout << person << " " << giftMoney << " " << friends << std::endl;
        for (int j = 0; j < friends; j++) {
            std::getline(fin, giftRecv);

            int k = 0;
            while (names[k] != giftRecv) {k++;}

            money[k] += giftMoney / friends;
        }

        int k = 0;
        while (names[k] != person) {k++;}
        //std::cout << giftMoney << " " << friends << std::endl;
        if (friends == 0) {
            money[k] -= giftMoney;
        } else {
            money[k]+= (giftMoney % friends) - giftMoney;
        }
    }

    std::ofstream fout("gift1.out");

    for (int i = 0; i < NP; i++) {
        fout << names[i] << " " << money[i] << std::endl;
        //std::cout << names[i] << " " << money[i] << std::endl;
    }

    return 0;
}