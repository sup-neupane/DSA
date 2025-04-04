#include<cstdlib>
#include<vector>
//Remove Duplicates from Sorted Array
//https://leetcode.com/problems/remove-duplicates-from-sorted-array/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
         if (nums.empty()) return 0;
        int i =1;
        for(int j=1; j < nums.size();j++){
            if(nums[i-1] != nums[j]){
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};

//Remove Element
//https://leetcode.com/problems/remove-element/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i =0; i<nums.size();i++){
            if(nums[i] !=val){
                nums[k] = nums[i];
                k++;
            }
        }
                   return k;
    }
};



//Shuffle the Array
//https://leetcode.com/problems/shuffle-the-array/
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        for (int i = 0; i < n; i++) {
            res.push_back(nums[i]);
            res.push_back(nums[i + n]);
        }
        return res;
    }
};
//Note: There is a more efficient way to solve this problem using bit manipulation.