/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if(root == NULL)
            return NULL;
        
        // case 1: both p and q both are in left
        if(p->val < root->val && q->val < root->val) {
            TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
            return leftAns;
        }

        // case 2: both p and q are in right
        if(p->val > root->val && q->val > root->val) {
            TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);
            return rightAns;
        }

        // case3: p in left and q in right
        if(p->val < root->val && q->val > root->val) {
            return root;
        }

        // case4: p in right and q in left
        if(p->val > root->val && q->val < root->val) {
            return root;
        }

        
        return root;
    }
};