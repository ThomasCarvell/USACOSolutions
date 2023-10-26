/*
ID: tcarvel1
TASK: friday
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int monthDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

bool isLeap(int year) {
    if (year % 4 == 0 && year % 100 != 0) {
        return true;
    } else if (year % 400 == 0) {
        return true;
    }
    return false;
}

unsigned int dayOfWeek(int year, int month, int date) {
    unsigned int days = 0;

    for (int y = 1900; y < year; y++) {
        if (isLeap(y)) {
            days += 366 % 7;
        } else {
            days += 365 % 7;
        }
    }

    for (int m = 0; m < month; m++) {
        if (m == 1 && isLeap(year)) {
            days += 29;
        } else {
            days += monthDays[m] % 7;
        }
    }

    days += date;

    return days % 7;
}

int main() {
    std::ifstream fin("friday.in");

    int N; fin >> N;

    fin.close();

    int frequencies[7] = {0,0,0,0,0,0,0};

    for (int y = 1900; y < 1900+N; y++) {
        for (int m = 0; m < 12; m++) {
            frequencies[dayOfWeek(y,m,12)] += 1;
        }
    }

    std::ofstream fout("friday.out");

    fout << frequencies[5] << " " << frequencies[6] << " " << frequencies[0] << " " << frequencies[1] << " " << frequencies[2] << " " << frequencies[3] << " " << frequencies[4] << std::endl;
    std::cout << frequencies[5] << " " << frequencies[6] << " " << frequencies[0] << " " << frequencies[1] << " " << frequencies[2] << " " << frequencies[3] << " " << frequencies[4] << std::endl;


    return 0;
}



