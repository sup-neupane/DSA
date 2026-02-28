#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//Partition Equal Subset Sum
//https://leetcode.com/problems/partition-equal-subset-sum/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = 0;
        for (int num : nums) total += num;

        if (total % 2 != 0) return false;

        int target = total / 2;
        vector<bool> dp(target + 1, false);
        vector<bool> nextDp(target + 1, false);

        dp[0] = true;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j <= target; j++) {
                if (j >= nums[i]) {
                    nextDp[j] = dp[j] || dp[j - nums[i]];
                } else {
                    nextDp[j] = dp[j];
                }
            }
            swap(dp, nextDp);
        }
        return dp[target];
    }
};

//Target Sum
//https://leetcode.com/problems/target-sum/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> dp;
        dp[0] = 1;

        for (int num : nums) {
            unordered_map<int, int> nextDp;
            for (auto& entry : dp) {
                int total = entry.first;
                int count = entry.second;
                nextDp[total + num] += count;
                nextDp[total - num] += count;
            }
            dp = nextDp;
        }
        return dp[target];
    }
};

//https://leetcode.com/problems/ones-and-zeroes/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (string s : strs) {
            int zeros = count(s.begin(), s.end(), '0');
            int ones  = count(s.begin(), s.end(), '1');

            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], 1 + dp[i - zeros][j - ones]);
                }
            }
        }

        return dp[m][n];
    }
};

//https://leetcode.com/problems/last-stone-weight-ii/
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int stoneSum = 0;
        for(int stone :  stones) stoneSum += stone;
        int target = stoneSum / 2;
        vector<int> dp(target + 1, 0);

        for (int stone : stones) {
            for (int t = target; t >= stone; t--) {
                dp[t] = max(dp[t], dp[t - stone] + stone);
            }
        }

        return stoneSum - 2 * dp[target];
    }
};