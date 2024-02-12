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
    TreeNode* insertIntoBST(TreeNode* &root, int data) {
        if(root == NULL) {
        
            root = new TreeNode(data);
            // cout << "root ka data " << root->data << endl;
            return root;
        }
    // its not the first node
        if(data > root->val) {
        root->right = insertIntoBST(root->right, data);
        }

        else {
            root->left = insertIntoBST(root->left, data);
        }

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root = NULL;
        for(int i=0; i<preorder.size(); i++) {
            insertIntoBST(root, preorder[i]);
        }

        return root;

    }
};