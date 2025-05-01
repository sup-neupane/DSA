//Last Stone Weight
//https://leetcode.com/problems/last-stone-weight/
#include <vector>
#include <queue>
using namespace std;
class Solution {
    public:
        int lastStoneWeight(vector<int>& stones) {
            priority_queue<int> maxHeap;
            for (int stone : stones) {
                maxHeap.push(stone);
            }
            while (maxHeap.size() > 1) {
                int first = maxHeap.top();
                maxHeap.pop();
                int second = maxHeap.top();
                maxHeap.pop();
                if (first != second) {
                    maxHeap.push(first - second);
                }
            }
            return maxHeap.empty() ? 0 : maxHeap.top();
        }
    };







//K Closest Points to Origin
//https://leetcode.com/problems/k-closest-points-to-origin/
class Solution {
    public:
        vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
            priority_queue<pair<int, vector<int>>> maxHeap;
    
            for (vector<int>& point : points) {
                int x = point[0];
                int y = point[1];
                int distance = x * x + y * y;
    
                maxHeap.push({distance, point});
    
                if (maxHeap.size() > k) {
                    maxHeap.pop();
                }
            }
    
            vector<vector<int>> result;
            while (!maxHeap.empty()) {
                result.push_back(maxHeap.top().second);
                maxHeap.pop();
            }
    
            return result;
        }
    };
    





//Kth Largest Element in an Array
//https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            priority_queue<int> maxHeap;
            for (int num : nums) {
                maxHeap.push(num);
            }
            for (int i = 0; i < k - 1; ++i) {
                maxHeap.pop();
            }
            return maxHeap.top();
        }
    };
    