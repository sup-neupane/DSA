//Maximum Subarray
//https://leetcode.com/problems/maximum-subarray/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = 0;

        for(int num: nums){
            currSum = max(currSum, 0);
            currSum += num;
            maxSum = max(maxSum, currSum);
        }
        return maxSum;

    }
};

 
  




//Maximum Sum Circular Subarray
//https://leetcode.com/problems/maximum-sum-circular-subarray/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globalMin = nums[0];
        int globalMax = nums[0];
        int total = 0;
        int curMax = 0, curMin = 0;

        for (int num : nums){
            curMax = max(curMax, 0);
            curMin = min(curMin, 0);
            curMax += num;
            curMin += num;
            total += num;
            globalMax = max(curMax, globalMax);
            globalMin = min(curMin, globalMin);
        }
       return (globalMax > 0) ? max(globalMax, total - globalMin) : globalMax;

    }
};





//Longest Turbulent Subarray
//https://leetcode.com/problems/longest-turbulent-subarray/
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int left = 0, right = 1;
        int res = 1;  
        char prev = 'X';

        while(right < arr.size()) {
            if(arr[right - 1] > arr[right] && prev != '>') {
                res = max(res, right - left + 1);
                right++;
                prev = '>';
            }
            else if(arr[right - 1] < arr[right] && prev != '<') {
                res = max(res, right - left + 1);
                right++;
                prev = '<';
            }
            else {
                right = (arr[right] == arr[right - 1]) ? right + 1 : right;
                left = right - 1;
                prev = 'X';
            }
        }
        return res;
    }
};
