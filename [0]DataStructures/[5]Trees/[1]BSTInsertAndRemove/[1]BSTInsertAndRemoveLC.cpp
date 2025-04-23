//Insert into a Binary Search Tree
//https://leetcode.com/problems/insert-into-a-binary-search-tree/
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
        TreeNode* insertIntoBST(TreeNode* root, int val) {
            if(!root){
                return new TreeNode(val);
            }
            if(val > root-> val){
                root -> right = insertIntoBST(root -> right, val);
            } else if(val < root-> val){
                root -> left = insertIntoBST(root -> left, val);
            }
            return root;
        }
    };













//Delete Node in a BST
//https://leetcode.com/problems/delete-node-in-a-bst/
class Solution {
    public:
        TreeNode* findMin(TreeNode* root){
            TreeNode* curr = root;
            while(curr && curr -> left){
                curr = curr -> left;
            }
            return curr;
        }
        TreeNode* deleteNode(TreeNode* root, int key) {
            if(!root){
                return nullptr;
            }
            if(key > root -> val){
                root -> right = deleteNode(root -> right, key);
            } else if( key < root -> val ){
                root -> left = deleteNode(root -> left, key);
            }else{
                if(!root -> left){
                    return root-> right;
                }else if(!root -> right){
                    return root-> left;
                }else{
                    TreeNode* minNode = findMin(root -> right);
                    root -> val = minNode -> val;
                    root -> right = deleteNode(root -> right, minNode -> val);
                }
            }
        return root;
        }
};