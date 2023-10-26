/*
ID: tcarvel1
TASK: milk2
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::string _;
    std::ifstream fin("milk2.in");

    int farmers;
    fin >> farmers;
    
    std::vector<int> startTimes;
    std::vector<int> endTimes;

    int startTime;
    int endTime;
    int start = 1000000;
    int end = 0;
    for (int i = 0; i < farmers; i++) {
        fin >> startTime;
        fin >> endTime;
        startTimes.push_back(startTime);
        endTimes.push_back(endTime);

        if (startTime < start) {start = startTime;}
        if (endTime > end) {end = endTime;}
    }

    bool startedMilking = false;
    int longestMilking = 0;
    int longestNonMilking = 0;
    int milkingTime = 0;
    int nonMilkingTime = 0;
    for (int s = start-2; s < end+2; s++) {
        bool milking = false;
        for (int i = 0; i < farmers; i++) {
            if (s > startTimes[i] && s <= endTimes[i]) {
                milking = true;
                break;
            }
        }

        if (milking == 0 && startedMilking) {
            nonMilkingTime++;
            if (milkingTime > longestMilking) {
                longestMilking = milkingTime;
            }
            milkingTime = 0;
        }
        if (milking != 0) {
            startedMilking = true;
            milkingTime ++;
            if (nonMilkingTime > longestNonMilking) {
                longestNonMilking = nonMilkingTime;
            }
            nonMilkingTime = 0;
        }
    }

    if (farmers == 1) {
        longestNonMilking = 0;
    }

    std::ofstream fout("milk2.out");

    fout << longestMilking << " " << longestNonMilking << std::endl;

    return 0;
}



