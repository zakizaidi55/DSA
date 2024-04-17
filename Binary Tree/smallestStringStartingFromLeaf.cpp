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
    void dfs(TreeNode* root, string path, string &ans) {
        // base case
        if(!root) 
            return;
        
        path += ('a' + root->val);

        if(!root->left && !root->right) {
            reverse(path.begin(), path.end());
            if(ans.size() == 0 || path < ans) {
                ans = path;
            }
            // catch-> yahi mistake karta hu important path 
            reverse(path.begin(), path.end());
        }

        dfs(root->left, path, ans);
        dfs(root->right, path, ans);
    }
    string smallestFromLeaf(TreeNode* root) {
        string path = "";
        string ans = "";

        dfs(root, path, ans);
        return ans;
    }
};