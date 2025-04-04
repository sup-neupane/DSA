 struct ListNode {
   int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };



//Reverse Linked List
//https://leetcode.com/problems/reverse-linked-list/
class Solution {
public:
    // Helper function for recursion
    ListNode* reverse(ListNode* cur, ListNode* prev) {
        if (cur == nullptr) {
            return prev;
        } else {
            ListNode* next = cur->next;
            cur->next = prev;
            return reverse(next, cur);
        }
    }

    ListNode* reverseList(ListNode* head) {
        return reverse(head, nullptr);
    }
};
