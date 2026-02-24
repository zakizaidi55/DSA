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
    int solveUsingRec(TreeNode* root, int val) {
        if(!root)
            return 0;
        
        val = 2*val + root->val;

        if(root->left == NULL && root->right == NULL) {
            return val;
        }

        return solveUsingRec(root->left, val) + solveUsingRec(root->right, val);
    }
    int sumRootToLeaf(TreeNode* root) {
        int val = 0;
        return solveUsingRec(root, val);
    }
};


