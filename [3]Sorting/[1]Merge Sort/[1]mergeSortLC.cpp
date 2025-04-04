// Sort an Array
// https://leetcode.com/problems/sort-an-array/
#include <vector>

using std::vector;

class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high) {
        // Copy the sorted left & right halves to temp arrays
        vector<int> L(nums.begin() + low, nums.begin() + mid + 1);
        vector<int> R(nums.begin() + mid + 1, nums.begin() + high + 1); 

        int i = 0; // index for L
        int j = 0; // index for R
        int k = low; // index for nums

        while (i < L.size() && j < R.size()) {
            if (L[i] <= R[j]) {
                nums[k] = L[i++];
            } else {
                nums[k] = R[j++];
            }
            k++;
        }

        // One of the halves will have elements remaining
        while (i < L.size()) {
            nums[k++] = L[i++];
        }
        while (j < R.size()) {
            nums[k++] = R[j++];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high) {
        if (high - low + 1 <= 1) {
            return;
        }

        // The middle index of the array
        int mid = (low + high) / 2;

        // Sort the left half
        mergeSort(nums, low, mid);

        // Sort the right half
        mergeSort(nums, mid + 1, high);

        // Merge sorted halves
        merge(nums, low, mid, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};





// Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next = nullptr;
    ListNode(int x)  {
        val = x;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        return mergeKListsHelper(lists, 0, lists.size() - 1);
    }
    
    ListNode* mergeKListsHelper(vector<ListNode*>& lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        int mid = (start + end) / 2;
        ListNode* left = mergeKListsHelper(lists, start, mid);
        ListNode* right = mergeKListsHelper(lists, mid + 1, end);
        return merge(left, right);
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        curr->next = l1 ? l1 : l2;
        
        return dummy->next;
    }
};
