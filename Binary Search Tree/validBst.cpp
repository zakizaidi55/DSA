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
    bool solve(TreeNode* root, long long int LB, long long int UB) {
        if(root == NULL)
            return true;
        
        bool cond1 = root->val > LB;
        bool cond2 = root->val < UB;

        bool leftAns = solve(root->left,LB ,root->val );

        bool rightAns = solve(root->right, root->val ,UB );

        if(cond1 && cond2 && leftAns && rightAns) {
            return true;
        }

        return false;
    }
    bool isValidBST(TreeNode* root) {
       long long int LB = -2147483688;
       long long int UB = 2147483688;


       bool ans = solve(root, LB, UB);

       return ans;
    }
};