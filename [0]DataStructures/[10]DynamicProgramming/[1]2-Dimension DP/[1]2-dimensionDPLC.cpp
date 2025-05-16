//Unique Paths
//https://leetcode.com/problems/unique-paths/
#include <vector>
using std::vector;

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prevRow(n, 0);
        for(int r = m - 1 ; r >= 0; r--){
            vector<int> currRow(n,0);
            currRow[n - 1] = 1;
            for(int c = n -2 ; c >=0 ; c--){
                currRow[c] = prevRow[c] + currRow[c + 1];
            }
            prevRow = currRow;
        }
        return prevRow[0];
    }
};






//Unique Paths II
//https://leetcode.com/problems/unique-paths-ii/
class Solution { 
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int M = grid.size(), N = grid[0].size();
        vector<long long> dp(N, 0);  // Use long long

        dp[N - 1] = 1;

        for (int r = M - 1; r >= 0; r--) {
            for (int c = N - 1; c >= 0; c--) {
                if (grid[r][c] == 1) {
                    dp[c] = 0;
                } else if (c + 1 < N) {
                    dp[c] = dp[c + 1] + dp[c];
                }
            }
        }

        return dp[0];
    }
};





//Longest Common Subsequence
//https://leetcode.com/problems/longest-common-subsequence/
