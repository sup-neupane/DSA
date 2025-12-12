#include <vector>
using namespace std;

class PrefixSum {
private:
    vector<int> prefix;

public:
    // Constructor: build prefix sum array
    PrefixSum(vector<int>& nums) {
        int total = 0;
        for (int n : nums) {
            total += n;
            prefix.push_back(total);
        }
    }

    // Get range sum from left to right (inclusive)
    int rangeSum(int left, int right) {
        int preRight = prefix[right];
        int preLeft = (left > 0 ? prefix[left - 1] : 0);
        return preRight - preLeft;
    }
};
