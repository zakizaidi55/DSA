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
    void inorder(TreeNode* root, long long num, long long& sum) {
        if(!root) {
            return;
        }

        num += root->val;
        if(!root->left && !root->right) {
            sum += num;
        }

        inorder(root->left, num*10, sum);
        inorder(root->right, num*10, sum);
    }
    int sumNumbers(TreeNode* root) {
        long long sum = 0;
        long long num = 0;

        inorder(root, num, sum);
        return sum;
    }
};