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
    void solveUsingRecursion(TreeNode* root, int val, int depth, int curr) {
        if(root == NULL) {
            return;
        }

        if(curr == depth-1) {
            TreeNode* tempLeft = root->left;
            TreeNode* newLeftNode = new TreeNode(val);
            root->left = newLeftNode;
            newLeftNode->left = tempLeft;

            TreeNode* tempRight = root->right;
            TreeNode* newRightNode = new TreeNode(val);
            root->right = newRightNode;
            newRightNode->right = tempRight;
        }

        else {
            solveUsingRecursion(root->left, val, depth, curr+1);
            solveUsingRecursion(root->right, val, depth, curr+1);
        }
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }

        int curr = 1; 
        solveUsingRecursion(root, val, depth, curr);        

        return root;
    }
};