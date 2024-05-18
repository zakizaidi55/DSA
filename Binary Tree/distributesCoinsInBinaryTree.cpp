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
    int solve(TreeNode* root, int &count) {
        if(!root) 
            return 0;
        
        int left = solve(root->left, count);
        int right = solve(root->right, count);

        count += abs(left)  + abs(right);

        return (left + right + root->val-1);
    }
    int distributeCoins(TreeNode* root) {
        int count = 0;
        solve(root, count);
        return count;
    }
};