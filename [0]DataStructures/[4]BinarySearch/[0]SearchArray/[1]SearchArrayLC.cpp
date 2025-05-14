// Binary Search
// https://leetcode.com/problems/binary-search/
#include<vector>
using std::vector;

class Solution {
public:
    int search(vector<int>& nums, int target) {
            int L = 0, R = nums.size() - 1;

    while (L <= R) {
        int mid = (L + R) / 2;

        if (target > nums[mid]) {
            L = mid + 1;
        } else if (target < nums[mid]) {
            R = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
    }
};









// Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), cols = matrix[0].size();
        int top = 0, bottom = row - 1;
        
        while (top <= bottom) {
            int mid_row = (top + bottom) / 2;
            
            // Check if the target is greater than the last element of mid_row
            if (matrix[mid_row][cols - 1] < target) {
                top = mid_row + 1;
            }
            // Check if the target is smaller than the first element of mid_row
            else if (matrix[mid_row][0] > target) {
                bottom = mid_row - 1;
            }
            // Target is within the range of the current row
            else {
                int target_row = mid_row;
                int left = 0, right = cols - 1;
                
                while (left <= right) {
                    int mid = (left + right) / 2;
                    
                    if (target > matrix[target_row][mid]) {
                        left = mid + 1;
                    } else if (target < matrix[target_row][mid]) {
                        right = mid - 1;
                    } else {
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }
};

