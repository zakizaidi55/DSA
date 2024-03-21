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
    bool isbalanced = true;
    int height (TreeNode* root) {
        if(!root) 
            return 0;
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if(isbalanced && abs(leftHeight - rightHeight) > 1)
            isbalanced = false;
        return max(leftHeight, rightHeight) + 1;
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return isbalanced;
    }
};