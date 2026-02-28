//Good To Watch
//https://www.youtube.com/watch?v=Mjy4hd2xgrs

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;
//https://leetcode.com/problems/coin-change/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for(int a = 1; a <= amount; a++){
            for(int c : coins){
                if(a - c >= 0){
                    dp[a] = min(dp[a] , 1 + dp[a - c]);
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};


//Coin Change II
//https://leetcode.com/problems/coin-change-ii/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = coins.size() - 1; i >= 0; i--) {
            vector<unsigned int> nextDP(amount + 1, 0);
            nextDP[0] = 1;

            for (int a = 1; a <= amount; a++) {
                nextDP[a] = dp[a];
                if (a - coins[i] >= 0) {
                    nextDP[a] += nextDP[a - coins[i]];
                }
            }
            dp = nextDP;
        }
        return dp[amount];
    }
};


//Minimum Cost For Tickets
//https://leetcode.com/problems/minimum-cost-for-tickets/
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, 0);
        int i = 0;

        for (int d = 1; d < 366; d++) {
            dp[d] = dp[d - 1];

            if (i == days.size()) {
                return dp[d];
            }

            if (d == days[i]) {
                dp[d] += costs[0];
                dp[d] = min(dp[d], costs[1] + dp[max(0, d - 7)]);
                dp[d] = min(dp[d], costs[2] + dp[max(0, d - 30)]);
                i++;
            }
        }
        return dp[365];
    }
};