//Path Sum
//https://leetcode.com/problems/path-sum/
class TreeNode {
    public:
        int val;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;

        TreeNode(int val) {
            val = val;
        }
};
class Solution {
    public:
        bool hasPathSum(TreeNode* root, int targetSum) {
            return backtrack(root, 0, targetSum);
        }
    
    private:
        bool backtrack(TreeNode* node, int currSum, int targetSum) {
            if (!node) {
                return false;
            }
    
            currSum += node->val;
    
            // If it's a leaf node, check if the sum matches
            if (!node->left && !node->right) {
                return currSum == targetSum;
            }
    
            // Recurse down the left and right children
            return backtrack(node->left, currSum, targetSum) || 
                   backtrack(node->right, currSum, targetSum);
        }
    };









//Subsets
//https://leetcode.com/problems/subsets/
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(0, nums, subset, res);
        return res;
    }

    void dfs(int i, vector<int>& nums, vector<int>& subset, vector<vector<int>>& res) {
        if (i >= nums.size()) {
            res.push_back(subset); // Add a copy of the current subset
            return;
        }

        // Decision to include nums[i]
        subset.push_back(nums[i]);
        dfs(i + 1, nums, subset, res);

        // Decision NOT to include nums[i]
        subset.pop_back();
        dfs(i + 1, nums, subset, res);
    }
};










//Combination Sum
//https://leetcode.com/problems/combination-sum/
class Solution {
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> res;
            vector<int> current;
            dfs(0, current, target, candidates, res);
            return res;
        }
    
    private:
        void dfs(int i, vector<int>& current, int target, vector<int>& candidates, vector<vector<int>>& res) {
            // Base case: if target is reached, add current combination to result
            if (target == 0) {
                res.push_back(current);
                return;
            }
    
            // If index is out of bounds or target is negative, stop
            if (i >= candidates.size() || target < 0) {
                return;
            }
    
            // Decision: include candidates[i]
            current.push_back(candidates[i]);
            dfs(i, current, target - candidates[i], candidates, res); // stay at i to reuse the number
    
            // Backtrack and try the next number
            current.pop_back();
            dfs(i + 1, current, target, candidates, res); // move to next index
        }
    };
    