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
    bool levelOrder(TreeNode* &root) {
        queue<TreeNode*> q;
        q.push(root);
        bool nullFound = false;
        while(!q.empty()) {
            TreeNode* frontNode = q.front();
            q.pop();

            if(frontNode == NULL) {
                nullFound = true;
            }

            else {

                if(nullFound) {
                    return false;
                }

                q.push(frontNode->left);
                q.push(frontNode->right);
            }

        }

        return true;
    }

    bool isCompleteTree(TreeNode* root) {
        return levelOrder(root);
    }
};