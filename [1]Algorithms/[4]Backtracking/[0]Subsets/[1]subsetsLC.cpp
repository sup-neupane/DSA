#include <vector>
#include <algorithm>

using std::vector;
using std::sort;
//Subsets
//https://leetcode.com/problems/subsets/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> currSet;
        vector<vector<int>> subsets;
        helper(0, nums, currSet, subsets);
        return subsets;
    }
    
    void helper(int i, vector<int>& nums,vector<int>&currSet, vector<vector<int>>& subsets){
        if(i >= nums.size()){
            subsets.push_back(vector<int>(currSet));
            return;
        }

        currSet.push_back(nums[i]);
        helper(i + 1, nums, currSet, subsets);
        currSet.pop_back();

        helper(i + 1, nums, currSet, subsets);

    }
};


//Subsets II
//https://leetcode.com/problems/subsets-ii/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> currSet;
        vector<vector<int>> subsets;
        helper(0, nums, currSet, subsets);
        return subsets;
    }

    void helper(int i, vector<int>& nums, vector<int>& currSet,vector<vector<int>>& subsets) {
        if (i >= nums.size()) {
            subsets.push_back(vector<int>(currSet));
            return;
        }

        // Include nums[i]
        currSet.push_back(nums[i]);
        helper(i + 1, nums, currSet, subsets);
        currSet.pop_back();

        // Exclude nums[i]
        while(i + 1 < nums.size() && nums[i] == nums[i + 1]){
            i++;
        }
        helper(i + 1, nums, currSet, subsets);
    }
};