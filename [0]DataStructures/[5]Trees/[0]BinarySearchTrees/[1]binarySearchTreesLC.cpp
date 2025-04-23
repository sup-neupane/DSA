//Search in a Binary Search Tree
//https://leetcode.com/problems/search-in-a-binary-search-tree/

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
        TreeNode* searchBST(TreeNode* root, int val) {
            if(! root){
                return nullptr;
            }
            if(val > root -> val){
                return searchBST(root -> right, val);
            }else if(val < root->val){
                return searchBST(root -> left , val);
            }else{
                return root;
            }
        }
    };










//Lowest Common Ancestor of a Binary Search Tree
//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            TreeNode* curr = root;
            while(curr){
                if(p-> val > curr ->val && q-> val > curr->val){
                    curr = curr -> right;
                }
                else if(p-> val < curr ->val && q-> val < curr->val){
                    curr = curr -> left;
                }
                else{
                    return curr;
                }
            }
            return nullptr;
        }
    };