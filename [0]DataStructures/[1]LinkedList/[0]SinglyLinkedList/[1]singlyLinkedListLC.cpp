 struct ListNode {
   int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };





//Reverse Linked List
//https://leetcode.com/problems/reverse-linked-list/

//Method 1: Iterative: Using 3 pointers



class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode * prev = nullptr;
        ListNode * curr = head;
        while(curr){
            ListNode * next = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

//Method 2: Recursive
//This method is not recommended as it uses extra space in the stack

//Solution is in Recursion File> One Branch Recursion




//Merge Two Sorted Lists
//https://leetcode.com/problems/merge-two-sorted-lists/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while (list1 && list2) {
            if (list1->val > list2->val) {
                tail->next = list2;
                list2 = list2->next;
            } else {
                tail->next = list1;
                list1 = list1->next;
            }
            tail = tail->next;
        }  

        tail->next = list1 ? list1 : list2;

        return dummy->next;        
    }
};
