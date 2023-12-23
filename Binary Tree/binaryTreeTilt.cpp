/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    public: 
    int treeSum(TreeNode* root){
        if(!root) return 0;
        return root->val + treeSum(root->left) + treeSum(root->right);
    }
    
    int findTilt(TreeNode* root) {
        if(!root) return 0;
        return abs(treeSum(root->left) - treeSum(root->right)) + 
            findTilt(root->left) + findTilt(root->right);
    }
};