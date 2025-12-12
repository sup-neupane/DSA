#include <iostream>
#include <vector>
#include <algorithm>   
using namespace std;


class ListNode {
public:
    ListNode* next;
    int val;
};

//Middle of the Linked List
//https://leetcode.com/problems/middle-of-the-linked-list/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) { 
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
    }
};

//Maximum Twin Sum of a Linked List
//https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode *fast = head, *slow = head;
        ListNode *prev = nullptr;
        int res = 0;
        while(fast && fast -> next){
            fast = fast -> next -> next;
            ListNode * temp = slow -> next;
            slow -> next = prev;
            prev = slow;
            slow = temp;
        }

        while(slow){
            res = max(res, prev -> val + slow -> val);
            prev = prev -> next;
            slow = slow -> next;
        }
        return res;
    }
};

//Linked List Cycle
//https://leetcode.com/problems/linked-list-cycle/
class Solution {
public:
    bool hasCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
    }
};

//Linked List Cycle II
//https://leetcode.com/problems/linked-list-cycle-ii/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    if (!fast || !fast->next) {
        return nullptr;
    }
    ListNode *slow2 = head;
    while (slow != slow2) {
        slow = slow->next;
        slow2 = slow2->next;
    }
    return slow;
    }
};



//Find the Duplicate Number
//https://leetcode.com/problems/find-the-duplicate-number/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
    int slow = 0, fast = 0;
    int slow2 = 0;
    while (true) {
        slow = nums[slow];
        fast = nums[nums[fast]];
        if (slow == fast) {
            break;
        }
    }

    while (true) {
        slow = nums[slow];
        slow2 = nums[slow2];
        if(slow == slow2){
            return slow;
        }
    };
    }
};