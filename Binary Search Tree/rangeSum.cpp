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
    int rangeSumBSTHelper(TreeNode* root, int low, int high, int&ans) {
        if(root == NULL) {
            return 0;
        }

        if(root->val >= low && root->val <= high) {
            ans += root->val;
            cout << "ans " << ans << endl; 
        }

        rangeSumBSTHelper(root->left, low, high,ans);

        rangeSumBSTHelper(root->right, low, high, ans);


        return ans;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;

        return rangeSumBSTHelper(root, low, high, ans);


    }
};