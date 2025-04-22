// Sort Colors
// https://leetcode.com/problems/sort-colors/
#include <vector>

using std::vector;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Assuming nums only contains 0, 1 or 2
        int counts[] = {0, 0, 0};

        // Count the quantity of each value in nums
        for (int n : nums) {
            counts[n]++;
        }

        int i = 0;
        for (int n = 0; n < 3; n++) {
            for (int j = 0; j < counts[n]; j++) {
                nums[i] = n;
                i++;
            }
        }
    }
};
