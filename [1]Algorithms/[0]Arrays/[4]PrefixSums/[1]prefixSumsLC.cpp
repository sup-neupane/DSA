#include <vector>
using namespace std;
//Range Sum Query - Immutable
//https://leetcode.com/problems/range-sum-query-immutable/
class NumArray {
    vector<int> prefix;
public:
    NumArray(vector<int>& nums) {
        int total = 0;
        for(int n : nums){
            total += n;
            prefix.push_back(total);
        }
    }
    
    int sumRange(int left, int right) {
        int preRight = prefix[right];
        int preLeft = (left > 0)?prefix[left - 1]:0;
        return preRight - preLeft;
    }
};

//Range Sum Query 2D - Immutable
//https://leetcode.com/problems/range-sum-query-2d-immutable/

//Find Pivot Index
//https://leetcode.com/problems/find-pivot-index/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        int leftSum = 0, rightSum = 0;
        for(int num : nums){
            total += num;
        }

        for(int i = 0; i < nums.size(); i++){
            rightSum = total - nums[i] - leftSum;
            if(leftSum == rightSum){
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};

//Product of Array Except Self
//https://leetcode.com/problems/product-of-array-except-self/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);

        int prefix = 1;
        for(int i = 0; i < nums.size(); i++){
            res[i] = prefix;
            prefix *= nums[i];
        }

        int postfix = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            res[i] = res[i] * postfix;
            postfix *= nums[i];
        }
        return res;
    }
};


//Subarray Sum Equals K
//https://leetcode.com/problems/subarray-sum-equals-k/
