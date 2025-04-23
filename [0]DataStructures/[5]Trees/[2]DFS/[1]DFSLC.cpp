//Binary Tree Inorder Traversal
//https://leetcode.com/problems/binary-tree-inorder-traversal/
#include <vector>
using namespace std;
class TreeNode {
    public:
        int val;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;

        TreeNode(int val) {
            val = val;
        }
};
class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> res;
            inorder(root, res);
            return res;
        }
    
        void inorder(TreeNode* node, vector<int>& res) {
            if (!node) return;
            inorder(node->left, res);
            res.push_back(node->val);
            inorder(node->right, res);
        }
    };
    











//Kth Smallest Element in a BST
//https://leetcode.com/problems/kth-smallest-element-in-a-bst/
class Solution {
    public:
        int kthSmallest(TreeNode* root, int k) {
            vector<int> res;
            inorder(root, res);
            return res[k -1];
        }
                void inorder(TreeNode* node, vector<int>& res) {
                if (!node) return;
                inorder(node->left, res);
                res.push_back(node->val);
                inorder(node->right, res);
            }
    };




