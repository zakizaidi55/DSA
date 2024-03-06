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
    int solveUsingRec(TreeNode* root) {
        if(!root) {
            return 0;
        }

        int robThisHouse = 0;
        int dontRobThisHouse = 0;

        // rob the current house
        robThisHouse += root->val;
        if(root->left) {
            robThisHouse += solveUsingRec(root->left->left) + solveUsingRec(root->left->right);
        }

        if(root->right) {
            robThisHouse += solveUsingRec(root->right->left) + solveUsingRec(root->right->right);
        }
        
        dontRobThisHouse += solveUsingRec(root->left) + solveUsingRec(root->right);

        return max(robThisHouse,dontRobThisHouse);

    }

    int solveUsingMem(TreeNode* root, unordered_map<TreeNode*, int>&dp) {
        if(!root) {
            return 0;
        }

        if(dp.find(root) != dp.end()) {
            return dp[root];
        }

        int robThisHouse = 0;
        int dontRobThisHouse = 0;
        

        // rob the current house
        robThisHouse += root->val;
        if(root->left) {
            robThisHouse += solveUsingMem(root->left->left, dp) + solveUsingMem(root->left->right, dp);
        }

        if(root->right) {
            robThisHouse += solveUsingMem(root->right->left, dp) + solveUsingMem(root->right->right, dp);
        }
        
        dontRobThisHouse += solveUsingMem(root->left, dp) + solveUsingMem(root->right, dp);

        dp[root] = max(robThisHouse,dontRobThisHouse);
        return dp[root];
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int>dp;
        // return solveUsingRec(root);
        return solveUsingMem(root, dp);
    }   
};