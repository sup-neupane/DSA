//Binary Tree Level Order Traversal
//https://leetcode.com/problems/binary-tree-level-order-traversal/
#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::queue;
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
        vector<vector<int>> levelOrder(TreeNode* root) {
            vector<vector<int>> res;
            queue<TreeNode*> queue;
            if(root){
                queue.push(root);
            }
            while(!queue.empty()){
                int length = queue.size();
                vector<int> level;  
                for(int i = 0; i < length; i++){
                    TreeNode* curr = queue.front();
                    queue.pop();
                    level.push_back(curr->val);
                    if(curr->left){
                        queue.push(curr->left);
                    }
                    if(curr->right){
                        queue.push(curr->right);
                    }
                }
                res.push_back(level);
            }
            return res;
        }
    };
    










//Binary Tree Right Side View
//https://leetcode.com/problems/binary-tree-right-side-view/
class Solution {
    public:
        vector<int> rightSideView(TreeNode* root) {
            vector<int> res;
            queue<TreeNode*> queue;
            if(root){
                queue.push(root);
            }
            while(!queue.empty()){
                int length = queue.size(); 
                for(int i = 0; i < length; i++){
                    TreeNode* curr = queue.front();
                    queue.pop();
                    if (i == length - 1) {
                        res.push_back(curr->val);
                    }
                    
                    if(curr->left){
                        queue.push(curr->left);
                    }
                    if(curr->right){
                        queue.push(curr->right);
                    }
                }
            }
            return res;
        }
    };