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
    void solve(TreeNode* root, int&sum) {
        // base case
        if(!root) 
            return;

        
        solve(root->right, sum); //right side covered

        // update sum
        sum += root->val;
        // update root ki val
        root->val = sum;

        solve(root->left, sum); //left side covered

         
    }


    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        solve(root, sum);

        return root;
    }
};