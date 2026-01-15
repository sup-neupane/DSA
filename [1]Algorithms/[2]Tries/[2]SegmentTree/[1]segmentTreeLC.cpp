#include <unordered_map>
#include <map>
#include<set>
#include<unordered_set>
#include <string>
#include<vector>
#include<algorithm>

using namespace std;

//Range Sum Query - Mutable
//https://leetcode.com/problems/range-sum-query-mutable/
class SegmentTree {
public:
    int sum_;
    SegmentTree* left_;
    SegmentTree* right_;
    int L_;
    int R_;

    SegmentTree(int total, int L, int R) {
        sum_ = total;
        L_ = L, R_ = R;
        left_ = nullptr, right_ = nullptr;
    }

    // O(n)
    static SegmentTree* build(vector<int>& nums, int L, int R) {
        if (L == R) {
            return new SegmentTree(nums[L], L, R);
        }

        int M = (L + R) / 2;
        SegmentTree *root = new SegmentTree(0, L, R);
        root->left_ = SegmentTree::build(nums, L, M);
        root->right_ = SegmentTree::build(nums, M + 1, R);
        root->sum_ = root->left_->sum_ + root->right_->sum_; 
        return root;
    }

    void update(int index, int val) {
        if (L_ == R_) {
            sum_ = val;
            return;
        }
        int M = (L_ + R_) / 2;
        if (index > M) {
             right_->update(index, val);
        } else {
            left_->update(index, val);
        }
        sum_ = left_->sum_ + right_->sum_;
    }

    int rangeQuery(int L, int R) {
        if (L == L_ && R == R_) {
            return sum_;
        }
        int M = (L_ + R_) / 2;
        if (L > M) {
            return right_->rangeQuery(L, R);
        } else if (R <= M) {
            return left_->rangeQuery(L, R);
        } else {
            return (left_->rangeQuery(L, M) + 
                right_->rangeQuery(M + 1, R));
        }
    }
};
class NumArray {
public:
    SegmentTree* segmentTree;
    NumArray(vector<int>& nums) {
        if (nums.empty()) return;
        segmentTree = SegmentTree::build(nums, 0, nums.size() - 1);
    }
    
    void update(int index, int val) {
        segmentTree->update(index, val);
    }
    
    int sumRange(int left, int right) {
        return segmentTree->rangeQuery(left,right);
    }
};




//https://leetcode.com/problems/my-calendar-i/



//https://leetcode.com/problems/longest-increasing-subsequence-ii/


//Queue Reconstruction by Height
//https://leetcode.com/problems/queue-reconstruction-by-height/

