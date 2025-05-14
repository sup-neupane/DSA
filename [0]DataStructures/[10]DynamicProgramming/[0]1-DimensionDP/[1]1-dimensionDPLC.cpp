//Climbing Stairs
//https://leetcode.com/problems/climbing-stairs/


//Memoization solution
#include <unordered_map>
using namespace std;

class Solution {
public:
    int helper(int n, unordered_map<int, int>& memo) {
        if (n <= 1) {
            return 1;
        }

        if (memo.count(n)) {
            return memo[n];
        }

        memo[n] = helper(n - 1, memo) + helper(n - 2, memo);
        return memo[n];
    }

    int climbStairs(int n) {
        unordered_map<int, int> memo;
        return helper(n, memo);
    }
};




//Dynamic Programming
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 1){
            return 1; // 1 way to climb 0 or 1 steps
        }

        int dp[] = {1, 1}; // dp[0] = ways to climb to (i-2), dp[1] = (i-1)

        for(int i = 2; i <= n; ++i){
            int tmp = dp[1];
            dp[1] = dp[0] + dp[1];
            dp[0] = tmp;
        }

        return dp[1];
    }
};











//House Robber
//https://leetcode.com/problems/house-robber/
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;

        //[rob1, rob2, n , n + 1, ...]
        for(int n : nums){
            int temp = max(n + rob1, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
};