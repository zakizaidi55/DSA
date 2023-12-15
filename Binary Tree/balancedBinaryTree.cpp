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
    int height(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        int finalAns = max(leftHeight, rightHeight) + 1;

        return finalAns;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) {
            return true;
        }

        // solve the current node
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        int diff = abs(leftHeight - rightHeight); 

        bool currNodeAns = (diff <= 1);
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);


        if(currNodeAns && leftAns && rightAns) {
            return true;
        }

        else {
            return false;
        }
    }
};







// ------------------method 2----------------------

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
    bool isBalancedNode = true;
    int height(TreeNode* root) {
        if(root == NULL) {
           return 0;
        } 

       
        int leftHeight = height(root->left);
        
        int rightHeight = height(root->right);
        
        // check for all the node, is it balanced

        if(isBalancedNode && abs(leftHeight - rightHeight) > 1) {
            isBalancedNode = false;
        }

        int ans = 1 + max(leftHeight, rightHeight);

        
        return ans;
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return isBalancedNode;
    }
};