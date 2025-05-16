//Number of 1 Bits
//https://leetcode.com/problems/number-of-1-bits/
class Solution {
public:
    int hammingWeight(int n) {
    int count = 0;
    while (n > 0) {
        if ((n & 1) == 1) {
            count++;
        }
        n = n >> 1;  
    }
    return count;
    }
};




//Counting Bits
//https://leetcode.com/problems/counting-bits/
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        int offset = 1;

        for (int i = 1; i <= n; i++) {
            if (offset * 2 == i) offset = i;
            dp[i] = 1 + dp[i - offset];
        }

        return dp;
    }
};





//Reverse Bits
//https://leetcode.com/problems/reverse-bits/
#include <cstdint>
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(int i = 0; i < 32; i++){
            uint32_t bit = (n >> i) & 1;
            res = res | (bit << (31 - i));
        }
        return res;
    }
};
