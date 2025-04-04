// Sort an Array
// https://leetcode.com/problems/sort-an-array/
#include <vector>

using std::vector;
class Solution {
public:
vector<int> quickSort(vector<int>& arr, int s, int e) {
    if (e - s + 1 <= 1) {
        return arr;
    }

    int pivot = arr[e];
    int left = s; // pointer for left side

    // Partition: elements smaller than pivot on the left side.
    for (int i = s; i < e; i++) {
        if (arr[i] < pivot) {
            int tmp = arr[left];
            arr[left] = arr[i];
            arr[i] = tmp;
            left++;
        }
    }
    // Move pivot in-between left & right sides
    arr[e] = arr[left];
    arr[left] = pivot;
    
    // Quick sort left side
    quickSort(arr, s, left - 1);

    // Quick sort right side
    quickSort(arr, left + 1, e);

    return arr;
}




    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};




//Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/
class Solution {
public:
vector<int> quickSort(vector<int>& arr, int s, int e) {
    if (e - s + 1 <= 1) {
        return arr;
    }

    int pivot = arr[e];
    int left = s; // pointer for left side

    // Partition: elements smaller than pivot on the left side.
    for (int i = s; i < e; i++) {
        if (arr[i] < pivot) {
            int tmp = arr[left];
            arr[left] = arr[i];
            arr[i] = tmp;
            left++;
        }
    }
    // Move pivot in-between left & right sides
    arr[e] = arr[left];
    arr[left] = pivot;
    
    // Quick sort left side
    quickSort(arr, s, left - 1);

    // Quick sort right side
    quickSort(arr, left + 1, e);

    return arr;
}
    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums, 0, nums.size() - 1);
        return nums[nums.size() - k]; 
    }
};




//Better do with merge sort: Same concept
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

    int findKthLargest(vector<int>& nums, int k) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums[nums.size() - k]; 
    }
};





