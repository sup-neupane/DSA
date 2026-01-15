#include <vector>
#include <string>

using namespace std;
//Combinations
//https://leetcode.com/problems/combinations/
class Solution {
public:

    vector<vector<int>> combine(int n, int k) {
       vector<vector<int>> combs;
       vector<int> curComb;
       helper( 1,combs, curComb, n, k  );
       return combs; 
    }
    
    void helper(int i ,vector<vector<int>>& combs, vector<int>& curComb, int n, int k ){
        if(curComb.size() == k){
            combs.push_back(vector<int>(curComb));
            return;
        }

        if(i > n){
            return;
        }

        curComb.push_back(i);
        helper(i + 1,combs,curComb,n,k);
        curComb.pop_back();

        helper(i + 1,combs,curComb,n,k);
    }
};


//Combination Sum
//https://leetcode.com/problems/combination-sum/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(res, nums, target, cur, 0);
        return res;
    }

    void backtrack(vector<vector<int>>& res,vector<int>& nums, int target, vector<int>& cur, int i) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (target < 0 || i >= nums.size()) {
            return;
        }

        cur.push_back(nums[i]);
        backtrack(res, nums, target - nums[i], cur, i);
        cur.pop_back();
        backtrack(res, nums, target, cur, i + 1);
    }
};


//Letter Combinations of a Phone Number
//https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};
        if (digits.empty()) return res;
        backtrack(0, "", digits,res,digitToChar);
        return res;
    }

    void backtrack(int i, string curStr, string& digits, vector<string>& res, vector<string>&digitToChar){
        if (curStr.size() == digits.size()) {
            res.push_back(curStr);
            return;
        }
        string chars = digitToChar[digits[i] - '0'];
        for (char c : chars) {
            backtrack(i + 1, curStr + c, digits,res,digitToChar);
        }
    }
};
