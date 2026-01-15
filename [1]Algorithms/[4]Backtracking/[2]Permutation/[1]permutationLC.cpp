#include <vector>
#include <unordered_map>
using namespace std;

//Permutations
//https://leetcode.com/problems/permutations/
class Solution {
public:
    vector<vector<int>> helper(int i, vector<int>& nums) {
        if (i == nums.size()) {
            return {{}};
        }
        vector<vector<int>> resPerms;
        vector<vector<int>> perms = helper(i + 1, nums);
        for (vector<int> p : perms) {
            for (int j = 0; j < p.size() + 1; j++) {
                vector<int> pCopy(p);
                pCopy.insert(pCopy.begin() + j, nums[i]);
                resPerms.push_back(pCopy);
            }
        }
        return resPerms;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        return helper(0,nums);
    }

};




//Permutations II
//https://leetcode.com/problems/permutations-ii/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        unordered_map<int , int> count;
        for(int n : nums){
            count[n]++;
        }
        vector<int> perm;
        dfs(res, nums, perm, count);
        return res;
    }
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& perm ,unordered_map<int , int>& count){
        if(perm.size() == nums.size()){
            res.push_back(perm);
            return;
        }
        for (auto& [num, cnt] : count){
            if(cnt > 0){
                perm.push_back(num);
                cnt--;
                dfs(res, nums, perm, count);
                cnt++;
                perm.pop_back();
            }
        }
    }
};

