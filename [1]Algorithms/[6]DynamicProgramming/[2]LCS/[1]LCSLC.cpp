#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

//Longest Common Subsequence
//https://leetcode.com/problems/longest-common-subsequence/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int N = text1.size(), M = text2.size();
        vector<int> dp(M + 1, 0);

        for(int i = 0; i < N; i++){
            vector<int> curRow(M + 1, 0);
            for(int j = 0; j < M; j++){
                if(text1[i] == text2[j]){
                    curRow[j + 1] = 1 + dp[j];
                }else{
                    curRow[j + 1] = max(dp[j + 1], curRow[j]);
                }
            } 
            dp = curRow;
        }
        return dp[M];
    }
};


//Distinct Subsequences
//https://leetcode.com/problems/distinct-subsequences/
//Why double? → The number of subsequences can exceed int limits (overflow), so double (or better long long) safely holds large counts.

//Why base case dp[0] = 1? → There is exactly one way to form an empty string: by choosing nothing.
class Solution {
public:
    int numDistinct(string s, string t) {
        int N = s.size(), M = t.size();
        vector<double> dp(M + 1, 0);
        dp[0] = 1;

        for(int i = 0; i < N; i++){
            vector<double> curRow(M + 1, 0);
            curRow[0] = 1;

            for(int j = 0; j < M; j++){
                if(s[i] == t[j]){
                    curRow[j + 1] = dp[j + 1] + dp[j];
                }else{
                    curRow[j + 1] = dp[j + 1];
                }
            }
            dp = curRow;
        } 
        return dp[M];
    }
};

//Edit Distance
//https://leetcode.com/problems/edit-distance/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int N = word1.size(), M = word2.size();
        vector<int> dp(M + 1, 0);

        for(int j = 0; j <= M; j++) dp[j] = j;

        for(int i = 1; i <= N; i++){
            vector<int> curRow(M + 1, 0);
            curRow[0] = i;

            for(int j = 1; j <= M; j++){
                if(word1[i - 1] == word2[j - 1]){
                    curRow[j] = dp[j - 1];
                }
                else{
                    curRow[j] = 1 + min({
                        dp[j],        // delete
                        curRow[j - 1],// insert
                        dp[j - 1]     // replace
                    });
                }
            }
            dp = curRow;
        }
        return dp[M];
    }
};

//Interleaving String
//https://leetcode.com/problems/interleaving-string/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (m + n != s3.size()) return false;

        vector<bool> dp(n + 1);
        dp[n] = true;
        for (int i = m; i >= 0; --i) {
            vector<bool> nextDp(n + 1);
            if (i == m) nextDp[n] = true;
            for (int j = n; j >= 0; --j) {
                if (i < m && s1[i] == s3[i + j] && dp[j]) {
                    nextDp[j] = true;
                }
                if (j < n && s2[j] == s3[i + j] && nextDp[j + 1]) {
                    nextDp[j] = true;
                }
            }
            dp = nextDp;
        }
        return dp[0];
    }
};



//Shortest Common Supersequence 
//https://leetcode.com/problems/shortest-common-supersequence/
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (i == 0) {
                    dp[i][j] = j;
                } else if (j == 0) {
                    dp[i][j] = i;
                } else if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        string res;
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                res.push_back(str1[i - 1]);
                i--;
                j--;
            } else if (dp[i - 1][j] < dp[i][j - 1]) {
                res.push_back(str1[i - 1]);
                i--;
            } else {
                res.push_back(str2[j - 1]);
                j--;
            }
        }

        while (i > 0) {
            res.push_back(str1[i - 1]);
            i--;
        }

        while (j > 0) {
            res.push_back(str2[j - 1]);
            j--;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};