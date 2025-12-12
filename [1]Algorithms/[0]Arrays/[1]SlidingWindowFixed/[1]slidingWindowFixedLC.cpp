#include <vector>
#include <unordered_set>
#include <algorithm>

using std::vector;
using std::unordered_set;
using std::min;


//Contains Duplicate II
//https://leetcode.com/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> window; 
    int L = 0;

    for (int R = 0; R < nums.size(); R++) {
        if (R - L > k) {
            window.erase(nums[L]);
            L++;
        }
        if (window.count(nums[R]) > 0) {
            return true;
        }
        window.insert(nums[R]);
    }
    return false;
}
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();

        for(int L = 0; L < size; L++){
            for(int R = L + 1; R <= min(size - 1, L + k); R++){
                if(nums[L] == nums[R]){
                    return true;
                }
            }
        }
        return false;
    }
};





//Number of Sub-arrays of Size K and Average Greater than or Equal to Threshold
//https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold/
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int res = 0;
        int currSum = 0;

        for(int i = 0 ; i < k - 1; i++){
            currSum += arr[i];
        }

        for(int L = 0 ; L <=  arr.size() - k; L++){
            currSum +=  arr[L + k - 1];
            if(currSum / k >= threshold){
                res++;
            }
            currSum -= arr[L];
        }
        return res++;
    }
};


