//Contains Duplicate
//https://leetcode.com/problems/contains-duplicate/
#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_set<int> countSet;
            for (int num : nums) {
                if (countSet.count(num)) {
                    return true;
                }
                countSet.insert(num);
            }
            return false;
        }
    };





//Two Sum
//https://leetcode.com/problems/two-sum/
#include <unordered_map>
class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> prevMap;  // value -> index
    
            for (int i = 0; i < nums.size(); i++) {
                int num = nums[i];
                int difference = target - num;
    
                if (prevMap.count(difference)) {
                    return vector<int>{prevMap[difference], i};
                }
    
                prevMap[num] = i;
            }
    
            return {}; 
        }
    };




//LRU Cache
//https://leetcode.com/problems/lru-cache/
#include <unordered_map>
class Node {
    public:
        int key, value;
        Node* prev;
        Node* next;
        Node(int key, int value) {
            this->key = key;
            this->value = value;
            prev = nullptr;
            next = nullptr;
        }
    };
class LRUCache {
    public:
        int capacity;
        unordered_map<int, Node*> cache;
        Node *left, *right; // dummy nodes: left = LRU, right = MRU
        LRUCache(int capacity) {
            this->capacity = capacity;
            left = new Node(0, 0);  // dummy LRU
            right = new Node(0, 0); // dummy MRU
            left->next = right;
            right->prev = left;
        }
        void remove(Node* node) {
            // Remove node from list
            Node* prevNode = node->prev;
            Node* nextNode = node->next;
            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }
    
        void insert(Node* node) {
            // Insert node before right (MRU end)
            Node* prevNode = right->prev;
            prevNode->next = node;
            node->prev = prevNode;
            node->next = right;
            right->prev = node;
        }
        int get(int key) {
            if (cache.count(key)) {
                Node* node = cache[key];
                remove(node);
                insert(node);  // move to MRU
                return node->value;
            }
            return -1;
        }
        
        void put(int key, int value) {
            if (cache.count(key)) {
                remove(cache[key]);
                delete cache[key];  // optional: to prevent memory leak
            }
            Node* newNode = new Node(key, value);
            insert(newNode);
            cache[key] = newNode;
    
            if (cache.size() > capacity) {
                Node* lru = left->next;
                remove(lru);
                cache.erase(lru->key);
                delete lru;  // free memory
            }
        }
    };