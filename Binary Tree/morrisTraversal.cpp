class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr = root;
        while(curr) {
            // left node is null, then visited it and go right
            if(curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            }

            // left node is not null
            else {
                // find inorder predeccasor
                TreeNode* pred = curr->left;
                while(pred->right != curr && pred->right) {
                    pred = pred->right;

                }

                // if right node is null then go left after establishing link from pred to curr
                if(pred->right == NULL) {
                    pred->right = curr;
                    curr = curr->left;
                }

                else {
                    // left is already visited, then go right after visiting curr node after removing the link
                    pred->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }

        }

        return ans;
    }
};