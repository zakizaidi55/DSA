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
    pair<int, int> solveUsingPostOrder(TreeNode* root, int&ans) {

        if(!root)
            return {0, 0};
        
        auto[leftSubTree, leftCount] = solveUsingPostOrder(root->left, ans);
        auto[rightSubTree, rightCount] = solveUsingPostOrder(root->right, ans);
        int sum = leftSubTree + rightSubTree + root->val;
        int count = leftCount + rightCount + 1;

        if(sum/count == root->val) 
            ans++;
        
        return {sum, count};

    }
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solveUsingPostOrder(root, ans);

        return ans;
    }
};
