#include <string>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//Longest Palindromic Substring
//https://leetcode.com/problems/longest-palindromic-substring/
class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 0;
        for(int i = 0; i < s.size(); i++){
            //Odd Length
            int l = i, r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if(r - l + 1 > maxLen){
                    start = l;
                    maxLen = r - l + 1;
                }
                l--;
                r++;
            }
            //Even Length
            l = i, r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                if(r - l + 1 > maxLen){
                    start = l;
                    maxLen = r - l + 1;
                }
                l--;
                r++;
            }
        }

        return s.substr(start , maxLen);
    }
};

//Palindromic Substrings
//https://leetcode.com/problems/palindromic-substrings/
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i = 0; i < s.size(); i++){
            //Odd Length
            int l = i, r = i;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                count++;
                l--;
                r++;
            }
            //Even Length
            l = i, r = i + 1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                count++;
                l--;
                r++;
            }
        }

        return count;
    }
};


// Longest Palindromic Subsequence
//https://leetcode.com/problems/longest-palindromic-subsequence/
//Using LCS concept
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string reversedS = s;
        reverse(reversedS.begin(), reversedS.end());

        int N = s.size(), M = reversedS.size();
        vector<int> dp(M + 1, 0);

        for (int i = 0; i < N; i++) {
            vector<int> curRow(M + 1, 0);
            for (int j = 0; j < M; j++) {
                if (s[i] == reversedS[j]) {
                    curRow[j + 1] = 1 + dp[j];
                } else {
                    curRow[j + 1] = max(dp[j + 1], curRow[j]);
                }
            }
            dp = curRow;
        }

        return dp[M];
    }
};