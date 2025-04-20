//Design Linked List
//https://leetcode.com/problems/design-linked-list/
class Node{
    public:
    int val_;
    Node * next = nullptr;
    Node * prev = nullptr;
    Node(int val){
        val_= val;
    }
};

class MyLinkedList {
public:
    Node * head;
    Node * tail;
    MyLinkedList() {  
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int index) {
        Node *curr =  head -> next;
        while (curr && index>0){
            curr = curr -> next;
            index --;
        }
        if (curr and curr !=tail and index == 0){
            return curr->val_;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node * newNode = new Node(val);
        newNode->prev = head;
        newNode->next = head->next;

        head->next->prev = newNode;
        head->next = newNode;

    }
    
    void addAtTail(int val) {
        Node* newNode = new Node(val);
        newNode->next = tail;
        newNode->prev = tail->prev;

        tail->prev->next = newNode;
        tail->prev = newNode;
    }
    
    void addAtIndex(int index, int val) {
        Node *curr =  head -> next;
        while (curr && index>0){
            curr = curr -> next;
            index --;
        }
        if (curr and index == 0){
            Node* newNode = new Node(val);
            newNode->next = curr;
            newNode->prev = curr -> prev;  
            curr->prev->next = newNode;
            curr->prev = newNode;
        }
    }
    
    void deleteAtIndex(int index) {
        Node *curr =  head -> next;
        while (curr && index>0){
            curr = curr -> next;
            index --;
        }
    if (curr and curr != tail and index == 0) {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        delete curr; 
        // Proper memory cleanup and no garbage collector in cpp
    }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */













//Design Browser History
//https://leetcode.com/problems/design-browser-history/
// You can approach it my two methods:
// 1.Doubly Linked List
#include <string>
using namespace std;
class BrowserNode{
    public:
    string val_;
    BrowserNode *prev = nullptr;
    BrowserNode *next = nullptr;

    BrowserNode(string val){
        val_ = val;
    }
};
class BrowserHistory {
public:
    BrowserNode * curr = nullptr;
    BrowserHistory(string homepage) {
       curr = new BrowserNode(homepage);
    }
    
    void visit(string url) {
        BrowserNode * newNode = new BrowserNode(url);
        curr->next = newNode;
        newNode->prev = curr;
        curr = curr->next;
    }
    
    string back(int steps) {
        while (curr->prev && steps>0) {
            curr = curr->prev;
            steps --;
        }
        return curr -> val_;

    }
    
    string forward(int steps) {
            while (curr->next && steps>0) {
            curr = curr->next;
            steps --;
        }
        return curr -> val_;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */




// 2.Stack: More Efficient because of indexing watch solution whenever you want


