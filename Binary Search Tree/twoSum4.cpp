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
    void storeInorder(TreeNode* root, vector<int>&inOrder) {
        if(root == NULL) {
            return;
        }

        // left
        storeInorder(root->left, inOrder);

        //Node
        inOrder.push_back(root->val);

        // right
        storeInorder(root->right, inOrder);

    }
    bool findTarget(TreeNode* root, int k) {
        vector<int>inOrder;
        storeInorder(root, inOrder);

        // two pointer approach
        int start = 0;
        int end = inOrder.size()-1;

        while(start < end) {
            int sum = inOrder[start] + inOrder[end];
            if(sum == k)
                return true;
                
            else if(sum > k) {
                end--;
            }

            else {
                start ++;
            }
        }

        return false;
    }
};