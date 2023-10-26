/*
ID: tcarvel1
TASK: milk
LANG: C++                 
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int sum(std::vector<int> arr) {
    int total = 0;
    for (int i = 0; i < arr.size(); i++) {
        total += arr[i];
    }
    return total;
}

int main() {
    std::string _;
    std::ifstream fin("milk.in");

    int milkNeeded, farmers;
    fin >> milkNeeded;
    fin >> farmers;

    std::vector<int> prices;
    std::vector<int> amount;

    int temp;
    for (int i = 0; i < farmers; i++) {
        fin >> temp;
        prices.push_back(temp);
        fin >> temp;
        amount.push_back(temp);
    }

    fin.close();

    std::vector<int> amountBought;
    std::vector<int> rate;
    if (farmers > 0) {
        rate.push_back(prices[0]);
        amountBought.push_back(amount[0]);
    }
    int needed;
    int extra;

    for (int farmer = 1; farmer < farmers; farmer++) {
        int i = 0;
        while (rate[i] < prices[farmer] && i < rate.size()) {i++;}
        
        needed = milkNeeded-sum(amountBought);

        if (needed > amount[farmer]) {
            rate.insert(rate.begin()+i, prices[farmer]);
            amountBought.insert(amountBought.begin()+i, amount[farmer]);
            continue;
        } 

        extra = amount[farmer]-needed;
        int sze = amountBought.size();
        for (int j = sze-1; j >= i; j--) {
            temp = std::min(extra,amountBought[j]);
            amountBought[j] -= temp;
            extra -= temp;
        }

        amountBought.insert(amountBought.begin()+i, amount[farmer]-extra);
        rate.insert(rate.begin()+i, prices[farmer]);
    }

    std::ofstream fout("milk.out");

    int cost = 0;

    for (int i = 0; i < amountBought.size(); i++) {
        cost += amountBought[i] * rate[i];
    }

    fout << cost << std::endl;

    fout.close();

    return 0;
}

