#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX;  // Track the minimum price seen so far
    int maxProfit = 0;       // Track the maximum profit possible

    for (int price : prices) {
        minPrice = min(minPrice, price);              // Update min price
        maxProfit = max(maxProfit, price - minPrice); // Update max profit
    }

    return maxProfit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << maxProfit(prices) << endl;
    return 0;
}
