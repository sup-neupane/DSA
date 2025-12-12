#include <string>
#include <vector>
#include <cctype>   // for isalnum, tolower
using namespace std;

//Valid Palindrome
//https://leetcode.com/problems/valid-palindrome/
class Solution {
public:
    bool isPalindrome(string s) {
        int L = 0, R = s.length() - 1;

        while(L <  R){

            while (L < R && !isalnum(s[L])) L++;
            while (L < R && !isalnum(s[R])) R--;
            
            if(tolower(s[L]) != tolower(s[R])){
                return false;
            }
            L++;
            R--;
        }
        return true;
    }
};

//Two Sum II - Input Array Is Sorted
//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int L = 0, R = numbers.size() - 1;

        while(L < R){
            if((numbers[L] + numbers[R]) < target) L++;
            else if((numbers[L] + numbers[R]) > target) R--;
            else return vector<int>{L + 1,R + 1}; // convert to 1-indexed
        }
        return {}; //// in case no solution is found
    }
};


//Remove Duplicates from Sorted Array II
//https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int L = 0, R = 0;

        while(R < nums.size()){
            int count = 1;

            while((R + 1) < nums.size() && nums[R] == nums[R + 1]){
                R++;
                count++;
            }

            for(int  i = 0; i < min(2,count); i++){
                nums[L] = nums[R];
                L++;
            }
            R++;
        }
        return L;
    }
};


//Container With Most Water
//https://leetcode.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int L = 0, R = height.size() - 1;
        int area = 0 , maxArea = 0;

        while(L < R){
            area = (R - L) * min(height[L], height[R]);
            maxArea = max(maxArea, area);

            if(height[L] < height[R]){
                L++;
            }
            else{
                R--;
            }
        }
        return maxArea;
    }
};



//Trapping Rain Water
//https://leetcode.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
        int L = 0, R = height.size() - 1;
        int leftMax = height[L], rightMax = height[R];
        int res = 0;

        while(L < R){
            if(leftMax < rightMax){
                L++;
                leftMax = max(leftMax, height[L]);
                res += leftMax - height[L];
            } else{
                R--;
                rightMax = max(rightMax, height[R]);
                res += rightMax - height[R];
            }
        }
        return res;
    }
};