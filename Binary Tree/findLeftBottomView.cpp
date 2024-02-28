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
    void solve(TreeNode* root, int level, stack<int>&leftView) {
        if(root == NULL)
            return;
        
        if(level == leftView.size()) {
            leftView.push(root->val);
        }

        solve(root->left, level+1, leftView);
        solve(root->right, level+1, leftView);

    }
    int findBottomLeftValue(TreeNode* root) {
        stack<int>leftView;
        solve(root,0, leftView);
        
        return leftView.top();

    }
};