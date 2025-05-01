//Kth Largest Element in a Stream
//https://leetcode.com/problems/kth-largest-element-in-a-stream/
#include <vector>
#include <queue>
using namespace std;
class KthLargest {
    public:
        int k;
        priority_queue<int, vector<int>, greater<int>> heap;
    
        KthLargest(int k, vector<int>& nums) {
            this->k = k;
            for (int num : nums) {
                heap.push(num);
                if (heap.size() > k) {
                    heap.pop();
                }
            }
        }
        
        int add(int val) {
            heap.push(val);
            if (heap.size() > k) {
                heap.pop();
            }
            return heap.top();
        }
    };