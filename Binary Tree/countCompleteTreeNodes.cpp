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
    int findLeft(TreeNode* root) {
        int h = 0;
        while(root) {
            h++;
            root = root->left;
        }

        return h;
    }

    int findRight(TreeNode* root) {
        int h = 0;
        while(root) {
            h++;
            root = root->right;
        }

        return h;
    }

    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        int lh = findLeft(root);
        int rh = findRight(root);

        if(lh == rh) {
            // full CBT
            return (1 << lh) - 1;
        }

        // lh != rh
        int countLeft = countNodes(root->left);
        int countRight = countNodes(root->right);

        return countLeft + countRight + 1;
    }
};


