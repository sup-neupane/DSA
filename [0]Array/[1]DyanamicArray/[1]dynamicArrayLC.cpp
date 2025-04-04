//Concatenation of Array
//https://leetcode.com/problems/concatenation-of-array/
#include <vector>
using namespace std;

vector<int> getConcatenation(const vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(2 * n);
    
    for (int i = 0; i < n; i++) {
        ans[i] = nums[i];      
        ans[i + n] = nums[i];  
    }
    
    return ans;
}
