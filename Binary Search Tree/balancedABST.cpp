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
    TreeNode* createABSTFromInorder(vector<int>&inorder, int start, int end) {
        if(start > end) {
            return NULL;
        }

        int mid = start + (end-start)/2;

        int element = inorder[mid];
        TreeNode* root = new TreeNode(element);

        root->left = createABSTFromInorder(inorder, start, mid-1);

        root->right = createABSTFromInorder(inorder, mid+1, end);


        return root;
    }
    void createInorder(TreeNode*&root, vector<int>& inorder) {
        if(root == NULL)
            return;
        
        createInorder(root->left, inorder);
        inorder.push_back(root->val);
        createInorder(root->right, inorder);

    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>inorder;

        createInorder(root, inorder);
        int start = 0;
        int end = inorder.size()-1;

        return createABSTFromInorder(inorder, start, end);
    }
}; 