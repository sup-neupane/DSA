//Design HashSet
//https://leetcode.com/problems/design-hashset/
#include <vector>
#include <string>
#include <iostream>

using namespace std;
class HashNode {
    public:
        int val;
        HashNode* next = nullptr;
    
        HashNode(int val) {
            this->val = val;
        }
    };
    
    class MyHashSet {
    public:
        vector<HashNode*> set;
    
        MyHashSet() {
            set.resize(10000, nullptr);
        }
    
        void add(int val) {
            int index = val % set.size();
    
            // Initialize the bucket with a dummy head if it doesn't exist
            if (!set[index]) {
                set[index] = new HashNode(-1);  // dummy node
            }
    
            HashNode* curr = set[index];
    
            // Traverse to check if val exists
            while (curr->next) {
                if (curr->next->val == val) return;  // already exists
                curr = curr->next;
            }
    
            // Add new node at the end
            curr->next = new HashNode(val);
        }
    
        void remove(int val) {
            int index = val % set.size();
    
            if (!set[index]) {
                set[index] = new HashNode(-1); 
            }
    
            HashNode* curr = set[index];
    
            while (curr->next) {
                if (curr->next->val == val) {
                    curr->next = curr->next->next;
                    return;
                }
                curr = curr->next;
            }
        }
    
        bool contains(int val) {
            int index = val % set.size();
    
            if (!set[index]) {
                set[index] = new HashNode(-1); 
            }
    
            HashNode* curr = set[index];
    
            while (curr->next) {
                if (curr->next -> val == val) {
                    return true;
                }
                curr = curr->next;
            }
    
            return false;
        }
    };
    




//Design HashMap
//https://leetcode.com/problems/design-hashmap/   
    class Node {
    public:
        int key, val;
        Node* next = nullptr;
    
        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };
    
    class MyHashMap {
    public:
        vector<Node*> map;
    
        MyHashMap() {
            map.resize(10000, nullptr);
        }
    
        void put(int key, int value) {
            int index = key % map.size();
            if (!map[index]) {
                map[index] = new Node(-1, -1);  // dummy head
            }
    
            Node* curr = map[index];
            while (curr->next) {
                if (curr->next->key == key) {
                    curr->next->val = value;  // update value if key exists
                    return;
                }
                curr = curr->next;
            }
    
            // Add new node at the end
            curr->next = new Node(key, value);
        }
    
        void remove(int key) {
            int index = key % map.size();
            if (!map[index]) return;
    
            Node* curr = map[index];
            while (curr->next) {
                if (curr->next->key == key) {
                    Node* toDelete = curr->next;
                    curr->next = curr->next->next;
                    delete toDelete;
                    return;
                }
                curr = curr->next;
            }
        }
    
        bool contains(int key) {
            int index = key % map.size();
            if (!map[index]) return false;
    
            Node* curr = map[index];
            while (curr->next) {
                if (curr->next -> key == key) return true;
                curr = curr->next;
            }
    
            return false;
        }
    
        int get(int key) {
            int index = key % map.size();
            if (!map[index]) return -1;
        
            Node* curr = map[index];
            while (curr->next) {
                if (curr->next->key == key)
                    return curr->next->val;
                curr = curr->next;
            }
            return -1;
        }   
    };