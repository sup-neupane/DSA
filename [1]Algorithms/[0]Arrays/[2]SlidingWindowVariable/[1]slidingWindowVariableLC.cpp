#include <vector>
#include <unordered_set>
#include <algorithm>
#include <climits>
#include <string>
#include <unordered_map>

using namespace std;
//Minimum Size Subarray Sum
//https://leetcode.com/problems/minimum-size-subarray-sum/
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int L = 0 , total = 0;
        int length = INT_MAX;

        for(int R = 0; R < nums.size(); R++){
            total += nums[R];
            while(total >= target){
                length = min(length,R - L + 1);
                total -= nums[L];
                L++;
                }
        }
        return (length == INT_MAX)?0:length;
    }
};



//Longest Substring Without Repeating Characters
//https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set;
        int L = 0, length = 0;

        for(int R = 0 ; R < s.size(); R++){
            while(set.count(s[R])){
                set.erase(s[L]);
                L ++;
            }
            set.insert(s[R]);
            length = max(length , R - L + 1);
        }
        return length;
    }
};


//Longest Repeating Character Replacement
//https://leetcode.com/problems/longest-repeating-character-replacement/
class Solution {
public:
    int characterReplacement(string s, int k) {
        int L = 0, longest = 0;
        vector<int> counts(26 , 0);
        int maxFreq = 0; 

        for (int R = 0; R < s.size(); R++) {
            counts[s[R] - 'A']++;
            maxFreq = max(maxFreq, counts[s[R] - 'A']);
            while (((R - L + 1) - maxFreq) > k) {
                counts[s[L] - 'A']--;
                L++;
            }

            longest = max(longest, R - L + 1);
        }
        return longest;
    }
};
