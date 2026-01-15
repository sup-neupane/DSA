#include <vector>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val, TreeNode* left, TreeNode* right) {
        val = val;
        left = left;
        right = right;
    }
};

//Binary Search Tree Iterator
//https://leetcode.com/problems/binary-search-tree-iterator/
class BSTIterator {
public:
    vector<int> res;
    int itr;

    BSTIterator(TreeNode* root) {
        TreeNode* curr = root;
        vector<TreeNode*> stack;
        itr = 0;

        while(curr || stack.size()){
            if(curr){
                stack.push_back(curr);
                curr = curr -> left;
            }else{
                curr = stack.back();
                stack.pop_back();
                res.push_back(curr -> val);
                curr = curr -> right;
            }
        }
    }
    
    int next() {
        return res[itr++];
    }
    
    bool hasNext() {
        return itr < res.size();
    }
};


//Binary Tree Preorder Traversal
//https://leetcode.com/problems/binary-tree-preorder-traversal/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<TreeNode*> stack;
        vector<int> res;
        TreeNode* curr = root;

        while(curr || stack.size()){
            if(curr){
                res.push_back(curr -> val);
                if(curr -> right){
                    stack.push_back(curr -> right);
                }
                curr = curr -> left;
            } else{
                curr = stack.back();
                stack.pop_back();
            }
        }
        return res;
    }
};


//Binary Tree Postorder Traversal
//https://leetcode.com/problems/binary-tree-postorder-traversal/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<TreeNode*> stack = {root};
        vector<bool> visit= {false};
        vector<int> res;

        while(stack.size()){
            TreeNode* curr = stack.back();
            bool visited = visit.back();
            stack.pop_back();
            visit.pop_back();

            if(curr){
                if(visited){
                    res.push_back(curr -> val);
                }else{
                    stack.push_back(curr);
                    visit.push_back(true);
                    stack.push_back(curr->right);
                    visit.push_back(false);
                    stack.push_back(curr->left);
                    visit.push_back(false);
                }
            }
        }
        return res;
    }
};
